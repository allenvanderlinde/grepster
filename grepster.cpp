/*
    File:       grepster.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       Source file for grepster's execution.

    Created:    11/2/14

    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "precomp.h"

#include "grepster.h"
#include "app/CAppEntry.h"

#include <mutex>

/* Global mutex used to lock access to shared resources
   during the execution of multiple threads on SpawnAndRun(). */
std::mutex          g_Mutex;

/* Frame globals definitions. */
wxString            g_szFrameTitle("grepster alpha v");
/* Frame control definitions. These are global. */
CConsole*           Console;
CServerStacks*      ServerStacks;
CSessionNotebook*      SessionNotebook;

/* grepster configuration object. This is global. */
CAppInit*           Configuration;


/* Utility function definitions. */
/*
    RESOURCE_ID_TO_STRING
*/
wxString RESOURCE_ID_TO_STRING(int id) { return wxString::Format("#%i", id); }

/*
    SpawnAndRun
*/
/* Maybe I can also pass a struct here that contains information about the current grep
script, the server stack, the ip, the alias, etc... and this is how grepster will ID the end
of each grep. */

std::string SpawnAndRun(wxString path, wxString args) {
    /* This locks access to these possibly shared resources to the current thread. */
    std::lock_guard<std::mutex> ResourceGuard(g_Mutex);
    /* Declare objects for child process. */
    HANDLE hRead, // Handle which reads stdout of child process
           hWrite;  // Handle to write to stdout
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    SECURITY_ATTRIBUTES sa;

    /* Define the child's security attributes.
        Note: This is used to establish inheritance between the parent and child via the application pipe. */
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = true;
    sa.lpSecurityDescriptor = NULL;

    /* Create pipe to child process. */
    if(!CreatePipe(&hRead, &hWrite, &sa, 0)) {
        wxMessageBox(L"Unable to create pipe!", L"Error", wxOK | wxICON_EXCLAMATION);
        //return false;
    } else if(!SetHandleInformation(hRead, HANDLE_FLAG_INHERIT, 0)) {
        wxMessageBox(L"Unable to set handle information!", L"Error", wxOK | wxICON_EXCLAMATION);
        //return false;
    }

    /* Build handle to child process to capture stdout from. */
    ZeroMemory(&si, sizeof(STARTUPINFO));
    ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
    si.cb = sizeof(STARTUPINFO);
    si.hStdOutput = hWrite;
    si.dwFlags |= STARTF_USESTDHANDLES;

    /* Execute child process and establish link to its handle to capture stdout. */
    CreateProcessW(path.wchar_str(),
                   args.wchar_str(),
                   NULL,
                   NULL,
                   true,
                   CREATE_NO_WINDOW,//CREATE_NEW_CONSOLE,
                   NULL,
                   NULL,
                   &si,
                   &pi);
    CloseHandle(hWrite);

    /* Note: SpawnAndRun() currently captures standard library, non-Unicode strings.
        Storing and/or typecasting to another string type might result in unpredictable behavior. */

    /* Read from stdout and print to grepster's console. */
    DWORD dwRead;   // Size of stdout being read
    CHAR chBuf[CHAR_BUFFER_LENGTH]; // Buffer which stores child's stdout for printing to grepster's console
    bool bSuccess = false;
    std::string out = "";   // Using std::string to ensure accurate capture of stdout

    for(;;) {   /* Continue reading from the stdout handle until the child quits. */
        bSuccess = ReadFile(hRead, chBuf, CHAR_BUFFER_LENGTH, &dwRead, NULL);
        if(!bSuccess || dwRead == 0) break;

        std::string s(chBuf, dwRead);
        *Console << s;  // Send buffer to grepster's console one line at a time
        out += s;   // String copy of entire child's stdout up to CHAR_BUFFER_LENGTH
    }

    /* Clean up handles. */
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    Console->BlueText();
    *Console << "\nFinished.\n";
    Console->BlackText();

    return out;
}

wxIMPLEMENT_APP(CAppEntry);
