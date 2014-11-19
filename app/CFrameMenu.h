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
const wxString FRAME_MENUBAR_STRINGS[]      = ("&File");
const wxString FRAME_MENU_STRINGS[]         = ("&Quit\tCtrl+Q");
const wxString FRAME_STATUSBAR_STRINGS[]    = ("Quit grepster.");

/* GUI frame menu string IDs. */
enum {
    FRAME_ID_FILE_MENU = 0
};

/* GUI frame menu item string IDs. */
enum {
    FRAME_MENU_STRING_ID_QUIT = 0
};

/* Status bar string IDs. */
enum {
    STATUSBAR_STRING_ID_QUIT = 0
};

/* Menu bar item IDs */
enum {
    MENU_FUNCTION_ID_FILE_QUIT = 0
};

/*  CFrameMenu

    Desc: wxWidgets menu bar class definition. */
class CFrameMenu : public wxMenuBar {
public:
    CFrameMenu();

private:
    wxMenu* m_file_menu;
};

#endif
