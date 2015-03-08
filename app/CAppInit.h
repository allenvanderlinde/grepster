/**
 * @file    CAppInit.h
 * @author  Allen Vanderlinde
 * @date    November 27, 2014
 * @brief   This object loads and populates grepster's configuration settings.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CAPPINIT_H_
#define _CAPPINIT_H_

#include "../session/CAdminAccount.h"


/** XML global definitions. */
#define XML_CONFIGURATION_NODE_LABEL        L"grepster"
#define XML_ELEMENT_LABEL                   L"setting"
#define XML_ID_LABEL                        L"id"
#define XML_VALUE_LABEL                     L"value"


/**
 * This object opens grepster's XML configuration and populates the configuration structure with its settings.
 * Variables which control grepster's current usage are public within this class so that they can be easily modified by other grepster objects.
 *
 * @class   CAppInit
 * @brief   Class definition for grepster's configuration.
 */
class CAppInit {
public:
    /**
     * @brief       Default constructor loads grepster's configuration from file and populates the configuration structure with its settings.
     */
    CAppInit();

    /**
     * Note: The order in which configuration settings are written to file must not be changed. This processing order is hard-coded.
     * @brief       Writes XML data to file from any configuration changes.
     */
    void WriteXMLData();

    /**
     * @brief       Query successful loading of configuration.
     * @retval      bool Returns true if XML configuration loaded successfully.
     */
    bool Success() { return m_bConfigurationLoadedSuccessfully; }

    /**
     * @brief       Query administrator's username.
     * @retval      wxString This is the administrator's username credential.
     */
    wxString Username() { return m_pAdministrator->Username(); }
    /**
     * @brief       Query administrator's password.
     * @retval      wxString This is the administrator's default password stored as plaintext in memory only.
     */
    wxString Password() { return m_pAdministrator->Password(); }

    /**
     * @brief       Query the path to PuTTY and its SSH/SFTP tools.
     * @retval      wxString This is the current configuration's path to PuTTY.
     */
    wxString PathToPuTTY() { return m_szPathToPuTTY; }

    /**
     * @brief       Change the administrator's credentials.
     * @param[in]   username The administrator's new username.
     * @param[in]   password The administrator's new password.
     */
    void ChangeCredentials(wxString username, wxString password) { m_pAdministrator->ChangeCredentials(username, password); }

    /**
     * @brief       Change the path grepster uses to access PuTTY and its tools.
     * @param[in]   path The new directory path to PuTTY.
     */
    void ChangePathToPuTTY(wxString path);

    bool bToggleFloating;

private:
    CAdminAccount*      m_pAdministrator;

    pugi::xml_document  m_XMLFile;
    pugi::xml_node      m_XMLSettings;

    wxString            m_szPathToPuTTY;

    bool m_bConfigurationLoadedSuccessfully;

    /**
     * Note: The order in which elements are parsed and settings applied must not be changed. This processing order is hard-coded.
     * @brief       Reads XML data from file and applies its values to this class's members.
     */
    void ApplyXMLData();
    /**
     * @brief       Write's grepster's default admin configuration file.
     */
    void WriteDefaultAdminConfiguration();
};

#endif // _CAPPINIT_H_
