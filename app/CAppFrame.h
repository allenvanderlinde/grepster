/**
 * @file    CAppFrame.h
 * @author  Allen Vanderlinde
 * @date    November 2, 2014
 * @brief   wxWidgets frame object which houses grepster.
 */
/*
    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CAPPFRAME_H_
#define _CAPPFRAME_H_

#include "menubar/CAppMenubar.h"

#define DEFAULT_FRAME_WIDTH             1280
#define DEFAULT_FRAME_HEIGHT            800

#define BG_COLOR                        "#e1e6f6"

#define WXCOLOR_LT_BLUE                 wxColor(143,163,174)
#define WXCOLOR_DK_BLUE                 wxColor(104,129,142)

#define STATUSBAR_WELCOME               L"Can we grep yet, user?"
#define STATUSBAR_NOTE_WIDTH            120

#define ABOUT_INFORMATION               L"Written by Allen Vanderlinde, 2014-2015.\nLicensed under the GNU GPL version 3 license.\n\nInspired by Socrates Maura's ZGREP-UTILITY.\n\ngrepster acts as an interface to SSH and SFTP tools for system administrators to easily grep logs and execute remote commands from a centralized utility.\n\nThe source code may be used for educational purposes and/or re-purposed with the explicit understanding that the same license will be used. To do this, please fork grepster by visiting https://github.com/allenvanderlinde/grepster. Read LICENSE.txt for details."

#define DEFAULT_SERVER_STACKS_PATH      L"\\stacks\\"


/**
 * This object creates a wxWidgets frame which houses the grepster application.
 *
 * @class   CAppFrame
 * @brief   Class definition for grepster's primary frame.
 */
class CAppFrame : public wxFrame {
public:
    /**
     * @brief       Default constructor which creates grepster's primary frame.
     * @param[in]   title Frame (window) title.
     * @param[in]   position Starting position of application.
     * @param[in]   size Starting size of frame in integer array wxSize.
     */
    CAppFrame(const wxString& title,
              const wxPoint& position,
              const wxSize& size);
    /**
     * @brief       Default class destructor. This joins all previously running threads
     *              to grepster's primary process.
     */
    ~CAppFrame();

    /**
     * @brief       Returns the CAppMenubar object of the frame.
     * @retval      CAppMenubar The primary frame's menubar object.
     */
    CAppMenubar* Menubar() { return m_pMenubar; }

    /**
     * @brief       Create and add a new server stack to the session.
     */
    void NewServerStack(wxCommandEvent& event);
    /**
     * @brief       Add one or more saved server stacks to the current session.
     */
    void AddServerStacks(wxCommandEvent &event);
    /**
     * @brief       Close all server stacks in current session.
     */
    void CloseServerStacks(wxCommandEvent& event);

    /**
     * @brief       Change the administrator's default credentials.
     */
    void ChangeDefaultCredentials(wxCommandEvent& event);

    /**
     * @brief       Save the current page in the notebook back
     *              to its original file.
     */
    void SavePage(wxCommandEvent& event);

    /**
     * @brief       Launch PuTTY from within grepster.
     */
    void LaunchPuTTY(wxCommandEvent& event);

    /**
     * @brief       Set grepster's default path to SSH/SFTP tools.
     */
    void SetPathToTools(wxCommandEvent& event);
    /**
     * @brief       Toggle floating controls for user's current session and configuration.
     */
    void ToggleFloating(wxCommandEvent& event);

    /**
     * @brief       Open grepster's welcome and updates page in a new notebook page.
     */
    void Welcome(wxCommandEvent& event);
    /**
     * @brief       Display simple about dialog box.
     */
    void OnAbout(wxCommandEvent& event);

    /**
     * @brief       Close the primary frame.
     */
    void CloseFrame(wxCommandEvent& event);

private:
    /** @brief      Thread vector for keeping tracking of process spawns. */
    std::vector<std::thread>    m_Spawns;

    /** @brief      grepster's menubar object. */
    CAppMenubar*                m_pMenubar;
    /** @brief      grepster's statusbar object. */
    wxStatusBar*                m_pStatusbar;
    /** @brief      wxWidgets' advanced UI manager. This object gives more
     *              options for widget appearance and customization. */
    wxAuiManager*               m_pAui;

    /**
     * @brief       Updates grepster's controls after configuration changes.
     */
    void UpdateControls();

    /**
     * @brief       Check to see if a menu's items should be activated.
     */
    void CheckMenu(wxMenuEvent& event);

    /**
     * @brief       Exit grepster.
     */
    void OnExit(wxCloseEvent& event);

    /**
     * @brief       Initialize and call the primary frame's event handler.
     */
    wxDECLARE_EVENT_TABLE();
};

#endif
