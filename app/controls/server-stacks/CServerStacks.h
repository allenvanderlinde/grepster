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

#include "../../../session/CAdminStack.h"


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
     * @brief       Add a built CAdminStack to the tree control for user interaction.
     * @param[in]   serverStack CAdminStack object from which CServerStacks builds its tree items.
     */
    void AddServerStack(CAdminStack serverStack);

    /**
     * @brief       Return the vector of server stacks.
     * @retval      std::vector<CAdminStack> The vector of server stacks in the current session.
     */
    std::vector<CAdminStack> GetStacks() { return m_Stacks; }

    /**
     * @brief       Look for a match in the current list of server stacks.
     * @param[in]   str String of server stack name to look for in current list.
     * @retval      int The index in the current list where the string is. This
     *              can also be wxNOT_FOUND as it uses a temporary wxArrayString.
     */
    int FindInStacks(wxString);

    /**
     * @brief       Open the currently selected item from the server stack.
     */
    void OpenItem(wxTreeEvent &event);

    /**
     * @brief       Update the current tree control associated with the administrator after configuration and server changes.
     */
    void UpdateStacks();

    /**
     * @brief       Return the number of stacks in the control.
     * @retval      int The number of stacks currently added to the control in the session.
     */
    int Count() { return (int)m_Stacks.size(); }

    /**
     * @brief       Close the currently selected stack.
     * @param[in]   name This is the identifying string of the selected stack.
     */
    void CloseStack(wxString name);

private:
    wxTreeItemId    m_treeRoot;
    /** @brief      This tree item will be replaced with the administrator's username. */
    wxTreeItemId    m_treeAdminItem;

    wxAuiPaneInfo   m_serverStacksInf_t;

    /** @brief      Vector of server stack roots for tree control. */
    //std::vector<wxTreeItemId>   m_treeStackRoots;
    /** @brief      Vector of tree items each representing one of the
     *              user's servers to run grep on.
     */
    std::vector<wxTreeItemId>   m_treeIPItems;
    /** @brief      Vector of CAdminStack from which the tree control builds its server list. */
    std::vector<CAdminStack>    m_Stacks;   // will this be where the actual string vectors are kept? then updatestacks() can stay to calling only members?

    /**
     * @brief       Context menu for an individual server stack.
     */
     //RENAME this ContextMenu() to be more general??
    void PopupStackOptions(wxTreeEvent& event);

    /**
     * @brief       Initialize and call the object's event handler.
     */
    wxDECLARE_EVENT_TABLE();
};

#endif
