/*
    File:       CNotebook.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets AUI notebook control class initialization and methods.

    Created:    11/21/14

    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../../../precomp.h"

#include "../notebook/CNotebook.h"
#include "../../CAppFrame.h"


/* Construct event handler calls. */
wxBEGIN_EVENT_TABLE(CNotebook, wxAuiNotebook)
    EVT_AUINOTEBOOK_PAGE_CLOSE(wxID_ANY, CNotebook::ClosePage)
wxEND_EVENT_TABLE()

/*
    CNotebook::CNotebook(wxWindow*)
*/
CNotebook::CNotebook(wxWindow* parentFrame)
    : wxAuiNotebook(parentFrame, NOTEBOOK_ID) {
    /* Configure the Notebook's display settings. */
    /* Miscellaneous settings. */
    m_grepNotebookInf_t.PaneBorder(true);
    m_grepNotebookInf_t.BestSize(NOTEBOOK_DEFAULT_WIDTH, NOTEBOOK_DEFAULT_HEIGHT);
    m_grepNotebookInf_t.Name(NOTEBOOK_NAME);
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
    CNotebook::OpenServerStack(CAdminStack)
*/
void CNotebook::OpenPage(CAdminStack stack) {
    /* Open server stack's file into a new wxTextFile and
        load its contents into a new wxTextCtrl. */

        /* NOTE: Don't reload stack from file? Is that a waste?
            NOTE: CAdminStack is built in the order which lines are read,
            so these lines could just be read from the object and its
            strings added to the text ctrl. */
    wxTextCtrl* pOutput = new wxTextCtrl(this,
                                         wxID_ANY,
                                         wxEmptyString,
                                         wxDefaultPosition,
                                         wxDefaultSize,
                                         wxTE_MULTILINE | wxTE_RICH2);
    /* Set the text control's font. */
    pOutput->SetFont(wxFont(wxFontInfo(10).FaceName("Courier New")));

    *pOutput << stack.Name() << L"\n";  // Okay to combine UTF with ASCII strings here?
    /* Grab each line from the server stack's file
        and add it to the control. */
    for(int i = 0; i < stack.Size(); i++) {
        *pOutput << stack.IP(i) << L"\n";
    }
    AddPage(pOutput, stack.Name());
    SetSelection(GetPageCount() - 1);

    /* Add the object to the notebook's vector. */
    m_Pages.push_back(pOutput);
    wxMessageBox(wxString::Format("%i", (int)m_Pages.size()), "ok", wxOK);
    // what about the welcome page? should it go into the vector??
}

/*
    CNotebook::OpenWelcomePage
*/
void CNotebook::OpenWelcomePage() {
    m_pBrowser = new CWebViewer(this);
    m_Pages.push_back(m_pBrowser->GetBrowser());
    AddPage(m_pBrowser->GetBrowser(), L"Welcome to grepster!");
    SetSelection(GetPageCount() - 1);
}

/*
    CNotebook::ClosePage
*/
void CNotebook::ClosePage(wxAuiNotebookEvent& event) {
// need to delete current page
    wxString str(GetPageText(GetSelection()));
    wxMessageBox(str, "what?", wxOK);
    //DeletePage(GetSelection());
    /* This checks to see if there would be no pages
        opened in the notebook. If so, it opens the welcome
        page for grepster. */
    if(GetPageCount() < 1)
        OpenWelcomePage();
}

/*
    CNotebook::SavePage(CAdminStack)
*/
void CNotebook::SavePage(CAdminStack stack) {
    // get the title of the current tab
    // match this name to the stack's name
    wxMessageBox("this works", "yeah", wxOK);
}
