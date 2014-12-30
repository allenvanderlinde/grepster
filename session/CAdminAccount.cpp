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
    /* Set this flag's default value to "true" as grepster should expect to load the configuration successfully.
        This flag needs to be "false" only once for grepster to warn the user as handled by CAppInit::CAppInit(). */
    m_bConfigurationLoadedSuccessfully = true;

    m_pszPath = path;
    /* Verify configuration file is present and intact. */
    pugi::xml_parse_result result = m_XMLFile.load_file(m_pszPath.wc_str());
    if(!result) { // XML file does not exist
        wxMessageBox("The administrator account found at " + path + " was not found. Using default configuration.", "Using Default Configuration", wxICON_WARNING | wxOK);
        m_bConfigurationLoadedSuccessfully = false;
    }
    else {
        m_XMLSettings = m_XMLFile.child(L"admin").child(L"info");    // Note: Do not change. Every grepster configuration element is labeled "setting"
        if(m_XMLSettings == NULL) {
            m_bConfigurationLoadedSuccessfully = false;
        }
    }

    // --------DEBUG: display okay-----------
    wxMessageBox(m_pszPath, "path to admin file", wxICON_INFORMATION);
}
