##---------------------------------------------------------------------------
## Author:      Sean D'Epagnier
## ***************************************************************************
## *   Copyright (C) 2013 by Sean D'Epagnier                                 *
## *   This program is free software; you can redistribute it and/or modify  *
## *   it under the terms of the GNU General Public License as published by  *
## *   the Free Software Foundation; either version 3 of the License, or     *
## *   (at your option) any later version.                                   *
## *                                                                         *
## *   This program is distributed in the hope that it will be useful,       *
## *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
## *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
## *   GNU General Public License for more details.                          *
## *                                                                         *
## *   You should have received a copy of the GNU General Public License     *
## *   along with this program; if not, write to the                         *
## *   Free Software Foundation, Inc.,                                       *
## *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
## ***************************************************************************


# define minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2)

PROJECT(chartscale_pi)
SET(PACKAGE_NAME chartscale_pi)
SET(VERBOSE_NAME Chartscale)
SET(TITLE_NAME Chartscale)
SET(CPACK_PACKAGE_CONTACT "Sean D'Epagnier ")
#SET(CMAKE_BUILD_TYPE Debug)
INCLUDE( VERSION.cmake )
#SET(PLUGIN_VERSION_MAJOR "0")
#SET(PLUGIN_VERSION_MINOR "2")
#SET(PLUGIN_VERSION_PATCH "0")
#SET(PLUGIN_VERSION_DATE "2015-11-21")
#SET(OCPN_MIN_VERSION "ov50")

SET(PLUGIN_VERSION "${PLUGIN_VERSION_MAJOR}.${PLUGIN_VERSION_MINOR}.${PLUGIN_VERSION_PATCH}" )

SET(VERSION_MAJOR ${PLUGIN_VERSION_MAJOR})
SET(VERSION_MINOR "${PLUGIN_VERSION_MINOR}")
SET(VERSION_PATCH "${PLUGIN_VERSION_PATCH}")
SET(VERSION_DATE ${PLUGIN_VERSION_DATE})

INCLUDE("cmake/PluginConfigure.cmake")

SET(SRC_CHARTSCALE
    src/chartscale_pi.cpp
    src/ChartScaleDialog.cpp
    src/PreferencesDialog.cpp
    src/ChartScaleUI.cpp
    src/icons.cpp
)


ADD_LIBRARY(${PACKAGE_NAME} SHARED ${SRC_CHARTSCALE} )

INCLUDE("cmake/PluginInstall.cmake")
INCLUDE("cmake/PluginLocalization.cmake")
INCLUDE("cmake/PluginPackage.cmake")
