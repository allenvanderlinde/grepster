/**
 * @file    CGrepNotebook.h
 * @author  Allen Vanderlinde
 * @date    November 20, 2014
 * @brief   wxWidgets AUI notebook control class definition.
 */
/*
    Copyright (C) 2014 by Allen Vanderlinde.
    Songbird and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CGREPNOTEBOOK_H
#define _CGREPNOTEBOOK_H

#include <wx/wx.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibook.h>

#include "../webviewer/CWebViewer.h"

/* Grep Notebook configuration definitions. */
/** @brief  These are defined here but not actually relevant because of a wxWidgets limitation being that wxAuiNotebook controls cannot yet float. */
/** grepster's default notebook width. */
#define GREP_NOTEBOOK_DEFAULT_WIDTH         500
/** grepster's default notebook height. */
#define GREP_NOTEBOOK_DEFAULT_HEIGHT        540

/**
 * This object creates grepster's grep job notebook for data entry, search terms and command execution.
 *
 * @class   CGrepNotebook
 * @brief   Class definition for grepster's notebook control.
 */
class CGrepNotebook : public wxAuiNotebook {
public:
    /**
     * @brief       Default constructor which produces the notebook.
     * @param[in]   parentFrame The primary frame to which this control belongs.
     */
    CGrepNotebook(wxWindow* parentFrame);

    /** Return control's pane information. */
    wxAuiPaneInfo getPaneInfo() { return m_grepNotebookInf; }
    /** Launch browser for welcome page. */
    void OpenWelcomePage();
    /** Open the welcome page when the user has closed all other open tabs. */
    void EmptyPage(wxAuiNotebookEvent& event);

private:
    /** grepster's welcome page browser. */
    CWebViewer* m_browser;
    /** AUI pane settings structure. */
    wxAuiPaneInfo m_grepNotebookInf;

    wxDECLARE_EVENT_TABLE();
};

#endif
