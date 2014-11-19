/*
    Project: grepster
    File: CAppEntry.cpp

    Desc: wxWidgets application execution functions.

    Date: 11/2/14
    Author: Allen Vanderlinde
*/

#include "CAppEntry.h"
#include "CAppFrame.h"

#include "../version.h"

/* Frame globals. */
wxString       g_Frame_Title("grepster v");

/*  CAppEntry::OnInit

    Desc: Initializes the wxWidgets application back-end. */
bool CAppEntry::OnInit() {
    g_Frame_Title += AutoVersion::FULLVERSION_STRING;

    m_grepster_frame = new CAppFrame(g_Frame_Title, wxPoint(50, 50), wxSize(FRAME_WIDTH, FRAME_HEIGHT));
    m_grepster_frame->Show(true);

    return true;
}
