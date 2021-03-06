/**
 * @file    CDialogNewServerStack.h
 * @author  Allen Vanderlinde
 * @date    April 8, 2015
 * @brief   Class which builds the dialog to create a new server stack.
 */
/*
    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CDIALOGNEWSERVERSTACK_H_
#define _CDIALOGNEWSERVERSTACK_H_


/**
 * This object creates a dialog box to create a new server stack.
 *
 * @class   CDialogNewServerStack
 * @brief   Class definition for dialog box to create a new server stack.
 */
class CDialogNewServerStack : public wxDialog {
public:
    /**
     * @brief       Default constructor which creates the dialog box.
     * @param[in]   parentFrame The primary frame to which this dialog belongs.
     */
    CDialogNewServerStack(wxWindow* parentFrame);

    /**
     * @brief       Get the name of the new server stack.
     * @retval      wxString The string of the new server stack's name.
     */
    wxString GetStackName() { return m_pInputStackName->GetLineText(0); }

    /**
     * @enum        enum_DialogCtrlIDs
     * @brief       These represent the dialog's individual function call IDs.
     */
    enum enum_DialogCtrlIDs {
        BUTTON_SAVE = 11001,
        INPUT_STACK_NAME
    };

private:
    wxBoxSizer*         m_pSizer;
    wxStaticBoxSizer*   m_pStaticSizerStackName;
    wxBoxSizer*         m_pSizerButtons;

    wxTextCtrl*         m_pInputStackName;

    wxButton*           m_pButtonSave;
    wxButton*           m_pButtonCancel;

    wxStaticBitmap*     m_pPNGBanner;

    /**
     * @brief       Processes the user clicking the "Save" button.
     *              Closes dialog and saves new server stack to disk.
     */
    void OnSave(wxCommandEvent& event);

    /**
     * @brief       Initialize and call the object's event handler.
     */
    wxDECLARE_EVENT_TABLE();
};


#endif // _CDIALOGNEWSERVERSTACK_H_
