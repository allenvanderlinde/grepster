/*
    File:       CCMenuAdminRoot.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       Context menu's class initialization and methods for the admin tree root item.

    Created:    4/12/2015

    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../../precomp.h"

#include "CCMenuAdminRoot.h"


/* Construct the menu's event handler calls. */
wxBEGIN_EVENT_TABLE(CCMenuAdminRoot, wxMenu)
    EVT_MENU(CCMenuAdminRoot::ADD_SERVER_STACKS, CCMenuAdminRoot::AddServerStacks)
    EVT_MENU(CCMenuAdminRoot::CLOSE_ALL_STACKS, CCMenuAdminRoot::CloseServerStacks)
wxEND_EVENT_TABLE()


/*
    CCMenuAdminRoot::CCMenuAdminRoot
*/
CCMenuAdminRoot::CCMenuAdminRoot()
    : wxMenu() {
    /* Build context menu items. */
    Append(ADD_SERVER_STACKS, L"Add server stacks...", L"Add one or multiple saved server stacks to the current session.");
    AppendSeparator();
    Append(CLOSE_ALL_STACKS, L"Close All Stacks", L"Close all server stacks in current session.");
    if(ServerStacks->GetStacks().empty())
        Enable(CLOSE_ALL_STACKS, false);
}

/*
    CCMenuAdminRoot::~CCMenuAdminRoot
*/
CCMenuAdminRoot::~CCMenuAdminRoot() {

}

/*
    CCMenuAdminRoot::AddServerStacks
*/
void CCMenuAdminRoot::AddServerStacks(wxCommandEvent& event) {
    GrepsterFrame->AddServerStacks(event);
}

/*
    CCMenuAdminRoot::CloseServerStacks
*/
void CCMenuAdminRoot::CloseServerStacks(wxCommandEvent& event) {
    GrepsterFrame->CloseServerStacks(event);
}
