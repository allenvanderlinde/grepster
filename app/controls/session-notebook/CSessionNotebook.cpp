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
    /* Open server stack's file into a new wxTextFile and
        load its contents into a new wxTextCtrl. */

        /* NOTE: Don't reload stack from file? Is that a waste?
            NOTE: CAdminStack is built in the order which lines are read,
            so these lines could just be read from the object and its
            strings added to the text ctrl. */
    wxTextFile file;
    file.Open(stack.Path());
    wxTextCtrl* pOutput = new wxTextCtrl(this,
                                         wxID_ANY,
                                         wxEmptyString,
                                         wxDefaultPosition,
                                         wxDefaultSize,
                                         wxTE_MULTILINE | wxTE_RICH2);

    /* Grab each line from the server stack's file
        and add it to the control. */
    while(!file.Eof()) {
        *pOutput << file.GetNextLine();
    }
    file.Close();   // Close file
    AddPage(pOutput, stack.Name());
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
