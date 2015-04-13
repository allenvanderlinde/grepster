/**
 * @file    CAppFrame.cpp
 * @author  Allen Vanderlinde
 * @date    November 2, 2014
 * @brief   wxWidgets frame object methods.
 */
/*
    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../precomp.h"

#include "../resources/grepster_rc.h"

#include "CAppFrame.h"

#include "../session/CAdminStack.h"

#include "dialogs/CDialogNewServerStack.h"
#include "dialogs/CDialogChangeCredentials.h"
#include "dialogs/CDialogSetPathToTools.h"


/* grepster's primary frame's event handler calls. */
wxBEGIN_EVENT_TABLE(CAppFrame, wxFrame)
    EVT_MENU(MENU_FUNCTION_ID_FILE_QUIT, CAppFrame::CloseFrame)
    EVT_MENU(MENU_FUNCTION_ID_SESSION_NEW_SERVER_STACK, CAppFrame::NewServerStack)
    EVT_MENU(MENU_FUNCTION_ID_SESSION_ADD_SERVER_STACKS, CAppFrame::AddServerStacks)
    EVT_MENU(MENU_FUNCTION_ID_SESSION_CLOSE_SERVER_STACKS, CAppFrame::CloseServerStacks)

    EVT_MENU(MENU_FUNCTION_ID_SESSION_DEFAULT_CREDENTIALS, CAppFrame::ChangeDefaultCredentials)

    EVT_MENU(MENU_FUNCTION_ID_TOOLS_LAUNCH_PUTTY, CAppFrame::LaunchPuTTY)

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
    /* Decide if the frame should be maximized based upon
        frame's last maximized state. */
    bool maximized;
    Configuration->Read(CONFIG_LABEL_FRAME_MAX, &maximized);
    if(maximized)
        Maximize(maximized);
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
    ServerStacks = new CServerStacks(this);
    Console = new CConsole(this);
    SessionNotebook = new CSessionNotebook(this);
    SessionNotebook->OpenWelcomePage();

    /* Create wxWidgets AUI object for managing frame controls. */
    m_pAui = new wxAuiManager(this);
    // Set AUI flags for display
    m_pAui->SetFlags(wxAUI_MGR_ALLOW_ACTIVE_PANE | wxAUI_MGR_LIVE_RESIZE | wxAUI_MGR_ALLOW_FLOATING | wxAUI_MGR_VENETIAN_BLINDS_HINT);

    m_pAui->AddPane(ServerStacks, ServerStacks->Info());
    m_pAui->AddPane(Console, Console->Info());
    m_pAui->AddPane(SessionNotebook, SessionNotebook->Info());

    // Set pane colors for controls
    wxAuiDockArt* art = m_pAui->GetArtProvider();
    art->SetColour(wxAUI_DOCKART_ACTIVE_CAPTION_COLOUR, WXCOLOR_LT_BLUE);
    art->SetColour(wxAUI_DOCKART_ACTIVE_CAPTION_GRADIENT_COLOUR, WXCOLOR_DK_BLUE);
    art->SetColour(wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR, WXCOLOR_LT_BLUE);
    art->SetColour(wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR, WXCOLOR_DK_BLUE);

    m_pAui->Update();

    /* Apply initial settings to controls. */
    UpdateControls();
}

/*
    CAppFrame::~CAppFrame
*/
CAppFrame::~CAppFrame() {
    m_pAui->UnInit();
    /* Join all threads to primary process before closing grepster. */
    for_each(m_Spawns.begin(), m_Spawns.end(), [](std::thread &t){ t.join(); });
}

/*
    CAppFrame::NewServerStack
*/
void CAppFrame::NewServerStack(wxCommandEvent& event) {
    CDialogNewServerStack* Dialog = new CDialogNewServerStack(this);
    wxString szStackName(Dialog->GetStackName());
    if(Dialog->ShowModal() == Dialog->BUTTON_SAVE) {
        /* Create a new file picker dialog to save the new
            server stack to. */
        wxFileDialog* pNewServerStack = new wxFileDialog(this,
                                                         L"New Server Stack",
                                                         DEFAULT_SERVER_STACKS_PATH,
                                                         szStackName,
                                                         L".servers files (*.servers)|*.servers",
                                                         wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
        pNewServerStack->CenterOnParent();
        if(pNewServerStack->ShowModal() == wxID_CANCEL) {
            pNewServerStack->Destroy();
            return;
        }
        /* Create new file and write server stack name
            to it. */
        wxTextFile file;
        wxString szFilePath(pNewServerStack->GetPath());
        pNewServerStack->Destroy();
        /* If the file already exists, overwrite it. */
        if(!file.Create(szFilePath)) {
            file.Open(szFilePath);
            file.Clear();
            /*If the session has at least one stack, check to see if the
                user's new stack was previously added. */
            if(!ServerStacks->GetStacks().empty()) {
                for(auto itr = ServerStacks->GetStacks().begin(); itr != ServerStacks->GetStacks().end(); ++itr) {
                    if(szFilePath.IsSameAs(itr->Name())) {
                        ServerStacks->CloseStack(itr->Name());  // Close the stack to be overwritten
                    }
                }
            }
        }
        file.AddLine(Dialog->GetStackName());
        file.Write();
        file.Close();
        /* Add the newly created stack to the control. */
        CAdminStack newStack(pNewServerStack->GetPath());
        ServerStacks->AddServerStack(newStack);
        /* Enable item(s) in Session menu. */
        m_pMenubar->GetMenu(FRAME_ID_SESSION_MENU)->Enable(MENU_FUNCTION_ID_SESSION_CLOSE_SERVER_STACKS, true);
    }
    Dialog->Destroy();
}

/*
    CAppFrame::AddServerStack
*/
void CAppFrame::AddServerStacks(wxCommandEvent& event) {
    /* Create a new file picker dialog to grab the .servers file
        to add to the current session's server stacks. Note: The file
        type is arbitrary as essentially these files are plain-text. */
    wxFileDialog* pServerStackSelect = new wxFileDialog(this,
                                                        L"Server Stack Selection",
                                                        DEFAULT_SERVER_STACKS_PATH,
                                                        L"",    // Default file
                                                        L".servers files (*.servers)|*.servers",
                                                        wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_MULTIPLE);  // File must exist to be valid
    pServerStackSelect->CenterOnParent();
    if(pServerStackSelect->ShowModal() == wxID_CANCEL)
        pServerStackSelect->Destroy();
    else {  // The user pressed OK
        wxArrayString FilePaths;
        pServerStackSelect->GetPaths(FilePaths);
        /* Check to see if the selected server stacks are already added to the session
            by doing a simple search in the current list. */
        for(auto itr = FilePaths.begin(); itr != FilePaths.end(); ++itr) {  /* Compare the current server stack list to each saved stack in file. */
            if(ServerStacks->GetStacks().empty()) {   // If the server stacks are empty, add the new stack
                CAdminStack newStack(*itr);
                ServerStacks->AddServerStack(newStack);
            }
            else {
                CAdminStack newStack(*itr); // Build stack from file
                int index = ServerStacks->FindPath(newStack.Path());
                if(index == wxNOT_FOUND)    // If the stack isn't already added to the session
                    ServerStacks->AddServerStack(newStack); // Add the new stack to the server stacks control
                else {    // Check to see if the stack should be reloaded
                    /* NOTE: Need to ask if user wants to ignore any changes to the stack already
                        in the session. */
                    if(newStack.Size() > ServerStacks->GetStacks()[index].Size()) {
                        ServerStacks->CloseStack(ServerStacks->GetStacks()[index].Name());
                        ServerStacks->AddServerStack(newStack);
                    } else {
                        *Console << L"\nStack already in session.\n";
                    }
                }
            }
        }
    }
    /* Enable item(s) in Session menu. */
    m_pMenubar->GetMenu(FRAME_ID_SESSION_MENU)->Enable(MENU_FUNCTION_ID_SESSION_CLOSE_SERVER_STACKS, true);
}

/*
    CAppFrame::CloseServerStacks
*/
void CAppFrame::CloseServerStacks(wxCommandEvent& event) {
    if(!ServerStacks->GetStacks().empty()) {    // Check to see if there are any stacks in the session
        if(wxMessageBox(L"Are you sure you want to close all the stacks in the session?",
                        L"Close Server Stacks",
                        wxICON_QUESTION | wxOK | wxCANCEL) == wxOK) {
            Console->BlueText();
            *Console << L"\nClosing all stacks in the session...\n";
            Console->BlackText();
            ServerStacks->CloseAll();
        } else return;
    }
    /* Disable item in Session menu. */
    m_pMenubar->GetMenu(FRAME_ID_SESSION_MENU)->Enable(MENU_FUNCTION_ID_SESSION_CLOSE_SERVER_STACKS, false);
}

/*
    CAppFrame::ChangeDefaultCredentials
*/
void CAppFrame::ChangeDefaultCredentials(wxCommandEvent& event) {
    CDialogChangeCredentials* Dialog = new CDialogChangeCredentials(this);
    if(Dialog->ShowModal() == Dialog->BUTTON_OK) {
        Configuration->Write(CONFIG_LABEL_USERNAME, Configuration->Username());
        Dialog->Destroy();
    }
}

/*
    CAppFrame::LaunchPuTTY
*/
void CAppFrame::LaunchPuTTY(wxCommandEvent& event ) {
    //wxString szArgs(L"plink "); // Build new string to use as arguments list
    //wxString szScriptPath(L"\"C:\\grepster\\user\\scripts\\grep-test.txt\""); // Call a user-saved grepster script to run on the server

    //szArgs += "-ssh avanderlinde@172.24.52.150 -pw " + Configuration->Password() + " -m " + szScriptPath;

    // SSH
    wxString szOutput(L""), szCommand;

    Console->BlueText();
    *Console << L"\n\nRunning script (SSH)...\n" + Configuration->Username() + L"@grepster> ";
    Console->BlackText();
    *Console << Configuration->PathToSSHTool() + L"\n\n";

    szCommand = Configuration->SSHTool() + L" -ssh " + Configuration->Username() + L"@speights.pd.local -pw " + Configuration->Password() + " -m \"C:\\grepster\\user\\scripts\\grep-test.txt\"";

    ////////
    // will need to keep track of currently available thread's index
    //
    // get current size of m_Spawns and use that to ID each thread by integer <-- should that be a struct element?
    //
    ////////
    m_Spawns.push_back(std::thread(SpawnAndRun, Configuration->PathToSSHTool(), szCommand));


    // SFTP
    Console->BlueText();
    *Console << L"\n\nRunning script (SFTP)...\n" + Configuration->Username() + L"@grepster> ";
    Console->BlackText();
    *Console << Configuration->PathToSFTPTool() + L"\n\n";

    szCommand = Configuration->SFTPTool() + L" " + Configuration->Username() + L"@speights.pd.local" + L" -pw " + Configuration->Password() + L" -b \"C:\\grepster\\user\\scripts\\grep-test-dl.txt\"";

    m_Spawns.push_back(std::thread(SpawnAndRun, Configuration->PathToSFTPTool(), szCommand));
}

/*
    CAppFrame::SetPathToTools
*/
void CAppFrame::SetPathToTools(wxCommandEvent& event) {
    CDialogSetPathToTools* Dialog = new CDialogSetPathToTools(this);
    if(Dialog->ShowModal() == Dialog->BUTTON_OK) {
        Configuration->Write(CONFIG_LABEL_PATH_SSH_TOOL, Configuration->PathToSSHTool());
        Configuration->Write(CONFIG_LABEL_PATH_SFTP_TOOL, Configuration->PathToSFTPTool());
        Dialog->Destroy();
    }
}

/*
    CAppFrame::ToggleFloating
*/
void CAppFrame::ToggleFloating(wxCommandEvent& event) {
    (Configuration->Floating()) ? Configuration->Floating(false) : Configuration->Floating(true);
    Configuration->Write(CONFIG_LABEL_TOGGLE_FLOATING, Configuration->Floating());
    /* Refresh grepster's settings to reflect local changes. */
    UpdateControls();
}

/*
    CAppFrame::UpdateControls
*/
void CAppFrame::UpdateControls() {
    // Floating controls
    m_pAui->GetPane(Console).Floatable(Configuration->Floating());
    m_pAui->GetPane(ServerStacks).Floatable(Configuration->Floating());
    m_pAui->GetPane(SessionNotebook).Floatable(Configuration->Floating());
}

/*
    CAppFrame::OnAbout
*/
void CAppFrame::OnAbout(wxCommandEvent& event) {
    /* Dialog's main controls and sizers. */
    wxDialog* Dialog = new wxDialog(this, wxID_ANY, g_szFrameTitle, wxDefaultPosition, wxDefaultSize);
    Dialog->SetIcon(wxICON(aaaaappicon));
    wxBoxSizer* pSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* pStaticSizer = new wxStaticBoxSizer(wxVERTICAL, Dialog, L"About " + g_szFrameTitle);

    wxStaticBitmap* pPNGBanner = new wxStaticBitmap(Dialog, wxID_ANY, wxBitmap(RESOURCE_ID_TO_STRING(RESID_PNG_ABOUT), wxBITMAP_TYPE_PNG_RESOURCE), wxDefaultPosition, wxDefaultSize);
    wxTextCtrl* pTextAbout = new wxTextCtrl(Dialog, wxID_ANY, ABOUT_INFORMATION, wxDefaultPosition, wxSize(wxDefaultSize.GetWidth(), 120), wxTE_MULTILINE | wxTE_READONLY);

    /* Dialog's buttons. */
    wxButton* pButtonOK = new wxButton(Dialog, wxID_OK, L"OK", wxDefaultPosition, wxDefaultSize);
    pButtonOK->SetDefault();

    /* Arrange dialog's controls. */
    pStaticSizer->Add(pTextAbout, wxSizerFlags().Expand().Center().Border(wxALL, 5));
    pSizer->Add(pPNGBanner, 0);
    pSizer->Add(pStaticSizer, wxSizerFlags().Center().Expand().Border(wxALL, 5));
    pSizer->Add(pButtonOK, wxSizerFlags().Center().Border(wxLEFT | wxRIGHT | wxDOWN, 5));

    Dialog->SetSizer(pSizer);
    Dialog->SetSize(Dialog->GetBestSize());
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
    /* Write frame position. */
    int nX, nY;
    GetPosition(&nX, &nY);
    Configuration->Write(CONFIG_LABEL_FRAME_X, nX);
    Configuration->Write(CONFIG_LABEL_FRAME_Y, nY);
    /* Write frame size. */
    int nWidth, nHeight;
    GetSize(&nWidth, &nHeight);
    Configuration->Write(CONFIG_LABEL_FRAME_WIDTH, nWidth);
    Configuration->Write(CONFIG_LABEL_FRAME_HEIGHT, nHeight);
    /* Write maximized state. */
    (IsMaximized()) ? Configuration->Write(CONFIG_LABEL_FRAME_MAX, true) : Configuration->Write(CONFIG_LABEL_FRAME_MAX, false);
    /* Write control sizes. */
    int nConsoleWidth, nConsoleHeight, nStacksWidth, nStacksHeight;
    ServerStacks->GetSize(&nStacksWidth, &nStacksHeight);
    Console->GetSize(&nConsoleWidth, &nConsoleHeight);
    Configuration->Write(CONFIG_LABEL_STACKS_WIDTH, nStacksWidth);
    Configuration->Write(CONFIG_LABEL_STACKS_HEIGHT, nStacksHeight);
    Configuration->Write(CONFIG_LABEL_CONSOLE_WIDTH, nConsoleWidth);
    Configuration->Write(CONFIG_LABEL_CONSOLE_HEIGHT, nConsoleHeight);
    delete Configuration;
    Destroy();
    /* NOTE: Do not call wxFrame::Close() here! It's called before CAppInit::WriteXMLData() is called. */
}
