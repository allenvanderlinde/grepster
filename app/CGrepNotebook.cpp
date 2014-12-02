/*
    File:       CConsole.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets AUI notebook control class initialization and methods.

    Created:    11/21/14

    Copyright (C) 2014 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../grepster.h"
#include "CGrepNotebook.h"

#include "CAppFrame.h"

/* Construct the Grep Notebook's event table. */
wxBEGIN_EVENT_TABLE(CGrepNotebook, wxAuiNotebook)
    EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, CGrepNotebook::EmptyPage)
wxEND_EVENT_TABLE()

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

    /* Customize the notebook's color. */
    wxAuiGenericTabArt* art = new wxAuiGenericTabArt();
    art->SetColour(WXCOLOR_LT_BLUE);
    art->SetActiveColour(WXCOLOR_LT_BLUE);
    SetArtProvider(art);
}

/*
    CGrepNotebook::EmptyPage(wxCommandEvent&)
*/
void CGrepNotebook::EmptyPage(wxAuiNotebookEvent& event) {
    if(GetPageCount() < 1) OpenWelcomePage();
}

/*
    CGrepNotebook::OpenWelcomePage
*/
void CGrepNotebook::OpenWelcomePage() {
    m_browser = new CWebViewer(this);
    AddPage(m_browser->getBrowser(), "Welcome to grepster!");
}
