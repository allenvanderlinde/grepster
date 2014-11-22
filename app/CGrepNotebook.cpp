/*
    Project: grepster
    File: CConsole.cpp

    Desc: wxWidgets AUI notebook control functions for grep notebook.

    Date: 11/21/14
    Author: Allen Vanderlinde
*/

#include "../grepster.h"

#include "CGrepNotebook.h"

/*  CGrepNotebook::CGrepNotebook

    Desc: Constructor for AUI grep notebook control. */
CGrepNotebook::CGrepNotebook(wxWindow* parentFrame)
    : wxAuiNotebook(parentFrame, GREP_NOTEBOOK_ID) {
    /* Configure grep notebook's display settings. */
    m_grepNotebookInf.PaneBorder(true);
    m_grepNotebookInf.BestSize(GREP_NOTEBOOK_DEFAULT_WIDTH, GREP_NOTEBOOK_DEFAULT_HEIGHT);
    m_grepNotebookInf.Name(GREP_NOTEBOOK_NAME);
    m_grepNotebookInf.Caption(GREP_NOTEBOOK_CTRL_TITLE);
    m_grepNotebookInf.CaptionVisible();
    m_grepNotebookInf.Center();
    m_grepNotebookInf.CloseButton(false);
    m_grepNotebookInf.Floatable(true);
    m_grepNotebookInf.Show(true);
    /* Load the grepster browser in the background. */
    //m_browser = new CWebViewer(this);
}

/*  CGrepNotebook::OpenWelcome Page

    Desc: Launches the browser and loads the default welcome page. */
void CGrepNotebook::OpenWelcomePage() {
    m_browser = new CWebViewer(this);
    AddPage(m_browser->getBrowser(), "Welcome to grepster!");
}
