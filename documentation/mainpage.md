<b>Acknowledgements</b>

grepster's XML methods are built on the pugixml backbone. Please visit http://pugixml.org for more information. The license is included in pugixml-1.4/readme.txt.

grepster uses PuTTY for its SSH and SFTP capabilities. Refer to PUTTY LICENSE.txt for more information.

Instructions
============

<b>Note:</b> PuTTY must first be installed on the PC using grepster. grepster assumes PuTTY to be installed in "C:\Program Files (x86)\PuTTY\"" or the like. If your installation is in another location, update grepster.xml in grepster's application folder with the correct directory path.
<br>

Design Notes
============

In most, if not all, of grepster's control methods you'll often see only a single argument being passed: <code>wxCommandEvent& event</code>. This is a reference to the wxWidgets command input structure. It is a record of the state of the method's parent frame at the time the event was triggered (i.e., which key on the keyboard was pressed; which button in the frame was clicked).

Some methods will have their own command event structure depending upon the type of wxWindow triggers the event.

As these are always required parameters for control event handling methods, they are not individually documented within the source code for the sake of preventing redundant documentation.
<br>

Source Code Notes
=================
<ol>
<li>CAppFrame::RefreshConfiguration is always called after a user changes one of grepster's control's options (such as setting a control to float). Essentially this saves all new changes to grepster's interface and configuration in real-time.</li>
<li>CAppFrame houses grepster's control methods and only refreshes grepster's configuration as changes are made, using CAppInit to then write the new settings to file. CAppInit is the only class which holds grepster's actual configuration flags and members.</li>
<li>grepster uses the pugixml API for reading and processing of XML files. pugixml code is not documented here and is sparsly documented in the source. Please visit: <a href="http://pugixml.org/">http://pugixml.org</a> for information and tutorials on the API.</li>
<li>grepster's configuration methods CAppInit::ApplyXMLData and CAppInit::WriteXMLData must not be modified unless you are adding new data to be appended to the end of the file, or reading from the end of the file for new, custom configurations. This order is hard-coded within the methods themselves and grepster will not function or save configuration properly if this order is changed.</li>
<li>The source code tries to maintain a standard but descriptive naming scheme for method variables whose scope does not leave the method in which it's declared. Their names describe just what they are. For example, <code>wxButton* pButtonOK</code>: <code>pButtonOK</code> will be found in each dialog's instantiation method which uses OK buttons, for example.</li>
</ol>