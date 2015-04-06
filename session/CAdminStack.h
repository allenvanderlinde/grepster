/**
 * @file    CAdminStack.h
 * @author  Allen Vanderlinde
 * @date    March 30, 2015
 * @brief   Object which holds the strings of hosts or IP addresses to grep in and/or run a remote command from.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CADMINSTACK_H_
#define _CADMINSTACK_H_

/**
 * This object represents a user's stack or list of hosts or
 * IP addresses in strings to be passed to the SSH/SFTP
 * tools.
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
     * @brief       Return the size of the server stack.
     * @retval      int The number of entries in the string vector of hosts.
     */
    int Size() { return (int)m_Hosts.size(); }

    /**
     * @brief       Return the name of this stack.
     * @retval      wxString The name of this stack as loaded from file.
     */
    wxString Name() { return m_szServerStackName; }

    /**
     * @brief       Return's the string of the host/IP address at the current index.
     * @param[in]   index The location of the m_Hosts vector to get the string from.
     * @retval      wxString The string form of the chosen host/IP address.
     */
    wxString IP(int index) { return m_Hosts[index]; }

private:
    wxString        m_szFilePath;
    wxString        m_szServerStackName;

    /** @brief      String vector for holding list of hosts/IP addresses. */
    std::vector<wxString>       m_Hosts;
};

#endif // _CADMINSTACK_H_
