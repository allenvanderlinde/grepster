/*
    File:       CConsole.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets AUI notebook control class initialization and methods.

    Created:    11/21/14

    Copyright (C) 2014 by Allen Vanderlinde.
    Songbird and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../grepster.h"
#include "CGrepNotebook.h"

/*
    CGrepNotebook::CGrepNotebook(wxWindow*)
*/
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
    //m_grepNotebookInf.Floatable(Configuration->bToggleFloating);
    m_grepNotebookInf.Show(true);
}

/*
    CGrepNotebook::OpenWelcomePage
*/
void CGrepNotebook::OpenWelcomePage() {
    m_browser = new CWebViewer(this);
    AddPage(m_browser->getBrowser(), "Welcome to grepster!");
}
