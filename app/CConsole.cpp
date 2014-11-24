/*
    Project: grepster
    File: CConsole.cpp

    Desc: wxWidgets text control functions for console.

    Date: 11/20/14
    Author: Allen Vanderlinde
*/

#include "../grepster.h"
#include "CAppFrame.h"

#include "CConsole.h"

/*  CConsole::CConsole

    Desc: Constructor for text control class. */
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
    m_consoleInf.Floatable(configuration.bUseFloatable);
    m_consoleInf.Show(true);

    /* Set the console's font. */
    //SetFont(wxFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));
    //font(wxFontInfo(12).FaceName("Helvetica").Italic());
    SetFont(wxFont(wxFontInfo(8).FaceName("Lucida Console")));
}
