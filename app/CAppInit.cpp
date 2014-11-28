/*
    File:       CAppInit.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       grepster's configuration class methods.

    Created:    11/28/14

    Copyright (C) 2014 by Allen Vanderlinde.
    Songbird and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../grepster.h"
#include "CAppInit.h"

/*
    CAppInit::CAppInit
*/
CAppInit::CAppInit() {
    /* Verify configuration file is present and intact. */
    pugi::xml_parse_result result = m_xml_file.load_file(CONFIGURATION_FILE_PATH);

    /* Set configuration values. */
    bToggleFloating = false;
}
