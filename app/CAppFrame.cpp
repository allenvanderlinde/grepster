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

#include "../precomp.h"

#include "../resources/grepster_rc.h"

#include "CAppFrame.h"

#include "../dialogs/CDialogChangeCredentials.h"
#include "../dialogs/CDialogSetPathToTools.h"

using namespace std;


/* grepster's primary frame's event handler calls. */
wxBEGIN_EVENT_TABLE(CAppFrame, wxFrame)
    //EVT_MENU(MENU_FUNCTION_ID_FILE_NEW_JOB, //CAppFrame::ChangeDefaultCredentials)
    EVT_MENU(MENU_FUNCTION_ID_FILE_QUIT, CAppFrame::CloseFrame)
    EVT_MENU(MENU_FUNCTION_ID_TOOLS_LAUNCH_PUTTY, CAppFrame::LaunchPuTTY)
    EVT_MENU(MENU_FUNCTION_ID_SESSION_DEFAULT_CREDENTIALS, CAppFrame::ChangeDefaultCredentials)
    EVT_MENU(MENU_FUNCTION_ID_OPTIONS_SET_PATH_TOOLS, CAppFrame::SetPathToTools)
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
    wxMessageBox(Configuration->SSHTool() + " and " + Configuration->SFTPTool(), "ssh-tool", wxOK);

    CDialogChangeCredentials* Dialog = new CDialogChangeCredentials(this, {L"Administrator Credentials", 300, 256});
    if(Dialog->ShowModal() == Dialog->BUTTON_OK)
        Dialog->Destroy();
}

/*
    CAppFrame::LaunchPuTTY
*/
void CAppFrame::LaunchPuTTY(wxCommandEvent& event ) {
    wxString szArgs(L"plink "); // Build new string to use as arguments list
    wxString szScriptPath(L"\"C:\\grepster\\user\\scripts\\grep-test.txt\""); // Call a user-saved grepster script to run on the server

    std::thread t;


    szArgs += "-ssh avanderlinde@172.24.52.150 -pw " + Configuration->Password() + " -m " + szScriptPath;

    Console->BlueText();
    *Console << L"\n\nRunning command...\n" + Configuration->Username() + L"@grepster> ";
    Console->BlackText();
    *Console << Configuration->PathToSSHTool() + L"\n\n";

    wxString szOutput;

    szOutput = SpawnAndRun(Configuration->PathToSSHTool(), szArgs);
    *Console << L"\nFinished.";


    Console->BlueText();
    *Console << L"\n\nRunning command...\n" + Configuration->Username() + L"@grepster> ";
    Console->BlackText();
    *Console << Configuration->PathToSFTPTool() + L"\n\n";

    wxString szArgsDownload(L"psftp " + Configuration->Username() + L"@172.24.52.150" + L" -pw " + Configuration->Password() + L" -b \"C:\\grepster\\user\\scripts\\grep-test-dl.txt\"");
    szOutput = SpawnAndRun(Configuration->PathToSFTPTool(), szArgsDownload);
    *Console << L"\nFinished.";
}

/*
    CAppFrame::SetPathToTools
*/
void CAppFrame::SetPathToTools(wxCommandEvent& event) {
    CDialogSetPathToTools* Dialog = new CDialogSetPathToTools(this, {L"Path to SSH/SFTP Tools", 300, 282});
    if(Dialog->ShowModal() == Dialog->BUTTON_OK)
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
    wxDialog* Dialog = new wxDialog(this, wxID_ANY, g_szFrameTitle, wxDefaultPosition, wxSize(400, 372));
    Dialog->SetIcon(wxICON(aaaaappicon));
    wxBoxSizer* dialogSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* dialogStaticSizer = new wxStaticBoxSizer(wxVERTICAL, Dialog, L"About " + g_szFrameTitle);

    wxStaticBitmap* bannerImg = new wxStaticBitmap(Dialog, wxID_ANY, wxBitmap(RESOURCE_ID_TO_STRING(RESID_PNG_ABOUT), wxBITMAP_TYPE_PNG_RESOURCE), wxDefaultPosition, wxDefaultSize);
    wxTextCtrl* textAbout = new wxTextCtrl(Dialog, wxID_ANY, ABOUT_INFORMATION, wxDefaultPosition, wxSize(wxDefaultSize.GetWidth(), 120), wxTE_MULTILINE | wxTE_READONLY);

    /* Dialog's buttons. */
    wxButton* pButtonOK = new wxButton(Dialog, wxID_OK, L"OK", wxDefaultPosition, wxDefaultSize);
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
