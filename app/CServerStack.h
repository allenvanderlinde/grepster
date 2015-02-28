/**
 * @file    CServerStack.h
 * @author  Allen Vanderlinde
 * @date    November 20, 2014
 * @brief   wxWidgets tree control class definition which displays user's server stacks.
 */
/*
    Copyright (C) 2014 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CSERVERSTACK_H_
#define _CSERVERSTACK_H_

#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/aui/aui.h>

/** grepster's Server Stack globals. */
#define SERVER_STACK_DEFAULT_LABEL          "Admin"

/**
 * This object creates a wxTreeCtrl used to house a list of servers which can be selected for more streamlined grepping.
 *
 * @class   CServerStack
 * @brief   Class definition for grepster's server stack.
 */
class CServerStack : public wxTreeCtrl {
public:
    /**
     * @brief       Default constructor which creates tree control server stack.
     * @param[in]   parentFrame The primary frame to which this control belongs.
     */
    CServerStack(wxWindow* parentFrame);

    /**
     * @brief       Get the server stacks control's pane information.
     * @retval      wxAuiPaneInfo This is the tree control's display configuration object.
     */
    wxAuiPaneInfo getPaneInfo() { return m_serverStackInf_t; }

private:
    /** wxTreeCtrl root item. */
    wxTreeItemId m_treeRoot;
    /** wxTreeCtrl administrator item populated with the user's server stacks. */
    wxTreeItemId m_treeAdminItem;
    /** AUI pane settings object. */
    wxAuiPaneInfo m_serverStackInf_t;

    /* Declare the wxWidgets event-handling table for this control. */
    //wxDECLARE_EVENT_TABLE();
};

#endif
