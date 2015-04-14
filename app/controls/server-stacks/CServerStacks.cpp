/*
    File:       CServerStacks.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets tree control class initialization and methods.

    Created:    11/21/14

    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../../../precomp.h"

#include "../../CAppFrame.h"
#include "../../menus/CCMenuAdminRoot.h"
#include "../../menus/CCMenuStack.h"
#include "../../menus/CCMenuServer.h"
#include "../server-stacks/CServerStacks.h"
#include "../../web-viewer/CWebViewer.h"


/* Construct event handler calls. */
wxBEGIN_EVENT_TABLE(CServerStacks, wxTreeCtrl)
    EVT_TREE_ITEM_ACTIVATED(wxID_ANY, CServerStacks::ExpandItem)
    /* Handle server stack's context menus. */
    EVT_TREE_ITEM_RIGHT_CLICK(wxID_ANY, CServerStacks::ContextMenu)
wxEND_EVENT_TABLE()


/*
    CServerStacks::CServerStacks
*/
CServerStacks::CServerStacks(wxWindow* parentFrame)
    : wxTreeCtrl(parentFrame, SERVER_STACKS_ID, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE | wxTR_HIDE_ROOT) {
    /* Configure server stack's display settings. */
    /* Set the initial size of the control when it's un-docked. */
    int nStacksWidth = Configuration->ReadLong(CONFIG_LABEL_STACKS_WIDTH, SERVER_STACKS_DEFAULT_WIDTH);
    int nStacksHeight = Configuration->ReadLong(CONFIG_LABEL_STACKS_HEIGHT, DEFAULT_FRAME_HEIGHT);
    SetSize(nStacksWidth, nStacksHeight);
    m_serverStacksInf_t.BestSize(nStacksWidth, nStacksHeight);
    m_serverStacksInf_t.Left();
    /* Miscellaneous settings. */
    m_serverStacksInf_t.PaneBorder(true);
    m_serverStacksInf_t.Name(SERVER_STACKS_NAME);
    m_serverStacksInf_t.Caption(SERVER_STACKS_CTRL_TITLE);
    m_serverStacksInf_t.CaptionVisible();
    m_serverStacksInf_t.CloseButton(false);
    m_serverStacksInf_t.Floatable(Configuration->Floating());
    m_serverStacksInf_t.Show(true);

    /* Initialize server stack from administrator account. */
    m_treeRoot = AddRoot(wxEmptyString);
    m_treeAdminItem = AppendItem(m_treeRoot, Configuration->Username());

    // Default empty session upon starting
    //AddServerStacks(CAdminStack(EMPTY_STACK));
    //m_treeServerStack = AppendItem(m_treeAdminItem, L"empty");
}

/*
    CServerStacks::FindName
*/
int CServerStacks::FindName(wxString str) {
    wxArrayString Stacks;
    for(auto itr = m_Stacks.begin(); itr != m_Stacks.end(); ++itr) {
        Stacks.Add(itr->Name());
    }
    return Stacks.Index(str);
}

/*
    CServerStacks::FindPath
*/
int CServerStacks::FindPath(wxString str) {
    wxArrayString Stacks;
    for(auto itr = m_Stacks.begin(); itr != m_Stacks.end(); ++itr) {
        Stacks.Add(itr->Path());
    }
    return Stacks.Index(str);
}

/*
    CServerStacks::AddServerStack
*/
void CServerStacks::AddServerStack(CAdminStack serverStack) {
    /* Check to see if there is a stack name conflict. */
    if(FindName(serverStack.Name()) != wxNOT_FOUND) {
        wxMessageBox(L"The stack " + serverStack.Name() + " in " + serverStack.Path() + " matches one already in the session. Please rename the original stack before adding this one.",
                     L"Server Stack Conflict", wxICON_INFORMATION | wxOK);
        return;
    }
    m_Stacks.push_back(serverStack);
    wxTreeItemId newStack = AppendItem(m_treeAdminItem, serverStack.Name());;
    m_TreeStacks.push_back(newStack);
    /* Build server list from server stack. */
    for(int i = 0; i < serverStack.Size(); i++)
        AppendItem(newStack, serverStack.IP(i));
    if(IsExpanded(m_treeAdminItem) == false)
        Expand(m_treeAdminItem);
    Expand(newStack);    // Expand the newly added stack
    SortChildren(m_treeAdminItem);
    /* Update console with stack addition. */
    Console->BlueText();
    *Console << L"\nAdding " + serverStack.Name() + " to session.\n";
    Console->BlackText();
}

/*
    CServerStacks::ExpandItem
*/
void CServerStacks::ExpandItem(wxTreeEvent &event) {
    wxTreeItemId item = event.GetItem();  // The currently selected tree item
    if(IsExpanded(item))
        Collapse(item);
    else
        Expand(item);
}

/*
    CServerStacks::UpdateStacks
*/
void CServerStacks::UpdateStacks() {
    /* Update grepster's Server Stacks control after changes. */
    SetItemText(m_treeAdminItem, Configuration->Username());
}

/*
    CServerStacks::ContextMenu
*/
void CServerStacks::ContextMenu(wxTreeEvent& event) {
    wxTreeItemId item = event.GetItem();  // The control's selected tree item
    SelectItem(item);    // Make sure the item user selected is focused
    wxString szItemText(GetItemText(item));    // Capture item's string that the user selected
    /* Decide what menu options should be displayed
        depending upon what item is selected. */
    if(szItemText.IsSameAs(GetItemText(m_treeAdminItem))) {
        CCMenuAdminRoot* pMenu = new CCMenuAdminRoot();
        PopupMenu(pMenu);
        return;
    } else {
        for(auto itr = m_Stacks.begin(); itr != m_Stacks.end(); ++itr) {
            if(szItemText.IsSameAs(itr->Name())) {  // If selecting a server stack
                CCMenuStack* pMenu = new CCMenuStack(szItemText, itr->Path());
                PopupMenu(pMenu);
                return;
            } else {    // Check if a server was selected
                wxString szServerText(GetItemText(GetItemParent(item)));
                for(int i = 0; i < itr->Size(); i++) {
                    if(szItemText.IsSameAs(itr->IP(i))) {   // If selecting a server
                        CCMenuServer* pMenu = new CCMenuServer(szItemText, szServerText);
                        PopupMenu(pMenu);
                        return;
                    }
                }
            }
        }
    }
}

/*
    CServerStacks::CloseStack
*/
void CServerStacks::CloseStack(wxString name) {
    /* Crawl through current server stacks and find match
        with the stack's name. */
    for(auto itr = m_Stacks.begin(); itr != m_Stacks.end(); ++itr) {
        if(name.IsSameAs(itr->Name())) {
            Console->BlueText();
            *Console << L"\nClosing stack " + itr->Name() + L".";
            /* Crawl through current tree items representing stacks
                to select and remove the match. */
            for(auto itrt = m_TreeStacks.begin(); itrt != m_TreeStacks.end(); ++itrt) {
                if(name.IsSameAs(GetItemText(*itrt))) {
                    Delete(*itrt);
                    break;
                }
            }
            m_Stacks.erase(itr);
            *Console << L"\nStack closed.\n";
            Console->BlackText();
            return;
        }
    }
}

/*
    CServerStacks::CloseAll
*/
void CServerStacks::CloseAll() {
    m_Stacks.clear();
    DeleteChildren(m_treeAdminItem);
}

/*
    CServerStacks::RemoveServer
*/
void CServerStacks::RemoveServer(wxString name, wxString parent) {
    /* Crawl through the server stacks and identify
        by the server's parent, which server to
        remove from which stack. */
    for(auto itr = m_Stacks.begin(); itr != m_Stacks.end(); ++itr) {
        if(parent.IsSameAs(itr->Name())) {  // Found the parent stack
            for(int i = 0; i < itr->Size(); i++) {
                if(name.IsSameAs(itr->IP(i))) { // Found the server
                    itr->RemoveServer(name);    // Remove the server from the corresponding stack object
                    Console->BlueText();
                    *Console << L"\nRemoving server " + name + L" from stack " + itr->Name() + L".\n";
                    Console->BlackText();
                    Delete(GetFocusedItem());
                    if(itr->Size() < 1)
                        CloseStack(parent);
                    return;
                }
            }
        }
    }
}
