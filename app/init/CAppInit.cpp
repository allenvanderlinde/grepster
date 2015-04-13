/*
    File:       CAppInit.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       grepster's configuration class methods.

    Created:    11/28/14

    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../../precomp.h"

#include "CAppInit.h"


/*
    CAppInit::CAppInit
*/
CAppInit::CAppInit(wxString label)
    : wxConfig(label) {
    /* Read basic session configuration from registry. */
    m_pAdministrator = new CAdminAccount(Read(CONFIG_LABEL_USERNAME, "Administrator"));
    /* Note: grepster attempts to use PuTTY's SSH and SFTP tools as default. */
    m_szPathToSSHTool = Read(CONFIG_LABEL_PATH_SSH_TOOL, "C:\\Program Files (x86)\\PuTTY\\plink.exe");
    m_szPathToSFTPTool = Read(CONFIG_LABEL_PATH_SFTP_TOOL, "C:\\Program Files (x86)\\PuTTY\\psftp.exe");
    Read(CONFIG_LABEL_TOGGLE_FLOATING, &m_bToggleFloating);
}

/*
    CAppInit::SSHTool
*/
wxString CAppInit::SSHTool() {
    wxString szShort = m_szPathToSSHTool.AfterLast(L'\\');
    return szShort.BeforeFirst(L'.');
}

/*
    CAppInit::SFTPTool
*/
wxString CAppInit::SFTPTool() {
    wxString szShort = m_szPathToSFTPTool.AfterLast(L'\\');
    return szShort.BeforeFirst(L'.');
}
