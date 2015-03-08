/**
 * @file    CAppFrame.h
 * @author  Allen Vanderlinde
 * @date    November 2, 2014
 * @brief   wxWidgets frame object which houses grepster.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CAPPFRAME_H_
#define _CAPPFRAME_H_

#include "CAppMenubar.h"


#define FRAME_WIDTH                     1024
#define FRAME_HEIGHT                    680

#define BG_COLOR                        "#e1e6f6"

#define WXCOLOR_LT_BLUE                 wxColor(143,163,174)
#define WXCOLOR_DK_BLUE                 wxColor(104,129,142)

#define STATUSBAR_WELCOME               "Can we grep yet, user?"
#define STATUSBAR_NOTE_WIDTH            120

#define ABOUT_INFORMATION               "Written by Allen Vanderlinde, 2014-2015.\nLicensed under the GNU GPL version 3.\n\nInspired by Socrates Maura's ZGREP-UTILITY.\n\ngrepster allows System Administrators immediate and dynamic access to client servers for grepping various logs en masse.\n\ngrepster may not be sold commercially and all source code is the intellectual property of Allen Vanderlinde. The source code may be used for educational purposes and/or re-purposed with the explicit understanding that the same license will be used. Read LICENSE.txt for details.\n\nPuTTY and its companion tools are copyright 1997-2013 Simon Tatham."

#define DIALOG_ID_CHANGE_CREDENTIALS    2000
#define DIALOG_ID_SET_PATH_PUTTY        3000


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
    CAppFrame(const wxString& title, const wxPoint& position, const wxSize& size);
    /**
     * @brief       Default class destructor.
     */
    ~CAppFrame();

private:
    CAppMenubar*    m_pMenubar;

    wxStatusBar*    m_pStatusbar;
    wxAuiManager*   m_pAui;

    /**
     * @brief       Refreshes grepster's configuration when any change is made to update user's interface.
     */
    void RefreshConfiguration();
    /**
     * @brief       Create new administrator XML configuration file. This will ask for the new admin's username only.
     *              Passwords will need to be entered with each new session.
     */
    void CreateAdminXMLConfiguration();

    /**
     * @brief       Change the administrator's default credentials.
     */
    void ChangeDefaultCredentials(wxCommandEvent& event);

    /**
     * @brief       Launch PuTTY from within grepster.
     */
    void LaunchPuTTY(wxCommandEvent& event);

    /**
     * @brief       Set grepster's default path to PuTTY.
     */
    void SetPathToPuTTY(wxCommandEvent& event);
    /**
     * @brief       Toggle floating controls for user's current session and configuration.
     */
    void ToggleFloating(wxCommandEvent& event);

    /**
     * @brief       Display simple about dialog box.
     */
    void OnAbout(wxCommandEvent& event);
    /**
     * @brief       Close the primary frame.
     */
    void CloseFrame(wxCommandEvent& event);
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
