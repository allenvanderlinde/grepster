/**
 * @file    CDialogSetPathToPuTTY.h
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

#include "CDialogSetPathToPuTTY.h"
#include "../app/CAppFrame.h"


/* The dialog's event handler calls. */
//wBEGIN_EVENT_TABLE(CDialogSetPathToPuTTY, wxDialog)

//wxEND_EVENT_TABLE()

/*
    CDialogSetPathToPuTTY::CDialogSetPathToPuTTY
*/
CDialogSetPathToPuTTY::CDialogSetPathToPuTTY(wxWindow* parentFrame, dialogVars_t dialogVars)
    : wxDialog(parentFrame, DIALOG_ID_SET_PATH_PUTTY, dialogVars.title, wxDefaultPosition, wxSize(dialogVars.width, dialogVars.height)) {
    SetIcon(wxICON(aaaaappicon));
    CenterOnParent();

    wxTextCtrl* pTextCurrentPath = new wxTextCtrl(this, wxID_ANY, Configuration->PathToPuTTY(), wxDefaultPosition, wxSize(100, -1), wxTE_READONLY);

    // use the third arg here to pass in the default path from config file, user can change
    // here, and then OnOK will send it to CAppInit where it will be saved

    //wxDirDialog* pDirSelect = new wxDirDialog(NULL, "Choose input directory", "");

    // add writable text ctrl here with a browse button ("...") next to it so user
    // can select folder via the dirdialog too

    //pDirSelect->ShowModal();

    /* Set dialog's main sizers. */
    m_pSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* pStaticSizer = new wxStaticBoxSizer(wxVERTICAL, this, L"Path");

    pStaticSizer->Add(pTextCurrentPath);

    m_pSizer->Add(pStaticSizer, wxSizerFlags().Center().Expand().Border(wxALL, 5));

    SetSizer(m_pSizer);
    Show(true); // Display the dialog box
}
