/*
    Project: grepster
    File: CFrameMenu.cpp

    Desc: wxWidgets main frame menu bar.

    Date: 11/5/14
    Author: Allen Vanderlinde
*/

#include "CFrameMenubar.h"

/*  CAppFrame::CAppFrame

    Desc: Constructor for frame class. */
CFrameMenubar::CFrameMenubar()
    : wxMenuBar() {
    // File menu
    m_file_menu = new wxMenu;
    m_file_menu->Append(MENU_FUNCTION_ID_FILE_QUIT,
                        FRAME_MENU_STRINGS[FRAME_MENU_STRING_ID_QUIT],
                        FRAME_STATUSBAR_STRINGS[STATUSBAR_STRING_ID_QUIT]);
    // Tools menu
    m_tools_menu = new wxMenu;
    m_tools_menu->Append(MENU_FUNCTION_ID_TOOLS_LAUNCH_PUTTY,
                         FRAME_MENU_STRINGS[FRAME_MENU_STRING_ID_LAUNCH_PUTTY],
                         FRAME_STATUSBAR_STRINGS[STATUSBAR_STRING_ID_LAUNCH_PUTTY]);
    // Options menu
    m_options_menu = new wxMenu;
    m_options_menu->Append(MENU_FUNCTION_ID_OPTIONS_TOGGLE_DOCKABLE,
                           FRAME_MENU_STRINGS[FRAME_MENU_STRING_ID_TOGGLE_DOCKABLE],
                           FRAME_STATUSBAR_STRINGS[STATUSBAR_STRING_ID_TOGGLE_DOCKABLE],
                           wxITEM_CHECK);
    // Help menu
    m_help_menu = new wxMenu;
    m_help_menu->Append(MENU_FUNCTION_ID_HELP_ABOUT,
                        FRAME_MENU_STRINGS[FRAME_MENU_STRING_ID_ABOUT],
                        FRAME_STATUSBAR_STRINGS[STATUSBAR_STRING_ID_ABOUT]);

    // Add menus to menu bar
    Append(m_file_menu, FRAME_MENUBAR_STRINGS[FRAME_ID_FILE_MENU]);
    Append(m_tools_menu, FRAME_MENUBAR_STRINGS[FRAME_ID_TOOLS_MENU]);
    Append(m_options_menu, FRAME_MENUBAR_STRINGS[FRAME_ID_OPTIONS_MENU]);
    Append(m_help_menu, FRAME_MENUBAR_STRINGS[FRAME_ID_HELP_MENU]);
}
