/*
    File:       CAppMenubar.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets menu bar control class initialization and methods.

    Created:    11/5/14

    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../grepster.h"
#include "CAppMenubar.h"


/*
    CAppFrame::CAppFrame
*/
CAppMenubar::CAppMenubar()
    : wxMenuBar() {
    // File menu
    m_pMenuFile = new wxMenu;
    m_pMenuFile->Append(MENU_FUNCTION_ID_FILE_NEW_JOB,
                        FRAME_MENU_STRINGS[FRAME_MENU_STRING_ID_NEW_JOB],
                        FRAME_STATUSBAR_STRINGS[STATUSBAR_STRING_ID_NEW_JOB]);
    m_pMenuFile->AppendSeparator();
    m_pMenuFile->Append(MENU_FUNCTION_ID_FILE_QUIT,
                        FRAME_MENU_STRINGS[FRAME_MENU_STRING_ID_QUIT],
                        FRAME_STATUSBAR_STRINGS[STATUSBAR_STRING_ID_QUIT]);

    // Session menu
    m_pMenuSession = new wxMenu;
    m_pMenuSession->Append(MENU_FUNCTION_ID_SESSION_DEFAULT_CREDENTIALS,
                           FRAME_MENU_STRINGS[FRAME_MENU_STRING_ID_DEFAULT_CREDENTIALS],
                           FRAME_STATUSBAR_STRINGS[STATUSBAR_STRING_ID_DEFAULT_CREDENTIALS]);

    // Tools menu
    m_pMenuTools = new wxMenu;
    m_pMenuTools->Append(MENU_FUNCTION_ID_TOOLS_LAUNCH_PUTTY,
                         FRAME_MENU_STRINGS[FRAME_MENU_STRING_ID_LAUNCH_PUTTY],
                         FRAME_STATUSBAR_STRINGS[STATUSBAR_STRING_ID_LAUNCH_PUTTY]);

    // Options menu
    m_pMenuOptions = new wxMenu;
    m_pMenuOptions->Append(MENU_FUNCTION_ID_OPTIONS_TOGGLE_FLOATABLE,
                           FRAME_MENU_STRINGS[FRAME_MENU_STRING_ID_TOGGLE_DOCKABLE],
                           FRAME_STATUSBAR_STRINGS[STATUSBAR_STRING_ID_TOGGLE_DOCKABLE],
                           wxITEM_CHECK);
    /* Check activated items set from configuration. */
    m_pMenuOptions->Check(MENU_FUNCTION_ID_OPTIONS_TOGGLE_FLOATABLE, Configuration->bToggleFloating);

    // Help menu
    m_pMenuHelp = new wxMenu;
    m_pMenuHelp->Append(MENU_FUNCTION_ID_HELP_ABOUT,
                        FRAME_MENU_STRINGS[FRAME_MENU_STRING_ID_ABOUT],
                        FRAME_STATUSBAR_STRINGS[STATUSBAR_STRING_ID_ABOUT]);

    // Add menus to menu bar
    Append(m_pMenuFile, FRAME_MENUBAR_STRINGS[FRAME_ID_FILE_MENU]);
    Append(m_pMenuSession, FRAME_MENUBAR_STRINGS[FRAME_ID_SESSION_MENU]);
    Append(m_pMenuTools, FRAME_MENUBAR_STRINGS[FRAME_ID_TOOLS_MENU]);

    Append(m_pMenuOptions, FRAME_MENUBAR_STRINGS[FRAME_ID_OPTIONS_MENU]);
    Append(m_pMenuHelp, FRAME_MENUBAR_STRINGS[FRAME_ID_HELP_MENU]);
}
