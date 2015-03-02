/**
 * @file    CDialogChangeCredentials.cpp
 * @author  Allen Vanderlinde
 * @date    February 28, 2015
 * @brief   Dialog box's methods.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../grepster.h"

#include "../resources/grepster_rc.h"

#include "CDialogChangeCredentials.h"
#include "../app/CAppFrame.h"


/* The dialog's event handler calls. */
wxBEGIN_EVENT_TABLE(CDialogChangeCredentials, wxDialog)
    EVT_BUTTON(BUTTON_OK, CDialogChangeCredentials::OnOK)
wxEND_EVENT_TABLE()

/*
    CDialogChangeCredentials::CDialogChangeCredentials
*/
CDialogChangeCredentials::CDialogChangeCredentials(wxWindow* parentFrame)
    : wxDialog(parentFrame, DIALOG_ID_CHANGE_CREDENTIALS, DIALOG_TITLE, wxDefaultPosition, wxSize(DIALOG_WIDTH, DIALOG_HEIGHT)) {
    SetIcon(wxICON(aaaaappicon));
    CenterOnParent();
    /* Dialog controls. */
    wxBoxSizer* pSizerUsername, *pSizerPassword;
    wxStaticText* pTextUsername, *pTextPassword;

    pSizerUsername = new wxBoxSizer(wxHORIZONTAL);
    pTextUsername = new wxStaticText(this, wxID_ANY, L"Username:");
    m_pInputUsername = new wxTextCtrl(this, INPUT_USERNAME, Configuration->Username(), wxDefaultPosition, wxSize(200, -1));
    pSizerUsername->Add(pTextUsername, wxSizerFlags().Center().Border(wxRIGHT, 10));
    pSizerUsername->Add(m_pInputUsername, wxSizerFlags().Center());

    pSizerPassword = new wxBoxSizer(wxHORIZONTAL);
    pTextPassword = new wxStaticText(this, wxID_ANY, L"Password:");
    m_pInputPassword = new wxTextCtrl(this, INPUT_PASSWORD, Configuration->Password(), wxDefaultPosition, wxSize(200, -1), wxTE_PASSWORD);
    pSizerPassword->Add(pTextPassword, wxSizerFlags().Center().Border(wxRIGHT, 13));
    pSizerPassword->Add(m_pInputPassword, wxSizerFlags().Center());

    m_pButtonOK = new wxButton(this, BUTTON_OK, L"OK", wxPoint(0, 0), wxDefaultSize);
    wxButton* pButtonCancel = new wxButton(this, wxID_CANCEL, L"Cancel", wxPoint(0, 0), wxDefaultSize); // Cancel button for convenience; catches ESC key
    m_pButtonOK->SetDefault();

    // Create dialog's banner
    wxStaticBitmap* pPNGBanner = new wxStaticBitmap(this, wxID_ANY, wxBitmap(RESOURCE_ID_TO_STRING(RESID_PNG_CREDENTIALS), wxBITMAP_TYPE_PNG_RESOURCE), wxDefaultPosition, wxDefaultSize);

    /* Set dialog's main sizers. */
    m_pSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* pStaticSizer = new wxStaticBoxSizer(wxVERTICAL, this, L"Default Credentials");

    pStaticSizer->Add(pSizerUsername, wxSizerFlags().Center());
    pStaticSizer->Add(pSizerPassword, wxSizerFlags().Center().Border(wxUP, 10));//, wxSizerFlags().Border(wxUP, 10));
    m_pSizer->Add(pPNGBanner);
    m_pSizer->Add(pStaticSizer, wxSizerFlags().Center().Expand().Border(wxALL, 5));

    wxBoxSizer* pSizerButtons = new wxBoxSizer(wxHORIZONTAL);
    pSizerButtons->Add(m_pButtonOK, wxSizerFlags().Center());
    pSizerButtons->Add(pButtonCancel, wxSizerFlags().Center());
    m_pSizer->Add(pSizerButtons, wxSizerFlags().Center().Border(wxTOP, 5));

    SetSizer(m_pSizer);

    Show(true); // Display the dialog box
}

/*
    CDialogChangeCredentials::OnOK
*/
void CDialogChangeCredentials::OnOK(wxCommandEvent& event) {
    wxString szPrevUsername = Configuration->Username();
    wxString szPrevPassword = Configuration->Password();

    /* Change the administrator's credentials and update configuration for saving to XML. Note: The user's password is never saved to file. */
    Configuration->ChangeCredentials(m_pInputUsername->GetLineText(0), m_pInputPassword->GetLineText(0));
    if(!szPrevUsername.IsSameAs(Configuration->Username())) {
        *Console << L"\n\nChanging username from " + szPrevUsername + " to " + Configuration->Username() + ".";
        Configuration->WriteXMLData();
        ServerStacks->UpdateStacks();
    }
    if(!szPrevPassword.IsSameAs(Configuration->Password())) {
        Console->BlueText();
        *Console << L"\n\nChanging password.";
        Console->BlackText();
    }

    EndModal(BUTTON_OK);    // End the dialog box with a specified successful return code
}
