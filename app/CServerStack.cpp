/*
    File:       CServerStack.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets tree control class initialization and methods.

    Created:    11/21/14

    Copyright (C) 2014 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../grepster.h"
#include "CAppFrame.h"
#include "CServerStack.h"

/*
    CServerStack::CServerStack(wxWindow*)
*/
CServerStack::CServerStack(wxWindow* parentFrame)
    : wxTreeCtrl(parentFrame, SERVER_STACK_ID, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE | wxTR_HIDE_ROOT) {
    /* Configure server stack's display settings. */
    m_serverStackInf.PaneBorder(true);
    m_serverStackInf.BestSize(SERVER_STACK_DEFAULT_WIDTH, FRAME_HEIGHT);
    m_serverStackInf.Name(SERVER_STACK_NAME);
    m_serverStackInf.Caption(SERVER_STACK_CTRL_TITLE);
    m_serverStackInf.CaptionVisible();
    m_serverStackInf.Left();
    m_serverStackInf.CloseButton(false);
    m_serverStackInf.Floatable(Configuration->bToggleFloating);
    m_serverStackInf.Show(true);

    /* Initialize server stack from administrator account. */
    m_root = AddRoot(wxEmptyString);
    m_admin_item = AppendItem(m_root, SERVER_STACK_DEFAULT_LABEL);
}
