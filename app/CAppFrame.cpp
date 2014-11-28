/**
 * @file    CAppFrame.cpp
 * @author  Allen Vanderlinde
 * @date    November 2, 2014
 * @brief   wxWidgets frame object methods.
 */
/*
    Copyright (C) 2014 by Allen Vanderlinde.
    Songbird and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../grepster.h"
#include "../resources/grepster_rc.h"

#include "CAppFrame.h"

#include <wx/aui/dockart.h>

/** grepster's primary frame's event handler calls. */
wxBEGIN_EVENT_TABLE(CAppFrame, wxFrame)
    EVT_MENU(MENU_FUNCTION_ID_FILE_QUIT, CAppFrame::OnExit)
    EVT_MENU(MENU_FUNCTION_ID_TOOLS_LAUNCH_PUTTY, CAppFrame::LaunchPuTTY)
    EVT_MENU(MENU_FUNCTION_ID_OPTIONS_TOGGLE_FLOATABLE, CAppFrame::ToggleFloating)
    EVT_MENU(MENU_FUNCTION_ID_HELP_ABOUT, CAppFrame::OnAbout)

wxEND_EVENT_TABLE()

/*
    CAppFrame::CAppFrame
*/
CAppFrame::CAppFrame(const wxString& title, const wxPoint& position, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, position, size) {
    // Set background color
    SetBackgroundColour(BG_COLOR);

    /* Create menu bar. */
    m_menubar = new CFrameMenubar;
    SetMenuBar(m_menubar);

    /* Configure and initialize status bar. */
    int iPaneWidths[]   =   { wxDefaultSize.GetWidth(), STATUSBAR_NOTE_WIDTH };
    m_statusbar = new wxStatusBar(this);
    m_statusbar->SetFieldsCount((sizeof(iPaneWidths) / sizeof(int)), iPaneWidths);
    SetStatusBar(m_statusbar);
    SetStatusText(STATUSBAR_WELCOME);

    /* Create and initialize primary frame cont                                                                                                                                                                                                                                                                                                                                               rols. */
    Console = new CConsole(this);
    ClientList = new CClientList(this);
    GrepNotebook = new CGrepNotebook(this);
    GrepNotebook->OpenWelcomePage();

    /* Create wxWidgets AUI object for managing frame controls. */
    m_aui = new wxAuiManager(this);
    // Set AUI flags for display
    m_aui->SetFlags(wxAUI_MGR_ALLOW_ACTIVE_PANE | wxAUI_MGR_LIVE_RESIZE | wxAUI_MGR_ALLOW_FLOATING | wxAUI_MGR_VENETIAN_BLINDS_HINT);

    m_aui->AddPane(Console, Console->getPaneInfo());
    m_aui->AddPane(ClientList, ClientList->getPaneInfo());
    m_aui->AddPane(GrepNotebook, GrepNotebook->getPaneInfo());

    // Set pane colors for controls
    wxAuiDockArt* art = m_aui->GetArtProvider();
    art->SetColour(wxAUI_DOCKART_ACTIVE_CAPTION_COLOUR, WXCOLOR_LT_BLUE);
    art->SetColour(wxAUI_DOCKART_ACTIVE_CAPTION_GRADIENT_COLOUR, WXCOLOR_DK_BLUE);
    art->SetColour(wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR, WXCOLOR_LT_BLUE);
    art->SetColour(wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR, WXCOLOR_DK_BLUE);

    m_aui->Update();

    /* Set grepster's initial configuration. */
    RefreshConfiguration();
}

/*
    CAppFrame::~CAppFrame
*/
CAppFrame::~CAppFrame() {
    m_aui->UnInit();
}

/*
    CAppFrame::LoadConfiguration
*/
void CAppFrame::RefreshConfiguration() {
    /* Update grepster's main controls' settings. */
    m_aui->GetPane(Console).Floatable(Configuration->bToggleFloating);
    m_aui->GetPane(ClientList).Floatable(Configuration->bToggleFloating);
    m_aui->GetPane(GrepNotebook).Floatable(Configuration->bToggleFloating);
}

/*
    CAppFrame::ToggleFloating
*/
void CAppFrame::ToggleFloating(wxCommandEvent& event) {
    if(Configuration->bToggleFloating)
        Configuration->bToggleFloating = false;
    else if(!Configuration->bToggleFloating)
        Configuration->bToggleFloating = true;

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
    CAppFrame::OnExit
*/
void CAppFrame::OnExit(wxCommandEvent& event) {
    Destroy();
    Close(true);
}

/*
    CAppFrame::OnAbout
*/
void CAppFrame::OnAbout(wxCommandEvent& event) {
    wxDialog* dialog = new wxDialog(this, wxID_ANY, g_Frame_Title, wxDefaultPosition, wxSize(400, 374));
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
