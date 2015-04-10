/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _PRECOMP_H_
#define _PRECOMP_H_


/* Include the wxWidgets headers to pre-compile. */
#if (!defined(WX_PRECOMP))
    #define WX_PRECOMP
#endif

/* Include the most frequently used and unchanging headers here. */
#include <wx/wxprec.h>
#include <wx/config.h>
#include <wx/treectrl.h>
#include <wx/aui/aui.h>
#include <wx/aui/framemanager.h>
#include <wx/aui/auibook.h>
#include <wx/aui/dockart.h>
#include <wx/webview.h>
#include <wx/wfstream.h>
#include <wx/splash.h>
#include <wx/icon.h>
#include <wx/filepicker.h>
#include <wx/textfile.h>
#include <wx/tokenzr.h>

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // WX_PRECOMP

#endif // _PRECOMP_H_
