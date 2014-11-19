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
#include <wx/aui/dockart.h>
#include <wx/aui/auibook.h>
#include <wx/treectrl.h>

#include "CFrameMenu.h"

/* Frame settings. */
#define FRAME_WIDTH                 960
#define FRAME_HEIGHT                600

#define FRAME_TITLE

#define CONSOLE_ID                  1000
#define CONSOLE_NAME                "the_con"
#define CONSOLE_CTRL_TITLE          "Console"
#define CONSOLE_DEFAULT_HEIGHT      140

#define CLIENT_LIST_ID              1001
#define CLIENT_LIST_NAME            "client_tree"
#define CLIENT_LIST_CTRL_TITLE      "Client List"
#define CLIENT_LIST_DEFAULT_WIDTH   200

#define GREP_NOTEBOOK_ID            1002
#define GREP_NOTEBOOK_NAME          "grepbook"
#define GREP_NOTEBOOK_CTRL_TITLE    "Grepbook"

/* Frame control visibility globals. */
#define IS_DOCKABLE                 false

#define BG_COLOR                    "#e1e6f6"
#define BUTTON_BG_COLOR             "#566275"

#define WXCOLOR_LT_BLUE             wxColor(174,188,225)
#define WXCOLOR_DK_BLUE             wxColor(112,146,190)
#define WXCOLOR_INACTIVE            wxColor(225,230,246)

/* Button IDs. */
enum {
    ButtonID_Grep = 0
};

/* Status bar settings. */
#define STATUSBAR_WELCOME           "Can we grep yet, user?"
#define STATUSBAR_NOTE_WIDTH        120  // Width of right-most status bar pane width for notes

/*  CAppFrame

    Desc: wxWidgets frame class definition. */
class CAppFrame : public wxFrame {
public:
    CAppFrame(const wxString& title, const wxPoint& position, const wxSize& size);
    ~CAppFrame();

private:
    // Menu bar
    CFrameMenu* m_menubar;
    // Status bar
    wxStatusBar* m_statusbar;
    // Console
    wxTextCtrl* m_console;
    // Client list tree control
    wxTreeCtrl* m_client_list;
    // Grep notebook
    wxAuiNotebook* m_grep_notebook;

    // wxWidgets Advanced UI Manager
    wxAuiManager* m_aui;

    // AUI info structures
    wxAuiPaneInfo consoleInf;
    wxAuiPaneInfo clientListInf;
    wxAuiPaneInfo grepNotebookInf;

    void TestPutty(wxCommandEvent& event);

    void OnAbout(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif
