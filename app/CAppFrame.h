/*
    Project: grepster
    File: CAppFrame.h

    Desc: wxWidgets frame classes.

    Date: 11/2/14
    Author: Allen Vanderlinde
*/

#ifndef _CAPPFRAME_H_
#define _CAPPFRAME_H_

#include <wx/wx.h>
#include <wx/aui/framemanager.h>

#include <wx/aui/auibook.h>

#include "../grepster.h"
#include "CFrameMenubar.h"

/* Frame settings. */
#define FRAME_WIDTH                 960
#define FRAME_HEIGHT                600

#define BG_COLOR                    "#e1e6f6"
#define BUTTON_BG_COLOR             "#566275"

#define WXCOLOR_LT_BLUE             wxColor(143,163,174)
#define WXCOLOR_DK_BLUE             wxColor(104,129,142)
//#define WXCOLOR_INACTIVE            wxColor(225,230,246)

/* Status bar settings. */
#define STATUSBAR_WELCOME           "Can we grep yet, user?"
#define STATUSBAR_NOTE_WIDTH        120  // Width of right-most status bar pane width for notes

/* About dialog information text. */
#define ABOUT_INFORMATION           "Written by Allen Vanderlinde, 2014.\nLicensed under the GNU GPL version 3.\n\nInspired by Socrates Maura's ZGREP-UTILITY.\n\ngrepster allows Blackboard TSMs immediate and dynamic access to client servers for grepping various logs en masse.\n\ngrepster may not be sold commercially and all source code is the intellectual property of Allen Vanderlinde. The source code may be used for educational purposes and/or re-purposed with the explicit understanding that the same license will be used. Read LICENSE.txt for details.\n\nPuTTY and its companion tools are copyright 1997-2013 Simon Tatham."

/* Floating controls toggle. */
static bool isFloating = USE_FLOATABLE;

/* Button IDs. */
enum e_ButtonIDs {
};

/*  CAppFrame

    Desc: wxWidgets frame class definition. */
class CAppFrame : public wxFrame {
public:
    CAppFrame(const wxString& title, const wxPoint& position, const wxSize& size);
    ~CAppFrame();

private:
    // Menu bar
    CFrameMenubar* m_menubar;
    // Status bar
    wxStatusBar* m_statusbar;

    // wxWidgets Advanced UI Manager
    wxAuiManager* m_aui;

    /* Control command functions. */
    void ToggleFloating(wxCommandEvent& event);

    /* Tools functions */
    void LaunchPuTTY(wxCommandEvent& event);

    /* Standard frame functions. */
    void OnAbout(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif
