/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  Chart Scale Plugin
 * Author:   Sean D'Epagnier
 *
 ***************************************************************************
 *   Copyright (C) 2015 by Sean D'Epagnier
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */

#include <wx/wx.h>
#include <wx/graphics.h>

#include "ChartScaleUI.h"
#include "chartscale_pi.h"
#include "ChartScaleDialog.h"
#include "PreferencesDialog.h"
#include "icons.h"

# if !defined(NAN)
# define NAN std::numeric_limits<double>::quiet_NaN ()
# endif

// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new chartscale_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}


//-----------------------------------------------------------------------------
//
//    Chartscale PlugIn Implementation
//
//-----------------------------------------------------------------------------

chartscale_pi::chartscale_pi(void *ppimgr)
    :opencpn_plugin_19(ppimgr)
{
    // Create the PlugIn icons
    initialize_images();
}

int chartscale_pi::Init(void)
{
    AddLocaleCatalog( _T("opencpn-chartscale_pi") );

    LoadConfig();

    m_pChartScaleDialog = new ChartScaleDialog(GetOCPNCanvasWindow(), *this, m_position, m_size,
                                               m_transparency, m_style, m_orientation, m_lastbutton);

    return (WANTS_CONFIG              |
            WANTS_ONPAINT_VIEWPORT    |
            WANTS_PREFERENCES
            );
}

bool chartscale_pi::DeInit(void)
{
    SaveConfig();

    delete m_pChartScaleDialog;

    return true;
}

int chartscale_pi::GetAPIVersionMajor()
{
    return MY_API_VERSION_MAJOR;
}

int chartscale_pi::GetAPIVersionMinor()
{
    return MY_API_VERSION_MINOR;
}

int chartscale_pi::GetPlugInVersionMajor()
{
    return PLUGIN_VERSION_MAJOR;
}

int chartscale_pi::GetPlugInVersionMinor()
{
    return PLUGIN_VERSION_MINOR;
}

wxBitmap *chartscale_pi::GetPlugInBitmap()
{
    return _img_chartscale;
}

wxString chartscale_pi::GetCommonName()
{
    return _("ChartScale");
}

wxString chartscale_pi::GetShortDescription()
{
    return _("ChartScale plugin provides a slider to adjust chart scale\n");
}

wxString chartscale_pi::GetLongDescription()
{
    return _("ChartScale plugin provides a slider to adjust chart scale\n");
}

void chartscale_pi::SetCurrentViewPort(PlugIn_ViewPort &vp)
{
    m_pChartScaleDialog->SetVP(vp);
}

void chartscale_pi::ShowPreferencesDialog( wxWindow* parent )
{
    PreferencesDialog dlg(GetOCPNCanvasWindow());

    dlg.m_sTransparency->SetValue(m_transparency);
    dlg.m_sSize->SetValue(m_size);
    dlg.m_cbShowTitleBar->SetValue(m_style);
    dlg.m_cOrientation->SetSelection(m_orientation == wxSL_HORIZONTAL);
    dlg.m_cbLastButton->SetValue(m_lastbutton);

    dlg.ShowModal();

    m_transparency = dlg.m_sTransparency->GetValue();
    m_size = dlg.m_sSize->GetValue();
    m_style = dlg.m_cbShowTitleBar->GetValue() ? wxCAPTION : 0;
    m_orientation = dlg.m_cOrientation->GetSelection() ? wxSL_HORIZONTAL : wxSL_VERTICAL;
    m_lastbutton = dlg.m_cbLastButton->GetValue();
    wxPoint p = m_pChartScaleDialog->GetPosition();
    
    delete m_pChartScaleDialog;
    m_pChartScaleDialog = new ChartScaleDialog(GetOCPNCanvasWindow(), *this, p, m_size,
                                               m_transparency, m_style, m_orientation, m_lastbutton);
}

void chartscale_pi::SetColorScheme(PI_ColorScheme cs)
{
}

bool chartscale_pi::LoadConfig(void)
{
    wxFileConfig *pConf = GetOCPNConfigObject();

    if(!pConf)
        return false;

    pConf->SetPath( _T("/PlugIns/ChartScale") );
    
    pConf->Read( _T("Transparency"), &m_transparency, 20 );
    pConf->Read( _T("Size"), &m_size, 180 );
    pConf->Read( _T("Style"), &m_style, wxCAPTION );
    if(m_style && m_style != (wxCAPTION))
        m_style = wxCAPTION;
    
    pConf->Read( _T("Orientation"), &m_orientation, wxSL_VERTICAL );
    if(m_orientation != wxSL_VERTICAL && m_orientation != wxSL_HORIZONTAL)
        m_orientation = wxSL_VERTICAL;

    pConf->Read( _T("LastButton"), &m_lastbutton, 0);

    int XPosition, YPosition;
    pConf->Read( _T("XPosition"), &XPosition, 100 );
    pConf->Read( _T("YPosition"), &YPosition, 100 );
    m_position = wxPoint(XPosition, YPosition);

    return true;
}

bool chartscale_pi::SaveConfig(void)
{
    wxFileConfig *pConf = GetOCPNConfigObject();

    if(!pConf)
        return false;

    pConf->SetPath( _T("/PlugIns/ChartScale") );
    
    pConf->Write( _T("Transparency"), m_transparency);
    pConf->Write( _T("Size"), m_size);
    pConf->Write( _T("Style"), m_style);
    pConf->Write( _T("Orientation"), m_orientation);
    pConf->Write( _T("LastButton"), m_lastbutton);
    
    pConf->Write( _T("XPosition"), m_pChartScaleDialog->GetPosition().x );
    pConf->Write( _T("YPosition"), m_pChartScaleDialog->GetPosition().y );
    
    return true;
}
