/**
 * @file    CDialogSetPathToTools.h
 * @author  Allen Vanderlinde
 * @date    March 5, 2015
 * @brief   Class which builds the dialog to set the default path to grepster's SSH/SFTP tools.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CDialogSetPathToTools_H_
#define _CDialogSetPathToTools_H_

#include "../grepster.h"


/**
 * This object creates a dialog box to set the default path to grepster's SSH/SFTP tools.
 *
 * @class   CDialogSetPathToTools
 * @brief   Class definition for dialog box to set the default path to grepster's SSH/SFTP tools.
 */
class CDialogSetPathToTools : public wxDialog {
public:
    /**
     * @brief       Default constructor which creates the dialog box.
     * @param[in]   parentFrame The primary frame to which this dialog belongs.
     * @param[in]   dialogVars The dialog's basic window properties.
     */
    CDialogSetPathToTools(wxWindow* parentFrame, dialogVars_t dialogVars);
    /**
    * @enum        enum_DialogCtrlIDs
    * @brief       Note: Each dialog class should have an enumeration which sets their controls' IDs
    * to match the major magnitude of the dialog's ID as defined in CAppFrame.h. This is done in order to take
    * control away from wxWidgets when handling what dialogs should do when the user activates a control.
    */
    enum enum_DialogCtrlIDs {
        BUTTON_OK = 3001,
        BUTTON_BROWSE
    };

private:
    wxBoxSizer*         m_pSizer;
    /**
     * @brief       Directory selection widget which stores the chosen location.
     */
    wxDirDialog*        m_pDirSel;

    wxTextCtrl*         m_pTextCurrentPath;

    wxButton*           m_pButtonBrowse;
    wxButton*           m_pButtonOK;

    /**
     * @brief       Opens a directory selection window to select a new path to grepster's SSH/SFTP tools
     *              and saves it to configuration.
     */
    void OnBrowse(wxCommandEvent& event);

    /**
     * @brief       Processes the user clicking the "OK" button.
     *              Closes dialog.
     */
    void OnOK(wxCommandEvent& event);

    /**
     * @brief       Initialize and call the primary object's event handler.
     */
    wxDECLARE_EVENT_TABLE();
};

#endif // _CDialogSetPathToTools_H_
