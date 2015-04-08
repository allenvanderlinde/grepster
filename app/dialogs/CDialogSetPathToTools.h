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

#ifndef _CDIALOGSETPATHTOTOOLS_H_
#define _CDIALOGSETPATHTOTOOLS_H_

#include "../../grepster.h"


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
     */
    CDialogSetPathToTools(wxWindow* parentFrame);

    /**
     * @enum        enum_DialogCtrlIDs
     * @brief       These represent the dialog's individual function call IDs.
     */
    enum enum_DialogCtrlIDs {
        BUTTON_OK = wxID_ANY,
        DIALOG_BROWSE_SSH,
        DIALOG_BROWSE_SFTP
    };

private:
    wxBoxSizer*         m_pSizer;
    wxStaticBoxSizer*   m_pStaticSizerSSHTool;
    wxStaticBoxSizer*   m_pStaticSizerSFTPTool;
    wxBoxSizer*         m_pSizerButtons;

    wxFilePickerCtrl*   m_pSSHToolSelect;
    wxFilePickerCtrl*   m_pSFTPToolSelect;

    wxButton*           m_pButtonOK;
    wxButton*           m_pButtonCancel;

    wxStaticBitmap*     m_pPNGBanner;

    /**
     * @brief       Processes the user clicking the "OK" button.
     *              Closes dialog.
     */
    void OnOK(wxCommandEvent& event);

    /**
     * @brief       Initialize and call the object's event handler.
     */
    wxDECLARE_EVENT_TABLE();
};

#endif // _CDialogSetPathToTools_H_
