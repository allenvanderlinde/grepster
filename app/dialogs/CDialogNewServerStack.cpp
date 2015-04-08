/**
 * @file    CDialogNewServerStack.h
 * @author  Allen Vanderlinde
 * @date    April 8, 2015
 * @brief   Dialog box's methods.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../../precomp.h"

#include "../../resources/grepster_rc.h"

#include "CDialogNewServerStack.h"


/* The dialog's event handler calls. */
wxBEGIN_EVENT_TABLE(CDialogNewServerStack, wxDialog)
    EVT_BUTTON(CDialogNewServerStack::BUTTON_SAVE, CDialogNewServerStack::OnSave)
wxEND_EVENT_TABLE()

/*
    CDialogNewServerStack::CDialogNewServerStack
*/
CDialogNewServerStack::CDialogNewServerStack(wxWindow* parentFrame)
    : wxDialog(parentFrame, wxID_ANY, L"New Server Stack", wxDefaultPosition, wxDefaultSize) {
    SetIcon(wxICON(aaaaappicon));
    CenterOnParent();
    /* Dialog controls. */
    m_pInputStackName = new wxTextCtrl(this, INPUT_STACK_NAME);
    m_pButtonSave = new wxButton(this, BUTTON_SAVE, L"Save", wxDefaultPosition, wxDefaultSize);
    m_pButtonSave->SetDefault();
    m_pButtonCancel = new wxButton(this, wxID_CANCEL, L"Cancel", wxDefaultPosition, wxDefaultSize);

    // Create dialog's banner
    m_pPNGBanner = new wxStaticBitmap(this, wxID_ANY, wxBitmap(RESOURCE_ID_TO_STRING(RESID_PNG_SERVER_STACK), wxBITMAP_TYPE_PNG_RESOURCE), wxDefaultPosition, wxDefaultSize);

    /* Set dialog's main sizers. */
    m_pSizer = new wxBoxSizer(wxVERTICAL);
    m_pStaticSizerStackName = new wxStaticBoxSizer(wxVERTICAL, this, L"Server Stack Name");
    m_pSizerButtons = new wxBoxSizer(wxHORIZONTAL);

    m_pStaticSizerStackName->Add(m_pInputStackName, wxSizerFlags().Expand().Border(wxLEFT | wxRIGHT | wxDOWN, 5));

    m_pSizerButtons->Add(m_pButtonSave, wxSizerFlags().Center());
    m_pSizerButtons->Add(m_pButtonCancel, wxSizerFlags().Center());

    m_pSizer->Add(m_pPNGBanner);
    m_pSizer->Add(m_pStaticSizerStackName, wxSizerFlags().Center().Expand().Border(wxALL, 5));
    m_pSizer->Add(m_pSizerButtons, wxSizerFlags().Center().Border(wxLEFT | wxRIGHT | wxDOWN, 5));

    SetSizer(m_pSizer);
    SetSize(GetBestSize());
    Show(true); // Display the dialog box
}

/*
    CDialogNewServerStack::OnSave
*/
void CDialogNewServerStack::OnSave(wxCommandEvent& event) {
    EndModal(BUTTON_SAVE);
}
