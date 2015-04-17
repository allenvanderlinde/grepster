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
    EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, CNotebook::ClosePage)
wxEND_EVENT_TABLE()

/*
    CNotebook::CNotebook(wxWindow*)
*/
CNotebook::CNotebook(wxWindow* parentFrame)
    : wxAuiNotebook(parentFrame, NOTEBOOK_ID) {
    /* Configure the Notebook's display settings. */
    /* Miscellaneous settings. */
    m_NotebookInf_t.PaneBorder(true);
    m_NotebookInf_t.BestSize(NOTEBOOK_DEFAULT_WIDTH, NOTEBOOK_DEFAULT_HEIGHT);
    m_NotebookInf_t.Name(NOTEBOOK_NAME);
    m_NotebookInf_t.CaptionVisible(false);
    m_NotebookInf_t.Center();
    m_NotebookInf_t.CloseButton(false);
    m_NotebookInf_t.Show(true);

    /* Customize the tab color. */
    //wxAuiGenericTabArt* art = new wxAuiGenericTabArt();
    //art->SetColour(WXCOLOR_LT_BLUE);
    //art->SetActiveColour(WXCOLOR_LT_BLUE);
    //SetArtProvider(art);
}

/*
    CNotebook::OpenPage(CAdminStack)
*/
void CNotebook::OpenPage(CAdminStack stack) {
    /* NOTE: Don't reload stack from file? Is that a waste?
        NOTE: CAdminStack is built in the order which lines are read,
        so these lines could just be read from the object and its
        strings added to the text ctrl. */
    int nNewId = GetPageCount() + 1;
    wxTextCtrl* pOutput = new wxTextCtrl(this,
                                         NEW_PAGE + nNewId,
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
    AddPage(pOutput, stack.Name(), true);
}

/*
    CNotebook::OpenWelcomePage
*/
void CNotebook::OpenWelcomePage() {
    m_pBrowser = new CWebViewer(this);
    AddPage(m_pBrowser->GetBrowser(), L"Welcome to grepster!", true);
}

/*
    CNotebook::SavePage
*/
void CNotebook::SavePage() {
    /* If this is the welcome page, return. */
    if(GetPageText(GetSelection()).IsSameAs(NOTEBOOK_GREETING))
        return;
    /* Save the current page's text back to its file. */
    //*(wxTextCtrl*)GetPage(GetSelection()) << L"\n\nSaving this...\n";

    //wxTextCtrl currentPage((wxTextCtrl)GetPage(GetSelection()));
    wxTextCtrl* pCurrentPage = (wxTextCtrl*)GetPage(GetSelection());
    //wxTextFile file;
    //wxString szPath;
    /* Find if page belongs to a server stack. */
    for(auto itr = ServerStacks->GetStacks().begin(); itr != ServerStacks->GetStacks().end(); ++itr) {
        wxMessageBox(itr->Path(), "ok", wxOK);
        //if(itr->Name().IsSameAs(GetPageText(GetSelection()))) {
            /* Is the user certain they wish to overwrite the file? */
            //if(wxMessageBox(L"Are you certain you want to overwrite " + itr->Path() + "?", L"Save Page", wxOK | wxCANCEL | wxICON_QUESTION) == wxCANCEL)
                //return;
            //break;  // Found a match, no need to continue searching
        //}
    }
    //ServerStacks->CloseStack(GetPageText(GetSelection()));
    /* Grab each line in the text control
        and write it to file. */
    //file.Open(szPath);
    //file.Clear();
    //for(int i = 0; i < pCurrentPage->GetNumberOfLines(); i++)
        //file.AddLine(pCurrentPage->GetLineText(i));
    //file.Write();   // Save lines to file
    //file.Close();
    //ServerStacks->AddServerStack(CAdminStack(szPath));
    //delete pCurrentPage;
}

/*
}

/*
    CNotebook::ClosePage
*/
void CNotebook::ClosePage(wxAuiNotebookEvent& event) {
    /* This checks to see if there would be no pages
        opened in the notebook. If so, it opens the welcome
        page for grepster. */
    if(GetPageCount() < 1) {
        OpenWelcomePage();
        return;
    }
}
