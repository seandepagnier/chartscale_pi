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

static double scales[] = {1, 2, 5, 10, 20, 50, 100, 200, 500,
                          1e3, 2e3, 5e3, 1e4, 2e4};
                          

ChartScaleDialog::ChartScaleDialog( wxWindow *parent, chartscale_pi &_chartscale_pi, wxPoint position,
                                    int size, int transparency, long style, long orientation )
: ChartScaleDialogBase( parent, wxID_ANY, _("Chart Scale"), position, wxDefaultSize, style ),
  m_chartscale_pi(_chartscale_pi)
{
    m_sScale = new wxSlider(this, wxID_ANY, 5, 0, sizeof scales / sizeof *scales-1, wxDefaultPosition,
                                    orientation == wxSL_VERTICAL ? wxSize(20, size) : wxSize(size, 20),
                                    orientation );
    m_fgSizer->Add( m_sScale, 0, wxALL|wxEXPAND, 5);
    m_fgSizer->Fit( this );

    m_sScale->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    m_sScale->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( ChartScaleDialog::OnScale ), NULL, this );
    
    SetTransparent(255 - transparency*255/100);
    Move(0,0);        // workaround for gtk autocentre dialog behavior
    Move(position);
    Show();
}

void ChartScaleDialog::SetVP( PlugIn_ViewPort &vp )
{
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
    double scale = scales[event.GetPosition()];
    JumpToPosition(m_vp.clat, m_vp.clon, 1/scale);
    GetOCPNCanvasWindow()->Refresh(true);
}
