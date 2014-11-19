/*
    Project: grepster
    File: CAppFrame.cpp

    Desc: wxWidgets frame functions.

    Date: 11/2/14
    Author: Allen Vanderlinde
*/

#include "../grepster.h"

#include "CAppEntry.h"
#include "CAppFrame.h"

/*  wxWidgets frame event table. */
wxBEGIN_EVENT_TABLE(CAppFrame, wxFrame)
    EVT_MENU(MENU_FUNCTION_ID_FILE_QUIT, CAppFrame::OnExit)
    EVT_MENU(MENU_FUNCTION_ID_HELP_ABOUT, CAppFrame::OnAbout)

    EVT_BUTTON(ButtonID_Grep, CAppFrame::TestPutty)
wxEND_EVENT_TABLE()

/*  CAppFrame::CAppFrame

    Desc: Constructor for frame class. */
CAppFrame::CAppFrame(const wxString& title, const wxPoint& position, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, position, size) {
    // Set background color
    SetBackgroundColour(BG_COLOR);

    /* Create menu bar. */
    m_menubar = new CFrameMenu;
    SetMenuBar(m_menubar);

    /* Configure and initialize status bar. */
    int iPaneWidths[]   =   { wxDefaultSize.GetWidth(), STATUSBAR_NOTE_WIDTH };
    m_statusbar = new wxStatusBar(this);
    m_statusbar->SetFieldsCount((sizeof(iPaneWidths) / sizeof(int)), iPaneWidths);
    SetStatusBar(m_statusbar);
    SetStatusText(STATUSBAR_WELCOME);

    /* Console control creation. */
    m_console = new wxTextCtrl(this,
                               CONSOLE_ID,
                               "grep",
                               wxDefaultPosition,
                               wxDefaultSize,
                               wxTE_MULTILINE | wxTE_RICH2 | wxTE_READONLY);  // Multi-line, rich-text text control for the console

    /* Configure console's display settings. */
    consoleInf.PaneBorder(true);
    consoleInf.BestSize(FRAME_WIDTH, CONSOLE_DEFAULT_HEIGHT);
    consoleInf.Name(CONSOLE_NAME);
    consoleInf.Caption(CONSOLE_CTRL_TITLE);
    consoleInf.CaptionVisible();
    consoleInf.Bottom();
    consoleInf.CloseButton(false);
    consoleInf.Dockable(IS_DOCKABLE);
    consoleInf.Show(true);

    /* Client list tree control creation. */
    m_client_list = new wxTreeCtrl(this,
                                   CLIENT_LIST_ID,
                                   wxDefaultPosition,
                                   wxDefaultSize,
                                   wxTR_DEFAULT_STYLE | wxTR_HIDE_ROOT);

    /* Configure console's display settings. */
    clientListInf.PaneBorder(true);
    clientListInf.BestSize(CLIENT_LIST_DEFAULT_WIDTH, FRAME_HEIGHT);
    clientListInf.Name(CLIENT_LIST_NAME);
    clientListInf.Caption(CLIENT_LIST_CTRL_TITLE);
    clientListInf.CaptionVisible();
    clientListInf.Left();
    clientListInf.CloseButton(false);
    clientListInf.Dockable(IS_DOCKABLE);
    clientListInf.Show(true);

    /* Grep notebook control creation. */
    m_grep_notebook = new wxAuiNotebook(this, GREP_NOTEBOOK_ID);

    /* Configure console's display settings. */
    grepNotebookInf.PaneBorder(true);
    //grepNotebookInf.BestSize(CLIENT_LIST_DEFAULT_WIDTH, FRAME_HEIGHT);
    grepNotebookInf.Name(GREP_NOTEBOOK_NAME);
    grepNotebookInf.Caption(GREP_NOTEBOOK_CTRL_TITLE);
    grepNotebookInf.CaptionVisible();
    grepNotebookInf.Center();
    grepNotebookInf.CloseButton(false);
    grepNotebookInf.Dockable(IS_DOCKABLE);
    grepNotebookInf.Show(true);

    /* Create wxWidgets AUI object for managing frame controls. */
    m_aui = new wxAuiManager(this);
    // Set AUI flags for display
    m_aui->SetFlags(wxAUI_MGR_ALLOW_ACTIVE_PANE | wxAUI_MGR_LIVE_RESIZE);// | wxAUI_MGR_ALLOW_FLOATING | wxAUI_MGR_VENETIAN_BLINDS_HINT);

    m_aui->AddPane(m_console, consoleInf);
    m_aui->AddPane(m_client_list, clientListInf);
    m_aui->AddPane(m_grep_notebook, grepNotebookInf);

    // Set pane colors for controls
    wxAuiDockArt* art = m_aui->GetArtProvider();
    art->SetColour(wxAUI_DOCKART_ACTIVE_CAPTION_COLOUR, WXCOLOR_LT_BLUE);
    art->SetColour(wxAUI_DOCKART_ACTIVE_CAPTION_GRADIENT_COLOUR, WXCOLOR_DK_BLUE);
    art->SetColour(wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR, WXCOLOR_LT_BLUE);
    art->SetColour(wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR, WXCOLOR_DK_BLUE);

    m_aui->Update();
}

/*  CAppFrame::~CAppFrame

    Desc: Destructor for frame class. */
CAppFrame::~CAppFrame() {
    m_aui->UnInit();
}

/*  CAppFrame::TestPutty */
void CAppFrame::TestPutty(wxCommandEvent& event ) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    LPCWSTR path = L"C:\\Program Files (x86)\\PuTTY\\putty.exe";
    LPWSTR args = L"-ssh -pw Elementbox9 avanderlinde@172.24.37.191 -m \"cmds\\zgrep.gcmd\"";
    CreateProcess(path,
                  L"",
                  NULL,
                  NULL,
                  false,
                  CREATE_NO_WINDOW,
                  NULL,
                  NULL,
                  &si,
                  &pi);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

/*  CAppFrame::OnExit

    Desc: Sends exit signal to primary frame. */
void CAppFrame::OnExit(wxCommandEvent& event) {
    Destroy();
    Close(true);
}

/*  CAppFrame::OnAbout

    Desc: Displays standard About dialog box. */
void CAppFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("PLACEHOLDER DIALOG FOR grepster about", g_Frame_Title, wxOK | wxICON_INFORMATION);
}
