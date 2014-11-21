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

/* Application entry settings. */
#define DISPLAY_SPLASH                  true
#define SPLASH_DURATION                 1000

/*  CAppEntry

    Desc: wxWidgets application class definition. */
class CAppEntry : public wxApp {
public:
    virtual bool OnInit();

    bool ShowSplash(int resource_id);

private:
    CAppFrame* m_grepster_frame;
};

#endif
