/*
    Project: grepster
    File: CGrepNotebook.h

    Desc: AUI notebook class definition for grepping.

    Date: 11/20/14
    Author: Allen Vanderlinde
*/

#ifndef _CGREPNOTEBOOK_H
#define _CGREPNOTEBOOK_H

#include <wx/wx.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibook.h>

#include "../webviewer/CWebViewer.h"

/* Grep Notebook configuration definitions. */
// These are defined here but not actually relevant because of a wxWidgets limitation being that wxAuiNotebook controls cannot yet float
#define GREP_NOTEBOOK_DEFAULT_WIDTH         500
#define GREP_NOTEBOOK_DEFAULT_HEIGHT        540

/*  CGrepNotebook

    Desc: wxWidgets AUI notebook control class definition. */
class CGrepNotebook : public wxAuiNotebook {
public:
    CGrepNotebook(wxWindow* parentFrame);

    /* Return control's pane information. */
    wxAuiPaneInfo getPaneInfo() { return m_grepNotebookInf; }

    /* Launch browser for welcome page. */
    void OpenWelcomePage();

private:
    // grepster's  browser control
    CWebViewer* m_browser;
    // AUI pane settings structure
    wxAuiPaneInfo m_grepNotebookInf;

    //wxDECLARE_EVENT_TABLE();
};

#endif
