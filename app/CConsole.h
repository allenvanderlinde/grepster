/**
 * @file    CConsole.h
 * @author  Allen Vanderlinde
 * @date    November 20, 2014
 * @brief   wxWidgets read-only text control class definition used as grepster's console.
 */
/*
    Copyright (C) 2014 by Allen Vanderlinde.
    Songbird and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CCONSOLE_H_
#define _CCONSOLE_H_

#include <wx/wx.h>
#include <wx/aui/aui.h>

/**
 * This object creates a wxTextCtrl which represents grepster's console for logging progress and returning results.
 *
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

    /** Return control's pane information. */
    wxAuiPaneInfo getPaneInfo() { return m_consoleInf; }

private:
    /** AUI pane settings structure. */
    wxAuiPaneInfo m_consoleInf;

    //wxDECLARE_EVENT_TABLE();
};

#endif
