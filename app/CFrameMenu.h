/*
    Project: grepster
    File: CFrameMenu.h

    Desc: wxWidgets main frame menu bar class and object definitions.

    Date: 11/5/14
    Author: Allen Vanderlinde
*/

#ifndef _CFRAMEMENU_H_
#define _CFRAMEMENU_H_

#include <wx/wx.h>

/* Strings array. */
const wxString FRAME_MENUBAR_STRINGS[]      = {"&File",
                                               "&Help"};
const wxString FRAME_MENU_STRINGS[]         = {"&Quit\tCtrl+Q",
                                               "About grepster..."};
const wxString FRAME_STATUSBAR_STRINGS[]    = {"Quit grepster.",
                                               "About grepster."};

/* GUI frame menu string IDs. */
enum {
    FRAME_ID_FILE_MENU = 0,
    FRAME_ID_HELP_MENU
};

/* GUI frame menu item string IDs. */
enum {
    FRAME_MENU_STRING_ID_QUIT = 0,
    FRAME_MENU_STRING_ID_ABOUT
};

/* Status bar string IDs. */
enum {
    STATUSBAR_STRING_ID_QUIT = 0,
    STATUSBAR_STRING_ID_ABOUT
};

/* CREATE TOOLS MENU FOR LAUNCHING PUTTY, ETC... */

/* Menu bar item IDs */
enum {
    MENU_FUNCTION_ID_FILE_QUIT = 0,
    MENU_FUNCTION_ID_HELP_ABOUT
};

/*  CFrameMenu

    Desc: wxWidgets menu bar class definition. */
class CFrameMenu : public wxMenuBar {
public:
    CFrameMenu();

private:
    // Menu bar menus
    wxMenu* m_file_menu;
    wxMenu* m_help_menu;
};

#endif
