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
    /* Set this flag's default value to "true" as grepster should expect to load the configuration successfully.
        This flag needs to be "false" only once for grepster to warn the user as handled by CAppEntry::LoadConfiguration. */
    m_bConfigurationLoadedSuccessfully = true;
    /* Verify configuration file is present and intact. */
    pugi::xml_parse_result result = m_XMLFile.load_file(CONFIGURATION_FILE_PATH);
    if(!result) // XML file does not exist
        m_bConfigurationLoadedSuccessfully = false;
    else {
        m_XMLSettings = m_XMLFile.child(L"setting");    // Note: Do not change. Every grepster configuration element is labeled "setting"
        if(m_XMLSettings == NULL)   // Element not intact and/or invalid character found
            m_bConfigurationLoadedSuccessfully = false;
    }

    /* Apply grepster's XML configuration to application. */
    ApplyXMLData();
}

/*
    CAppInit::ApplyXMLData()
*/
void CAppInit::ApplyXMLData() {
    /* Crawl through configuration file and populate CAppInit's member settings and flags with values. */
    wxString id, value;
    id = m_XMLSettings.attribute(L"id").value();
    value = m_XMLSettings.attribute(L"value").value();
    (value.IsSameAs("true")) ? bToggleFloating = true : bToggleFloating = false;

    // m_XMLSettings.next_sibling();
}

/*
    CAppInit::WriteXMLData()
*/
void CAppInit::WriteXMLData() {
    // Start writing at beginning of file
    m_XMLSettings.first_child();
    // Floating controls
    m_XMLSettings.attribute(L"value").set_value("true");

    // Save XML data to file and close
    m_XMLFile.save_file(CONFIGURATION_FILE_PATH);
}
