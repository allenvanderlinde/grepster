/*
    File:       CAppInit.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       grepster's configuration class methods.

    Created:    11/28/14

    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../precomp.h"

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
        /* Initialize a new administrator class for the session. */
        m_XMLSettings = m_XMLFile.child(XML_CONFIGURATION_NODE_LABEL).child(XML_ELEMENT_LABEL);
        if(m_XMLSettings == NULL)   // Element not intact and/or invalid character found
            m_bConfigurationLoadedSuccessfully = false;
        else {
            /* Note: Pass username as argument to CAdminAccount's instantiation. */
            m_pAdministrator = new CAdminAccount(m_XMLSettings.attribute(XML_VALUE_LABEL).value());
            /* Apply grepster's XML configuration to application. */
            ApplyXMLData();
        }
    }
}

/*
    CAppInit::ApplyXMLData
*/
void CAppInit::ApplyXMLData() {
    /* Crawl through configuration file and populate CAppInit's member settings and flags with values. */
    // id and value are used for each element data read from file, they are used for attribute checking (if needed) as grepster grows in future releases
    wxString id, value;

    // Step to first application configuration element
    m_XMLSettings = m_XMLSettings.next_sibling();

    // Floating control
    id = m_XMLSettings.attribute(XML_ID_LABEL).value();
    value = m_XMLSettings.attribute(XML_VALUE_LABEL).value();
    (value.IsSameAs("true")) ? bToggleFloating = true : bToggleFloating = false;
    m_XMLSettings = m_XMLSettings.next_sibling();

    // Path to SSH/SFTP tools
    id = m_XMLSettings.attribute(XML_ID_LABEL).value();
    value = m_XMLSettings.attribute(XML_VALUE_LABEL).value();
    m_szPathToTools = value;
    m_XMLSettings = m_XMLSettings.next_sibling();

    // SSH tool name
    id = m_XMLSettings.attribute(XML_ID_LABEL).value();
    value = m_XMLSettings.attribute(XML_VALUE_LABEL).value();
    m_szSSHTool = value;
    m_XMLSettings = m_XMLSettings.next_sibling();

    // SFTP tool name
    id = m_XMLSettings.attribute(XML_ID_LABEL).value();
    value = m_XMLSettings.attribute(XML_VALUE_LABEL).value();
    m_szSFTPTool = value;
    m_XMLSettings = m_XMLSettings.next_sibling();
}

/*
    CAppInit::WriteXMLData
*/
void CAppInit::WriteXMLData() {
    // Reset the file
    m_XMLFile.reset();
    pugi::xml_node param;   // XML node used to declare configuration parameters (elements)
    pugi::xml_node node = m_XMLFile.append_child(XML_CONFIGURATION_NODE_LABEL); // Append grepster's configuration element label

    // Append administrator's credentials
    param = node.append_child(XML_ELEMENT_LABEL);
    param.append_attribute(XML_ID_LABEL) = L"Username";
    param.append_attribute(XML_VALUE_LABEL) = m_pAdministrator->Username().wchar_str();

    // Floating controls
    param = node.append_child(XML_ELEMENT_LABEL);
    param.append_attribute(XML_ID_LABEL) = L"ToggleFloating";
    param.append_attribute(XML_VALUE_LABEL) = bToggleFloating;

    // Path to SSH/SFTP tools
    param = node.append_child(XML_ELEMENT_LABEL);
    param.append_attribute(XML_ID_LABEL) = L"PathToTools";
    param.append_attribute(XML_VALUE_LABEL) = m_szPathToTools.wchar_str();

    // SSH tool name
    param = node.append_child(XML_ELEMENT_LABEL);
    param.append_attribute(XML_ID_LABEL) = L"SSHTool";
    param.append_attribute(XML_VALUE_LABEL) = m_szSSHTool.wchar_str();

    // Path to SSH/SFTP tools
    param = node.append_child(XML_ELEMENT_LABEL);
    param.append_attribute(XML_ID_LABEL) = L"SFTPTool";
    param.append_attribute(XML_VALUE_LABEL) = m_szSFTPTool.wchar_str();

    // Save XML document to configuration file
    m_XMLFile.save_file(CONFIGURATION_FILE_PATH);

    /* Write configuration changes to file. */
    Console->BlueText();
    *Console << "\nConfiguration saved.";
    Console->BlackText();
}
