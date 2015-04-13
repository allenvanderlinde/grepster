/*
    File:       CCMenuServer.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       Context menu's class initialization and methods for a server stack's individual server.

    Created:    4/6/2015

    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../../precomp.h"

#include "CCMenuServer.h"


/* Construct the menu's event handler calls. */
wxBEGIN_EVENT_TABLE(CCMenuServer, wxMenu)
    EVT_MENU(CCMenuServer::OPEN, CCMenuServer::Open)
    EVT_MENU(CCMenuServer::REMOVE, CCMenuServer::Remove)
wxEND_EVENT_TABLE()


/*
    CCMenuServer::CCMenuServer
*/
CCMenuServer::CCMenuServer(wxString name, wxString parent)
    : wxMenu() {
    m_szName = name;
    m_szParent = parent;
    /* Build context menu items. */
    Append(OPEN, L"Open " + name, L"Open the selected server stack into the notebook.");
    AppendSeparator();
    Append(REMOVE, L"Remove", L"Remove this server from the stack.");
}

/*
    CCMenuServer::~CCMenuServer
*/
CCMenuServer::~CCMenuServer() {

}

/*
    CCMenuServer::Open
*/
void CCMenuServer::Open(wxCommandEvent& event) {
    //ServerStack->OpenServerStack
}

/*
    CCMenuServer::Remove
*/
void CCMenuServer::Remove(wxCommandEvent& event) {
    ServerStacks->RemoveServer(m_szName, m_szParent);
}
