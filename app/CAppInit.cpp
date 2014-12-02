/*
    File:       CAppInit.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       grepster's configuration class methods.

    Created:    11/28/14

    Copyright (C) 2014 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
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
        m_XMLSettings = m_XMLFile.child(L"grepster").child(L"setting");    // Note: Do not change. Every grepster configuration element is labeled "setting"
        if(m_XMLSettings == NULL)   // Element not intact and/or invalid character found
            m_bConfigurationLoadedSuccessfully = false;
    }

    /* Apply grepster's XML configuration to application. */
    ApplyXMLData();
}

/*
    CAppInit::ApplyXMLData
*/
void CAppInit::ApplyXMLData() {
    /* Crawl through configuration file and populate CAppInit's member settings and flags with values. */
    // id and value are used for each element data read from file
    wxString id, value;

    // Floating control
    id = m_XMLSettings.attribute(L"id").value();
    value = m_XMLSettings.attribute(L"value").value();
    (value.IsSameAs("true")) ? bToggleFloating = true : bToggleFloating = false;
    m_XMLSettings = m_XMLSettings.next_sibling();

    // next
}

/*
    CAppInit::WriteXMLData
*/
void CAppInit::WriteXMLData() {
    // Reset the file
    m_XMLSaveFile.reset();

    // Add the configuration node
    pugi::xml_node node = m_XMLSaveFile.append_child(XML_CONFIGURATION_NODE_LABEL);
    pugi::xml_node param;

    // Floating controls
    param = node.append_child(XML_ELEMENT_LABEL);
    param.append_attribute(XML_ID_LABEL) = L"bToggleFloating";
    param.append_attribute(XML_VALUE_LABEL) = bToggleFloating;

    // Save XML document to configuration file
    m_XMLSaveFile.save_file(CONFIGURATION_FILE_PATH);
}
