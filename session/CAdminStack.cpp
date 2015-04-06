/*
    File:       CAdminStack.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       Server stack data object's class initialization and methods.

    Created:    3/30/15

    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../precomp.h"

#include "CAdminStack.h"

#include "../grepster.h"


/*
    CAdminStack::CAdminStack
*/
CAdminStack::CAdminStack(wxString filePath) {
    /* Check to see if this will be the "empty" stack added to the
        current session. */
    if(filePath.IsSameAs(L"empty"))
        m_szFilePath = m_szServerStackName = filePath;
    else {    // This is a new stack
        m_szFilePath = filePath;
        /* Open the text file at the given path and read
            its list of hosts/IP addresses. The file should be
            guaranteed to exist by this point. */
        wxTextFile file;
        file.Open(filePath);

        /* Read data until end of file and populate vector
            with each line. */
        m_szServerStackName = file.GetFirstLine();  // Name of the server stack
        *Console << L"\nReading " + m_szServerStackName + "...";
        wxString szHost;
        while(!file.Eof()) {
            szHost = file.GetNextLine();
            if(!szHost.IsEmpty()) {
                m_Hosts.push_back(szHost);
                *Console << L"\nServer: " + szHost;
            }
        }
        file.Close();
        /* Write some basic information to the console. */
        *Console << L"\nNumber of servers in stack: " + wxString::Format(L"%i", Size());
        *Console << L"\n";
    }
}
