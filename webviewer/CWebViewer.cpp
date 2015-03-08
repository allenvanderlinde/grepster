/*
    File:       CWebViewer.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       wxWidgets web viewer control class initialization and methods.

    Created:    11/22/14

    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../precomp.h"

#include "../grepster.h"

#include "CWebViewer.h"


/*
    CWebViewer::CWebViewer(wxWindow)
*/
CWebViewer::CWebViewer(wxWindow* parentFrame) {
    /* Initialize the browser. */
    m_pBrowser = wxWebView::New(parentFrame,
                                BROWSER_ID,
                                "file:///C:/grepster/welcome.html",
                                wxDefaultPosition,
                                wxDefaultSize,
                                wxWebViewBackendIE, // This uses the Microsoft Internet Explorer browser back-end
                                0,
                                wxWebViewNameStr);
}
