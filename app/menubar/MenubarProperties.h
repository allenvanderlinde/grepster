/**
 * @file    MenubarProperties.h
 * @author  Allen Vanderlinde
 * @date    March 7, 2015
 * @brief   Definitions for grepster's menubar, including strings, ids, and enumerations for use by CAppMenubar.
 */
/*
    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _MENUBARPROPERTIES_H_
#define _MENUBARPROPERTIES_H_


/**
 * @brief       Menubar menu strings.
 */
const wxString FRAME_MENUBAR_STRINGS[]      = {L"&grepster",
                                               L"&Session",
                                               L"&Notebook",
                                               L"&Tools",
                                               L"&Options",
                                               L"&Help"};
/**
 * @brief       Menubar menu item strings.
 */
const wxString FRAME_MENU_STRINGS[]         = {L"&Quit\tCtrl+Q",
                                               L"&New grepster Session...\tCtrl+N",
                                               L"&Open grepster Session...\tCtrl+O",
                                               L"&New Server Stack...\tCtrl+Shift+N",
                                               L"&Add Server Stacks...\tCtrl+Shift+O",
                                               L"&Close All Stacks\tCtrl+C",
                                               L"&Admin Credentials...\tCtrl+Shift+C",
                                               L"&Save Page\tCtrl+S",
                                               L"&Launch PuTTY\tCtrl+P",
                                               L"&Set Path to SSH/SFTP Tools...",
                                               L"&Toggle Floating Controls",
                                               L"Open &Welcome Page",
                                               L"&About grepster..."};
/**
 * @brief       Status bar strings. These are the labels displayed for each menu item.
 */
const wxString FRAME_STATUSBAR_STRINGS[]    = {L"Quit grepster.",
                                               L"Create a new session of configured server stacks for grepping and running remote commands.",
                                               L"Open a saved session.",
                                               L"Create and add a new server stack to the current session.",
                                               L"Add one or multiple saved server stacks to the current session.",
                                               L"Close all server stacks in current session.",
                                               L"Set the session's administrator credentials.",
                                               L"Save the current page.",
                                               L"Launch PuTTY.",
                                               L"Set the default path to grepster's SSH/SFTP tools.",
                                               L"Allow grepster's server stacks and console controls to be un-docked.",
                                               L"Open grepster's welcome and updates page.",
                                               L"About grepster."};

/**
 * @brief       Menubar menu IDs.
 */
enum enum_FrameMenuIDs {
    FRAME_ID_FILE_MENU = 0,
    FRAME_ID_SESSION_MENU,
    FRAME_ID_NOTEBOOK_MENU,
    FRAME_ID_TOOLS_MENU,
    FRAME_ID_OPTIONS_MENU,
    FRAME_ID_HELP_MENU
};

/**
 * @brief       Menu string IDs.
 */
enum enum_MenuStringIDs {
    FRAME_MENU_STRING_ID_QUIT = 0,
    FRAME_MENU_STRING_ID_NEW_SESSION,
    FRAME_MENU_STRING_ID_OPEN_SESSION,
    FRAME_MENU_STRING_ID_NEW_SERVER_STACK,
    FRAME_MENU_STRING_ID_ADD_SERVER_STACKS,
    FRAME_MENU_STRING_ID_CLOSE_SERVER_STACKS,
    FRAME_MENU_STRING_ID_DEFAULT_CREDENTIALS,
    FRAME_MENU_STRING_ID_SAVE_PAGE,
    FRAME_MENU_STRING_ID_LAUNCH_PUTTY,
    FRAME_MENU_STRING_ID_SET_PATH_TOOLS,
    FRAME_MENU_STRING_ID_TOGGLE_DOCKABLE,
    FRAME_MENU_STRING_ID_WELCOME_PAGE,
    FRAME_MENU_STRING_ID_ABOUT
};

/**
 * @brief       Status bar string IDs.
 */
enum enum_StatusbarStringIDs {
    STATUSBAR_STRING_ID_QUIT = 0,
    STATUSBAR_STRING_ID_NEW_SESSION,
    STATUSBAR_STRING_ID_OPEN_SESSION,
    STATUSBAR_STRING_ID_NEW_SERVER_STACK,
    STATUSBAR_STRING_ID_ADD_SERVER_STACKS,
    STATUSBAR_STRING_ID_CLOSE_SERVER_STACKS,
    STATUSBAR_STRING_ID_DEFAULT_CREDENTIALS,
    STATUSBAR_STRING_ID_SAVE_PAGE,
    STATUSBAR_STRING_ID_LAUNCH_PUTTY,
    STATUSBAR_STRING_ID_SET_PATH_TOOLS,
    STATUSBAR_STRING_ID_TOGGLE_DOCKABLE,
    STATUSBAR_STRING_ID_WELCOME_PAGE,
    STATUSBAR_STRING_ID_ABOUT
};

/**
 * @brief       Menu bar function IDs used to decide which function should handle the event.
 *              This must start at a high enough number as to
 *              not get confused with what wxWidgets thinks should
 *              be the default action for ENTER. If it's too low,
 *              hitting enter could quit the application.
 */
enum enum_MenuFunctionIDs {
    MENU_FUNCTION_ID_FILE_QUIT = 9000,
    MENU_FUNCTION_ID_SESSION_NEW,
    MENU_FUNCTION_ID_SESSION_OPEN,
    MENU_FUNCTION_ID_SESSION_NEW_SERVER_STACK,
    MENU_FUNCTION_ID_SESSION_ADD_SERVER_STACKS,
    MENU_FUNCTION_ID_SESSION_CLOSE_SERVER_STACKS,
    MENU_FUNCTION_ID_SESSION_DEFAULT_CREDENTIALS,
    MENU_FUNCTION_ID_NOTEBOOK_SAVE_PAGE,
    MENU_FUNCTION_ID_TOOLS_LAUNCH_PUTTY,
    MENU_FUNCTION_ID_OPTIONS_SET_PATH_TOOLS,
    MENU_FUNCTION_ID_OPTIONS_TOGGLE_FLOATABLE,
    MENU_FUNCTION_ID_HELP_WELCOME_PAGE,
    MENU_FUNCTION_ID_HELP_ABOUT
};

#endif // _MENUBARPROPERTIES_H_
