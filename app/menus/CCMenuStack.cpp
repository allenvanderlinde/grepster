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
    /* Check to see if the stack has already been opened
        in the notebook. */
    for(unsigned int i = 0; i < Notebook->GetPageCount(); i++) {
        if(m_szName.IsSameAs(Notebook->GetPageText(i))) {
            Notebook->SetSelection(i);
            return;
        }
    }
    /* Otherwise open the selected server
        stack into the notebook. */
    int nIndex = ServerStacks->FindName(m_szName);
    Notebook->OpenPage(ServerStacks->GetStacks()[nIndex]);
}

/*
    CCMenuStack::Close()
*/
void CCMenuStack::Close(wxCommandEvent& event) {
    if(wxMessageBox(L"Are you sure you want to close " + m_szName + "?", L"Close Server Stack?", wxOK | wxCANCEL | wxICON_QUESTION) == wxOK) {
        ServerStacks->CloseStack(m_szName); // Close the selected stack
        /* If the stack has already been opened, close its
            page in the notebook. */
        for(unsigned int i = 0; i < Notebook->GetPageCount(); i++) {
            if(m_szName.IsSameAs(Notebook->GetPageText(i))) {
                Notebook->SetSelection(i);
                Notebook->DeletePage(Notebook->GetSelection());
                return;
            }
        }
    }
}
