/*
    File:       CConsole.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets AUI notebook control class initialization and methods.

    Created:    11/21/14

    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../../../precomp.h"

#include "../session-notebook/CSessionNotebook.h"
#include "../../CAppFrame.h"


/* Construct the Session Notebook's event handler calls. */
wxBEGIN_EVENT_TABLE(CSessionNotebook, wxAuiNotebook)
    EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, CSessionNotebook::EmptyPage)
wxEND_EVENT_TABLE()

/*
    CSessionNotebook::CSessionNotebook(wxWindow*)
*/
CSessionNotebook::CSessionNotebook(wxWindow* parentFrame)
    : wxAuiNotebook(parentFrame, SESSION_NOTEBOOK_ID) {
    /* Configure the Session Notebook's display settings. */
    /* Miscellaneous settings. */
    m_grepNotebookInf_t.PaneBorder(true);
    m_grepNotebookInf_t.BestSize(SESSION_NOTEBOOK_DEFAULT_WIDTH, SESSION_NOTEBOOK_DEFAULT_HEIGHT);
    m_grepNotebookInf_t.Name(SESSION_NOTEBOOK_NAME);
    m_grepNotebookInf_t.CaptionVisible(false);
    m_grepNotebookInf_t.Center();
    m_grepNotebookInf_t.CloseButton(false);
    m_grepNotebookInf_t.Show(true);

    /* Customize the tab color. */
    //wxAuiGenericTabArt* art = new wxAuiGenericTabArt();
    //art->SetColour(WXCOLOR_LT_BLUE);
    //art->SetActiveColour(WXCOLOR_LT_BLUE);
    //SetArtProvider(art);
}

/*
    CSessionNotebook::OpenServerStack
*/
void CSessionNotebook::OpenServerStack(CAdminStack stack) {

}

/*
    CSessionNotebook::EmptyPage(wxCommandEvent&)
*/
void CSessionNotebook::EmptyPage(wxAuiNotebookEvent& event) {
    if(GetPageCount() < 1) OpenWelcomePage();
}

/*
    CSessionNotebook::OpenWelcomePage
*/
void CSessionNotebook::OpenWelcomePage() {
    m_pBrowser = new CWebViewer(this);
    AddPage(m_pBrowser->GetBrowser(), L"Welcome to grepster!");
}
