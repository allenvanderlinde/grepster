/*
    Project: grepster
    File: CAppEntry.h

    Desc: Class definition for grepster's wxWidgets application execution.

    Date: 11/2/14
    Author: Allen Vanderlinde
*/

#ifndef _CAPPENTRY_H_
#define _CAPPENTRY_H_

#include <wx/wx.h>

#include "CAppFrame.h"

/*  CAppEntry

    Desc: wxWidgets application class definition. */
class CAppEntry : public wxApp {
public:
    virtual bool OnInit();

private:
    CAppFrame* m_grepster_frame;
};

#endif
