/*
    Project: grepster
    File: grepster.cpp

    Desc: Source file for grepster's execution.

    Date: 11/2/14
    Author: Allen Vanderlinde
*/

/* NOTES */
// MAKE CONFIG FILE WITH PATH TO PUTTY DIRECTORY!!

#include <wx/wx.h>
#include "grepster.h"

/* Frame globals definitions. */
wxString            g_Frame_Title("grepster v");
/* Frame control definitions. */
CConsole*           Console;
CClientList*        ClientList;
CGrepNotebook*      GrepNotebook;

/* grepster configuration global structure. */
grepsterConfig_t    configuration;

/* Utility function definitions. */
wxString RESOURCE_ID_TO_STRING(int id) { return wxString::Format("#%i", id); }

#include "app/CAppEntry.h"
wxIMPLEMENT_APP(CAppEntry);
