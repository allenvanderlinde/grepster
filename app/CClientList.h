/**
 * @file    CClientList.h
 * @author  Allen Vanderlinde
 * @date    November 20, 2014
 * @brief   wxWidgets tree control class definition.
 */
/*
    Copyright (C) 2014 by Allen Vanderlinde.
    Songbird and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CCLIENTLIST_H_
#define _CCLIENTLIST_H_

#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/aui/aui.h>

/**
 * This object creates a wxTreeCtrl used to house a list of clients which can be selected for more streamlined grepping.
 *
 * @class   CClientList
 * @brief   Class definition for grepster's client list.
 */
class CClientList : public wxTreeCtrl {
public:
    /**
     * @brief       Default constructor which creates tree control client list.
     * @param[in]   parentFrame The primary frame to which this control belongs.
     */
    CClientList(wxWindow* parentFrame);

    /** Return control's pane information. */
    wxAuiPaneInfo getPaneInfo() { return m_clientListInf; }

private:
    /** AUI pane settings structure. */
    wxAuiPaneInfo m_clientListInf;

    //wxDECLARE_EVENT_TABLE();
};

#endif
