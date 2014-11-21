/*
    Project: grepster
    File: grepster.h

    Desc: grepster's global definitions, main classes, and variables.

    Date: 11/2/14
    Author: Allen Vanderlinde
*/

#ifndef _GREPSTER_H_
#define _GREPSTER_H_

#include <wx/wx.h>

#include "app/CConsole.h"
#include "app/CClientList.h"

#include "version.h"

/* Frame globals. */
extern wxString         g_Frame_Title;

extern CConsole*        Console;
extern CClientList*     ClientList;

/* Utility functions. */
wxString RESOURCE_ID_TO_STRING(int id);

/* Frame definitions. */
#define USE_FLOATABLE                false

/* Console control settings. */
#define CONSOLE_ID                  1000
#define CONSOLE_NAME                "the_con"
#define CONSOLE_CTRL_TITLE          "Console"
#define CONSOLE_DEFAULT_HEIGHT      140

/* Client list control settings. */
#define CLIENT_LIST_ID              1001
#define CLIENT_LIST_NAME            "client_tree"
#define CLIENT_LIST_CTRL_TITLE      "Client List"
#define CLIENT_LIST_DEFAULT_WIDTH   200

#endif
