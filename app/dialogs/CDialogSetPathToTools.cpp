/**
 * @file    CDialogSetPathToTools.h
 * @author  Allen Vanderlinde
 * @date    March 5, 2015
 * @brief   Dialog box's methods.
 */
/*
    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../../precomp.h"

#include "../../resources/grepster_rc.h"

#include "CDialogSetPathToTools.h"


/* The dialog's event handler calls. */
wxBEGIN_EVENT_TABLE(CDialogSetPathToTools, wxDialog)
    EVT_BUTTON(CDialogSetPathToTools::BUTTON_OK, CDialogSetPathToTools::OnOK)
wxEND_EVENT_TABLE()

/*
    CDialogSetPathToTools::CDialogSetPathToTools
*/
CDialogSetPathToTools::CDialogSetPathToTools(wxWindow* parentFrame)
    : wxDialog(parentFrame, wxID_ANY, L"Set SSH/SFTP Tools", wxDefaultPosition, wxDefaultSize) {
    SetIcon(wxICON(aaaaappicon));
    CenterOnParent();
    /* Dialog controls. */
    m_pSSHToolSelect = new wxFilePickerCtrl(this, DIALOG_BROWSE_SSH, Configuration->PathToSSHTool(), L"SSH Tool Selection", L"Executable files (*.exe)|*.exe", wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE | wxFLP_SMALL);
    m_pSFTPToolSelect = new wxFilePickerCtrl(this, DIALOG_BROWSE_SFTP, Configuration->PathToSFTPTool(), L"SFTP Tool Selection", L"Executable files (*.exe)|*.exe", wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE | wxFLP_SMALL);
    m_pButtonOK = new wxButton(this, BUTTON_OK, L"OK", wxDefaultPosition, wxDefaultSize);
    m_pButtonOK->SetDefault();
    m_pButtonCancel = new wxButton(this, wxID_CANCEL, L"Cancel", wxDefaultPosition, wxDefaultSize);

    // Create dialog's banner
    m_pPNGBanner = new wxStaticBitmap(this, wxID_ANY, wxBitmap(RESOURCE_ID_TO_STRING(RESID_PNG_TOOLS), wxBITMAP_TYPE_PNG_RESOURCE), wxDefaultPosition, wxDefaultSize);

    /* Set dialog's main sizers. */
    m_pSizer = new wxBoxSizer(wxVERTICAL);
    m_pStaticSizerSSHTool = new wxStaticBoxSizer(wxVERTICAL, this, L"SSH Tool");
    m_pStaticSizerSFTPTool = new wxStaticBoxSizer(wxVERTICAL, this, L"SFTP Tool");
    m_pSizerButtons = new wxBoxSizer(wxHORIZONTAL);

    m_pStaticSizerSSHTool->Add(m_pSSHToolSelect, wxSizerFlags().Expand());
    m_pStaticSizerSFTPTool->Add(m_pSFTPToolSelect, wxSizerFlags().Expand());

    m_pSizerButtons->Add(m_pButtonOK, wxSizerFlags().Center());
    m_pSizerButtons->Add(m_pButtonCancel, wxSizerFlags().Center());

    m_pSizer->Add(m_pPNGBanner);
    m_pSizer->Add(m_pStaticSizerSSHTool, wxSizerFlags().Center().Expand().Border(wxALL, 5));
    m_pSizer->Add(m_pStaticSizerSFTPTool, wxSizerFlags().Center().Expand().Border(wxALL, 5));
    m_pSizer->Add(m_pSizerButtons, wxSizerFlags().Center().Border(wxLEFT | wxRIGHT | wxDOWN, 5));

    SetSizer(m_pSizer);
    SetSize(GetBestSize());
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
    if(!szPrevSSHToolPath.IsSameAs(Configuration->PathToSSHTool()))
       *Console << L"\n\nChanging grepster's SSH tool to: " + Configuration->PathToSSHTool();
    if(!szPrevSFTPToolPath.IsSameAs(Configuration->PathToSFTPTool()))
       *Console << L"\n\nChanging grepster's SFTP tool to: " + Configuration->PathToSFTPTool();

    EndModal(BUTTON_OK);
}
