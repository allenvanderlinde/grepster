/**
 * @file    CAppInit.h
 * @author  Allen Vanderlinde
 * @date    November 27, 2014
 * @brief   This object loads grepster's configuration from the Windows registry.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CAPPINIT_H_
#define _CAPPINIT_H_

#include "../../session/CAdminAccount.h"


/* Configuration definitions. */
#define CONFIG_LABEL_FRAME_WIDTH            "width"
#define CONFIG_LABEL_FRAME_HEIGHT           "height"
/* NOTE:
    NEED TO WRITE LABELS FOR MAXIMIZED
    CONSOLE WIDTH, HEIGHT
    SERVER STACKS WIDTH, HEIGHT
    ARRANGEMENT OF CONTROLS.
    */
#define CONFIG_LABEL_USERNAME               "username"
#define CONFIG_LABEL_PATH_SSH_TOOL          "pathssh"
#define CONFIG_LABEL_PATH_SFTP_TOOL         "pathsftp"
#define CONFIG_LABEL_TOGGLE_FLOATING        "togglefloating"


/**
 * This object reads grepster's configuration from the Windows registry and populates
 * its members with its values.
 *
 * @class   CAppInit
 * @brief   Class definition for grepster's configuration.
 */
class CAppInit : public wxConfig {
public:
    /**
     * @brief       Default constructor loads grepster's configuration from registry.
     * @param[in]   label Label for grepster's configuration in Windows registry.
     */
    CAppInit(wxString label);

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
     * @brief       Query the path to the SSH tool.
     * @retval      wxString This is the path to grepster's SSH tool.
     */
    wxString PathToSSHTool() { return m_szPathToSSHTool; }
    /**
     * @brief       Query the path to the SFTP tool.
     * @retval      wxString This is the path to grepster's SFTP tool.
     */
    wxString PathToSFTPTool() { return m_szPathToSFTPTool; }
    /**
     * @brief       Splits the SSH tool path string and returns only the tool's name.
     * @retval      wxString This is the name of the SSH tool grepster uses.
     */
    wxString SSHTool();
    /**
     * @brief       Splits the SFTP tool path string and returns only the tool's name.
     * @retval      wxString This is the name of the SFTP tool grepster uses.
     */
    wxString SFTPTool();

    /**
     * @brief       Change the administrator's credentials.
     * @param[in]   username The administrator's new username.
     * @param[in]   password The administrator's new password.
     */
    void ChangeCredentials(wxString username,
                           wxString password) { m_pAdministrator->ChangeCredentials(username, password); }

    /**
     * @brief       Change the path grepster uses to its SSH/SFTP tools.
     * @param[in]   sshPath The path to the SSH tool grepster will use.
     * @param[in]   sftpPath The path to the SFTP tool grepster will use.
     */
    void ChangePathToTools(wxString sshPath,
                           wxString sftpPath) { m_szPathToSSHTool = sshPath; m_szPathToSFTPTool = sftpPath; }

    /**
     * @brief       Find out if grepster's controls are currently set to float.
     * @retval      bool True if grepster's controls are currently set to float.
     */
    bool Floating() { return m_bToggleFloating; }
    /**
     * @brief       Set grepster's controls to float or to be fixed.
     * @param[in]   floating Allows the user to set grepster's controls to float (true)
     *              or to be fixed (false). */
    void Floating(bool floating) { m_bToggleFloating = floating; }

private:
    /** @brief      Object which stores all the user's administrator information. */
    CAdminAccount*      m_pAdministrator;

    /**
     * @brief       Fully-qualified path to grepster's SSH tool.
     */
    wxString            m_szPathToSSHTool;
    /**
     * @brief       Fully-qualified path to grepster's SFTP tool.
     */
    wxString            m_szPathToSFTPTool;
    /**
     * @brief       String holding the actual name of the SSH executable.
     */
    wxString            m_szSSHTool;
    /**
     * @brief       String holding the actual name of the SFTP executable.
     */
    wxString            m_szSFTPTool;

    /** @brief      Toggle floating controls. */
    bool m_bToggleFloating;
};

#endif // _CAPPINIT_H_
