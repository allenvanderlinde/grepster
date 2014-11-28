/*
    File:       CConsole.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets read-only text control class initialization and methods. Note: This is used as grepster's console.

    Created:    11/20/14

    Copyright (C) 2014 by Allen Vanderlinde.
    Songbird and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../grepster.h"
#include "CAppFrame.h"
#include "CConsole.h"

/*
    CConsole::CConsole(wxWindow*)
*/
CConsole::CConsole(wxWindow* parentFrame)
    : wxTextCtrl(parentFrame, CONSOLE_ID, g_Frame_Title + " initialized successfully.\nReady to grep.", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_RICH2 | wxTE_READONLY) {
    /* Configure console's display settings. */
    m_consoleInf.PaneBorder(true);
    m_consoleInf.BestSize(FRAME_WIDTH, CONSOLE_DEFAULT_HEIGHT);
    m_consoleInf.Name(CONSOLE_NAME);
    m_consoleInf.Caption(CONSOLE_CTRL_TITLE);
    m_consoleInf.CaptionVisible();
    m_consoleInf.Bottom();
    m_consoleInf.CloseButton(false);
    m_consoleInf.Floatable(Configuration->bToggleFloating);
    m_consoleInf.Show(true);

    /* Set the console's font. */
    SetFont(wxFont(wxFontInfo(8).FaceName("Lucida Console")));
}
