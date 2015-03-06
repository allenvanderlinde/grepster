/**
 * @file    CAdminAccount.h
 * @author  Allen Vanderlinde
 * @date    December 1, 2014
 * @brief   grepster's administrator account which loads user's credentials and server stacks for a new session.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CADMINACCOUNT_H_
#define _CADMINACCOUNT_H_


/**
* This object represents an administrator's user account which houses the user-defined server stacks for each grepping session.
* Administrator account information is written/read from a single representative XML file.
*
* @class   CAdminAccount
* @brief   Class definition for grepster's administrator accounts.
*/
class CAdminAccount {
public:
    /**
     * @brief       Default constructor which creates administrator account object.
     * @param[in]   username Administrator's username credential required to access servers for the current session.
     */
    CAdminAccount(wxString username);

    /**
     * @brief       Query administrator's username.
     * @retval      wxString This is the current session's administrator's username credential.
     */
    wxString Username() { return m_szUsername; }
    /**
     * @brief       Query administrator's password. Note: This is a plaintext password and is saved only in memory until the user quits grepster.
     * @retval      wxString This is the current session's administrator's password credential in plaintext.
     */
    wxString Password() { return m_szPassword; }

    /**
     * @brief       Change the administrator's credentials.
     */
    void ChangeCredentials(wxString username, wxString password) { m_szUsername = username; m_szPassword = password; }

private:
    /** Flag for successful loading of configuration. */
    bool m_bConfigurationLoadedSuccessfully;

    /** Administrator's username for the current job. */
    wxString m_szUsername;
    /** Administrator's password for the current job. */
    wxString m_szPassword;
 };

#endif // _CADMINACCOUNT_H_
