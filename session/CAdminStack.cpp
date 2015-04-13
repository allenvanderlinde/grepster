/*
    File:       CAdminStack.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       Server stack data object's class initialization and methods.

    Created:    3/30/15

    Copyleft (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code are licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../precomp.h"

#include "CAdminStack.h"


/*
    CAdminStack::CAdminStack
*/
CAdminStack::CAdminStack(wxString filePath) {
    /* Check to see if this will be the "empty" stack added to the
        current session. */
    m_szFilePath = filePath;
    /* Open the text file at the given path and read
        its list of servers. The file should be
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
            m_Servers.push_back(szHost);
            *Console << L"\nServer: " + szHost;
        }
    }
    file.Close();
    /* Write some basic information to the console. */
    *Console << L"\nNumber of servers in stack: " + wxString::Format(L"%i", Size());
    *Console << L"\n";
}

/*
    CAdminStack::RemoveServer
*/
void CAdminStack::RemoveServer(wxString name) {
    /* Find the matching server in the vector
        and remove it. */
    for(auto itr = m_Servers.begin(); itr != m_Servers.end(); ++itr) {
        if(name.IsSameAs(*itr)) {
            m_Servers.erase(itr);
            return;
        }
    }
}
