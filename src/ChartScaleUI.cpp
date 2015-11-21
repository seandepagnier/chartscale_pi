///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 12 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ChartScaleUI.h"

///////////////////////////////////////////////////////////////////////////

ChartScaleDialogBase::ChartScaleDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	
	this->Centre( wxBOTH );
}

ChartScaleDialogBase::~ChartScaleDialogBase()
{
}

PreferencesDialogBase::PreferencesDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer6->AddGrowableCol( 1 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, _("Transparency"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	fgSizer6->Add( m_staticText18, 0, wxALL, 5 );
	
	m_sTransparency = new wxSlider( this, wxID_ANY, 15, 0, 80, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_sTransparency->SetMinSize( wxSize( 60,-1 ) );
	
	fgSizer6->Add( m_sTransparency, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, _("Orientation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer6->Add( m_staticText10, 0, wxALL, 5 );
	
	wxString m_cOrientationChoices[] = { _("Vertical"), _("Horizontal") };
	int m_cOrientationNChoices = sizeof( m_cOrientationChoices ) / sizeof( wxString );
	m_cOrientation = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_cOrientationNChoices, m_cOrientationChoices, 0 );
	m_cOrientation->SetSelection( 0 );
	fgSizer6->Add( m_cOrientation, 0, wxALL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer6->Add( m_staticText3, 0, wxALL, 5 );
	
	m_sSize = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 20, 500, 180 );
	fgSizer6->Add( m_sSize, 0, wxALL, 5 );
	
	
	fgSizer7->Add( fgSizer6, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_cbShowTitleBar = new wxCheckBox( this, wxID_ANY, _("Show Title Bar"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_cbShowTitleBar, 0, wxALL, 5 );
	
	m_cbLastButton = new wxCheckBox( this, wxID_ANY, _("Last Button"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_cbLastButton, 0, wxALL, 5 );
	
	
	fgSizer7->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer4->AddGrowableCol( 1 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_bAboutAuthor = new wxButton( this, wxID_ANY, _("About Author"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_bAboutAuthor, 0, wxALL, 5 );
	
	m_sdbSizer2 = new wxStdDialogButtonSizer();
	m_sdbSizer2OK = new wxButton( this, wxID_OK );
	m_sdbSizer2->AddButton( m_sdbSizer2OK );
	m_sdbSizer2->Realize();
	
	fgSizer4->Add( m_sdbSizer2, 1, wxEXPAND, 5 );
	
	
	fgSizer7->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( fgSizer7 );
	this->Layout();
	fgSizer7->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_sTransparency->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_bAboutAuthor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialogBase::OnAboutAuthor ), NULL, this );
}

PreferencesDialogBase::~PreferencesDialogBase()
{
	// Disconnect Events
	m_sTransparency->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_sTransparency->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PreferencesDialogBase::Refresh ), NULL, this );
	m_bAboutAuthor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PreferencesDialogBase::OnAboutAuthor ), NULL, this );
	
}
