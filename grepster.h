/**
 * @file    grepster.h
 * @author  Allen Vanderlinde
 * @date    November 2, 2014
 * @brief   grepster's global definitions, main classes, and variables.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _GREPSTER_H_
#define _GREPSTER_H_

#include <wx/wx.h>

#include "app/CConsole.h"
#include "app/CServerStacks.h"
#include "app/CGrepNotebook.h"
#include "app/CAppInit.h"

#include "version.h"


/** grepster's frame globals. */
extern wxString         g_szFrameTitle;

/**
 * This object reports grepster's activity to a central text control for the user.
 * @brief       grepster's console.
 */
extern CConsole*        Console;
/**
 * This object holds the list of servers configured for grepping.
 * @brief       grepster's Server Stack.
 */
extern CServerStacks*     ServerStacks;
/**
 * This object holds the user's book of grep session pages.
 * @brief       grepster's grep Session Notebook.
 */
extern CGrepNotebook*   GrepNotebook;

/**
 * This structure contains each of grepster's configuration settings which are saved automatically file upon change.
 *
 * @brief       grepster's configuration object.
 */
extern CAppInit*        Configuration;

/* Utility functions. */
/**
 * @brief       Translate a resource integer ID into a wxWidgets readable string for calling resources.
 * @param[in]   id The resource's integer ID as found in grepster_rc.h.
 */
wxString RESOURCE_ID_TO_STRING(int id);

/**
 * @brief       Creates a child process and sends it an argument list for remote commands. SpawnAndRun also records the child's stdout to grepster's console.
 * @param[in]   path Local directory path to external application.
 * @param[in]   args Argument list passed to child process.
 * @retval      bool Returns true if successfully created child process.
 *
 * grepster can launch external applications and send them arguments as if it were a terminal.
 *
 * For example:
 * @code
 * C:\Users\Admin>psftp admin@127.0.0.1 -pw passwd
 * @endcode
 * can be launched with grepster code as:
 * @code
 * SpawnAndRun("C:\Program Files (x86)\PuTTY\", "psftp.exe admin@127.0.0.1 -pw passwd");
 * @endcode
 */
bool SpawnAndRun(wxString path, wxString args);

/**
 * @brief       Casts a variable's identifier as a wxString for debugging/console reporting.
 */
#define _cast(v) wxString(#v)

/** grepster's configuration file path. */
#define CONFIGURATION_FILE_PATH     "grepster.xml"

/** grepster's buffer length for sending remote commands. Measured in bytes. */
#define CHAR_BUFFER_LENGTH          4096

/* Console control settings. */
/** grepster's console control ID. */
#define CONSOLE_ID                  1000
/** grepster's console's local name for wxWidgets. */
#define CONSOLE_NAME                "the_con"
/** grepster's console's control title. */
#define CONSOLE_CTRL_TITLE          "Console"
/** Default height (pixels) of grepster's console control used when floating. */
#define CONSOLE_DEFAULT_HEIGHT      140

/* Server Stacks tree control settings. */
/** grepster's server stack's control ID. */
#define SERVER_STACKS_ID              1001
/** grepster's server stack's local name for wxWidgets. */
#define SERVER_STACKS_NAME            "server_stacks"
/** grepster's server stack's control title. */
#define SERVER_STACKS_CTRL_TITLE      "Server Stacks"
/** Default width (pixels) of grepster's tree list control used when floating. */
#define SERVER_STACKS_DEFAULT_WIDTH   200

/* Grep Notebook control settings. */
/** grepster's AUI notebook control ID. */
#define GREP_NOTEBOOK_ID            1002
/** grepster's notebook's local name for wxWidgets. */
#define GREP_NOTEBOOK_NAME          "grep_notebook"
/** grepster's notebook control title. */
#define GREP_NOTEBOOK_CTRL_TITLE    "Grep Notebook"

/* Browser/web viewer control settings. */
/** grepster's browser control ID. */
#define BROWSER_ID             1003
/** grepster's browser's local name for wxWidgets. */
#define BROWSER_NAME           "browser"

#endif
