/*
    Project: grepster
    File: CWebViewer.cpp

    Desc: wxWidgets web viewer control for grepster's home page.

    Date: 11/22/14
    Author: Allen Vanderlinde
*/

#include "../grepster.h"

#include "CWebViewer.h"

/*  CWebViewer::CWebViewer

    Desc: Constructor for grepster's browser for the welcome page. */
CWebViewer::CWebViewer(wxWindow* parentFrame) {
    /* Initialize the browser. */
    m_browser = wxWebView::New(parentFrame,
                               BROWSER_ID,
                               "file:///C:/grepster/welcome.html",
                               wxDefaultPosition,
                               wxDefaultSize,
                               wxWebViewBackendIE, // This uses the Microsoft Internet Explorer browser back-end
                               0,
                               wxWebViewNameStr);

}
