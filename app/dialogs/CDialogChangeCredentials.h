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

#include "../../grepster.h"


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

    /**
     * @enum        enum_DialogCtrlIDs
     * @brief       These represent the dialog's individual function call IDs.
     */
    enum enum_DialogCtrlIDs {
        BUTTON_OK = wxID_ANY,
        INPUT_USERNAME,
        INPUT_PASSWORD
    };

private:
    wxBoxSizer*         m_pSizer;
    wxBoxSizer*         m_pSizerButtons;
    wxStaticBoxSizer*   m_pStaticSizer;
    wxFlexGridSizer*    m_pSizerInput;

    wxStaticText*       m_pTextUsername;
    wxStaticText*       m_pTextPassword;
    wxTextCtrl*         m_pInputUsername;
    wxTextCtrl*         m_pInputPassword;
    wxButton*           m_pButtonOK;
    wxButton*           m_pButtonCancel;

    wxStaticBitmap*     m_pPNGBanner;

    /**
     * @brief       Processes the user clicking the "OK" button.
     *              Saves new username to configuration and sets password for the session.
     */
    void OnOK(wxCommandEvent& event);

    /**
     * @brief       Initialize and call the object's event handler.
     */
    wxDECLARE_EVENT_TABLE();
};

#endif // _CDIALOGCHANGECREDENTIALS_H_
