/*
    File:       CFrameMenubar.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets menu bar control class initialization and methods.

    Created:    11/5/14

    Copyright (C) 2014 by Allen Vanderlinde.
    Songbird and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "CFrameMenubar.h"

/*
    CAppFrame::CAppFrame
*/
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
    m_options_menu->Append(MENU_FUNCTION_ID_OPTIONS_TOGGLE_FLOATABLE,
                           FRAME_MENU_STRINGS[FRAME_MENU_STRING_ID_TOGGLE_DOCKABLE],
                           FRAME_STATUSBAR_STRINGS[STATUSBAR_STRING_ID_TOGGLE_DOCKABLE],
                           wxITEM_CHECK);
    /* Check activated items set from configuration. */
    m_options_menu->Check(MENU_FUNCTION_ID_OPTIONS_TOGGLE_FLOATABLE, configuration.bUseFloatable);

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
