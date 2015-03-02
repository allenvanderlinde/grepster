/**
 * @file    CDialogChangeCredentials.h
 * @author  Allen Vanderlinde
 * @date    February 28, 2015
 * @brief   Class which builds the dialog to change the administrator's credentials.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CDIALOGCHANGECREDENTIALS_H_
#define _CDIALOGCHANGECREDENTIALS_H_

#include <wx/wx.h>


/* Dialog's globals. */
#define DIALOG_TITLE    L"Administrator Default Credentials"

#define DIALOG_WIDTH    300
#define DIALOG_HEIGHT   260

/* Dialog's control IDs. */
enum {
    BUTTON_OK = 2101,
    INPUT_USERNAME,
    INPUT_PASSWORD
};


/**
 * This object creates a dialog box to change the administrator's credentials.
 *
 * @class   CDialogChangeCredentials
 * @brief   Class definition for dialog box to change administrator's credentials.
 */
 class CDialogChangeCredentials : public wxDialog {
 public:
     /**
      * @brief       Default constructor which creates the dialog box.
      * @param[in]   parentFrame The primary frame to which this dialog belongs.
      */
     CDialogChangeCredentials(wxWindow* parentFrame);

 private:
    /** Primary box sizer for dialog. */
    wxBoxSizer*         m_pSizer;

    /** Dialog's text control used to grab new default username. */
    wxTextCtrl*         m_pInputUsername;
    /** Dialog's text control used to grab new default password. */
    wxTextCtrl*         m_pInputPassword;
    /** Dialog's button control used to save new credentials. */
    wxButton*           m_pButtonOK;

    /**
     * @brief       Save new username to configuration.
     */
    void OnOK(wxCommandEvent& event);

    /**
     * @brief       Initialize and call the primary object's event handler.
     */
    wxDECLARE_EVENT_TABLE();
 };

#endif // _CDIALOGCHANGECREDENTIALS_H_
