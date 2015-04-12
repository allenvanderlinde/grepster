/*
    File:       CConsole.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets read-only text control class initialization and methods. Note: This is used as grepster's console.

    Created:    11/20/14

    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../../../precomp.h"

#include "../../../grepster.h"

#include "../../CAppFrame.h"
#include "CConsole.h"


/*
    CConsole::CConsole(wxWindow*)
*/
CConsole::CConsole(wxWindow* parentFrame)
    : wxTextCtrl(parentFrame, CONSOLE_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_RICH2 | wxTE_READONLY) {
    /* Configure console's display settings. */
    /* Set the initial size of the control when it's un-docked. */
    int nConsoleWidth = Configuration->ReadLong(CONFIG_LABEL_CONSOLE_WIDTH, DEFAULT_FRAME_WIDTH);
    int nConsoleHeight = Configuration->ReadLong(CONFIG_LABEL_CONSOLE_HEIGHT, CONSOLE_DEFAULT_HEIGHT);
    SetSize(nConsoleWidth, nConsoleHeight);
    m_consoleInf_t.BestSize(nConsoleWidth, nConsoleHeight);
    m_consoleInf_t.Bottom();
    /* Miscellaneous settings. */
    m_consoleInf_t.PaneBorder(true);
    m_consoleInf_t.Name(CONSOLE_NAME);
    m_consoleInf_t.Caption(CONSOLE_CTRL_TITLE);
    m_consoleInf_t.CaptionVisible();
    m_consoleInf_t.CloseButton(false);
    m_consoleInf_t.Floatable(Configuration->Floating());
    m_consoleInf_t.Show(true);

    /* Set the console's font. */
    SetFont(wxFont(wxFontInfo(8).FaceName("Lucida Console")));
    /* Welcome the user. */
    *this << g_szFrameTitle + L" initialized successfully.\n\nWelcome " + Configuration->Username() + L".\nReady to grep.\n";
}
