In most, if not all, of grepster's control methods you'll often see only a single argument being passed: <code>wxCommandEvent& event</code>. This is a reference to the wxWidgets command input structure. It is a record of the state of the method's parent frame at the time the event was triggered (i.e., which key on the keyboard was pressed; which button in the frame was clicked).

Some methods will have their own command event structure depending upon the type of wxWindow triggers the event.

As these are always required parameters for custom control methods, they are not individually documented within the source code for the sake of preventing redundant documentation.