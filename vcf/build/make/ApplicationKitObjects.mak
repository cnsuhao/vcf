###########################################################
#
#CVS Log info
#$Log$
#Revision 1.5.4.2  2004/04/28 18:42:22  ddiego
#migrating over changes for unicode strings.
#This contains fixes for the linux port and changes to the Makefiles
#
#Revision 1.5.4.1  2004/04/28 14:40:01  ddiego
#migration towards new directory structure
#
#Revision 1.5  2003/12/19 05:48:34  ddiego
#made some adjustments in the makefiles to compile and link correctly
#
#Revision 1.4  2003/12/18 05:15:47  ddiego
#merge from devmain-0-6-2 branch into the stable branch
#
#Revision 1.3.4.5  2003/12/13 18:19:00  ddiego
#*** empty log message ***
#
#Revision 1.3.4.4  2003/11/01 20:41:00  ddiego
#updated makefil to add the gtk toolbar class
#
#Revision 1.3.4.3  2003/10/04 20:13:44  ddiego
#updated the Makefiles - everything works now, including compiling
#building on GCC 3.3.1
#
#Revision 1.3.4.2  2003/10/03 01:07:48  ddiego
#added/fixed problems to get it to compile under linux
#
#Revision 1.3.4.1  2003/10/02 04:50:34  ddiego
#changes to ensure the code compiles on linux. made a bunch of updates to
#the makefiles
#
#Revision 1.3  2003/05/17 20:36:20  ddiego
#this is the checkin for the 0.6.1 release - represents the merge over from
#the devmain-0-6-0 branch plus a few minor bug fixes
#
#Revision 1.2.2.1  2003/04/19 22:21:43  ddiego
#tested the code developed in windows using gtk in linux. Seems to work ok except for a
#few minor compiler glitches. Had to comment out the partial specialization for
#floating point image bits in include/graphics/ImageBits.h. Also made some
#adjustments in the makefiles for building the GraphicsKit and ApplicationKit
#from the build/make/Makefile.
#
#Revision 1.2  2003/02/26 04:30:25  ddiego
#merge of code in the devmain-0-5-9 branch into the current tree.
#most additions are in the area of the current linux port, but the major
#addition to this release is the addition of a Condition class (currently
#still under development) and the change over to using the Delegate class
#exclusively from the older event handler macros.
#
#Revision 1.1.2.3  2003/02/08 17:55:44  ddiego
#modified the makefiles to have cvs Log entries, so we can keepo track of
#whats going on :)
#
#
#
#
#Object files for the ApplicationKit 
#
###########################################################



###########################################################
#Debug files
###########################################################

$(OUTDIR_AK_D)/ApplicationKit.o : $(SRC_APPKIT)/ApplicationKit.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ApplicationKit.cpp -o $(OUTDIR_AK_D)/ApplicationKit.o


$(OUTDIR_AK_D)/AbstractApplication.o : $(SRC_APPKIT)/AbstractApplication.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/AbstractApplication.cpp -o $(OUTDIR_AK_D)/AbstractApplication.o

$(OUTDIR_AK_D)/AbstractCommand.o : $(SRC_APPKIT)/AbstractCommand.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/AbstractCommand.cpp -o $(OUTDIR_AK_D)/AbstractCommand.o

$(OUTDIR_AK_D)/AbstractComponentEditor.o : $(SRC_APPKIT)/AbstractComponentEditor.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/AbstractComponentEditor.cpp -o $(OUTDIR_AK_D)/AbstractComponentEditor.o

$(OUTDIR_AK_D)/AbstractContainer.o : $(SRC_APPKIT)/AbstractContainer.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/AbstractContainer.cpp -o $(OUTDIR_AK_D)/AbstractContainer.o

$(OUTDIR_AK_D)/AbstractListModel.o : $(SRC_APPKIT)/AbstractListModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/AbstractListModel.cpp -o $(OUTDIR_AK_D)/AbstractListModel.o

$(OUTDIR_AK_D)/AbstractPropertyEditor.o : $(SRC_APPKIT)/AbstractPropertyEditor.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/AbstractPropertyEditor.cpp -o $(OUTDIR_AK_D)/AbstractPropertyEditor.o

$(OUTDIR_AK_D)/AbstractScrollable.o : $(SRC_APPKIT)/AbstractScrollable.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/AbstractScrollable.cpp -o $(OUTDIR_AK_D)/AbstractScrollable.o

$(OUTDIR_AK_D)/AbstractTableModel.o : $(SRC_APPKIT)/AbstractTableModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/AbstractTableModel.cpp -o $(OUTDIR_AK_D)/AbstractTableModel.o

$(OUTDIR_AK_D)/AbstractTextModel.o : $(SRC_APPKIT)/AbstractTextModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/AbstractTextModel.cpp -o $(OUTDIR_AK_D)/AbstractTextModel.o

$(OUTDIR_AK_D)/AbstractTreeModel.o : $(SRC_APPKIT)/AbstractTreeModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/AbstractTreeModel.cpp -o $(OUTDIR_AK_D)/AbstractTreeModel.o

$(OUTDIR_AK_D)/AbstractView.o : $(SRC_APPKIT)/AbstractView.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/AbstractView.cpp -o $(OUTDIR_AK_D)/AbstractView.o

$(OUTDIR_AK_D)/AcceleratorKey.o : $(SRC_APPKIT)/AcceleratorKey.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/AcceleratorKey.cpp -o $(OUTDIR_AK_D)/AcceleratorKey.o

$(OUTDIR_AK_D)/Application.o : $(SRC_APPKIT)/Application.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Application.cpp -o $(OUTDIR_AK_D)/Application.o

$(OUTDIR_AK_D)/Basic3DBorder.o : $(SRC_APPKIT)/Basic3DBorder.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Basic3DBorder.cpp -o $(OUTDIR_AK_D)/Basic3DBorder.o

$(OUTDIR_AK_D)/BasicTableItemEditor.o : $(SRC_APPKIT)/BasicTableItemEditor.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/BasicTableItemEditor.cpp -o $(OUTDIR_AK_D)/BasicTableItemEditor.o

$(OUTDIR_AK_D)/ButtonEvent.o : $(SRC_APPKIT)/ButtonEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ButtonEvent.cpp -o $(OUTDIR_AK_D)/ButtonEvent.o

$(OUTDIR_AK_D)/CheckBoxControl.o : $(SRC_APPKIT)/CheckBoxControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/CheckBoxControl.cpp -o $(OUTDIR_AK_D)/CheckBoxControl.o

$(OUTDIR_AK_D)/Clipboard.o : $(SRC_APPKIT)/Clipboard.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Clipboard.cpp -o $(OUTDIR_AK_D)/Clipboard.o

$(OUTDIR_AK_D)/DataObject.o : $(SRC_APPKIT)/DataObject.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DataObject.cpp -o $(OUTDIR_AK_D)/DataObject.o

$(OUTDIR_AK_D)/ClipboardEvent.o : $(SRC_APPKIT)/ClipboardEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ClipboardEvent.cpp -o $(OUTDIR_AK_D)/ClipboardEvent.o

$(OUTDIR_AK_D)/ColumnItemEvent.o : $(SRC_APPKIT)/ColumnItemEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ColumnItemEvent.cpp -o $(OUTDIR_AK_D)/ColumnItemEvent.o

$(OUTDIR_AK_D)/ColumnModelEvent.o : $(SRC_APPKIT)/ColumnModelEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ColumnModelEvent.cpp -o $(OUTDIR_AK_D)/ColumnModelEvent.o

$(OUTDIR_AK_D)/ComboBoxControl.o : $(SRC_APPKIT)/ComboBoxControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ComboBoxControl.cpp -o $(OUTDIR_AK_D)/ComboBoxControl.o

$(OUTDIR_AK_D)/CommandButton.o : $(SRC_APPKIT)/CommandButton.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/CommandButton.cpp -o $(OUTDIR_AK_D)/CommandButton.o

$(OUTDIR_AK_D)/CommandGroup.o : $(SRC_APPKIT)/CommandGroup.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/CommandGroup.cpp -o $(OUTDIR_AK_D)/CommandGroup.o

$(OUTDIR_AK_D)/CommonColor.o : $(SRC_APPKIT)/CommonColor.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/CommonColor.cpp -o $(OUTDIR_AK_D)/CommonColor.o

$(OUTDIR_AK_D)/CommonFileBrowse.o : $(SRC_APPKIT)/CommonFileBrowse.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/CommonFileBrowse.cpp -o $(OUTDIR_AK_D)/CommonFileBrowse.o

$(OUTDIR_AK_D)/CommonFileDialog.o : $(SRC_APPKIT)/CommonFileDialog.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/CommonFileDialog.cpp -o $(OUTDIR_AK_D)/CommonFileDialog.o

$(OUTDIR_AK_D)/CommonFileOpen.o : $(SRC_APPKIT)/CommonFileOpen.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/CommonFileOpen.cpp -o $(OUTDIR_AK_D)/CommonFileOpen.o

$(OUTDIR_AK_D)/CommonFileSave.o : $(SRC_APPKIT)/CommonFileSave.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/CommonFileSave.cpp -o $(OUTDIR_AK_D)/CommonFileSave.o

$(OUTDIR_AK_D)/CommonFont.o : $(SRC_APPKIT)/CommonFont.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/CommonFont.cpp -o $(OUTDIR_AK_D)/CommonFont.o

$(OUTDIR_AK_D)/CommonPrint.o : $(SRC_APPKIT)/CommonPrint.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/CommonPrint.cpp -o $(OUTDIR_AK_D)/CommonPrint.o

$(OUTDIR_AK_D)/Component.o : $(SRC_APPKIT)/Component.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Component.cpp -o $(OUTDIR_AK_D)/Component.o

$(OUTDIR_AK_D)/ComponentEditorManager.o : $(SRC_APPKIT)/ComponentEditorManager.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ComponentEditorManager.cpp -o $(OUTDIR_AK_D)/ComponentEditorManager.o

$(OUTDIR_AK_D)/ComponentInfo.o : $(SRC_APPKIT)/ComponentInfo.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ComponentInfo.cpp -o $(OUTDIR_AK_D)/ComponentInfo.o

$(OUTDIR_AK_D)/Action.o : $(SRC_APPKIT)/Action.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Action.cpp -o $(OUTDIR_AK_D)/Action.o
	
$(OUTDIR_AK_D)/Control.o : $(SRC_APPKIT)/Control.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Control.cpp -o $(OUTDIR_AK_D)/Control.o

$(OUTDIR_AK_D)/ControlContainer.o : $(SRC_APPKIT)/ControlContainer.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ControlContainer.cpp -o $(OUTDIR_AK_D)/ControlContainer.o

$(OUTDIR_AK_D)/ControlEvent.o : $(SRC_APPKIT)/ControlEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ControlEvent.cpp -o $(OUTDIR_AK_D)/ControlEvent.o

$(OUTDIR_AK_D)/ControlGraphicsContext.o : $(SRC_APPKIT)/ControlGraphicsContext.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ControlGraphicsContext.cpp -o $(OUTDIR_AK_D)/ControlGraphicsContext.o

$(OUTDIR_AK_D)/Cursor.o : $(SRC_APPKIT)/Cursor.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Cursor.cpp -o $(OUTDIR_AK_D)/Cursor.o

$(OUTDIR_AK_D)/CursorManager.o : $(SRC_APPKIT)/CursorManager.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/CursorManager.cpp -o $(OUTDIR_AK_D)/CursorManager.o

$(OUTDIR_AK_D)/CustomControl.o : $(SRC_APPKIT)/CustomControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/CustomControl.cpp -o $(OUTDIR_AK_D)/CustomControl.o


$(OUTDIR_AK_D)/DefaultColumnItem.o : $(SRC_APPKIT)/DefaultColumnItem.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DefaultColumnItem.cpp -o $(OUTDIR_AK_D)/DefaultColumnItem.o

$(OUTDIR_AK_D)/DefaultColumnModel.o : $(SRC_APPKIT)/DefaultColumnModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DefaultColumnModel.cpp -o $(OUTDIR_AK_D)/DefaultColumnModel.o

$(OUTDIR_AK_D)/DefaultListItem.o : $(SRC_APPKIT)/DefaultListItem.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DefaultListItem.cpp -o $(OUTDIR_AK_D)/DefaultListItem.o

$(OUTDIR_AK_D)/DefaultListModel.o : $(SRC_APPKIT)/DefaultListModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DefaultListModel.cpp -o $(OUTDIR_AK_D)/DefaultListModel.o

$(OUTDIR_AK_D)/DefaultMenuItem.o : $(SRC_APPKIT)/DefaultMenuItem.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DefaultMenuItem.cpp -o $(OUTDIR_AK_D)/DefaultMenuItem.o

$(OUTDIR_AK_D)/DefaultPropertyEditors.o : $(SRC_APPKIT)/DefaultPropertyEditors.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DefaultPropertyEditors.cpp -o $(OUTDIR_AK_D)/DefaultPropertyEditors.o

$(OUTDIR_AK_D)/DefaultTableCellItem.o : $(SRC_APPKIT)/DefaultTableCellItem.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DefaultTableCellItem.cpp -o $(OUTDIR_AK_D)/DefaultTableCellItem.o

$(OUTDIR_AK_D)/DefaultTableModel.o : $(SRC_APPKIT)/DefaultTableModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DefaultTableModel.cpp -o $(OUTDIR_AK_D)/DefaultTableModel.o

$(OUTDIR_AK_D)/DefaultTabModel.o : $(SRC_APPKIT)/DefaultTabModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DefaultTabModel.cpp -o $(OUTDIR_AK_D)/DefaultTabModel.o

$(OUTDIR_AK_D)/DefaultTabPage.o : $(SRC_APPKIT)/DefaultTabPage.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DefaultTabPage.cpp -o $(OUTDIR_AK_D)/DefaultTabPage.o

$(OUTDIR_AK_D)/DefaultTextModel.o : $(SRC_APPKIT)/DefaultTextModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DefaultTextModel.cpp -o $(OUTDIR_AK_D)/DefaultTextModel.o

$(OUTDIR_AK_D)/DefaultTreeItem.o : $(SRC_APPKIT)/DefaultTreeItem.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DefaultTreeItem.cpp -o $(OUTDIR_AK_D)/DefaultTreeItem.o

$(OUTDIR_AK_D)/DefaultTreeModel.o : $(SRC_APPKIT)/DefaultTreeModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DefaultTreeModel.cpp -o $(OUTDIR_AK_D)/DefaultTreeModel.o

$(OUTDIR_AK_D)/Desktop.o : $(SRC_APPKIT)/Desktop.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Desktop.cpp -o $(OUTDIR_AK_D)/Desktop.o

$(OUTDIR_AK_D)/Dialog.o : $(SRC_APPKIT)/Dialog.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Dialog.cpp -o $(OUTDIR_AK_D)/Dialog.o


$(OUTDIR_AK_D)/DragSource.o : $(SRC_APPKIT)/DragSource.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DragSource.cpp -o $(OUTDIR_AK_D)/DragSource.o


$(OUTDIR_AK_D)/DropTarget.o : $(SRC_APPKIT)/DropTarget.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DropTarget.cpp -o $(OUTDIR_AK_D)/DropTarget.o

$(OUTDIR_AK_D)/FocusEvent.o : $(SRC_APPKIT)/FocusEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/FocusEvent.cpp -o $(OUTDIR_AK_D)/FocusEvent.o

$(OUTDIR_AK_D)/Frame.o : $(SRC_APPKIT)/Frame.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Frame.cpp -o $(OUTDIR_AK_D)/Frame.o

$(OUTDIR_AK_D)/HeaderControl.o : $(SRC_APPKIT)/HeaderControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/HeaderControl.cpp -o $(OUTDIR_AK_D)/HeaderControl.o

$(OUTDIR_AK_D)/HelpEvent.o : $(SRC_APPKIT)/HelpEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/HelpEvent.cpp -o $(OUTDIR_AK_D)/HelpEvent.o

$(OUTDIR_AK_D)/HTMLBrowserControl.o : $(SRC_APPKIT)/HTMLBrowserControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/HTMLBrowserControl.cpp -o $(OUTDIR_AK_D)/HTMLBrowserControl.o

$(OUTDIR_AK_D)/ImageControl.o : $(SRC_APPKIT)/ImageControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ImageControl.cpp -o $(OUTDIR_AK_D)/ImageControl.o

$(OUTDIR_AK_D)/ImageList.o : $(SRC_APPKIT)/ImageList.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ImageList.cpp -o $(OUTDIR_AK_D)/ImageList.o

$(OUTDIR_AK_D)/ImageListEvent.o : $(SRC_APPKIT)/ImageListEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ImageListEvent.cpp -o $(OUTDIR_AK_D)/ImageListEvent.o

$(OUTDIR_AK_D)/ItemEvent.o : $(SRC_APPKIT)/ItemEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ItemEvent.cpp -o $(OUTDIR_AK_D)/ItemEvent.o

$(OUTDIR_AK_D)/KeyboardEvent.o : $(SRC_APPKIT)/KeyboardEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/KeyboardEvent.cpp -o $(OUTDIR_AK_D)/KeyboardEvent.o

$(OUTDIR_AK_D)/Label.o : $(SRC_APPKIT)/Label.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Label.cpp -o $(OUTDIR_AK_D)/Label.o

$(OUTDIR_AK_D)/LibraryApplication.o : $(SRC_APPKIT)/LibraryApplication.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/LibraryApplication.cpp -o $(OUTDIR_AK_D)/LibraryApplication.o

$(OUTDIR_AK_D)/Light3DBorder.o : $(SRC_APPKIT)/Light3DBorder.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Light3DBorder.cpp -o $(OUTDIR_AK_D)/Light3DBorder.o
	
$(OUTDIR_AK_D)/EtchedBorder.o : $(SRC_APPKIT)/EtchedBorder.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/EtchedBorder.cpp -o $(OUTDIR_AK_D)/EtchedBorder.o
	
$(OUTDIR_AK_D)/ColorEtchedBorder.o : $(SRC_APPKIT)/ColorEtchedBorder.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ColorEtchedBorder.cpp -o $(OUTDIR_AK_D)/ColorEtchedBorder.o		
	
$(OUTDIR_AK_D)/TitledBorder.o : $(SRC_APPKIT)/TitledBorder.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/TitledBorder.cpp -o $(OUTDIR_AK_D)/TitledBorder.o			

$(OUTDIR_AK_D)/LightweightComponent.o : $(SRC_APPKIT)/LightweightComponent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/LightweightComponent.cpp -o $(OUTDIR_AK_D)/LightweightComponent.o

$(OUTDIR_AK_D)/ListBoxControl.o : $(SRC_APPKIT)/ListBoxControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ListBoxControl.cpp -o $(OUTDIR_AK_D)/ListBoxControl.o

$(OUTDIR_AK_D)/ListModelEvent.o : $(SRC_APPKIT)/ListModelEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ListModelEvent.cpp -o $(OUTDIR_AK_D)/ListModelEvent.o

$(OUTDIR_AK_D)/ListViewControl.o : $(SRC_APPKIT)/ListViewControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ListViewControl.cpp -o $(OUTDIR_AK_D)/ListViewControl.o

$(OUTDIR_AK_D)/Menu.o : $(SRC_APPKIT)/Menu.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Menu.cpp -o $(OUTDIR_AK_D)/Menu.o

$(OUTDIR_AK_D)/MenuBar.o : $(SRC_APPKIT)/MenuBar.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/MenuBar.cpp -o $(OUTDIR_AK_D)/MenuBar.o

$(OUTDIR_AK_D)/MenuItemEvent.o : $(SRC_APPKIT)/MenuItemEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/MenuItemEvent.cpp -o $(OUTDIR_AK_D)/MenuItemEvent.o

$(OUTDIR_AK_D)/Model.o : $(SRC_APPKIT)/Model.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Model.cpp -o $(OUTDIR_AK_D)/Model.o

$(OUTDIR_AK_D)/MouseEvent.o : $(SRC_APPKIT)/MouseEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/MouseEvent.cpp -o $(OUTDIR_AK_D)/MouseEvent.o

$(OUTDIR_AK_D)/MultilineTextControl.o : $(SRC_APPKIT)/MultilineTextControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/MultilineTextControl.cpp -o $(OUTDIR_AK_D)/MultilineTextControl.o

$(OUTDIR_AK_D)/Panel.o : $(SRC_APPKIT)/Panel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Panel.cpp -o $(OUTDIR_AK_D)/Panel.o

$(OUTDIR_AK_D)/PopupMenu.o : $(SRC_APPKIT)/PopupMenu.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/PopupMenu.cpp -o $(OUTDIR_AK_D)/PopupMenu.o

$(OUTDIR_AK_D)/ProgressControl.o : $(SRC_APPKIT)/ProgressControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ProgressControl.cpp -o $(OUTDIR_AK_D)/ProgressControl.o	
	
$(OUTDIR_AK_D)/PropertyEditorManager.o : $(SRC_APPKIT)/PropertyEditorManager.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/PropertyEditorManager.cpp -o $(OUTDIR_AK_D)/PropertyEditorManager.o

$(OUTDIR_AK_D)/PushButton.o : $(SRC_APPKIT)/PushButton.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/PushButton.cpp -o $(OUTDIR_AK_D)/PushButton.o

$(OUTDIR_AK_D)/RadioButtonControl.o : $(SRC_APPKIT)/RadioButtonControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/RadioButtonControl.cpp -o $(OUTDIR_AK_D)/RadioButtonControl.o

$(OUTDIR_AK_D)/Resource.o : $(SRC_APPKIT)/Resource.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Resource.cpp -o $(OUTDIR_AK_D)/Resource.o

$(OUTDIR_AK_D)/ResourceStream.o : $(SRC_APPKIT)/ResourceStream.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ResourceStream.cpp -o $(OUTDIR_AK_D)/ResourceStream.o

$(OUTDIR_AK_D)/SliderControl.o : $(SRC_APPKIT)/SliderControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/SliderControl.cpp -o $(OUTDIR_AK_D)/SliderControl.o

$(OUTDIR_AK_D)/ScrollbarManager.o : $(SRC_APPKIT)/ScrollbarManager.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ScrollbarManager.cpp -o $(OUTDIR_AK_D)/ScrollbarManager.o
	
$(OUTDIR_AK_D)/Splitter.o : $(SRC_APPKIT)/Splitter.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Splitter.cpp -o $(OUTDIR_AK_D)/Splitter.o

$(OUTDIR_AK_D)/StatusBar.o : $(SRC_APPKIT)/StatusBar.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/StatusBar.cpp -o $(OUTDIR_AK_D)/StatusBar.o

$(OUTDIR_AK_D)/TabbedPages.o : $(SRC_APPKIT)/TabbedPages.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/TabbedPages.cpp -o $(OUTDIR_AK_D)/TabbedPages.o

$(OUTDIR_AK_D)/TableControl.o : $(SRC_APPKIT)/TableControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/TableControl.cpp -o $(OUTDIR_AK_D)/TableControl.o

$(OUTDIR_AK_D)/TableModelEvent.o : $(SRC_APPKIT)/TableModelEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/TableModelEvent.cpp -o $(OUTDIR_AK_D)/TableModelEvent.o

$(OUTDIR_AK_D)/TabModelEvent.o : $(SRC_APPKIT)/TabModelEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/TabModelEvent.cpp -o $(OUTDIR_AK_D)/TabModelEvent.o

$(OUTDIR_AK_D)/TextControl.o : $(SRC_APPKIT)/TextControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/TextControl.cpp -o $(OUTDIR_AK_D)/TextControl.o

$(OUTDIR_AK_D)/TextEvent.o : $(SRC_APPKIT)/TextEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/TextEvent.cpp -o $(OUTDIR_AK_D)/TextEvent.o

$(OUTDIR_AK_D)/TimerComponent.o : $(SRC_APPKIT)/TimerComponent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/TimerComponent.cpp -o $(OUTDIR_AK_D)/TimerComponent.o

$(OUTDIR_AK_D)/TimerEvent.o : $(SRC_APPKIT)/TimerEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/TimerEvent.cpp -o $(OUTDIR_AK_D)/TimerEvent.o

$(OUTDIR_AK_D)/ToggledButton.o : $(SRC_APPKIT)/ToggledButton.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ToggledButton.cpp -o $(OUTDIR_AK_D)/ToggledButton.o

$(OUTDIR_AK_D)/Toolbar.o : $(SRC_APPKIT)/Toolbar.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Toolbar.cpp -o $(OUTDIR_AK_D)/Toolbar.o


$(OUTDIR_AK_D)/ToolbarDock.o : $(SRC_APPKIT)/ToolbarDock.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ToolbarDock.cpp -o $(OUTDIR_AK_D)/ToolbarDock.o


$(OUTDIR_AK_D)/ToolTipEvent.o : $(SRC_APPKIT)/ToolTipEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ToolTipEvent.cpp -o $(OUTDIR_AK_D)/ToolTipEvent.o

$(OUTDIR_AK_D)/TreeControl.o : $(SRC_APPKIT)/TreeControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/TreeControl.cpp -o $(OUTDIR_AK_D)/TreeControl.o

$(OUTDIR_AK_D)/TreeListControl.o : $(SRC_APPKIT)/TreeListControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/TreeListControl.cpp -o $(OUTDIR_AK_D)/TreeListControl.o

$(OUTDIR_AK_D)/TreeModelEvent.o : $(SRC_APPKIT)/TreeModelEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/TreeModelEvent.cpp -o $(OUTDIR_AK_D)/TreeModelEvent.o

$(OUTDIR_AK_D)/UIToolkit.o : $(SRC_APPKIT)/UIToolkit.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/UIToolkit.cpp -o $(OUTDIR_AK_D)/UIToolkit.o

$(OUTDIR_AK_D)/UndoRedoEvent.o : $(SRC_APPKIT)/UndoRedoEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/UndoRedoEvent.cpp -o $(OUTDIR_AK_D)/UndoRedoEvent.o

$(OUTDIR_AK_D)/UndoRedoStack.o : $(SRC_APPKIT)/UndoRedoStack.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/UndoRedoStack.cpp -o $(OUTDIR_AK_D)/UndoRedoStack.o

$(OUTDIR_AK_D)/ValidationEvent.o : $(SRC_APPKIT)/ValidationEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/ValidationEvent.cpp -o $(OUTDIR_AK_D)/ValidationEvent.o

$(OUTDIR_AK_D)/VFFInputStream.o : $(SRC_APPKIT)/VFFInputStream.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/VFFInputStream.cpp -o $(OUTDIR_AK_D)/VFFInputStream.o

$(OUTDIR_AK_D)/VFFOutputStream.o : $(SRC_APPKIT)/VFFOutputStream.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/VFFOutputStream.cpp -o $(OUTDIR_AK_D)/VFFOutputStream.o

$(OUTDIR_AK_D)/WhatsThisHelpEvent.o : $(SRC_APPKIT)/WhatsThisHelpEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/WhatsThisHelpEvent.cpp -o $(OUTDIR_AK_D)/WhatsThisHelpEvent.o

$(OUTDIR_AK_D)/Window.o : $(SRC_APPKIT)/Window.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Window.cpp -o $(OUTDIR_AK_D)/Window.o

$(OUTDIR_AK_D)/WindowEvent.o : $(SRC_APPKIT)/WindowEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/WindowEvent.cpp -o $(OUTDIR_AK_D)/WindowEvent.o
	
$(OUTDIR_AK_D)/Containers.o : $(SRC_APPKIT)/Containers.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/Containers.cpp -o $(OUTDIR_AK_D)/Containers.o	
	
#$(OUTDIR_AK_D)/PackageInfo.o : $(SRC_APPKIT)/PackageInfo.cpp $(APPKIT_HDRS)
#	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/PackageInfo.cpp -o $(OUTDIR_AK_D)/PackageInfo.o		

$(OUTDIR_AK_D)/DocumentManager.o : $(SRC_APPKIT)/DocumentManager.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/DocumentManager.cpp -o $(OUTDIR_AK_D)/DocumentManager.o	

$(OUTDIR_AK_D)/MessageDialog.o : $(SRC_APPKIT)/MessageDialog.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/MessageDialog.cpp -o $(OUTDIR_AK_D)/MessageDialog.o		

$(OUTDIR_AK_D)/GTKUIToolkit.o : $(SRC_APPKIT)/GTKUIToolkit.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/GTKUIToolkit.cpp -o $(OUTDIR_AK_D)/GTKUIToolkit.o

$(OUTDIR_AK_D)/GTKDesktop.o : $(SRC_APPKIT)/GTKDesktop.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/GTKDesktop.cpp -o $(OUTDIR_AK_D)/GTKDesktop.o

$(OUTDIR_AK_D)/GTKApplication.o : $(SRC_APPKIT)/GTKApplication.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/GTKApplication.cpp -o $(OUTDIR_AK_D)/GTKApplication.o

$(OUTDIR_AK_D)/AbstractGTKControl.o : $(SRC_APPKIT)/AbstractGTKControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/AbstractGTKControl.cpp -o $(OUTDIR_AK_D)/AbstractGTKControl.o

$(OUTDIR_AK_D)/GTKControl.o : $(SRC_APPKIT)/GTKControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/GTKControl.cpp -o $(OUTDIR_AK_D)/GTKControl.o

$(OUTDIR_AK_D)/GTKWindow.o : $(SRC_APPKIT)/GTKWindow.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/GTKWindow.cpp -o $(OUTDIR_AK_D)/GTKWindow.o

$(OUTDIR_AK_D)/GTKControlContext.o : $(SRC_APPKIT)/GTKControlContext.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/GTKControlContext.cpp -o $(OUTDIR_AK_D)/GTKControlContext.o

$(OUTDIR_AK_D)/GTKCursor.o : $(SRC_APPKIT)/GTKCursor.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/GTKCursor.cpp -o $(OUTDIR_AK_D)/GTKCursor.o
	
$(OUTDIR_AK_D)/GTKDialog.o : $(SRC_APPKIT)/GTKDialog.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/GTKDialog.cpp -o $(OUTDIR_AK_D)/GTKDialog.o	

$(OUTDIR_AK_D)/GTKTextControl.o : $(SRC_APPKIT)/GTKTextControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/GTKTextControl.cpp -o $(OUTDIR_AK_D)/GTKTextControl.o	
	
$(OUTDIR_AK_D)/GTKFileOpenDialog.o : $(SRC_APPKIT)/GTKFileOpenDialog.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/GTKFileOpenDialog.cpp -o $(OUTDIR_AK_D)/GTKFileOpenDialog.o		
	
$(OUTDIR_AK_D)/GTKCommandButton.o : $(SRC_APPKIT)/GTKCommandButton.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/GTKCommandButton.cpp -o $(OUTDIR_AK_D)/GTKCommandButton.o			

$(OUTDIR_AK_D)/GTKToolbar.o : $(SRC_APPKIT)/GTKToolbar.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS_D) $(SRC_APPKIT)/GTKToolbar.cpp -o $(OUTDIR_AK_D)/GTKToolbar.o			





###########################################################
#Release files
###########################################################




$(OUTDIR_AK)/ApplicationKit.o : $(SRC_APPKIT)/ApplicationKit.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ApplicationKit.cpp -o $(OUTDIR_AK)/ApplicationKit.o


$(OUTDIR_AK)/AbstractApplication.o : $(SRC_APPKIT)/AbstractApplication.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/AbstractApplication.cpp -o $(OUTDIR_AK)/AbstractApplication.o

$(OUTDIR_AK)/AbstractCommand.o : $(SRC_APPKIT)/AbstractCommand.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/AbstractCommand.cpp -o $(OUTDIR_AK)/AbstractCommand.o

$(OUTDIR_AK)/AbstractComponentEditor.o : $(SRC_APPKIT)/AbstractComponentEditor.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/AbstractComponentEditor.cpp -o $(OUTDIR_AK)/AbstractComponentEditor.o

$(OUTDIR_AK)/AbstractContainer.o : $(SRC_APPKIT)/AbstractContainer.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/AbstractContainer.cpp -o $(OUTDIR_AK)/AbstractContainer.o

$(OUTDIR_AK)/AbstractListModel.o : $(SRC_APPKIT)/AbstractListModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/AbstractListModel.cpp -o $(OUTDIR_AK)/AbstractListModel.o

$(OUTDIR_AK)/AbstractPropertyEditor.o : $(SRC_APPKIT)/AbstractPropertyEditor.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/AbstractPropertyEditor.cpp -o $(OUTDIR_AK)/AbstractPropertyEditor.o

$(OUTDIR_AK)/AbstractScrollable.o : $(SRC_APPKIT)/AbstractScrollable.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/AbstractScrollable.cpp -o $(OUTDIR_AK)/AbstractScrollable.o

$(OUTDIR_AK)/AbstractTableModel.o : $(SRC_APPKIT)/AbstractTableModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/AbstractTableModel.cpp -o $(OUTDIR_AK)/AbstractTableModel.o

$(OUTDIR_AK)/AbstractTextModel.o : $(SRC_APPKIT)/AbstractTextModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/AbstractTextModel.cpp -o $(OUTDIR_AK)/AbstractTextModel.o

$(OUTDIR_AK)/AbstractTreeModel.o : $(SRC_APPKIT)/AbstractTreeModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/AbstractTreeModel.cpp -o $(OUTDIR_AK)/AbstractTreeModel.o

$(OUTDIR_AK)/AbstractView.o : $(SRC_APPKIT)/AbstractView.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/AbstractView.cpp -o $(OUTDIR_AK)/AbstractView.o

$(OUTDIR_AK)/AcceleratorKey.o : $(SRC_APPKIT)/AcceleratorKey.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/AcceleratorKey.cpp -o $(OUTDIR_AK)/AcceleratorKey.o

$(OUTDIR_AK)/Application.o : $(SRC_APPKIT)/Application.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Application.cpp -o $(OUTDIR_AK)/Application.o

$(OUTDIR_AK)/Basic3DBorder.o : $(SRC_APPKIT)/Basic3DBorder.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Basic3DBorder.cpp -o $(OUTDIR_AK)/Basic3DBorder.o

$(OUTDIR_AK)/BasicTableItemEditor.o : $(SRC_APPKIT)/BasicTableItemEditor.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/BasicTableItemEditor.cpp -o $(OUTDIR_AK)/BasicTableItemEditor.o

$(OUTDIR_AK)/ButtonEvent.o : $(SRC_APPKIT)/ButtonEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ButtonEvent.cpp -o $(OUTDIR_AK)/ButtonEvent.o

$(OUTDIR_AK)/CheckBoxControl.o : $(SRC_APPKIT)/CheckBoxControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/CheckBoxControl.cpp -o $(OUTDIR_AK)/CheckBoxControl.o

$(OUTDIR_AK)/Clipboard.o : $(SRC_APPKIT)/Clipboard.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Clipboard.cpp -o $(OUTDIR_AK)/Clipboard.o

$(OUTDIR_AK)/DataObject.o : $(SRC_APPKIT)/DataObject.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DataObject.cpp -o $(OUTDIR_AK)/DataObject.o

$(OUTDIR_AK)/ClipboardEvent.o : $(SRC_APPKIT)/ClipboardEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ClipboardEvent.cpp -o $(OUTDIR_AK)/ClipboardEvent.o

$(OUTDIR_AK)/ColumnItemEvent.o : $(SRC_APPKIT)/ColumnItemEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ColumnItemEvent.cpp -o $(OUTDIR_AK)/ColumnItemEvent.o

$(OUTDIR_AK)/ColumnModelEvent.o : $(SRC_APPKIT)/ColumnModelEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ColumnModelEvent.cpp -o $(OUTDIR_AK)/ColumnModelEvent.o

$(OUTDIR_AK)/ComboBoxControl.o : $(SRC_APPKIT)/ComboBoxControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ComboBoxControl.cpp -o $(OUTDIR_AK)/ComboBoxControl.o

$(OUTDIR_AK)/CommandButton.o : $(SRC_APPKIT)/CommandButton.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/CommandButton.cpp -o $(OUTDIR_AK)/CommandButton.o

$(OUTDIR_AK)/CommandGroup.o : $(SRC_APPKIT)/CommandGroup.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/CommandGroup.cpp -o $(OUTDIR_AK)/CommandGroup.o

$(OUTDIR_AK)/CommonColor.o : $(SRC_APPKIT)/CommonColor.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/CommonColor.cpp -o $(OUTDIR_AK)/CommonColor.o

$(OUTDIR_AK)/CommonFileBrowse.o : $(SRC_APPKIT)/CommonFileBrowse.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/CommonFileBrowse.cpp -o $(OUTDIR_AK)/CommonFileBrowse.o

$(OUTDIR_AK)/CommonFileDialog.o : $(SRC_APPKIT)/CommonFileDialog.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/CommonFileDialog.cpp -o $(OUTDIR_AK)/CommonFileDialog.o

$(OUTDIR_AK)/CommonFileOpen.o : $(SRC_APPKIT)/CommonFileOpen.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/CommonFileOpen.cpp -o $(OUTDIR_AK)/CommonFileOpen.o

$(OUTDIR_AK)/CommonFileSave.o : $(SRC_APPKIT)/CommonFileSave.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/CommonFileSave.cpp -o $(OUTDIR_AK)/CommonFileSave.o

$(OUTDIR_AK)/CommonFont.o : $(SRC_APPKIT)/CommonFont.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/CommonFont.cpp -o $(OUTDIR_AK)/CommonFont.o

$(OUTDIR_AK)/CommonPrint.o : $(SRC_APPKIT)/CommonPrint.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/CommonPrint.cpp -o $(OUTDIR_AK)/CommonPrint.o

$(OUTDIR_AK)/Component.o : $(SRC_APPKIT)/Component.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Component.cpp -o $(OUTDIR_AK)/Component.o

$(OUTDIR_AK)/ComponentEditorManager.o : $(SRC_APPKIT)/ComponentEditorManager.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ComponentEditorManager.cpp -o $(OUTDIR_AK)/ComponentEditorManager.o

$(OUTDIR_AK)/ComponentInfo.o : $(SRC_APPKIT)/ComponentInfo.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ComponentInfo.cpp -o $(OUTDIR_AK)/ComponentInfo.o

$(OUTDIR_AK)/Action.o : $(SRC_APPKIT)/Action.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Action.cpp -o $(OUTDIR_AK)/Action.o
	
$(OUTDIR_AK)/Control.o : $(SRC_APPKIT)/Control.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Control.cpp -o $(OUTDIR_AK)/Control.o

$(OUTDIR_AK)/ControlContainer.o : $(SRC_APPKIT)/ControlContainer.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ControlContainer.cpp -o $(OUTDIR_AK)/ControlContainer.o

$(OUTDIR_AK)/ControlEvent.o : $(SRC_APPKIT)/ControlEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ControlEvent.cpp -o $(OUTDIR_AK)/ControlEvent.o

$(OUTDIR_AK)/ControlGraphicsContext.o : $(SRC_APPKIT)/ControlGraphicsContext.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ControlGraphicsContext.cpp -o $(OUTDIR_AK)/ControlGraphicsContext.o

$(OUTDIR_AK)/Cursor.o : $(SRC_APPKIT)/Cursor.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Cursor.cpp -o $(OUTDIR_AK)/Cursor.o

$(OUTDIR_AK)/CursorManager.o : $(SRC_APPKIT)/CursorManager.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/CursorManager.cpp -o $(OUTDIR_AK)/CursorManager.o

$(OUTDIR_AK)/CustomControl.o : $(SRC_APPKIT)/CustomControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/CustomControl.cpp -o $(OUTDIR_AK)/CustomControl.o


$(OUTDIR_AK)/DefaultColumnItem.o : $(SRC_APPKIT)/DefaultColumnItem.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DefaultColumnItem.cpp -o $(OUTDIR_AK)/DefaultColumnItem.o

$(OUTDIR_AK)/DefaultColumnModel.o : $(SRC_APPKIT)/DefaultColumnModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DefaultColumnModel.cpp -o $(OUTDIR_AK)/DefaultColumnModel.o

$(OUTDIR_AK)/DefaultListItem.o : $(SRC_APPKIT)/DefaultListItem.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DefaultListItem.cpp -o $(OUTDIR_AK)/DefaultListItem.o

$(OUTDIR_AK)/DefaultListModel.o : $(SRC_APPKIT)/DefaultListModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DefaultListModel.cpp -o $(OUTDIR_AK)/DefaultListModel.o

$(OUTDIR_AK)/DefaultMenuItem.o : $(SRC_APPKIT)/DefaultMenuItem.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DefaultMenuItem.cpp -o $(OUTDIR_AK)/DefaultMenuItem.o

$(OUTDIR_AK)/DefaultPropertyEditors.o : $(SRC_APPKIT)/DefaultPropertyEditors.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DefaultPropertyEditors.cpp -o $(OUTDIR_AK)/DefaultPropertyEditors.o

$(OUTDIR_AK)/DefaultTableCellItem.o : $(SRC_APPKIT)/DefaultTableCellItem.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DefaultTableCellItem.cpp -o $(OUTDIR_AK)/DefaultTableCellItem.o

$(OUTDIR_AK)/DefaultTableModel.o : $(SRC_APPKIT)/DefaultTableModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DefaultTableModel.cpp -o $(OUTDIR_AK)/DefaultTableModel.o

$(OUTDIR_AK)/DefaultTabModel.o : $(SRC_APPKIT)/DefaultTabModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DefaultTabModel.cpp -o $(OUTDIR_AK)/DefaultTabModel.o

$(OUTDIR_AK)/DefaultTabPage.o : $(SRC_APPKIT)/DefaultTabPage.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DefaultTabPage.cpp -o $(OUTDIR_AK)/DefaultTabPage.o

$(OUTDIR_AK)/DefaultTextModel.o : $(SRC_APPKIT)/DefaultTextModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DefaultTextModel.cpp -o $(OUTDIR_AK)/DefaultTextModel.o

$(OUTDIR_AK)/DefaultTreeItem.o : $(SRC_APPKIT)/DefaultTreeItem.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DefaultTreeItem.cpp -o $(OUTDIR_AK)/DefaultTreeItem.o

$(OUTDIR_AK)/DefaultTreeModel.o : $(SRC_APPKIT)/DefaultTreeModel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DefaultTreeModel.cpp -o $(OUTDIR_AK)/DefaultTreeModel.o

$(OUTDIR_AK)/Desktop.o : $(SRC_APPKIT)/Desktop.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Desktop.cpp -o $(OUTDIR_AK)/Desktop.o

$(OUTDIR_AK)/Dialog.o : $(SRC_APPKIT)/Dialog.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Dialog.cpp -o $(OUTDIR_AK)/Dialog.o


$(OUTDIR_AK)/DragSource.o : $(SRC_APPKIT)/DragSource.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DragSource.cpp -o $(OUTDIR_AK)/DragSource.o


$(OUTDIR_AK)/DropTarget.o : $(SRC_APPKIT)/DropTarget.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DropTarget.cpp -o $(OUTDIR_AK)/DropTarget.o

$(OUTDIR_AK)/FocusEvent.o : $(SRC_APPKIT)/FocusEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/FocusEvent.cpp -o $(OUTDIR_AK)/FocusEvent.o

$(OUTDIR_AK)/Frame.o : $(SRC_APPKIT)/Frame.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Frame.cpp -o $(OUTDIR_AK)/Frame.o

$(OUTDIR_AK)/HeaderControl.o : $(SRC_APPKIT)/HeaderControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/HeaderControl.cpp -o $(OUTDIR_AK)/HeaderControl.o

$(OUTDIR_AK)/HelpEvent.o : $(SRC_APPKIT)/HelpEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/HelpEvent.cpp -o $(OUTDIR_AK)/HelpEvent.o

$(OUTDIR_AK)/HTMLBrowserControl.o : $(SRC_APPKIT)/HTMLBrowserControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/HTMLBrowserControl.cpp -o $(OUTDIR_AK)/HTMLBrowserControl.o

$(OUTDIR_AK)/ImageControl.o : $(SRC_APPKIT)/ImageControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ImageControl.cpp -o $(OUTDIR_AK)/ImageControl.o

$(OUTDIR_AK)/ImageList.o : $(SRC_APPKIT)/ImageList.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ImageList.cpp -o $(OUTDIR_AK)/ImageList.o

$(OUTDIR_AK)/ImageListEvent.o : $(SRC_APPKIT)/ImageListEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ImageListEvent.cpp -o $(OUTDIR_AK)/ImageListEvent.o

$(OUTDIR_AK)/ItemEvent.o : $(SRC_APPKIT)/ItemEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ItemEvent.cpp -o $(OUTDIR_AK)/ItemEvent.o

$(OUTDIR_AK)/KeyboardEvent.o : $(SRC_APPKIT)/KeyboardEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/KeyboardEvent.cpp -o $(OUTDIR_AK)/KeyboardEvent.o

$(OUTDIR_AK)/Label.o : $(SRC_APPKIT)/Label.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Label.cpp -o $(OUTDIR_AK)/Label.o

$(OUTDIR_AK)/LibraryApplication.o : $(SRC_APPKIT)/LibraryApplication.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/LibraryApplication.cpp -o $(OUTDIR_AK)/LibraryApplication.o

$(OUTDIR_AK)/Light3DBorder.o : $(SRC_APPKIT)/Light3DBorder.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Light3DBorder.cpp -o $(OUTDIR_AK)/Light3DBorder.o
	
$(OUTDIR_AK)/EtchedBorder.o : $(SRC_APPKIT)/EtchedBorder.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/EtchedBorder.cpp -o $(OUTDIR_AK)/EtchedBorder.o	
	
$(OUTDIR_AK)/ColorEtchedBorder.o : $(SRC_APPKIT)/ColorEtchedBorder.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ColorEtchedBorder.cpp -o $(OUTDIR_AK)/ColorEtchedBorder.o		
	
$(OUTDIR_AK)/TitledBorder.o : $(SRC_APPKIT)/TitledBorder.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/TitledBorder.cpp -o $(OUTDIR_AK)/TitledBorder.o		

$(OUTDIR_AK)/LightweightComponent.o : $(SRC_APPKIT)/LightweightComponent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/LightweightComponent.cpp -o $(OUTDIR_AK)/LightweightComponent.o

$(OUTDIR_AK)/ListBoxControl.o : $(SRC_APPKIT)/ListBoxControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ListBoxControl.cpp -o $(OUTDIR_AK)/ListBoxControl.o

$(OUTDIR_AK)/ListModelEvent.o : $(SRC_APPKIT)/ListModelEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ListModelEvent.cpp -o $(OUTDIR_AK)/ListModelEvent.o

$(OUTDIR_AK)/ListViewControl.o : $(SRC_APPKIT)/ListViewControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ListViewControl.cpp -o $(OUTDIR_AK)/ListViewControl.o

$(OUTDIR_AK)/Menu.o : $(SRC_APPKIT)/Menu.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Menu.cpp -o $(OUTDIR_AK)/Menu.o

$(OUTDIR_AK)/MenuBar.o : $(SRC_APPKIT)/MenuBar.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/MenuBar.cpp -o $(OUTDIR_AK)/MenuBar.o

$(OUTDIR_AK)/MenuItemEvent.o : $(SRC_APPKIT)/MenuItemEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/MenuItemEvent.cpp -o $(OUTDIR_AK)/MenuItemEvent.o

$(OUTDIR_AK)/Model.o : $(SRC_APPKIT)/Model.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Model.cpp -o $(OUTDIR_AK)/Model.o

$(OUTDIR_AK)/MouseEvent.o : $(SRC_APPKIT)/MouseEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/MouseEvent.cpp -o $(OUTDIR_AK)/MouseEvent.o

$(OUTDIR_AK)/MultilineTextControl.o : $(SRC_APPKIT)/MultilineTextControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/MultilineTextControl.cpp -o $(OUTDIR_AK)/MultilineTextControl.o

$(OUTDIR_AK)/Panel.o : $(SRC_APPKIT)/Panel.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Panel.cpp -o $(OUTDIR_AK)/Panel.o

$(OUTDIR_AK)/PopupMenu.o : $(SRC_APPKIT)/PopupMenu.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/PopupMenu.cpp -o $(OUTDIR_AK)/PopupMenu.o
	
$(OUTDIR_AK)/ProgressControl.o : $(SRC_APPKIT)/ProgressControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ProgressControl.cpp -o $(OUTDIR_AK)/ProgressControl.o	

$(OUTDIR_AK)/PropertyEditorManager.o : $(SRC_APPKIT)/PropertyEditorManager.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/PropertyEditorManager.cpp -o $(OUTDIR_AK)/PropertyEditorManager.o

$(OUTDIR_AK)/PushButton.o : $(SRC_APPKIT)/PushButton.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/PushButton.cpp -o $(OUTDIR_AK)/PushButton.o

$(OUTDIR_AK)/RadioButtonControl.o : $(SRC_APPKIT)/RadioButtonControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/RadioButtonControl.cpp -o $(OUTDIR_AK)/RadioButtonControl.o

$(OUTDIR_AK)/Resource.o : $(SRC_APPKIT)/Resource.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Resource.cpp -o $(OUTDIR_AK)/Resource.o

$(OUTDIR_AK)/ResourceStream.o : $(SRC_APPKIT)/ResourceStream.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ResourceStream.cpp -o $(OUTDIR_AK)/ResourceStream.o

$(OUTDIR_AK)/ScrollbarManager.o : $(SRC_APPKIT)/ScrollbarManager.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ScrollbarManager.cpp -o $(OUTDIR_AK)/ScrollbarManager.o

$(OUTDIR_AK)/SliderControl.o : $(SRC_APPKIT)/SliderControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/SliderControl.cpp -o $(OUTDIR_AK)/SliderControl.o
	
$(OUTDIR_AK)/Splitter.o : $(SRC_APPKIT)/Splitter.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Splitter.cpp -o $(OUTDIR_AK)/Splitter.o

$(OUTDIR_AK)/StatusBar.o : $(SRC_APPKIT)/StatusBar.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/StatusBar.cpp -o $(OUTDIR_AK)/StatusBar.o

$(OUTDIR_AK)/TabbedPages.o : $(SRC_APPKIT)/TabbedPages.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/TabbedPages.cpp -o $(OUTDIR_AK)/TabbedPages.o

$(OUTDIR_AK)/TableControl.o : $(SRC_APPKIT)/TableControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/TableControl.cpp -o $(OUTDIR_AK)/TableControl.o

$(OUTDIR_AK)/TableModelEvent.o : $(SRC_APPKIT)/TableModelEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/TableModelEvent.cpp -o $(OUTDIR_AK)/TableModelEvent.o

$(OUTDIR_AK)/TabModelEvent.o : $(SRC_APPKIT)/TabModelEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/TabModelEvent.cpp -o $(OUTDIR_AK)/TabModelEvent.o

$(OUTDIR_AK)/TextControl.o : $(SRC_APPKIT)/TextControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/TextControl.cpp -o $(OUTDIR_AK)/TextControl.o

$(OUTDIR_AK)/TextEvent.o : $(SRC_APPKIT)/TextEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/TextEvent.cpp -o $(OUTDIR_AK)/TextEvent.o

$(OUTDIR_AK)/TimerComponent.o : $(SRC_APPKIT)/TimerComponent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/TimerComponent.cpp -o $(OUTDIR_AK)/TimerComponent.o

$(OUTDIR_AK)/TimerEvent.o : $(SRC_APPKIT)/TimerEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/TimerEvent.cpp -o $(OUTDIR_AK)/TimerEvent.o

$(OUTDIR_AK)/ToggledButton.o : $(SRC_APPKIT)/ToggledButton.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ToggledButton.cpp -o $(OUTDIR_AK)/ToggledButton.o

$(OUTDIR_AK)/Toolbar.o : $(SRC_APPKIT)/Toolbar.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Toolbar.cpp -o $(OUTDIR_AK)/Toolbar.o


$(OUTDIR_AK)/ToolbarDock.o : $(SRC_APPKIT)/ToolbarDock.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ToolbarDock.cpp -o $(OUTDIR_AK)/ToolbarDock.o


$(OUTDIR_AK)/ToolTipEvent.o : $(SRC_APPKIT)/ToolTipEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ToolTipEvent.cpp -o $(OUTDIR_AK)/ToolTipEvent.o

$(OUTDIR_AK)/TreeControl.o : $(SRC_APPKIT)/TreeControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/TreeControl.cpp -o $(OUTDIR_AK)/TreeControl.o

$(OUTDIR_AK)/TreeListControl.o : $(SRC_APPKIT)/TreeListControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/TreeListControl.cpp -o $(OUTDIR_AK)/TreeListControl.o

$(OUTDIR_AK)/TreeModelEvent.o : $(SRC_APPKIT)/TreeModelEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/TreeModelEvent.cpp -o $(OUTDIR_AK)/TreeModelEvent.o

$(OUTDIR_AK)/UIToolkit.o : $(SRC_APPKIT)/UIToolkit.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/UIToolkit.cpp -o $(OUTDIR_AK)/UIToolkit.o

$(OUTDIR_AK)/UndoRedoEvent.o : $(SRC_APPKIT)/UndoRedoEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/UndoRedoEvent.cpp -o $(OUTDIR_AK)/UndoRedoEvent.o

$(OUTDIR_AK)/UndoRedoStack.o : $(SRC_APPKIT)/UndoRedoStack.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/UndoRedoStack.cpp -o $(OUTDIR_AK)/UndoRedoStack.o

$(OUTDIR_AK)/ValidationEvent.o : $(SRC_APPKIT)/ValidationEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/ValidationEvent.cpp -o $(OUTDIR_AK)/ValidationEvent.o

$(OUTDIR_AK)/VFFInputStream.o : $(SRC_APPKIT)/VFFInputStream.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/VFFInputStream.cpp -o $(OUTDIR_AK)/VFFInputStream.o

$(OUTDIR_AK)/VFFOutputStream.o : $(SRC_APPKIT)/VFFOutputStream.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/VFFOutputStream.cpp -o $(OUTDIR_AK)/VFFOutputStream.o

$(OUTDIR_AK)/WhatsThisHelpEvent.o : $(SRC_APPKIT)/WhatsThisHelpEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/WhatsThisHelpEvent.cpp -o $(OUTDIR_AK)/WhatsThisHelpEvent.o

$(OUTDIR_AK)/Window.o : $(SRC_APPKIT)/Window.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Window.cpp -o $(OUTDIR_AK)/Window.o

$(OUTDIR_AK)/WindowEvent.o : $(SRC_APPKIT)/WindowEvent.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/WindowEvent.cpp -o $(OUTDIR_AK)/WindowEvent.o
	
$(OUTDIR_AK)/Containers.o : $(SRC_APPKIT)/Containers.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/Containers.cpp -o $(OUTDIR_AK)/Containers.o	
	
#$(OUTDIR_AK)/PackageInfo.o : $(SRC_APPKIT)/PackageInfo.cpp $(APPKIT_HDRS)
#	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/PackageInfo.cpp -o $(OUTDIR_AK)/PackageInfo.o		

$(OUTDIR_AK)/DocumentManager.o : $(SRC_APPKIT)/DocumentManager.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/DocumentManager.cpp -o $(OUTDIR_AK)/DocumentManager.o	

$(OUTDIR_AK)/MessageDialog.o : $(SRC_APPKIT)/MessageDialog.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/MessageDialog.cpp -o $(OUTDIR_AK)/MessageDialog.o		

$(OUTDIR_AK)/GTKUIToolkit.o : $(SRC_APPKIT)/GTKUIToolkit.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/GTKUIToolkit.cpp -o $(OUTDIR_AK)/GTKUIToolkit.o

$(OUTDIR_AK)/GTKDesktop.o : $(SRC_APPKIT)/GTKDesktop.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/GTKDesktop.cpp -o $(OUTDIR_AK)/GTKDesktop.o

$(OUTDIR_AK)/GTKApplication.o : $(SRC_APPKIT)/GTKApplication.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/GTKApplication.cpp -o $(OUTDIR_AK)/GTKApplication.o

$(OUTDIR_AK)/AbstractGTKControl.o : $(SRC_APPKIT)/AbstractGTKControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/AbstractGTKControl.cpp -o $(OUTDIR_AK)/AbstractGTKControl.o

$(OUTDIR_AK)/GTKControl.o : $(SRC_APPKIT)/GTKControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/GTKControl.cpp -o $(OUTDIR_AK)/GTKControl.o

$(OUTDIR_AK)/GTKWindow.o : $(SRC_APPKIT)/GTKWindow.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/GTKWindow.cpp -o $(OUTDIR_AK)/GTKWindow.o

$(OUTDIR_AK)/GTKControlContext.o : $(SRC_APPKIT)/GTKControlContext.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/GTKControlContext.cpp -o $(OUTDIR_AK)/GTKControlContext.o

$(OUTDIR_AK)/GTKCursor.o : $(SRC_APPKIT)/GTKCursor.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/GTKCursor.cpp -o $(OUTDIR_AK)/GTKCursor.o
	
$(OUTDIR_AK)/GTKDialog.o : $(SRC_APPKIT)/GTKDialog.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/GTKDialog.cpp -o $(OUTDIR_AK)/GTKDialog.o	

$(OUTDIR_AK)/GTKTextControl.o : $(SRC_APPKIT)/GTKTextControl.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/GTKTextControl.cpp -o $(OUTDIR_AK)/GTKTextControl.o	
	
$(OUTDIR_AK)/GTKFileOpenDialog.o : $(SRC_APPKIT)/GTKFileOpenDialog.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/GTKFileOpenDialog.cpp -o $(OUTDIR_AK)/GTKFileOpenDialog.o		
	
$(OUTDIR_AK)/GTKCommandButton.o : $(SRC_APPKIT)/GTKCommandButton.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/GTKCommandButton.cpp -o $(OUTDIR_AK)/GTKCommandButton.o			
	
$(OUTDIR_AK)/GTKToolbar.o : $(SRC_APPKIT)/GTKToolbar.cpp $(APPKIT_HDRS)
	$(CXX) $(AK_CXX_FLAGS) $(SRC_APPKIT)/GTKToolbar.cpp -o $(OUTDIR_AK)/GTKToolbar.o				



