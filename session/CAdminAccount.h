/**
 * @file    CAdminAccount.h
 * @author  Allen Vanderlinde
 * @date    December 1, 2014
 * @brief   grepster's administrator account which loads user's workspace and server stacks for a new session.
 */
/*
    Copyright (C) 2014 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CADMINACCOUNT_H_
#define _CADMINACCOUNT_H_

#include <wx/wx.h>

#include "../pugixml-1.4/pugixml.hpp"

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
     * @param[in]   path The path used to load the administrator's account information from file. This is passed from grepster's configuration.
     */
    CAdminAccount(wxString path);

 private:
    /** Path to the user's administrator account configuration for initialization. */
    wxString m_pszPath;
    /** XML file handle for reading. */
    pugi::xml_document m_XMLFile;
 };

#endif // _CADMINACCOUNT_H_
