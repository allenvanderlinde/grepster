/**
 * @file    CDialogSetPathToTools.h
 * @author  Allen Vanderlinde
 * @date    March 5, 2015
 * @brief   Dialog box's methods.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../precomp.h"

#include "../resources/grepster_rc.h"

#include "CDialogSetPathToTools.h"
#include "../app/CAppFrame.h"


/* The dialog's event handler calls. */
wxBEGIN_EVENT_TABLE(CDialogSetPathToTools, wxDialog)
    EVT_BUTTON(CDialogSetPathToTools::BUTTON_OK, CDialogSetPathToTools::OnOK)
    EVT_BUTTON(CDialogSetPathToTools::BUTTON_BROWSE, CDialogSetPathToTools::OnBrowse)
wxEND_EVENT_TABLE()

/*
    CDialogSetPathToTools::CDialogSetPathToTools
*/
CDialogSetPathToTools::CDialogSetPathToTools(wxWindow* parentFrame, dialogVars_t dialogVars)
    : wxDialog(parentFrame, DIALOG_ID_SET_PATH_TOOLS, dialogVars.title, wxDefaultPosition, wxSize(dialogVars.width, dialogVars.height)) {
    SetIcon(wxICON(aaaaappicon));
    CenterOnParent();
    /* Dialog controls. */
    m_pTextCurrentPath = new wxTextCtrl(this, wxID_ANY, Configuration->PathToTools(), wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    m_pButtonBrowse = new wxButton(this, BUTTON_BROWSE, L"...", wxDefaultPosition, wxSize(36, 24));

    m_pButtonOK = new wxButton(this, BUTTON_OK, L"OK", wxDefaultPosition, wxDefaultSize);
    m_pButtonOK->SetDefault();

    /* Set dialog's main sizers. */
    m_pSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* pStaticSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, L"Path");

    pStaticSizer->Add(m_pTextCurrentPath, 1, wxEXPAND);
    pStaticSizer->Add(m_pButtonBrowse, wxSizerFlags().Center());

    m_pSizer->Add(pStaticSizer, wxSizerFlags().Center().Expand().Border(wxALL, 5));
    m_pSizer->Add(m_pButtonOK, wxSizerFlags().Center());

    SetSizer(m_pSizer);
    Show(true); // Display the dialog box
}

/*
    CDialogSetPathToTools::OnBrowse
*/
void CDialogSetPathToTools::OnBrowse(wxCommandEvent& event) {
    m_pDirSel = new wxDirDialog(NULL, "Select path to SSH/SFTP tools", Configuration->PathToTools(), wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize);
    if(m_pDirSel->ShowModal() == wxID_OK ) {
        m_pTextCurrentPath->Clear();
        *m_pTextCurrentPath << m_pDirSel->GetPath();
    }
}

/*
    CDialogSetPathToTools::OnOK
*/
void CDialogSetPathToTools::OnOK(wxCommandEvent& event) {
    Configuration->ChangePathToTools(m_pTextCurrentPath->GetLineText(0));
    Configuration->WriteXMLData();

    EndModal(BUTTON_OK);
}
