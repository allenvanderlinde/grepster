/*
    File:       CAdminAccount.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       grepster's administrator account class initialization and methods.

    Created:    12/3/14

    Copyright (C) 2014 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "CAdminAccount.h"

/*
    CAdminAccount::CAdminAccount(wxString)
*/
CAdminAccount::CAdminAccount(wxString path) {
    m_pszPath = path;
    wxMessageBox(m_pszPath, "path to admin file", wxICON_INFORMATION);
}
