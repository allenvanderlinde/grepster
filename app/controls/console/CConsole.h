/**
 * @file    CConsole.h
 * @author  Allen Vanderlinde
 * @date    November 20, 2014
 * @brief   wxWidgets read-only text control class definition used as grepster's console.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CCONSOLE_H_
#define _CCONSOLE_H_


/**
 * This object creates a wxTextCtrl which represents grepster's console for logging progress and returning results.
 * Due to wxTextCtrl's flexibility, you can use this like a standard iostream object by referencing its pointer.
 * @code
 * *Console << "\nHello, world!";
 * @endcode
 * @class   CConsole
 * @brief   Class definition for grepster's console.
 */
class CConsole : public wxTextCtrl {
public:
    /**
     * @brief       Default constructor which creates the text control console.
     * @param[in]   parentFrame The primary frame to which this control belongs.
     */
    CConsole(wxWindow* parentFrame);

    /**
     * @brief       Get the console control's pane information.
     * @retval      wxAuiPaneInfo This is the text control's display configuration object.
     */
    wxAuiPaneInfo Info() { return m_consoleInf_t; }

    /**
     * @brief       Set the text color to light cobalt blue.
     */
    void BlueText() { SetDefaultStyle(wxColour(0,
                                               102,
                                               153)); }
    /**
     * @brief       Set the text color to default black.
     */
    void BlackText() { SetDefaultStyle(wxTextAttr(*wxBLACK)); }

private:
    wxAuiPaneInfo m_consoleInf_t;

    /**
     * @brief       Initialize and call the object's event handler.
     */
    //wxDECLARE_EVENT_TABLE();
};

#endif
