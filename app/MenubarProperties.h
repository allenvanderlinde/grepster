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
const wxString FRAME_MENU_STRINGS[]         = {L"&New grepster job...\tCtrl+Shift+N",
                                               L"&Quit\tCtrl+Q",
                                               L"&Admin Credentials...\tCtrl+Shift+C",
                                               L"&Launch PuTTY\tCtrl+P",
                                               L"&Set path to PuTTY...",
                                               L"&Toggle Floating Controls",
                                               L"&About grepster..."};
/** Status bar strings. These are the labels displayed for each menu item. */
const wxString FRAME_STATUSBAR_STRINGS[]    = {L"Create a new grep job for the currently selected stack.",
                                               L"Quit grepster.",
                                               L"Set the session's administrator default credentials.",
                                               L"Launch PuTTY.",
                                               L"Set the default path to PuTTY and its SSH/SFTP tools.",
                                               L"Allow the server stack and console to be un-docked from grepster.",
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
    FRAME_MENU_STRING_ID_NEW_JOB = 0,
    FRAME_MENU_STRING_ID_QUIT,
    FRAME_MENU_STRING_ID_DEFAULT_CREDENTIALS,
    FRAME_MENU_STRING_ID_LAUNCH_PUTTY,
    FRAME_MENU_STRING_ID_SET_PATH_PUTTY,
    FRAME_MENU_STRING_ID_TOGGLE_DOCKABLE,
    FRAME_MENU_STRING_ID_ABOUT
};

/** Status bar string IDs. */
enum enum_StatusbarStringIDs {
    STATUSBAR_STRING_ID_NEW_JOB = 0,
    STATUSBAR_STRING_ID_QUIT,
    STATUSBAR_STRING_ID_DEFAULT_CREDENTIALS,
    STATUSBAR_STRING_ID_LAUNCH_PUTTY,
    STATUSBAR_STRING_ID_SET_PATH_PUTTY,
    STATUSBAR_STRING_ID_TOGGLE_DOCKABLE,
    STATUSBAR_STRING_ID_ABOUT
};

/* CREATE TOOLS MENU FOR LAUNCHING PUTTY, ETC... */

/** Menu bar function IDs used to decide which function should handle the event. */
enum enum_MenuFunctionIDs {
    MENU_FUNCTION_ID_FILE_NEW_JOB = 9000,
    MENU_FUNCTION_ID_FILE_QUIT,
    MENU_FUNCTION_ID_SESSION_DEFAULT_CREDENTIALS,
    MENU_FUNCTION_ID_TOOLS_LAUNCH_PUTTY,
    MENU_FUNCTION_ID_OPTIONS_SET_PATH_PUTTY,
    MENU_FUNCTION_ID_OPTIONS_TOGGLE_FLOATABLE,
    MENU_FUNCTION_ID_HELP_ABOUT
};

#endif // _MENUBARPROPERTIES_H_
