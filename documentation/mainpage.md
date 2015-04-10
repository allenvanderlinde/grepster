<b>Acknowledgements</b>



Instructions
============

<b>Note:</b> grepster uses standard SFTP commands for pulling down compiled results from each grep session. A SFTP and a SSH tool must be installed and grepster must be able to point to the directory paths which hold each tool's executable. These paths can be set from within grepster.

I suggest using PuTTY's SSH and SFTP tools as they were the tools tested during development. Thanks to Simon Tatham and the PuTTY Team for creating such great tools! More information on PuTTY's license can be found <a href="http://www.chiark.greenend.org.uk/~sgtatham/putty/licence.html" target="_blank">here</a>.

Design Notes
============

In most, if not all, of grepster's control methods you'll often see only a single argument being passed: <code>wxCommandEvent& event</code>, or some other <code>event</code> class. This is a reference to the wxWidgets event capture structure. It is a record of the state of the method's parent window or control at the time the event was triggered (i.e., which key on the keyboard was pressed; which button in the frame was clicked, an item's label).

Some methods will have their own command event structure depending upon the type of wxWindow triggers the event.

As these are always required parameters for control event handling methods, they are not individually documented within the source code.
<br>

Source Code Notes
=================
<ol>
<li>The source code tries to maintain a standard but descriptive naming scheme for method variables whose scope does not leave the method in which it's declared. Their names describe just what they are. For example, <code>wxButton* pButtonOK</code>: <code>pButtonOK</code> will be found in each dialog's instantiation method which uses OK buttons, for example.</li>
</ol>