/**
 * @file    CCMenuServer.h
 * @author  Allen Vanderlinde
 * @date    April 6, 2015
 * @brief   wxMenu object used as the context menu for a server stack's individual server.
 */
/*
    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CCMENUSERVER_H_
#define _CCMENUSERVER_H_

/**
 * This object creates a wxMenu used as the context menu for a server
 * with its respective functions and information.
 *
 * @class   CCMenuServer
 * @brief   Class definition for this context menu object.
 */
class CCMenuServer : public wxMenu {
public:
    /**
     * @brief       Default constructor which creates the context menu.
     * @param[in]   name The string/label of the selected server.
     * @param[in]   parent The string/label of the server's parent stack.
     */
    CCMenuServer(wxString name, wxString parent);
    /**
     * @brief       Default destructor.
     */
    ~CCMenuServer();

    /**
    * @enum        enum_ContextMenuItemIDs
    * @brief       These represent the context menu's individual function call IDs.
    */
    enum enum_ContextMenuItemIDs {
        OPEN = 11006,
        REMOVE
    };

private:
    /** @brief      Name of the selected server which owns this context menu. */
    wxString        m_szName;
    /** @brief      Name of the server's parent stack. */
    wxString        m_szParent;

    /**
     * @brief       Open the selected server stack into the session notebook.
     */
    void Open(wxCommandEvent& event);
    /**
     * @brief       Remove the selected server from the stack.
     */
    void Remove(wxCommandEvent& event);

    /**
     * @brief       Initialize and call the object's event handler.
     */
    wxDECLARE_EVENT_TABLE();
};

#endif // _CCMENUSERVER_H_
