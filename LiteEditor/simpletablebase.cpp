///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "simpletablebase.h"

///////////////////////////////////////////////////////////////////////////

SimpleTableBase::SimpleTableBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	long treeStyle = wxTR_HIDE_ROOT|wxTR_COLUMN_LINES|wxTR_ROW_LINES|wxTR_FULL_ROW_HIGHLIGHT|wxTR_EDIT_LABELS|wxTR_HAS_BUTTONS;
	m_listTable = new wxTreeListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, treeStyle);
	bSizer3->Add( m_listTable, 1, wxEXPAND|wxALL, 1 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_button1 = new wxButton( this, wxID_ANY, wxT("New..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button1, 0, wxALL|wxEXPAND, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button2, 0, wxALL|wxEXPAND, 5 );

	m_button3 = new wxButton( this, wxID_ANY, wxT("Delete All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button3, 0, wxALL|wxEXPAND, 5 );

	bSizer3->Add( bSizer4, 0, wxEXPAND, 5 );

	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );

	this->SetSizer( bSizer1 );
	this->Layout();

	// Connect Events
	m_listTable->Connect( wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT, wxTreeEventHandler( SimpleTableBase::OnListEditLabelBegin ), NULL, this );
	m_listTable->Connect( wxEVT_COMMAND_TREE_END_LABEL_EDIT,   wxTreeEventHandler( SimpleTableBase::OnListEditLabelEnd ), NULL, this );
	m_listTable->Connect( wxEVT_COMMAND_TREE_ITEM_MENU,        wxTreeEventHandler( SimpleTableBase::OnItemRightClick ), NULL, this );
	m_listTable->Connect( wxEVT_COMMAND_TREE_KEY_DOWN,         wxTreeEventHandler( SimpleTableBase::OnListKeyDown ), NULL, this );
	m_listTable->Connect( wxEVT_COMMAND_TREE_ITEM_EXPANDING,   wxTreeEventHandler( SimpleTableBase::OnItemExpanding ), NULL, this );
	
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SimpleTableBase::OnNewWatch ), NULL, this );
	m_button1->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( SimpleTableBase::OnNewWatchUI ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SimpleTableBase::OnDeleteWatch ), NULL, this );
	m_button2->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( SimpleTableBase::OnDeleteWatchUI ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SimpleTableBase::OnDeleteAll ), NULL, this );
	m_button3->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( SimpleTableBase::OnDeleteAllUI ), NULL, this );
}

SimpleTableBase::~SimpleTableBase()
{
	// Disconnect Events
	m_listTable->Disconnect( wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT, wxTreeEventHandler( SimpleTableBase::OnListEditLabelBegin ), NULL, this );
	m_listTable->Disconnect( wxEVT_COMMAND_TREE_END_LABEL_EDIT,   wxTreeEventHandler( SimpleTableBase::OnListEditLabelEnd ), NULL, this );
	m_listTable->Disconnect( wxEVT_COMMAND_TREE_ITEM_MENU,        wxTreeEventHandler( SimpleTableBase::OnItemRightClick ), NULL, this );
	m_listTable->Disconnect( wxEVT_COMMAND_TREE_KEY_DOWN,         wxTreeEventHandler( SimpleTableBase::OnListKeyDown ), NULL, this );
	m_listTable->Disconnect( wxEVT_COMMAND_TREE_ITEM_EXPANDING,   wxTreeEventHandler( SimpleTableBase::OnItemExpanding ), NULL, this );
	
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SimpleTableBase::OnNewWatch ), NULL, this );
	m_button1->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( SimpleTableBase::OnNewWatchUI ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SimpleTableBase::OnDeleteWatch ), NULL, this );
	m_button2->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( SimpleTableBase::OnDeleteWatchUI ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SimpleTableBase::OnDeleteAll ), NULL, this );
	m_button3->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( SimpleTableBase::OnDeleteAllUI ), NULL, this );
}

LocalsTableBase::LocalsTableBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_listTable = new wxListView( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	bSizer3->Add( m_listTable, 1, wxEXPAND|wxALL, 1 );

	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );

	wxString m_choiceExpandChoices[] = { wxT("Select an entry to explore it in the 'Display Variable' dialog"), wxT("Double click an entry to explore it in the 'Display Variable' dialog") };
	int m_choiceExpandNChoices = sizeof( m_choiceExpandChoices ) / sizeof( wxString );
	m_choiceExpand = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceExpandNChoices, m_choiceExpandChoices, 0 );
	m_choiceExpand->SetSelection( 1 );
	bSizer1->Add( m_choiceExpand, 0, wxALL|wxEXPAND, 5 );

	this->SetSizer( bSizer1 );
	this->Layout();

	// Connect Events
	m_listTable->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( LocalsTableBase::OnItemActivated ), NULL, this );
	m_listTable->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( LocalsTableBase::OnItemSelected ), NULL, this );
}

LocalsTableBase::~LocalsTableBase()
{
	// Disconnect Events
	m_listTable->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( LocalsTableBase::OnItemActivated ), NULL, this );
	m_listTable->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( LocalsTableBase::OnItemSelected ), NULL, this );
}
