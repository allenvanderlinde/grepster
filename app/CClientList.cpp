/*
    Project: grepster
    File: CClientList.cpp

    Desc: wxWidgets tree control functions.

    Date: 11/20/14
    Author: Allen Vanderlinde
*/

#include "../grepster.h"
#include "CAppFrame.h"

#include "CClientList.h"

/*  CClientList::CClientList

    Desc: Constructor for tree control class. */
CClientList::CClientList(wxWindow* parentFrame)
    : wxTreeCtrl(parentFrame, CLIENT_LIST_ID, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE | wxTR_HIDE_ROOT) {
    /* Configure client list's display settings. */
    m_clientListInf.PaneBorder(true);
    m_clientListInf.BestSize(CLIENT_LIST_DEFAULT_WIDTH, FRAME_HEIGHT);
    m_clientListInf.Name(CLIENT_LIST_NAME);
    m_clientListInf.Caption(CLIENT_LIST_CTRL_TITLE);
    m_clientListInf.CaptionVisible();
    m_clientListInf.Left();
    m_clientListInf.CloseButton(false);
    m_clientListInf.Floatable(configuration.bUseFloatable);
    m_clientListInf.Show(true);
}
