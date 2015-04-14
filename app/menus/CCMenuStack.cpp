/*
    File:       CCMenuStack.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       Context menu's class initialization and methods for a server stack.

    Created:    4/5/2015

    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../../precomp.h"

#include "CCMenuStack.h"


/* Construct the menu's event handler calls. */
wxBEGIN_EVENT_TABLE(CCMenuStack, wxMenu)
    EVT_MENU(CCMenuStack::OPEN_STACK, CCMenuStack::Open)
    EVT_MENU(CCMenuStack::CLOSE_STACK, CCMenuStack::Close)
wxEND_EVENT_TABLE()


/*
    CCMenuStack::CCMenuStack
*/
CCMenuStack::CCMenuStack(wxString name, wxString path)
    : wxMenu() {
    m_szName = name;
    m_szPath = path;
    /* Build context menu items. */
    Append(OPEN_STACK, L"Open " + name, L"Open this server stack into the session notebook." );
    AppendSeparator();
    Append(CLOSE_STACK, L"Close " + name, L"Close this server stack.");

}

/*
    CCMenuStack::~CCMenuStack
*/
CCMenuStack::~CCMenuStack() {

}

/*
    CCMenuStack::Open
*/
void CCMenuStack::Open(wxCommandEvent& event) {
    int nIndex = ServerStacks->FindName(m_szName);

    Notebook->OpenPage(ServerStacks->GetStacks()[nIndex]);
}

/*
    CCMenuStack::Close()
*/
void CCMenuStack::Close(wxCommandEvent& event) {
    if(wxMessageBox(L"Are you sure you want to close " + m_szName + "?", L"Close Server Stack?", wxOK | wxCANCEL | wxICON_QUESTION) == wxOK) {
        ServerStacks->CloseStack(m_szName);
        if(ServerStacks->GetStacks().empty())
            GrepsterFrame->Menubar()->GetMenu(FRAME_ID_SESSION_MENU)->Enable(MENU_FUNCTION_ID_SESSION_CLOSE_SERVER_STACKS, false);
    }
}
