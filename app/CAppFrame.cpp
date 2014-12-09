/**
 * @file    CAppFrame.cpp
 * @author  Allen Vanderlinde
 * @date    November 2, 2014
 * @brief   wxWidgets frame object methods.
 */
/*
    Copyright (C) 2014 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../grepster.h"
#include "../resources/grepster_rc.h"

#include "CAppFrame.h"

#include <wx/aui/dockart.h>

/** grepster's primary frame's event handler calls. */
wxBEGIN_EVENT_TABLE(CAppFrame, wxFrame)
    EVT_MENU(MENU_FUNCTION_ID_FILE_NEW, CAppFrame::NewAdministratorAccount)
    EVT_MENU(MENU_FUNCTION_ID_FILE_QUIT, CAppFrame::CloseFrame)
    EVT_MENU(MENU_FUNCTION_ID_TOOLS_LAUNCH_PUTTY, CAppFrame::LaunchPuTTY)
    EVT_MENU(MENU_FUNCTION_ID_OPTIONS_TOGGLE_FLOATABLE, CAppFrame::ToggleFloating)
    EVT_MENU(MENU_FUNCTION_ID_HELP_ABOUT, CAppFrame::OnAbout)

    EVT_CLOSE(CAppFrame::OnExit)
wxEND_EVENT_TABLE()

/*
    CAppFrame::CAppFrame
*/
CAppFrame::CAppFrame(const wxString& title, const wxPoint& position, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, position, size) {
    // Set background color
    SetBackgroundColour(BG_COLOR);

    /* Create menu bar. */
    m_pMenubar = new CFrameMenubar;
    SetMenuBar(m_pMenubar);

    /* Configure and initialize status bar. */
    int iPaneWidths[]   =   { wxDefaultSize.GetWidth(), STATUSBAR_NOTE_WIDTH };
    m_pStatusbar = new wxStatusBar(this);
    m_pStatusbar->SetFieldsCount((sizeof(iPaneWidths) / sizeof(int)), iPaneWidths);
    SetStatusBar(m_pStatusbar);
    SetStatusText(STATUSBAR_WELCOME);

    /* Create and initialize primary frame cont                                                                                                                                                                                                                                                                                                                                               rols. */
    Console = new CConsole(this);
    ServerStack = new CServerStack(this);
    GrepNotebook = new CGrepNotebook(this);
    GrepNotebook->OpenWelcomePage();

    /* Create wxWidgets AUI object for managing frame controls. */
    m_pAui = new wxAuiManager(this);
    // Set AUI flags for display
    m_pAui->SetFlags(wxAUI_MGR_ALLOW_ACTIVE_PANE | wxAUI_MGR_LIVE_RESIZE | wxAUI_MGR_ALLOW_FLOATING | wxAUI_MGR_VENETIAN_BLINDS_HINT);

    m_pAui->AddPane(Console, Console->getPaneInfo());
    m_pAui->AddPane(ServerStack, ServerStack->getPaneInfo());
    m_pAui->AddPane(GrepNotebook, GrepNotebook->getPaneInfo());

    // Set pane colors for controls
    wxAuiDockArt* art = m_pAui->GetArtProvider();
    art->SetColour(wxAUI_DOCKART_ACTIVE_CAPTION_COLOUR, WXCOLOR_LT_BLUE);
    art->SetColour(wxAUI_DOCKART_ACTIVE_CAPTION_GRADIENT_COLOUR, WXCOLOR_DK_BLUE);
    art->SetColour(wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR, WXCOLOR_LT_BLUE);
    art->SetColour(wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR, WXCOLOR_DK_BLUE);

    m_pAui->Update();

    /* Set grepster's initial configuration. */
    RefreshConfiguration();
}

/*
    CAppFrame::~CAppFrame
*/
CAppFrame::~CAppFrame() {
    m_pAui->UnInit();
}

/*
    CAppFrame::NewAdministratorAccount
*/
void CAppFrame::NewAdministratorAccount(wxCommandEvent& event) {
    wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    GrepNotebook->AddPage(panel, "New Admin Account");
    /* Update notebook's page count. */
    size_t nNewPageIndex = GrepNotebook->GetPageCount();
    GrepNotebook->SetSelection(nNewPageIndex - 1);
}

/*
    CAppFrame::ToggleFloating
*/
void CAppFrame::ToggleFloating(wxCommandEvent& event) {
    (Configuration->bToggleFloating) ? Configuration->bToggleFloating = false : Configuration->bToggleFloating = true;

    /* Refresh grepster's configuration to reflect local changes. */
    RefreshConfiguration();
}

/*
    CAppFrame::TestPutty
*/
void CAppFrame::LaunchPuTTY(wxCommandEvent& event ) {
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

/*
    CAppFrame::RefreshConfiguration
*/
void CAppFrame::RefreshConfiguration() {
    // Floating controls
    m_pAui->GetPane(Console).Floatable(Configuration->bToggleFloating);
    m_pAui->GetPane(ServerStack).Floatable(Configuration->bToggleFloating);
    m_pAui->GetPane(GrepNotebook).Floatable(Configuration->bToggleFloating);

    /* Write configuration changes to file. */
    //Configuration->WriteXMLData();
    Console->BlueText();
    *Console << "\nConfiguration changed.";
    Console->BlackText();
}

/*
    CAppFrame::OnAbout
*/
void CAppFrame::OnAbout(wxCommandEvent& event) {
    wxDialog* dialog = new wxDialog(this, wxID_ANY, g_szFrameTitle, wxDefaultPosition, wxSize(400, 374));
    wxBoxSizer* dialog_sizer = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* dialog_static_sizer = new wxStaticBoxSizer(wxVERTICAL, dialog, "About grepster");

    wxStaticBitmap* banner = new wxStaticBitmap(dialog, wxID_ANY, wxBitmap(RESOURCE_ID_TO_STRING(RESID_PNG_ABOUT), wxBITMAP_TYPE_PNG_RESOURCE), wxDefaultPosition, wxDefaultSize);
    wxTextCtrl* about_text = new wxTextCtrl(dialog, wxID_ANY, ABOUT_INFORMATION, wxDefaultPosition, wxSize(wxDefaultSize.GetWidth(), 120), wxTE_MULTILINE | wxTE_READONLY);

    wxButton* button_ok = new wxButton(dialog, wxID_OK, "OK", wxPoint(5, 5), wxDefaultSize);
    button_ok->SetDefault();

    /* Arrange dialog's controls. */
    dialog_static_sizer->Add(about_text, wxSizerFlags().Expand().Center().Border(wxALL, 5));
    dialog_sizer->Add(banner, 0);
    dialog_sizer->Add(dialog_static_sizer, wxSizerFlags().Center().Expand().Border(wxALL, 5));
    dialog_sizer->Add(button_ok, wxSizerFlags().Center());

    dialog->SetSizer(dialog_sizer);
    dialog->Center();
    if(dialog->ShowModal() == wxID_OK)
        dialog->Destroy();
}

/*
    CAppFrame::CloseFrame
*/
void CAppFrame::CloseFrame(wxCommandEvent& event) {
    AddPendingEvent(wxCloseEvent(wxEVT_CLOSE_WINDOW, wxID_ANY));
}

/*
    CAppFrame::OnExit
*/
void CAppFrame::OnExit(wxCloseEvent& event) {
    Configuration->WriteXMLData();
    Destroy();
}
