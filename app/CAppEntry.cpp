/*
    Project: grepster
    File: CAppEntry.cpp

    Desc: wxWidgets application execution functions.

    Date: 11/2/14
    Author: Allen Vanderlinde
*/

#include "../grepster.h"
#include "../resources/grepster_rc.h"

#include "CAppEntry.h"
#include "CAppFrame.h"

#include <wx/splash.h>

/*  CAppEntry::OnInit

    Desc: Initializes the wxWidgets application back-end. */
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

    m_grepster_frame = new CAppFrame(g_Frame_Title, wxPoint(50, 50), wxSize(FRAME_WIDTH, FRAME_HEIGHT));
    m_grepster_frame->Show(true);

    return true;
}

/*  CAppEntry::ShowSplash

    Desc: Initializes the wxWidgets application back-end. */
bool CAppEntry::ShowSplash(int resource_id) {
    wxBitmap png;
    wxSplashScreen* splash_screen = NULL;

    if(png.LoadFile(RESOURCE_ID_TO_STRING(resource_id), wxBITMAP_TYPE_PNG_RESOURCE)) {
        if((splash_screen = new wxSplashScreen(png,
                                               wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_TIMEOUT,
                                               SPLASH_DURATION,    // Display splash for a number of milliseconds
                                               NULL,
                                               -1,
                                               wxDefaultPosition,
                                               wxDefaultSize,        // Splash will automatically fit to size of bitmap being used
                                               wxBORDER_NONE)) == NULL) {
            return false;
        }
        return true;
    }
    else return false;
}
