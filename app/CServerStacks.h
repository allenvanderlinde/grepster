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

#include "../session/CAdminStack.h"


#define SERVER_STACKS_DEFAULT_LABEL          "default"

#define SERVER_STACKS_OPEN_SCRIPT            0x0B01


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
    wxAuiPaneInfo GetPaneInfo() { return m_serverStacksInf_t; }

    /**
     * @brief       Get the chosen server stack's tree item.
     * @retval      wxTreeItemId Object which holds the tree item.
     */
    wxTreeItemId GetServerStackTreeItem() { return m_treeServerStack; }

    /**
     * @brief       Open the currently selected user script from the Server Stack into a new page.
     */
    void OpenScript(wxTreeEvent &event);

    /**
     * @brief       Update the current tree control associated with the administrator after configuration and server changes.
     */
    void UpdateStacks();

private:
    wxTreeItemId    m_treeRoot;
    wxTreeItemId    m_treeAdminItem;

    wxTreeItemId    m_treeServerStack;

    wxAuiPaneInfo   m_serverStacksInf_t;

    /** @brief      Vector of tree items each representing one of the
     *              user's servers to run grep on.
     */
    std::vector<wxTreeItemId>   m_Servers;

    std::vector<CAdminStack>    m_Stacks;   // will this be where the actual string vectors are kept? then updatestacks() can stay to calling only members?

    /**
     * @brief       Context menu for an individual server stack.
     */
    void PopupStackOptions(wxTreeEvent& event);

    /**
     * @brief       Initialize and call the primary object's event handler.
     */
    wxDECLARE_EVENT_TABLE();
};

#endif
