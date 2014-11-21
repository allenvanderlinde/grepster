/*
    Project: grepster
    File: CFrameMenubar.h

    Desc: wxWidgets main frame menu bar class and object definitions.

    Date: 11/5/14
    Author: Allen Vanderlinde
*/

#ifndef _CFRAMEMENUBAR_H_
#define _CFRAMEMENUBAR_H_

#include <wx/wx.h>

/* Strings array. */
const wxString FRAME_MENUBAR_STRINGS[]      = {"&File",
                                               "&Tools",
                                               "&Options",
                                               "&Help"};

const wxString FRAME_MENU_STRINGS[]         = {"&Quit\tCtrl+Q",
                                               "&Launch PuTTY\tCtrl+P",
                                               "Toggle Floating Controls",
                                               "About grepster..."};

const wxString FRAME_STATUSBAR_STRINGS[]    = {"Quit grepster.",
                                               "Launch PuTTY.",
                                               "Allow the client list, console, and notebook to be un-docked from grepster.",
                                               "About grepster."};

/* GUI frame menu string IDs. */
enum e_FrameMenuStringIDs {
    FRAME_ID_FILE_MENU = 0,
    FRAME_ID_TOOLS_MENU,
    FRAME_ID_OPTIONS_MENU,
    FRAME_ID_HELP_MENU
};

/* GUI frame menu item string IDs. */
enum e_MenuItemStringIDs {
    FRAME_MENU_STRING_ID_QUIT = 0,
    FRAME_MENU_STRING_ID_LAUNCH_PUTTY,
    FRAME_MENU_STRING_ID_TOGGLE_DOCKABLE,
    FRAME_MENU_STRING_ID_ABOUT
};

/* Status bar string IDs. */
enum e_StatusbarStringIDs {
    STATUSBAR_STRING_ID_QUIT = 0,
    STATUSBAR_STRING_ID_LAUNCH_PUTTY,
    STATUSBAR_STRING_ID_TOGGLE_DOCKABLE,
    STATUSBAR_STRING_ID_ABOUT
};

/* CREATE TOOLS MENU FOR LAUNCHING PUTTY, ETC... */

/* Menu bar item IDs */
enum e_MenuFunctionIDs {
    MENU_FUNCTION_ID_FILE_QUIT = 9000,
    MENU_FUNCTION_ID_TOOLS_LAUNCH_PUTTY,
    MENU_FUNCTION_ID_OPTIONS_TOGGLE_DOCKABLE,
    MENU_FUNCTION_ID_HELP_ABOUT
};

/*  CFrameMenu

    Desc: wxWidgets menu bar class definition. */
class CFrameMenubar : public wxMenuBar {
public:
    CFrameMenubar();

private:
    // Menu bar menus
    wxMenu* m_file_menu;
    wxMenu* m_tools_menu;
    wxMenu* m_options_menu;
    wxMenu* m_help_menu;
};

#endif
