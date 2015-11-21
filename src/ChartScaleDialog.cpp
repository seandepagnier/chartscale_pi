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

#include "ChartScaleUI.h"
#include "chartscale_pi.h"
#include "ChartScaleDialog.h"

static double scales[] = {.5, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};
                          

ChartScaleDialog::ChartScaleDialog( wxWindow *parent, chartscale_pi &_chartscale_pi, wxPoint position,
                                    int size, int transparency, long style, long orientation, bool lastbutton )
: ChartScaleDialogBase( parent, wxID_ANY, _("Chart Scale"), position, wxDefaultSize, style ),
  m_chartscale_pi(_chartscale_pi)
{
    wxFlexGridSizer *fgSizer = new wxFlexGridSizer( orientation != wxSL_VERTICAL,
                                                    orientation == wxSL_VERTICAL, 0, 0 );
    fgSizer->AddGrowableCol( 0 );
    fgSizer->AddGrowableRow( 0 );
    fgSizer->SetFlexibleDirection( wxBOTH );
    fgSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
    this->SetSizer( fgSizer );
    this->Layout();
    fgSizer->Fit( this );

    m_sScale = new wxSlider(this, wxID_ANY, 5, 0, sizeof scales / sizeof *scales-1, wxDefaultPosition,
                            orientation == wxSL_VERTICAL ? wxSize(20, size) : wxSize(size, 20), orientation );
    fgSizer->Add( m_sScale, 0, wxALL|wxEXPAND, 5);
    if(lastbutton) {
        wxButton *bLast = new wxButton( this, wxID_ANY, orientation == wxSL_VERTICAL ? _("L\na\ns\nt") : _("Last"),
                                        wxDefaultPosition, orientation == wxSL_VERTICAL ? wxSize(28, 80) : wxSize(50, 32));
        fgSizer->Add( bLast, 0, 0, 0);
        bLast->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ChartScaleDialog::OnLast ), NULL, this );
    }
    fgSizer->Fit( this );
    m_sScale->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );

    m_sScale->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( ChartScaleDialog::OnScaleClicked ), NULL, this );

    SetTransparent(255 - transparency*255/100);
    Move(0,0);        // workaround for gtk autocentre dialog behavior
    Move(position);
    Show();
}

void ChartScaleDialog::SetVP( PlugIn_ViewPort &vp )
{
    if(m_vp.view_scale_ppm != vp.view_scale_ppm)
        m_lastppm = m_vp.view_scale_ppm;
    m_vp = vp;

    double scale = 1/vp.view_scale_ppm;
    
    int i;
    for(i=0; i<(int)(sizeof scales / sizeof *scales)-1; i++)
        if(scale < scales[i])
            break;

    if(scales[i] + scales[i-1] > 2*scale)
        i--;

    m_sScale->SetValue(i);
}

void ChartScaleDialog::OnScale( wxScrollEvent& event )
{
    double scale = scales[m_sScale->GetValue()];
    JumpToPosition(m_vp.clat, m_vp.clon, 1/scale);
    GetOCPNCanvasWindow()->Refresh(true);
}

void ChartScaleDialog::OnScaleClicked( wxMouseEvent& event )
{
    wxPoint p = event.GetPosition();
    wxSize s = m_sScale->GetSize();

    int a, b;
    if(m_sScale->HasFlag(wxSL_VERTICAL))
        a = p.y, b = s.y;
    else
        a = p.x, b = s.x;

    m_sScale->SetValue((m_sScale->GetMax() * a + b/2) / b);

    wxScrollEvent sevent;
    OnScale( sevent );
}
void ChartScaleDialog::OnLast( wxCommandEvent& event )
{
    JumpToPosition(m_vp.clat, m_vp.clon, m_lastppm);
}
