#include "php_parser_thread.h"
#include "PHPLookupTable.h"
#include "PHPSourceFile.h"
#include "macros.h"
#include <wx/dir.h>

PHPParserThread* PHPParserThread::ms_instance = 0;

PHPParserThread::PHPParserThread() {}

PHPParserThread::~PHPParserThread() {}

PHPParserThread* PHPParserThread::Instance()
{
    if(ms_instance == 0) {
        ms_instance = new PHPParserThread();
    }
    return ms_instance;
}

void PHPParserThread::Release()
{
    ms_instance->Stop();
    if(ms_instance) {
        delete ms_instance;
    }
    ms_instance = 0;
}

void PHPParserThread::ProcessRequest(ThreadRequest* request)
{
    PHPParserThreadRequest* r = dynamic_cast<PHPParserThreadRequest*>(request);
    if(r) {
        switch(r->requestType) {
        case PHPParserThreadRequest::kParseWorkspaceFilesFull:
        case PHPParserThreadRequest::kParseWorkspaceFilesQuick:
            ParseFiles(r);
            break;
        case PHPParserThreadRequest::kParseSingleFile:
            ParseFile(r);
            break;
        }
    }
}

void PHPParserThread::ParseFiles(PHPParserThreadRequest* request)
{
    wxFileName fnWorkspaceFile(request->workspaceFile);

    wxStringSet_t uniqueFilesSet;
    uniqueFilesSet.insert(request->files.begin(), request->files.end());

    // Open the database
    PHPLookupTable lookuptable;
    lookuptable.Open(fnWorkspaceFile.GetPath());

    for(size_t i = 0; i < request->frameworksPaths.GetCount(); ++i) {
        wxArrayString frameworkFiles;
        wxDir::GetAllFiles(request->frameworksPaths.Item(i), &frameworkFiles, "*.php", wxDIR_DIRS | wxDIR_FILES);
        uniqueFilesSet.insert(frameworkFiles.begin(), frameworkFiles.end());
    }

    // Convert the set back to array
    wxArrayString allFiles;
    wxStringSet_t::iterator iter = uniqueFilesSet.begin();
    for(; iter != uniqueFilesSet.end(); ++iter) {
        allFiles.Add(*iter);
    }

    // Get list of PHP files under
    lookuptable.UpdateSourceFiles(allFiles,
                                  request->requestType == PHPParserThreadRequest::kParseWorkspaceFilesFull ?
                                      PHPLookupTable::kUpdateMode_Full :
                                      PHPLookupTable::kUpdateMode_Fast,
                                  false);
}

void PHPParserThread::ParseFile(PHPParserThreadRequest* request)
{
    wxFileName fnWorkspaceFile(request->workspaceFile);
    PHPLookupTable lookuptable;
    lookuptable.Open(fnWorkspaceFile.GetPath());

    wxArrayString files;
    files.Add(request->file);
    lookuptable.UpdateSourceFiles(files, PHPLookupTable::kUpdateMode_Full, false);
}