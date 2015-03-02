/**
 * @file    CAppFrame.cpp
 * @author  Allen Vanderlinde
 * @date    November 2, 2014
 * @brief   wxWidgets frame object methods.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../grepster.h"
#include "../resources/grepster_rc.h"

#include <wx/aui/dockart.h>

#include "CAppFrame.h"

#include <iostream>
using namespace std;


/* grepster's primary frame's event handler calls. */
wxBEGIN_EVENT_TABLE(CAppFrame, wxFrame)
    //EVT_MENU(MENU_FUNCTION_ID_FILE_NEW_JOB, //CAppFrame::ChangeDefaultCredentials)
    EVT_MENU(MENU_FUNCTION_ID_SESSION_DEFAULT_CREDENTIALS, CAppFrame::ChangeDefaultCredentials)
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
    m_pMenubar = new CAppMenubar;
    SetMenuBar(m_pMenubar);

    /* Configure and initialize status bar. */
    int iPaneWidths[]   =   { wxDefaultSize.GetWidth(), STATUSBAR_NOTE_WIDTH };
    m_pStatusbar = new wxStatusBar(this);
    m_pStatusbar->SetFieldsCount((sizeof(iPaneWidths) / sizeof(int)), iPaneWidths);
    SetStatusBar(m_pStatusbar);
    SetStatusText(STATUSBAR_WELCOME);

    /* Create and initialize primary frame controls. */
    Console = new CConsole(this);
    ServerStacks = new CServerStacks(this);
    GrepNotebook = new CGrepNotebook(this);
    GrepNotebook->OpenWelcomePage();

    /* Create wxWidgets AUI object for managing frame controls. */
    m_pAui = new wxAuiManager(this);
    // Set AUI flags for display
    m_pAui->SetFlags(wxAUI_MGR_ALLOW_ACTIVE_PANE | wxAUI_MGR_LIVE_RESIZE | wxAUI_MGR_ALLOW_FLOATING | wxAUI_MGR_VENETIAN_BLINDS_HINT);

    m_pAui->AddPane(Console, Console->getPaneInfo());
    m_pAui->AddPane(ServerStacks, ServerStacks->getPaneInfo());
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
    CAppFrame::ChangeDefaultCredentials
*/
void CAppFrame::ChangeDefaultCredentials(wxCommandEvent& event) {
    CDialogChangeCredentials* Dialog = new CDialogChangeCredentials(this);
    if(Dialog->ShowModal() == BUTTON_OK)
        Dialog->Destroy();
}

/*
    CAppFrame::ToggleFloating
*/
void CAppFrame::ToggleFloating(wxCommandEvent& event) {
    (Configuration->bToggleFloating) ? Configuration->bToggleFloating = false : Configuration->bToggleFloating = true;

    /* Refresh grepster's configuration to reflect local changes. */
    RefreshConfiguration();
    Configuration->WriteXMLData();
}

/*
    CAppFrame::LaunchPuTTY
*/
void CAppFrame::LaunchPuTTY(wxCommandEvent& event ) {
    HANDLE hPSFTP_Read, hPSFTP_Write;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    /* Build handle to child process to capture stdout from. */
    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = true;
    sa.lpSecurityDescriptor = NULL;

    /* Create pipe to child process. */
    if(!CreatePipe(&hPSFTP_Read, &hPSFTP_Write, &sa, 0)) {
        wxMessageBox("Unable to create pipe!", "Error", wxOK | wxICON_EXCLAMATION);
    } else if(!SetHandleInformation(hPSFTP_Read, HANDLE_FLAG_INHERIT, 0)) {
        wxMessageBox("Unable to set handle information!", "Error", wxOK | wxICON_EXCLAMATION);
    }

    /* Build the command line arguments string. */
    wxString szArgs(L"psftp.exe "); // Build new string to use as arguments list
    wxString szScriptPath(L"\"C:\\grepster\\user\\scripts\\script1.grep\""); // Call a user-saved grepster script to run on the server
    szArgs += Configuration->Username() + L"@" + L"172.24.52.150" + L" -pw " + Configuration->Password() + L" -b " + szScriptPath;


    // REPLACE THE BELOW STRING LITERAL WITH WITH SAVED PATH TO PSFTP.EXE IN XML CONFIG, ALONG WITH PUTTY.EXE AND PLINK.EXE
    // CREATE A SETTING IN XML CONFIG, TOO, THAT IS THE STARTING DIRECTORY FOR GREPSTER FOR LOADING SCRIPTS
    // ^^^^^BE ABLE TO EDIT THE ABOVE AS A GUI setting

    LPCWSTR pszPath = L"C:\\Program Files (x86)\\PuTTY\\psftp.exe";    // Path to psftp.exe which extends secured FTP downloading capabilities to grepster
    //LPWSTR pszArgs = L"psftp.exe avanderlinde@172.24.52.150 -pw Coolsolid9 -b \"C:\\grepster\\user\\scripts\\script1.grep\"";


    /* Execute child process and establish link to its handle to capture stdout. */

    ZeroMemory(&si, sizeof(STARTUPINFO));
    ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
    si.cb = sizeof(STARTUPINFO);
    si.hStdOutput = hPSFTP_Write;
    si.dwFlags |= STARTF_USESTDHANDLES;

    CreateProcessW(pszPath,
                   szArgs.wchar_str(),
                   NULL,
                   NULL,
                   true,
                   CREATE_NO_WINDOW,
                   NULL,
                   NULL,
                   &si,
                   &pi);
    CloseHandle(hPSFTP_Write);


    /* Read from child process's stdout. */
    DWORD dwRead;
    CHAR chBuf[4096];
    bool bSuccess = false;
    std::string out = "";

    for(;;) {
        bSuccess = ReadFile(hPSFTP_Read, chBuf, 4096, &dwRead, NULL);
        if(!bSuccess || dwRead == 0) break;

        std:string s(chBuf, dwRead);
        *Console << "\n\npsftp.exe:\n" << s;
        out += s;
    }
    //*Console << "psftp: \n" << out;

    /* */


    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    /* *** TRY READCONSOLEOUTPUT HERE AND print to CONSOLE to see what it grabs. Trying to be able to report to user when external processes succeed/fail. *** ^^^ ++ */
    /*
    bool move_rect(
    int x,     int y,
    int new_x, int new_y,
    int width, int height
    ) {
    HANDLE     hStdOut      = GetStdHandle( STD_OUTPUT_HANDLE );
    PCHAR_INFO buffer       = new CHAR_INFO[ width * height ];
    COORD      buffer_size  = { width, height };
    COORD      buffer_index = { 0, 0 };  // read/write rectangle has upper-right corner at upper-right corner of buffer
    SMALL_RECT read_rect    = { x,     y,     x     + width - 1, y     + height - 1 };
    SMALL_RECT write_rect   = { new_x, new_y, new_x + width - 1, new_y + height - 1 };

    bool result = ReadConsoleOutput(  hStdOut, buffer, buffer_size, buffer_index, &read_rect )
        && WriteConsoleOutput( hStdOut, buffer, buffer_size, buffer_index, &write_rect );

    delete [] buffer;

    return result;
    }
    */
}

/*
    CAppFrame::RefreshConfiguration
*/
void CAppFrame::RefreshConfiguration() {
    // Floating controls
    m_pAui->GetPane(Console).Floatable(Configuration->bToggleFloating);
    m_pAui->GetPane(ServerStacks).Floatable(Configuration->bToggleFloating);
    m_pAui->GetPane(GrepNotebook).Floatable(Configuration->bToggleFloating);
}

/*
    CAppFrame::OnAbout
*/
void CAppFrame::OnAbout(wxCommandEvent& event) {
    /* Dialog's main controls and sizers. */
    wxDialog* Dialog = new wxDialog(this, wxID_ANY, g_szFrameTitle, wxDefaultPosition, wxSize(400, 374));
    wxBoxSizer* dialogSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* dialogStaticSizer = new wxStaticBoxSizer(wxVERTICAL, Dialog, L"About " + g_szFrameTitle);

    wxStaticBitmap* bannerImg = new wxStaticBitmap(Dialog, wxID_ANY, wxBitmap(RESOURCE_ID_TO_STRING(RESID_PNG_ABOUT), wxBITMAP_TYPE_PNG_RESOURCE), wxDefaultPosition, wxDefaultSize);
    wxTextCtrl* textAbout = new wxTextCtrl(Dialog, wxID_ANY, ABOUT_INFORMATION, wxDefaultPosition, wxSize(wxDefaultSize.GetWidth(), 120), wxTE_MULTILINE | wxTE_READONLY);

    /* Dialog's buttons. */
    wxButton* pButtonOK = new wxButton(Dialog, wxID_OK, L"OK", wxPoint(0, 0), wxDefaultSize);
    pButtonOK->SetDefault();

    /* Arrange dialog's controls. */
    dialogStaticSizer->Add(textAbout, wxSizerFlags().Expand().Center().Border(wxALL, 5));
    dialogSizer->Add(bannerImg, 0);
    dialogSizer->Add(dialogStaticSizer, wxSizerFlags().Center().Expand().Border(wxALL, 5));
    dialogSizer->Add(pButtonOK, wxSizerFlags().Center());

    Dialog->SetSizer(dialogSizer);
    Dialog->Center();
    if(Dialog->ShowModal() == wxID_OK)
        Dialog->Destroy();
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
    /* NOTE: Do not call wxFrame::Close() here! It's called before CAppInit::WriteXMLData() is called. */
}
