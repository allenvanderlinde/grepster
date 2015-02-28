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

#include "CDialogChangeCredentials.h"
#include "../app/CAppFrame.h"

/* The dialog's event handler calls. */
wxBEGIN_EVENT_TABLE(CDialogChangeCredentials, wxDialog)
    //EVT_CLOSE(CAppFrame::OnExit)
    EVT_BUTTON(BUTTON_OK, CDialogChangeCredentials::OnOK)
wxEND_EVENT_TABLE()

/*
    CDialogChangeCredentials::CDialogChangeCredentials
*/
CDialogChangeCredentials::CDialogChangeCredentials(wxWindow* parentFrame)
    : wxDialog(parentFrame, DIALOG_ID_CHANGE_CREDENTIALS, DIALOG_TITLE, wxDefaultPosition, wxSize(400, 180)) {
    /* Assign values. */
    m_szUsername = Configuration->Username();

    m_pSizer = new wxBoxSizer(wxVERTICAL);
    /* Create and arrange dialog's controls. */
    m_textbox_username    = new wxTextCtrl(this, TEXTBOX_USERNAME, m_szUsername, wxDefaultPosition, wxDefaultSize);
    m_button_ok           = new wxButton(this, BUTTON_OK, L"OK", wxPoint(0, 0), wxDefaultSize);

    /* Add controls to sizer. */
    m_pSizer->Add(m_textbox_username, wxSizerFlags().Center());
    m_pSizer->Add(m_button_ok, wxSizerFlags().Center());

    SetSizer(m_pSizer);

    Show(true); // Display the dialog box
}

/*
    CDialogChangeCredentials::OnOK
*/
void CDialogChangeCredentials::OnOK(wxCommandEvent& event) {
    wxString szPrevUsername = Configuration->Username();
    Configuration->ChangeUsername(m_textbox_username->GetLineText(0));  // Change the administrator's username and save to configuration for saving to XML
    if(szPrevUsername.IsSameAs(Configuration->Username()))
        Destroy();
    else {
        *Console << L"\n\nChanging username from " + szPrevUsername + " to " + Configuration->Username() + ".";
        Configuration->WriteXMLData();
    }

    // can't close with enter key
    /* */
    // UPDATE TREE CTRL WITH NEW USERNAME
    /* */

    Destroy();
}
