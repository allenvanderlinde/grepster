/*
    File:       grepster.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       Source file for grepster's execution.

    Created:    11/2/14

    Copyright (C) 2014 by Allen Vanderlinde.
    Songbird and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
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
