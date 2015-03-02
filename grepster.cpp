/*
    File:       grepster.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       Source file for grepster's execution.

    Created:    11/2/14

    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include <wx/wx.h>

#include "grepster.h"


/* Frame globals definitions. */
wxString            g_szFrameTitle("grepster alpha v");
/* Frame control definitions. These are global. */
CConsole*           Console;
CServerStacks*      ServerStacks;
CGrepNotebook*      GrepNotebook;

/* grepster configuration object. This is global. */
CAppInit*           Configuration;

/* Utility function definitions. */
wxString RESOURCE_ID_TO_STRING(int id) { return wxString::Format("#%i", id); }

#include "app/CAppEntry.h"
wxIMPLEMENT_APP(CAppEntry);
