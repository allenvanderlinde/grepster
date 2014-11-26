/*
    File:       CAppEntry.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets application execution class methods.

    Created:    11/2/14

    Copyright (C) 2014 by Allen Vanderlinde.
    Songbird and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../grepster.h"
#include "../resources/grepster_rc.h"

#include "CAppEntry.h"

#include <wx/splash.h>
#include <wx/icon.h>

/*
    CAppEntry::OnInit
*/
bool CAppEntry::OnInit() {
    /* Initial set-up. */
    wxLog::SetLogLevel(0);  // Suppress wxWidgets from reporting color profile errors for certain image media
    wxImage::AddHandler(new wxPNGHandler);  // Enable wxWidget's bitmap-as-PNG capability
    g_Frame_Title += AutoVersion::FULLVERSION_STRING;

    /* Run splash screen. */
    if(DISPLAY_SPLASH) {
        if(!ShowSplash(RESID_PNG_SPLASH)) {
            // place-holder for missing .png resource exception
        }
        clock_t start = clock();
        while((clock() - start) < SPLASH_DURATION) {}   // Use predefined timeout for splash screen
    }

    /* Load grepster's configuration. */
    LoadConfiguration();

    m_grepster_frame = new CAppFrame(g_Frame_Title, wxPoint(50, 50), wxSize(FRAME_WIDTH, FRAME_HEIGHT));
    /* Set grepster's window icon. */
    m_grepster_frame->SetIcon(wxICON(aaaaappicon));
    SetTopWindow(m_grepster_frame);
    m_grepster_frame->Show(true);

    return true;
}

/*
    CAppEntry::ShowSplash(int)
*/
bool CAppEntry::ShowSplash(int resource_id) {
    wxBitmap png;
    wxSplashScreen* splash_screen = NULL;

    if(png.LoadFile(RESOURCE_ID_TO_STRING(resource_id), wxBITMAP_TYPE_PNG_RESOURCE)) {
        if((splash_screen = new wxSplashScreen(png,
                                               wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_TIMEOUT,
                                               SPLASH_DURATION,     // Display splash for a number of milliseconds
                                               NULL,
                                               -1,
                                               wxDefaultPosition,
                                               wxDefaultSize,       // Splash will automatically fit to size of bitmap being used
                                               wxBORDER_NONE)) == NULL) {
            return false;
        }
        return true;
    }
    else return false;
}

/*
    CAppEntry::LoadConfiguration
*/
void CAppEntry::LoadConfiguration() {
    configuration.bUseFloatable = false;
}
