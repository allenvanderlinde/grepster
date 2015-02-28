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
    m_serverStackInf_t.PaneBorder(true);
    m_serverStackInf_t.BestSize(SERVER_STACK_DEFAULT_WIDTH, FRAME_HEIGHT);
    m_serverStackInf_t.Name(SERVER_STACK_NAME);
    m_serverStackInf_t.Caption(SERVER_STACK_CTRL_TITLE);
    m_serverStackInf_t.CaptionVisible();
    m_serverStackInf_t.Left();
    m_serverStackInf_t.CloseButton(false);
    m_serverStackInf_t.Floatable(Configuration->bToggleFloating);
    m_serverStackInf_t.Show(true);

    /* Initialize server stack from administrator account. */
    m_treeRoot = AddRoot(wxEmptyString);
    m_treeAdminItem = AppendItem(m_treeRoot, Configuration->Username());//SERVER_STACK_DEFAULT_LABEL);

    wxTreeItemId item = AppendItem(m_treeAdminItem, "blackboard-grepper");
}
