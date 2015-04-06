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

#include "../../../precomp.h"

#include "../../../grepster.h"

#include "../../CAppFrame.h"
#include "../../menus/CCMenuStack.h"
#include "../server-stacks/CServerStacks.h"
#include "../../web-viewer/CWebViewer.h"


/* Construct the Server Stacks' event handler calls. */
wxBEGIN_EVENT_TABLE(CServerStacks, wxTreeCtrl)
    EVT_TREE_ITEM_ACTIVATED(wxID_ANY, CServerStacks::OpenItem)
    // User right-clicks on an item to access its contextual menu
    EVT_TREE_ITEM_MENU(wxID_ANY, CServerStacks::PopupStackOptions)
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
    m_treeAdminItem = AppendItem(m_treeRoot, Configuration->Username());

    // Default empty session upon starting
    //AddServerStack(CAdminStack(EMPTY_STACK));
    //m_treeServerStack = AppendItem(m_treeAdminItem, L"empty");
}

/*
    CServerStacks::FindInStacks
*/
int CServerStacks::FindInStacks(wxString str) {
    wxArrayString Stacks;
    for(auto itr = m_Stacks.begin(); itr != m_Stacks.end(); ++itr) {
        Stacks.Add(itr->Name());
    }
    return Stacks.Index(str);
}

/*
    CServerStacks::AddServerStack
*/
void CServerStacks::AddServerStack(CAdminStack serverStack) {
    m_Stacks.push_back(serverStack);
    wxTreeItemId newStack = AppendItem(m_treeAdminItem, serverStack.Name());;
    /* Build host/IP list from server stack. */
    for(int i = 0; i < serverStack.Size(); i++)
        m_treeIPItems.push_back(AppendItem(newStack, serverStack.IP(i)));
    if(IsExpanded(m_treeAdminItem) == false)
        Expand(m_treeAdminItem);
    Expand(newStack);    // Expand the newly added stack
}

/*
    CServerStacks::OpenItem
*/
void CServerStacks::OpenItem(wxTreeEvent &event) {
    wxTreeItemId item = event.GetItem();  // The currently selected tree item
    /* Expand or collapse the user's server list and associated scripts
        if they double-click on their username in the Server Stacks control. */
    if(IsExpanded(item))
        Collapse(item);
    else
        Expand(item);

    CWebViewer* pBrowser = new CWebViewer(this);    // does belonging to this item eat up more memory than belonging to CAppFrame? should that be extern global?
    SessionNotebook->AddPage(pBrowser->GetBrowser(), GetItemText(item));
    size_t nNewPageIndex = SessionNotebook->GetPageCount();
    SessionNotebook->SetSelection(nNewPageIndex - 1);
    delete pBrowser;
}

/*
    CServerStacks::UpdateStacks
*/
void CServerStacks::UpdateStacks() {
    /* Update grepster's Server Stacks control after changes. */
    SetItemText(m_treeAdminItem, Configuration->Username());
}

/*
    CServerStacks::PopupStackOptions
*/
void CServerStacks::PopupStackOptions(wxTreeEvent& event) {
    wxString szItemText(GetItemText(event.GetItem()));    // Capture item's string that the user right-clicked on
    CCMenuStack* contextMenu;  // Build menu object to display as the item's contextual menu
    /* Decide what menu options should be displayed
        depending upon what item is selected. */
    for(auto itr = m_Stacks.begin(); itr != m_Stacks.end(); ++itr) {
        if(szItemText.IsSameAs(itr->Name())) {  // If selecting a server stack root
            /* Build menu. */
            contextMenu = new CCMenuStack(szItemText);
            //pContext->Append(wxID_ANY, L"This is a server stack root: " + szItemText);
            PopupMenu(contextMenu);    // Display the contextual menu
            break;//return;
        } else {    // Search through stack's host/IP list for a match
            for(int i = 0; i < itr->Size(); i++) {
                if(szItemText.IsSameAs(itr->IP(i))) {
                        // Need to write context menu for the host/IP items
                    //contextMenu = new CCMenuStack(L"This is a host/IP address: " + szItemText);
                    //PopupMenu(contextMenu);
                    break;//return;
                    // DELETE CCMenuStack manually??
                }
            }
        }
    }
    if(&contextMenu != nullptr)
        delete contextMenu;    // Clean up temporary menu
}

/*
    CServerStacks::CloseStack
*/
void CServerStacks::CloseStack(wxString name) {
    //need to also delete cadminstack from vector!
    //wxTreeItemId selectedStack = GetFocusedItem();
    for(auto itr = m_Stacks.begin(); itr != m_Stacks.end(); ++itr) {
        if(name.IsSameAs(itr->Name()))
            m_Stacks.erase(itr);
    }
    Delete(GetFocusedItem());
}
