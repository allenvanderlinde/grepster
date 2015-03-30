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
#include "../webviewer/CWebViewer.h"


/* Construct the Server Stacks' event handler calls. */
wxBEGIN_EVENT_TABLE(CServerStacks, wxTreeCtrl)
    EVT_TREE_ITEM_ACTIVATED(wxID_ANY, CServerStacks::OpenScript)

    EVT_TREE_ITEM_MENU(wxID_ANY, CServerStacks::ServerOptions)
wxEND_EVENT_TABLE()


/*
    CServerStacks::CServerStacks
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
    m_treeAdminItem = AppendItem(m_treeRoot, Configuration->Username());//SERVER_STACKS_DEFAULT_LABEL);

    // Default empty session upon starting
    m_treeServerStack = AppendItem(m_treeAdminItem, L"empty");
}

/*
    CServerStacks::OpenScript
*/
void CServerStacks::OpenScript(wxTreeEvent &event) {
    // search through entire vector of items
    // and do switch on the ID?
    if(event.GetItem().GetID() == m_treeAdminItem.GetID()) {
        /* Expand or collapse the user's server list and associated scripts
            if they double-click on their username in the Server Stacks control. */
        if(IsExpanded(m_treeAdminItem))
            Collapse(m_treeAdminItem);
        else
            Expand(m_treeAdminItem);
    } else {//(event.GetItem().GetID() != m_treeAdminItem.GetID()) {
        CWebViewer* pBrowser = new CWebViewer(this);
        SessionNotebook->AddPage(pBrowser->GetBrowser(), L"Welcome to grepster!");

        /* Set focus to newly opened page. */
        size_t nNewPageIndex = SessionNotebook->GetPageCount();
        SessionNotebook->SetSelection(nNewPageIndex - 1);
        delete pBrowser;
    }
}

/*
    CServerStacks::UpdateStacks
*/
void CServerStacks::UpdateStacks() {
    /* Update grepster's Server Stacks control after changes. */
    SetItemText(m_treeAdminItem, Configuration->Username());
}

/*
    CServerStacks::ServerOptions
*/
void CServerStacks::ServerOptions(wxTreeEvent& event) {
    wxMenu* pContext = new wxMenu();
    pContext->Append(wxID_ANY, L"string");

    // if(event.GetItem().GetID() == ITEM_CONTEXT_MENU_OPEN)..... <= works?
    if(event.GetItem().GetID() == m_treeServerStack.GetID()) {

        PopupMenu(pContext);
    }
    delete pContext;
    //wxMessageBox("menu", "menu", wxOK);
}
