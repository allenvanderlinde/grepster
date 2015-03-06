/*
    File:       CConsole.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets AUI notebook control class initialization and methods.

    Created:    11/21/14

    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../precomp.h"

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
    m_grepNotebookInf_t.PaneBorder(true);
    m_grepNotebookInf_t.BestSize(GREP_NOTEBOOK_DEFAULT_WIDTH, GREP_NOTEBOOK_DEFAULT_HEIGHT);
    m_grepNotebookInf_t.Name(GREP_NOTEBOOK_NAME);
    /* wxWidgets does not yet allow notebook controls to float,
    so there is no need for it to have a title bar. */
    //m_grepNotebookInf_t.Caption(GREP_NOTEBOOK_CTRL_TITLE);
    m_grepNotebookInf_t.CaptionVisible(false);
    m_grepNotebookInf_t.Center();
    m_grepNotebookInf_t.CloseButton(false);
    //m_grepNotebookInf_t.Floatable(Configuration->bToggleFloating);
    m_grepNotebookInf_t.Show(true);

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
    m_pBrowser = new CWebViewer(this);
    AddPage(m_pBrowser->getBrowser(), "Welcome to grepster!");
}
