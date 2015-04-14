/**
 * @file    CAppMenubar.h
 * @author  Allen Vanderlinde
 * @date    November 5, 2014
 * @brief   wxWidgets menu bar control class definition.
 */
/*
    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CAPPMENUBAR_H_
#define _CAPPMENUBAR_H_

#include "MenubarProperties.h"


/**
 * This object creates grepster's menu bar.
 *
 * @class   CAppMenubar
 * @brief   Class definition for grepster's menu bar control.
 */
class CAppMenubar : public wxMenuBar {
public:
    /**
     * @brief   Default constructor which builds menu bar.
     */
    CAppMenubar();

private:
    wxMenu* m_pMenuFile;
    wxMenu* m_pMenuSession;
    wxMenu* m_pMenuNotebook;
    wxMenu* m_pMenuTools;
    wxMenu* m_pMenuOptions;
    wxMenu* m_pMenuHelp;
};

#endif
