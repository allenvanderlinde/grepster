/*
    File:       CServerStacks.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets tree control class initialization and methods.

    Created:    11/21/14

    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../precomp.h"

#include "../grepster.h"

#include "CAppFrame.h"
#include "CServerStacks.h"


/*
    CServerStacks::CServerStacks(wxWindow*)
*/
CServerStacks::CServerStacks(wxWindow* parentFrame)
    : wxTreeCtrl(parentFrame, SERVER_STACKS_ID, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE | wxTR_HIDE_ROOT) {
    /* Configure server stack's display settings. */
    m_serverStacksInf_t.PaneBorder(true);
    m_serverStacksInf_t.BestSize(SERVER_STACKS_DEFAULT_WIDTH, FRAME_HEIGHT);
    m_serverStacksInf_t.Name(SERVER_STACKS_NAME);
    m_serverStacksInf_t.Caption(SERVER_STACKS_CTRL_TITLE);
    m_serverStacksInf_t.CaptionVisible();
    m_serverStacksInf_t.Left();
    m_serverStacksInf_t.CloseButton(false);
    m_serverStacksInf_t.Floatable(Configuration->bToggleFloating);
    m_serverStacksInf_t.Show(true);

    /* Initialize server stack from administrator account. */
    m_treeRoot = AddRoot(wxEmptyString);
    m_treeAdminItem = AppendItem(m_treeRoot, Configuration->Username());//SERVER_STACK_DEFAULT_LABEL);

    wxTreeItemId item = AppendItem(m_treeAdminItem, "blackboard-grepper");
}


/*
    CServerStacks::UpdateStacks
*/
void CServerStacks::UpdateStacks() {
    /* Update grepster's Server Stacks control after changes. */
    SetItemText(m_treeAdminItem, Configuration->Username());
}
