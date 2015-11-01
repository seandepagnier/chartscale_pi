///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 12 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CHARTSCALEUI_H__
#define __CHARTSCALEUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>
#include <wx/string.h>
#include <wx/dialog.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/choice.h>
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/button.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ChartScaleDialogBase
///////////////////////////////////////////////////////////////////////////////
class ChartScaleDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxFlexGridSizer* m_fgSizer;
	
	public:
		
		ChartScaleDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Chart Scale"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxCLOSE_BOX ); 
		~ChartScaleDialogBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PreferencesDialogBase
///////////////////////////////////////////////////////////////////////////////
class PreferencesDialogBase : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText10;
		wxStaticText* m_staticText3;
		wxButton* m_bAboutAuthor;
		
		// Virtual event handlers, overide them in your derived class
		virtual void Refresh( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnAboutAuthor( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxStaticText* m_staticText18;
		wxSlider* m_sTransparency;
		wxChoice* m_cOrientation;
		wxSpinCtrl* m_sSize;
		wxCheckBox* m_cbShowTitleBar;
		wxStdDialogButtonSizer* m_sdbSizer2;
		wxButton* m_sdbSizer2OK;
		
		PreferencesDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Chart Scale Preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION|wxDEFAULT_DIALOG_STYLE ); 
		~PreferencesDialogBase();
	
};

#endif //__CHARTSCALEUI_H__
