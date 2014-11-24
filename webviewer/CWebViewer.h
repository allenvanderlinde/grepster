/*
    Project: grepster
    File: CWebViewer.h

    Desc: grepster's http browser. wxWidgets web viewer control for grepster's home page.

    Date: 11/22/14
    Author: Allen Vanderlinde
*/

#ifndef _CWEBVIEWER_H_
#define _CWEBVIEWER_H_

#include <wx/wx.h>
#include <wx/webview.h>
#include <wx/wfstream.h>

/* Default home page URL. */
#define HOME_PAGE   "file:///C:/grepster/welcome.html"

class CWebViewer {
public:
    CWebViewer(wxWindow* parentFrame);

    /* Return the http browser control. */
    wxWebView* getBrowser() { return m_browser; }

private:
    /* grepster's http browser/web viewer. */
    wxWebView* m_browser;
};

#endif // _CWEBVIEWER_H_
