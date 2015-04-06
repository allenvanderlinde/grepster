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

#include "../../precomp.h"

#include "../../resources/grepster_rc.h"

#include "CDialogSetPathToTools.h"
#include "../CAppFrame.h"


/* The dialog's event handler calls. */
wxBEGIN_EVENT_TABLE(CDialogSetPathToTools, wxDialog)
    EVT_BUTTON(CDialogSetPathToTools::BUTTON_OK, CDialogSetPathToTools::OnOK)
    //EVT_BUTTON(CDialogSetPathToTools::BUTTON_BROWSE_SSH, CDialogSetPathToTools::OnBrowseSSH)
    //EVT_BUTTON(CDialogSetPathToTools::BUTTON_BROWSE_SFTP, CDialogSetPathToTools::OnBrowseSFTP)
wxEND_EVENT_TABLE()

/*
    CDialogSetPathToTools::CDialogSetPathToTools
*/
CDialogSetPathToTools::CDialogSetPathToTools(wxWindow* parentFrame, dialogVars_t dialogVars)
    : wxDialog(parentFrame, wxID_ANY, dialogVars.title, wxDefaultPosition, wxSize(dialogVars.width, dialogVars.height)) {
    SetIcon(wxICON(aaaaappicon));
    CenterOnParent();
    /* Dialog controls. */
    m_pSSHToolSelect = new wxFilePickerCtrl(this, DIALOG_BROWSE_SSH, Configuration->PathToSSHTool(), L"SSH Tool Selection", L"Executable files (*.exe)|*.exe", wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE | wxFLP_SMALL);
    m_pSFTPToolSelect = new wxFilePickerCtrl(this, DIALOG_BROWSE_SFTP, Configuration->PathToSFTPTool(), L"SFTP Tool Selection", L"Executable files (*.exe)|*.exe", wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE | wxFLP_SMALL);
    m_pButtonOK = new wxButton(this, BUTTON_OK, L"OK", wxDefaultPosition, wxDefaultSize);
    m_pButtonOK->SetDefault();
    wxButton* pButtonCancel = new wxButton(this, wxID_CANCEL, L"Cancel", wxDefaultPosition, wxDefaultSize);

    // Create dialog's banner
    wxStaticBitmap* pPNGBanner = new wxStaticBitmap(this, wxID_ANY, wxBitmap(RESOURCE_ID_TO_STRING(RESID_PNG_TOOLS), wxBITMAP_TYPE_PNG_RESOURCE), wxDefaultPosition, wxDefaultSize);

    /* Set dialog's main sizers. */
    m_pSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* pStaticSizerSSHTool = new wxStaticBoxSizer(wxVERTICAL, this, L"SSH Tool");
    wxStaticBoxSizer* pStaticSizerSFTPTool = new wxStaticBoxSizer(wxVERTICAL, this, L"SFTP Tool");
    wxBoxSizer* pSizerButtons = new wxBoxSizer(wxHORIZONTAL);

    pStaticSizerSSHTool->Add(m_pSSHToolSelect, wxSizerFlags().Expand());
    pStaticSizerSFTPTool->Add(m_pSFTPToolSelect, wxSizerFlags().Expand());

    pSizerButtons->Add(m_pButtonOK, wxSizerFlags().Center());
    pSizerButtons->Add(pButtonCancel, wxSizerFlags().Center());

    m_pSizer->Add(pPNGBanner);
    m_pSizer->Add(pStaticSizerSSHTool, wxSizerFlags().Center().Expand().Border(wxALL, 5));
    m_pSizer->Add(pStaticSizerSFTPTool, wxSizerFlags().Center().Expand().Border(wxALL, 5));
    m_pSizer->Add(pSizerButtons, wxSizerFlags().Center());

    SetSizer(m_pSizer);
    Show(true); // Display the dialog box
}

/*
    CDialogSetPathToTools::OnOK
*/
void CDialogSetPathToTools::OnOK(wxCommandEvent& event) {
    wxString szPrevSSHToolPath = Configuration->PathToSSHTool();
    wxString szPrevSFTPToolPath = Configuration->PathToSFTPTool();
    /* Change the paths to grepster's SSH and SFTP tools and update configuration. */
    Configuration->ChangePathToTools(m_pSSHToolSelect->GetPath(), m_pSFTPToolSelect->GetPath());
    if(!szPrevSSHToolPath.IsSameAs(Configuration->PathToSSHTool())) {
       *Console << L"\n\nChanging grepster's SSH tool to: " + Configuration->PathToSSHTool();
       Configuration->WriteXMLData();
    }
    if(!szPrevSFTPToolPath.IsSameAs(Configuration->PathToSFTPTool())) {
       *Console << L"\n\nChanging grepster's SFTP tool to: " + Configuration->PathToSFTPTool();
       Configuration->WriteXMLData();
    }

    EndModal(BUTTON_OK);
}
