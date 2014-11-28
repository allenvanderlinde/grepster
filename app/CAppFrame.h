/**
 * @file    CAppFrame.h
 * @author  Allen Vanderlinde
 * @date    November 2, 2014
 * @brief   wxWidgets frame object which houses grepster.
 */
/*
    Copyright (C) 2014 by Allen Vanderlinde.
    Songbird and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CAPPFRAME_H_
#define _CAPPFRAME_H_

#include "CFrameMenubar.h"

#include <wx/wx.h>
#include <wx/aui/framemanager.h>

#include <wx/aui/auibook.h>

/** Frame width (pixels). */
#define FRAME_WIDTH                 1024
/** Frame height (pixels). */
#define FRAME_HEIGHT                680

/** Default frame background color. */
#define BG_COLOR                    "#e1e6f6"

/** wxWidgets color: light blue. */
#define WXCOLOR_LT_BLUE             wxColor(143,163,174)
/** wxWidgets color: dark blue. */
#define WXCOLOR_DK_BLUE             wxColor(104,129,142)

/** Status bar welcome label. */
#define STATUSBAR_WELCOME           "Can we grep yet, user?"
/** Width of the status bar note pane (pixels). */
#define STATUSBAR_NOTE_WIDTH        120

/** About grepster information string. */
#define ABOUT_INFORMATION           "Written by Allen Vanderlinde, 2014.\nLicensed under the GNU GPL version 3.\n\nInspired by Socrates Maura's ZGREP-UTILITY.\n\ngrepster allows System Administrators immediate and dynamic access to client servers for grepping various logs en masse.\n\ngrepster may not be sold commercially and all source code is the intellectual property of Allen Vanderlinde. The source code may be used for educational purposes and/or re-purposed with the explicit understanding that the same license will be used. Read LICENSE.txt for details.\n\nPuTTY and its companion tools are copyright 1997-2013 Simon Tatham."

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
    /** Frame's menu bar. */
    CFrameMenubar* m_menubar;
    /** Frame's status bar. */
    wxStatusBar* m_statusbar;

    /** wxWidgets Advanced UI Manager. */
    wxAuiManager* m_aui;

    /**
     * @brief       Refreshes grepster's configuration when any change is made to update user's interface.
     */
    void RefreshConfiguration();

    /* Options menu methods. */
    /**
     * @brief       Toggle floating controls for user's current session and configuration.
     */
    void ToggleFloating(wxCommandEvent& event);

    /* Tools menu methods. */
    /**
     * @brief       Launch PuTTY from within grepster.
     */
    void LaunchPuTTY(wxCommandEvent& event);

    /* Standard frame functions. */
    /**
     * @brief       Display simple about dialog box.
     */
    void OnAbout(wxCommandEvent& event);
    /**
     * @brief       Exit grepster.
     */
    void OnExit(wxCommandEvent& event);

    /**
     * @brief       Initialize and call the primary frame's event handler.
     */
    wxDECLARE_EVENT_TABLE();
};

#endif
