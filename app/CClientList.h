/*
    Project: grepster
    File: CClientList.h

    Desc: wxWidgets tree control definition for housing client server sets and misc. information.

    Date: 11/20/14
    Author: Allen Vanderlinde
*/

#ifndef _CCLIENTLIST_H_
#define _CCLIENTLIST_H_

#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/aui/aui.h>

/*  CClientList

    Desc: wxWidgets tree control class definition. */
class CClientList : public wxTreeCtrl {
public:
    CClientList(wxWindow* parentFrame);

    /* Return control's pane information. */
    wxAuiPaneInfo getPaneInfo() { return m_clientListInf; }

private:
    // AUI pane settings structure
    wxAuiPaneInfo m_clientListInf;

    //wxDECLARE_EVENT_TABLE();
};

#endif
