/**
 * @file    grepster.h
 * @author  Allen Vanderlinde
 * @date    November 2, 2014
 * @brief   grepster's global definitions, objects, and methods.
 */
/*
    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _GREPSTER_H_
#define _GREPSTER_H_

#include "app/CAppFrame.h"
#include "app/init/CAppInit.h"
#include "app/controls/console/CConsole.h"
#include "app/controls/server-stacks/CServerStacks.h"
#include "app/controls/session-notebook/CSessionNotebook.h"

#include "version.h"


/** grepster's primary frame object. */
extern CAppFrame*       GrepsterFrame;

/** grepster's frame title. */
extern wxString         g_szFrameTitle;

/**
 * This control reports grepster's activity and remote commands to the user.
 * @brief       grepster's console.
 */
extern CConsole*        Console;
/**
 * This control is the graphical list of servers configured for grepping.
 * @brief       grepster's Server Stack.
 */
extern CServerStacks*     ServerStacks;
/**
 * This control holds the user's notebook of remote commands and grep scripts.
 * @brief       grepster's Session Notebook.
 */
extern CSessionNotebook*   SessionNotebook;

/**
 * This object contains each of grepster's configuration settings which are saved automatically to file upon change.
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
 * @retval      std::string Returns the process's stdout buffer as a string.
 *
 * grepster can launch external applications and send them arguments as if it were a terminal.
 *
 * For example:
 * @code
 * C:\Users\Admin>psftp admin@127.0.0.1 -pw passwd
 * @endcode
 * can be launched with grepster code as:
 * @code
 * *Console << SpawnAndRun("C:\\Program Files (x86)\\PuTTY\\", "psftp.exe admin@127.0.0.1 -pw passwd");
 * @endcode
 * grepster uses user-configured tools and an argument format for sending those tools remote commands for grepping and downloading operations.
 */
std::string SpawnAndRun(wxString path,
                        wxString args);

/**
 * @brief       Casts a variable's identifier as a wxString for debugging/console reporting.
 */
#define _cast(v) wxString(#v)

/** grepster's configuration label in Windows registry. */
#define CONFIG_REG_LABEL                    "grepster"

/** grepster's buffer length for sending remote commands. Measured in bytes. */
#define CHAR_BUFFER_LENGTH                  4096

/* Console control settings. */
/** grepster's console control ID. */
#define CONSOLE_ID                          10000
/** grepster's console's local name for wxWidgets. */
#define CONSOLE_NAME                        "the_con"
/** grepster's console's control title. */
#define CONSOLE_CTRL_TITLE                  L"Console"
/** Default height (pixels) of grepster's console control used when floating. */
#define CONSOLE_DEFAULT_HEIGHT              200

/* Server Stacks tree control settings. */
/** grepster's server stack's control ID. */
#define SERVER_STACKS_ID                    11000
/** grepster's server stack's local name for wxWidgets. */
#define SERVER_STACKS_NAME                  "server_stacks"
/** grepster's server stack's control title. */
#define SERVER_STACKS_CTRL_TITLE            L"Server Stacks"
/** Default width (pixels) of grepster's tree list control used when floating. */
#define SERVER_STACKS_DEFAULT_WIDTH         240

/* Session Notebook control settings. */
/** grepster's AUI notebook control ID. */
#define SESSION_NOTEBOOK_ID                 12000
/** grepster's notebook's local name for wxWidgets. */
#define SESSION_NOTEBOOK_NAME               "grep_notebook"
/** grepster's notebook control title. */
#define SESSION_NOTEBOOK_CTRL_TITLE         L"Notebook"

/* Browser/web viewer control settings. */
/** grepster's browser control ID. */
#define BROWSER_ID                          13000
/** grepster's browser's local name for wxWidgets. */
#define BROWSER_NAME                        "browser"

#endif
