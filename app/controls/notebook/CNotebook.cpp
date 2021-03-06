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
    //*pOutput << stack.Name() << L"\n";
    // Open file into text control
    pOutput->LoadFile(stack.Path());

    /*  NOTE: NEED TO OPEN PAGE MANUALLY, LINE-BY-LINE. */

    AddPage(pOutput, stack.Name(), true);   // Add a new page to the notebook
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
    wxString szPageName(GetPageText(GetSelection()));
    /* If this is the welcome page, return. */
    if(szPageName.IsSameAs(NOTEBOOK_GREETING))
        return;
    /* Gather properties of selected page to save. */
    wxTextCtrl* pCurrentPage = (wxTextCtrl*)GetPage(GetSelection());
    int nPageIndex = GetPageIndex(GetPage(GetSelection()));
    wxTextFile file;
    wxString szPath;
    /* Find if page belongs to a server stack. */
    /* NOTE: I'm not sure why iterating through m_Stacks with auto
        corrupts the m_szFilePath string of the CAdminStack object,
        but integer iteration works. */
    bool bFound;    // Identify if the page was found in the server stacks control
    for(int i = 0; i < (int)ServerStacks->GetStacks().size(); i++) {
        /* Is the user certain they wish to overwrite the file? */
        if(ServerStacks->GetStacks()[i].Name().IsSameAs(szPageName)) {
            if(wxMessageBox(L"Are you certain you want to overwrite " + szPageName + "?", L"Save Page", wxOK | wxCANCEL | wxICON_QUESTION) == wxOK) {
                szPath = ServerStacks->GetStacks()[i].Path();
                bFound = true;
                break;  // Found a match, no need to continue searching
            }
            else return;
        }
    }
    if(bFound) {    // If found, close stack, save page to file, reload stack
        if(pCurrentPage->SaveFile(szPath)) {
            CAdminStack newStack(szPath);   // Create new stack from saved changes
            /* grepster is designed so that the title of the notebook
                tab is also the name given to the server stack. */
            ServerStacks->CloseStack(szPageName);
            DeletePage(nPageIndex);
            ServerStacks->AddServerStack(newStack);
            OpenPage(newStack);
        }
    }
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
