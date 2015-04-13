/**
 * @file    CAdminStack.h
 * @author  Allen Vanderlinde
 * @date    March 30, 2015
 * @brief   Object which holds the strings of servers to grep in and/or run a remote command from.
 *          The strings are then passed as part of a user-defined command string to the selected
 *          SSH/SFTP tools.
 */
/*
    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CADMINSTACK_H_
#define _CADMINSTACK_H_


/**
 * This object represents a user's stack of server IP addresses
 * in strings to be passed to the SSH/SFTP tools.
 *
 * @class   CAdminStack
 * @brief   Class definition for grepster's server stack data object.
 */
class CAdminStack {
public:
    /**
     * @brief       Default constructor which builds user's server stack from file.
     * @param[in]   filePath Path to the file where the user's server stack is stored.
     */
    CAdminStack(wxString filePath);

    /**
     * @brief       Get the path to this server stack's file.
     * @retval      wxString The string of the path to this stack's file.
     */
    wxString Path() { return m_szFilePath; }

    /**
     * @brief       Return the size of the server stack.
     * @retval      int The number of entries in the string vector of servers.
     */
    int Size() { return (int)m_Servers.size(); }

    /**
     * @brief       Return the name of this stack.
     * @retval      wxString The name of this stack as loaded from file.
     */
    wxString Name() { return m_szServerStackName; }

    /**
     * @brief       Return's the string of the server at the current index.
     * @param[in]   index The location of the string in the m_Servers vector.
     * @retval      wxString The string of the chosen server.
     */
    wxString IP(int index) { return m_Servers[index]; }

    /**
     * @brief       Remove the server string from the vector.
     * @param[in]   name The string of the server to remove from the m_Servers vector.
     */
    void RemoveServer(wxString name);

private:
    wxString        m_szFilePath;
    wxString        m_szServerStackName;

    /** @brief      String vector for holding list of servers. */
    std::vector<wxString>       m_Servers;
};

#endif // _CADMINSTACK_H_
