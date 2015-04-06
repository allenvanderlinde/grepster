/*
    File:       CCMenuStack.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       Context menu's class initialization and methods for a server stack.

    Created:    4/5/2015

    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../../precomp.h"

#include "../../grepster.h"

#include "CCMenuStack.h"


/* Construct the menu's event handler calls. */
wxBEGIN_EVENT_TABLE(CCMenuStack, wxMenu)
    EVT_MENU(CCMenuStack::CLOSE_STACK, CCMenuStack::Close)
wxEND_EVENT_TABLE()


/*
    CCMenuStack::CCMenuStack
*/
CCMenuStack::CCMenuStack(wxString name)
    : wxMenu() {
    m_szName = name;
    /* Build context menu items. */
    Append(CLOSE_STACK, L"Close", L"Close this server stack.");
}

/*
    CCMenuStack::~CCMenuStack
*/
CCMenuStack::~CCMenuStack() {

}

/*
    CCMenuStack::Close()
*/
void CCMenuStack::Close(wxCommandEvent& event) {
    ServerStacks->CloseStack(m_szName);
}
