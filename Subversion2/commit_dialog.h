#ifndef __commit_dialog__
#define __commit_dialog__

/**
@file
Subclass of CommitDialogBase, which is generated by wxFormBuilder.
*/

#include "subversion2_ui.h"

class IManager;
/** Implementing CommitDialogBase */
class CommitDialog : public CommitDialogBase
{
	IManager *m_manager;

private:
	wxString NormalizeMessage(const wxString &message);

public:
	/** Constructor */
	CommitDialog( wxWindow* parent, const wxArrayString &paths, IManager *manager );
	virtual ~CommitDialog();

	wxString      GetMesasge();
	wxArrayString GetPaths();
};

#endif // __commit_dialog__
