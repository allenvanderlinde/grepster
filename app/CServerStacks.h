/**
 * @file    CServerStacks.h
 * @author  Allen Vanderlinde
 * @date    November 20, 2014
 * @brief   wxWidgets tree control class definition which displays user's server stacks.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CSERVERSTACKS_H_
#define _CSERVERSTACKS_H_

#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/aui/aui.h>


/* CServerStack configuration definitions. */
/** The server stacks control's root item label. */
#define SERVER_STACK_DEFAULT_LABEL          "default"


/**
 * This object creates a wxTreeCtrl used to house a list of servers which can be selected for more streamlined grepping tasks.
 *
 * @class   CServerStacks
 * @brief   Class definition for grepster's tree control for housing server stacks.
 */
class CServerStacks : public wxTreeCtrl {
public:
    /**
     * @brief       Default constructor which creates the tree control.
     * @param[in]   parentFrame The primary frame to which this control belongs.
     */
    CServerStacks(wxWindow* parentFrame);

    /**
     * @brief       Get the control's pane information.
     * @retval      wxAuiPaneInfo This is the tree control's display configuration object.
     */
    wxAuiPaneInfo getPaneInfo() { return m_serverStacksInf_t; }

    /**
     * @brief       Update the current tree control associated with the administrator after configuration and server changes.
     */
    void UpdateStacks();

private:
    /** wxTreeCtrl root item. */
    wxTreeItemId    m_treeRoot;
    /** wxTreeCtrl administrator item populated with the user's server stacks. */
    wxTreeItemId    m_treeAdminItem;
    /** AUI pane settings object. */
    wxAuiPaneInfo   m_serverStacksInf_t;

    /**
     * @brief       Initialize and call the primary object's event handler.
     */
    //wxDECLARE_EVENT_TABLE();
};

#endif
