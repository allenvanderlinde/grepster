/**
 * @file    CCMenuAdminRoot.h
 * @author  Allen Vanderlinde
 * @date    April 12, 2015
 * @brief   wxMenu object used as the context menu for the admin tree root in the server stacks control.
 */
/*
    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CCMENUADMINROOT_H_
#define _CCMENUADMINROOT_H_


/**
 * This object creates a wxMenu used as the context menu for the admin tree
 * root in the server stacks control. It holds duplicate functions as found
 * in the Session menu.
 *
 * @class   CCMenuAdminRoot
 * @brief   Class definition for this context menu object.
 */
 class CCMenuAdminRoot : public wxMenu {
 public:
    /**
     * @brief       Default constructor which creates the context menu.
     */
    CCMenuAdminRoot();
    /**
     * @brief       Default destructor.
     */
    ~CCMenuAdminRoot();

    /**
     * @enum        enum_ContextMenuItemIDs
     * @brief       These represent the context menu's individual function call IDs.
     */
    enum enum_ContextMenuItemIDs {
        ADD_SERVER_STACKS = 11003,
        CLOSE_ALL_STACKS
    };

private:
    /**
     * @brief       Add one or more saved server stacks to the current session.
     *              Note: This just calls CAppFrame::AddServerStacks.
     */
    void AddServerStacks(wxCommandEvent& event);
    /**
     * @brief       Close all server stacks in current session.
     *              Note: This just calls CAppFrame::CloseServerStacks.
     */
    void CloseServerStacks(wxCommandEvent& event);

    /**
     * @brief       Initialize and call the object's event handler.
     */
    wxDECLARE_EVENT_TABLE();
 };

#endif // _CCMENUADMINROOT_H_
