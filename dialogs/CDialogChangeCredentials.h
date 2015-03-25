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

#include "../grepster.h"


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
     * @param[in]   dialogVars The dialog's basic window properties.
     */
    CDialogChangeCredentials(wxWindow* parentFrame,
                             dialogVars_t dialogVars);
    /**
    * @enum        enum_DialogCtrlIDs
    * @brief       Note: Each dialog class should have an enumeration which sets their controls' ID
    * to match the major magnitude of the dialog's ID as defined in CAppFrame.h. This is done in order to take
    * control away from wxWidgets when handling what dialogs should do when the user activates a control.
    */
    enum enum_DialogCtrlIDs {
        BUTTON_OK = wxID_ANY,
        INPUT_USERNAME,
        INPUT_PASSWORD
    };

private:
    wxBoxSizer*         m_pSizer;

    wxTextCtrl*         m_pInputUsername;
    wxTextCtrl*         m_pInputPassword;
    wxButton*           m_pButtonOK;

    /**
     * @brief       Processes the user clicking the "OK" button.
     *              Saves new username to configuration and sets password for the session.
     */
    void OnOK(wxCommandEvent& event);

    /**
     * @brief       Initialize and call the primary object's event handler.
     */
    wxDECLARE_EVENT_TABLE();
};

#endif // _CDIALOGCHANGECREDENTIALS_H_
