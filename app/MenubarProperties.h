/**
 * @file    MenubarProperties.h
 * @author  Allen Vanderlinde
 * @date    March 7, 2015
 * @brief   Definitions for grepster's menu bar, including strings, ids, and enumerations for use by CAppMenubar.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _MENUBARPROPERTIES_H_
#define _MENUBARPROPERTIES_H_


/* Strings array. */
/** Menu bar menu strings. */
const wxString FRAME_MENUBAR_STRINGS[]      = {L"&File",
                                               L"&Session",
                                               L"&Tools",
                                               L"&Options",
                                               L"&Help"};
/** Menu bar menu item strings. */
const wxString FRAME_MENU_STRINGS[]         = {L"&Quit\tCtrl+Q",
                                               L"&New grepster session...\tCtrl+N",
                                               L"&New server stack...\tCtrl+Shift+N",
                                               L"&Open grepster session...\tCtrl+O",
                                               L"&Add server stack...\tCtrl+Shift+O",
                                               L"&Admin credentials...\tCtrl+Shift+C",
                                               L"&Launch PuTTY\tCtrl+P",
                                               L"&Set path to SSH/SFTP tools...",
                                               L"&Toggle floating controls",
                                               L"&About grepster..."};
/** Status bar strings. These are the labels displayed for each menu item. */
const wxString FRAME_STATUSBAR_STRINGS[]    = {L"Quit grepster.",
                                               L"Create a new session of configured server stacks for grepping and running remote commands.",
                                               L"Create and add a new server stack to the current session.",
                                               L"Open a saved session.",
                                               L"Add a saved server stack to the current session.",
                                               L"Set the session's administrator credentials.",
                                               L"Launch PuTTY.",
                                               L"Set the default path to grepster's SSH/SFTP tools.",
                                               L"Allow grepster's server stacks and console controls to be un-docked.",
                                               L"About grepster."};

/** Menubar menu IDs. */
enum enum_FrameMenuIDs {
    FRAME_ID_FILE_MENU = 0,
    FRAME_ID_SESSION_MENU,
    FRAME_ID_TOOLS_MENU,
    FRAME_ID_OPTIONS_MENU,
    FRAME_ID_HELP_MENU
};

/** Menu string IDs. */
enum enum_MenuStringIDs {
    FRAME_MENU_STRING_ID_QUIT = 0,
    FRAME_MENU_STRING_ID_NEW_SESSION,
    FRAME_MENU_STRING_ID_NEW_SERVER_STACK,
    FRAME_MENU_STRING_ID_OPEN_SESSION,
    FRAME_MENU_STRING_ID_ADD_SERVER_STACK,
    FRAME_MENU_STRING_ID_DEFAULT_CREDENTIALS,
    FRAME_MENU_STRING_ID_LAUNCH_PUTTY,
    FRAME_MENU_STRING_ID_SET_PATH_TOOLS,
    FRAME_MENU_STRING_ID_TOGGLE_DOCKABLE,
    FRAME_MENU_STRING_ID_ABOUT
};

/** Status bar string IDs. */
enum enum_StatusbarStringIDs {
    STATUSBAR_STRING_ID_QUIT = 0,
    STATUSBAR_STRING_ID_NEW_SESSION,
    STATUSBAR_STRING_ID_NEW_SERVER_STACK,
    STATUSBAR_STRING_ID_OPEN_SESSION,
    STATUSBAR_STRING_ID_ADD_SERVER_STACK,
    STATUSBAR_STRING_ID_DEFAULT_CREDENTIALS,
    STATUSBAR_STRING_ID_LAUNCH_PUTTY,
    STATUSBAR_STRING_ID_SET_PATH_TOOLS,
    STATUSBAR_STRING_ID_TOGGLE_DOCKABLE,
    STATUSBAR_STRING_ID_ABOUT
};

/** Menu bar function IDs used to decide which function should handle the event. */
enum enum_MenuFunctionIDs {
    /** @brief      This must start at a high enough number as to
     *              not get confused with what wxWidgets thinks should
     *              be the default action for enter. If it's too low,
     *              hitting enter could quit the application. */
    MENU_FUNCTION_ID_FILE_QUIT = 9000,
    MENU_FUNCTION_ID_SESSION_NEW,
    MENU_FUNCTION_ID_SESSION_NEW_SERVER_STACK,
    MENU_FUNCTION_ID_SESSION_OPEN,
    MENU_FUNCTION_ID_SESSION_ADD_SERVER_STACK,
    MENU_FUNCTION_ID_SESSION_DEFAULT_CREDENTIALS,
    MENU_FUNCTION_ID_TOOLS_LAUNCH_PUTTY,
    MENU_FUNCTION_ID_OPTIONS_SET_PATH_TOOLS,
    MENU_FUNCTION_ID_OPTIONS_TOGGLE_FLOATABLE,
    MENU_FUNCTION_ID_HELP_ABOUT
};

#endif // _MENUBARPROPERTIES_H_
