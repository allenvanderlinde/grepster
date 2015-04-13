/**
 * @file    CSessionNotebook.h
 * @author  Allen Vanderlinde
 * @date    November 20, 2014
 * @brief   wxWidgets AUI notebook control class definition.
 */
/*
    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    Songbird and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CGREPNOTEBOOK_H
#define _CGREPNOTEBOOK_H

#include "../../web-viewer/CWebViewer.h"
#include "../../../session/CAdminStack.h"


/* Note: These are defined here but not actually relevant because
    of a wxWidgets limitation being that wxAuiNotebook controls cannot yet float. */
#define SESSION_NOTEBOOK_DEFAULT_WIDTH         500
#define SESSION_NOTEBOOK_DEFAULT_HEIGHT        540


/**
 * This object creates grepster's grep job notebook for data entry, search terms and command execution.
 *
 * @class   CSessionNotebook
 * @brief   Class definition for grepster's notebook control.
 */
class CSessionNotebook : public wxAuiNotebook {
public:
    /**
     * @brief       Default constructor which produces the notebook.
     * @param[in]   parentFrame The primary frame to which this control belongs.
     */
    CSessionNotebook(wxWindow* parentFrame);

    /**
     * @brief       Get notebook control's pane information.
     * @retval      wxAuiPaneInfo This is the notebook control's display configuration object.
     */
    wxAuiPaneInfo Info() { return m_grepNotebookInf_t; }

    /**
     * @brief       Open the contents of a server stack into a new page
     *              for editing.
     * @param[in]   stack The string name of the CAdminStack object to read and edit.
     */
    void OpenServerStack(CAdminStack stack);

    /**
     * @brief       Creates a new CWebViewer object and opens grepster's home page.
     */
    void OpenWelcomePage();
    /**
     * @brief       Open the welcome page when the user has closed all other open tabs.
     */
    void EmptyPage(wxAuiNotebookEvent& event);

private:
    CWebViewer*     m_pBrowser;

    wxAuiPaneInfo   m_grepNotebookInf_t;


    /**
     * @brief       Initialize and call the object's event handler.
     */
    wxDECLARE_EVENT_TABLE();
};

#endif
