/**
 * @file    CWebViewer.h
 * @author  Allen Vanderlinde
 * @date    November 22, 2014
 * @brief   wxWidgets web viewer control class definition.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CWEBVIEWER_H_
#define _CWEBVIEWER_H_


/** Default home page URL. */
#define HOME_PAGE   "file:///C:/grepster/welcome.html"


/**
 * This object creates grepster's browser for the welcome page.
 *
 * @class   CWebViewer
 * @brief   Class definition for grepster's browser. Note: The default back-end HTML renderer is Internet Explorer.
 */
class CWebViewer {
public:
    /**
     * @brief       Default constructor which produces the frame.
     * @param[in]   parentFrame The primary frame to which this control belongs.
     */
    CWebViewer(wxWindow* parentFrame);

    /**
     * @brief       Get the web viewer object.
     */
    wxWebView* getBrowser() { return m_pBrowser; }

private:
    wxWebView* m_pBrowser;
};

#endif // _CWEBVIEWER_H_
