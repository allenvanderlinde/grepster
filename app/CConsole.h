/*
    Project: grepster
    File: CConsole.h

    Desc: wxWidgets text control definition representing grepster's console.

    Date: 11/20/14
    Author: Allen Vanderlinde
*/

#ifndef _CCONSOLE_H_
#define _CCONSOLE_H_

#include <wx/wx.h>
#include <wx/aui/aui.h>

/*  CConsole

    Desc: wxWidgets text control class definition for the console. */
class CConsole : public wxTextCtrl {
public:
    CConsole(wxWindow* parentFrame);

    /* Return control's pane information. */
    wxAuiPaneInfo getPaneInfo() { return m_consoleInf; }

private:
    // AUI pane settings structure
    wxAuiPaneInfo m_consoleInf;

    //wxDECLARE_EVENT_TABLE();
};

#endif
