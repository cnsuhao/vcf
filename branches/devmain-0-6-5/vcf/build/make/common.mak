##############################################################
#
#
#CVS Log info
#$Log$
#Revision 1.5.2.1  2004/04/28 14:40:01  ddiego
#migration towards new directory structure
#
#Revision 1.5  2004/04/03 15:47:59  ddiego
#Merged over code from the 0-6-3 branch.
#
#Revision 1.4.2.1  2004/02/16 03:00:26  ddiego
#*** empty log message ***
#
#Revision 1.4  2003/12/18 05:15:47  ddiego
#merge from devmain-0-6-2 branch into the stable branch
#
#Revision 1.3.4.4  2003/12/13 18:19:00  ddiego
#*** empty log message ***
#
#Revision 1.3.4.3  2003/10/03 04:33:03  ddiego
#add precompiled header target - doesn't seem to really work though
#
#Revision 1.3.4.2  2003/10/02 04:50:34  ddiego
#changes to ensure the code compiles on linux. made a bunch of updates to
#the makefiles
#
#Revision 1.3.4.1  2003/09/27 16:11:30  ddiego
#fixed some minor glitches in the makefile due to changes made on the Win32
#side.
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
#Revision 1.1.2.4  2003/02/08 17:55:44  ddiego
#modified the makefiles to have cvs Log entries, so we can keepo track of
#whats going on :)
#
#
#
#common definitions
#
#output directory for debug builds
#
#output base directories
#
#see the prep_dirs_XXX targets for auto creation
#of output directories
#
##############################################################

OUTPUT_BASE_FK=./FoundationKit
OUTPUT_BASE_AK=./ApplicationKit
OUTPUT_BASE_GK=./GraphicsKit
OUTPUT_BASE_NK=./NetworkKit
OUTPUT_BASE_RK=./RemoteObjectKit

OUTDIR_FK_D=$(OUTPUT_BASE_FK)/Debug
OUTDIR_FK=$(OUTPUT_BASE_FK)/Release

OUTDIR_GK_D=$(OUTPUT_BASE_GK)/Debug
OUTDIR_GK=$(OUTPUT_BASE_GK)/Release

OUTDIR_AK_D=$(OUTPUT_BASE_AK)/Debug
OUTDIR_AK=$(OUTPUT_BASE_AK)/Release

OUTDIR_NK_D=$(OUTPUT_BASE_NK)/Debug
OUTDIR_NK=$(OUTPUT_BASE_NK)/Release

#imlib2 include path, used by graphics kit
IMLIB2_INC=/usr/local/include/imlib2

#X11 include path and library, used by ApplicationKit and GraphicsKit
X11_INC=/usr/X11R6/include
X11_LIB=/usr/X11R6/lib


SRC=../../src


INC=../../src


#binary output directory
BIN_OUT=../../bin


#library output directory
LIB_OUT=../../lib


#source file short cut directories
SRC_FOUNDATIONKIT=$(SRC)/vcf/FoundationKit
SRC_APPKIT=$(SRC)/vcf/ApplicationKit
SRC_GRAPHICSKIT=$(SRC)/vcf/GraphicsKit
SRC_NETWORKKIT=$(SRC)/vcf/NetworkKit
SRC_REMOTEOBJKIT=$(SRC)/vcf/RemoteObjectKit





#toolchain definitions
CXX_INC=$(INC) 


#we are using the g++ compiler for C++
CXX=g++

#we are using the g++ linker
LINKER=g++
STATIC_LINKER=ar


###########################################################
#
#"make" is pretty stupid. So, unfortunately (AFAIK) to get
#it to understand that we MAY need to check on other headers,
#we have to explicitly tell it to look at these headers.
#Sigh...you'd think stuff like this would be build in...
#
#So this long list of headers is the set of VCF include
#files that each project uses (by and large), and would
#need to be checked for each file that gets compiled. If
#any of these files changes, then the file will need to 
#be compiled again.
#
###########################################################

###########################################################
#FoundationKit headers
###########################################################

FOUNDATIONKIT_HDRS=$(SRC_FOUNDATIONKIT)/VCFChar.h \
	$(SRC_FOUNDATIONKIT)/VCFProcess.h \
	$(SRC_FOUNDATIONKIT)/VCFString.h \
	$(SRC_FOUNDATIONKIT)/XMLParser.h \
	$(SRC_FOUNDATIONKIT)/Runnable.h \
	$(SRC_FOUNDATIONKIT)/Semaphore.h \
	$(SRC_FOUNDATIONKIT)/SemaphorePeer.h \
	$(SRC_FOUNDATIONKIT)/StringUtils.h \
	$(SRC_FOUNDATIONKIT)/SynchObject.h \
	$(SRC_FOUNDATIONKIT)/System.h \
	$(SRC_FOUNDATIONKIT)/SystemPeer.h \
	$(SRC_FOUNDATIONKIT)/SystemToolkit.h \
	$(SRC_FOUNDATIONKIT)/Thread.h \
	$(SRC_FOUNDATIONKIT)/Mutex.h \
	$(SRC_FOUNDATIONKIT)/Parser.h \
	$(SRC_FOUNDATIONKIT)/ProcessWithRedirectedIO.h \
	$(SRC_FOUNDATIONKIT)/References.h \
	$(SRC_FOUNDATIONKIT)/Registry.h \
	$(SRC_FOUNDATIONKIT)/Library.h \
	$(SRC_FOUNDATIONKIT)/Lock.h \
	$(SRC_FOUNDATIONKIT)/Enum.h \
	$(SRC_FOUNDATIONKIT)/Enumerator.h \
	$(SRC_FOUNDATIONKIT)/ErrorLog.h \
	$(SRC_FOUNDATIONKIT)/FilePath.h \
	$(SRC_FOUNDATIONKIT)/Stream.h \
	$(SRC_FOUNDATIONKIT)/TextInputStream.h \
	$(SRC_FOUNDATIONKIT)/TextOutputStream.h \
	$(SRC_FOUNDATIONKIT)/VariantDataStream.h \
	$(SRC_FOUNDATIONKIT)/Directory.h \
	$(SRC_FOUNDATIONKIT)/File.h \
	$(SRC_FOUNDATIONKIT)/FileIOError.h \
	$(SRC_FOUNDATIONKIT)/FileNotFound.h \
	$(SRC_FOUNDATIONKIT)/FileStream.h \
	$(SRC_FOUNDATIONKIT)/FileStreamPeer.h \
	$(SRC_FOUNDATIONKIT)/FileUtils.h \
	$(SRC_FOUNDATIONKIT)/MemoryStream.h \
	$(SRC_FOUNDATIONKIT)/MemStreamUtils.h \
	$(SRC_FOUNDATIONKIT)/Persistable.h \
	$(SRC_FOUNDATIONKIT)/BasicFileError.h \
	$(SRC_FOUNDATIONKIT)/BasicInputStream.h \
	$(SRC_FOUNDATIONKIT)/BasicOutputStream.h \
	$(SRC_FOUNDATIONKIT)/ThreadPeer.h \
	$(SRC_FOUNDATIONKIT)/ProcessIORedirectionPeer.h \
	$(SRC_FOUNDATIONKIT)/ProcessPeer.h \
	$(SRC_FOUNDATIONKIT)/RegistryPeer.h \
	$(SRC_FOUNDATIONKIT)/MutexPeer.h \
	$(SRC_FOUNDATIONKIT)/LibraryPeer.h \
	$(SRC_FOUNDATIONKIT)/FilePeer.h \
	$(SRC_FOUNDATIONKIT)/RuntimeException.h \
	$(SRC_FOUNDATIONKIT)/ThreadException.h \
	$(SRC_FOUNDATIONKIT)/TypeCastException.h \
	$(SRC_FOUNDATIONKIT)/FoundationKit.h \
	$(SRC_FOUNDATIONKIT)/FoundationKitPrivate.h \
	$(SRC_FOUNDATIONKIT)/OutOfBoundsException.h \
	$(SRC_FOUNDATIONKIT)/ProcessException.h \
	$(SRC_FOUNDATIONKIT)/PropertyChangeException.h \
	$(SRC_FOUNDATIONKIT)/NoImplementerFoundException.h \
	$(SRC_FOUNDATIONKIT)/NoPeerFoundException.h \
	$(SRC_FOUNDATIONKIT)/NoSuchElementException.h \
	$(SRC_FOUNDATIONKIT)/InvalidImplementer.h \
	$(SRC_FOUNDATIONKIT)/InvalidPeer.h \
	$(SRC_FOUNDATIONKIT)/InvalidPointerException.h \
	$(SRC_FOUNDATIONKIT)/NoFreeMemException.h \
	$(SRC_FOUNDATIONKIT)/BasicException.h \
	$(SRC_FOUNDATIONKIT)/CantCreateObjectException.h \
	$(SRC_FOUNDATIONKIT)/ClassNotFound.h \
	$(SRC_FOUNDATIONKIT)/ErrorStrings.h \
	$(SRC_FOUNDATIONKIT)/NotifyEvent.h \
	$(SRC_FOUNDATIONKIT)/OutputReadyEvent.h \
	$(SRC_FOUNDATIONKIT)/PropertyChangeEvent.h \
	$(SRC_FOUNDATIONKIT)/Class.h \
	$(SRC_FOUNDATIONKIT)/ClassInfo.h \
	$(SRC_FOUNDATIONKIT)/ClassRegistry.h \
	$(SRC_FOUNDATIONKIT)/CommonDefines.h \
	$(SRC_FOUNDATIONKIT)/FoundationKitSelectLib.h \
	$(SRC_FOUNDATIONKIT)/FrameworkConfig.h \
	$(SRC_FOUNDATIONKIT)/Interface.h \
	$(SRC_FOUNDATIONKIT)/InterfaceClass.h \
	$(SRC_FOUNDATIONKIT)/Locales.h \
	$(SRC_FOUNDATIONKIT)/Method.h \
	$(SRC_FOUNDATIONKIT)/Field.h \
	$(SRC_FOUNDATIONKIT)/Object.h \
	$(SRC_FOUNDATIONKIT)/ObjectWithEvents.h \
	$(SRC_FOUNDATIONKIT)/Property.h \
	$(SRC_FOUNDATIONKIT)/VCF.h \
	$(SRC_FOUNDATIONKIT)/VCFMath.h \
	$(SRC_FOUNDATIONKIT)/WarningsOffVc.h \
	$(SRC_FOUNDATIONKIT)/Delegate.h \
	$(SRC_FOUNDATIONKIT)/Event.h \
	$(SRC_FOUNDATIONKIT)/EventHandler.h \
	$(SRC_FOUNDATIONKIT)/LinuxFilePeer.h \
	$(SRC_FOUNDATIONKIT)/LinuxFileStream.h \
	$(SRC_FOUNDATIONKIT)/LinuxLibraryPeer.h \
	$(SRC_FOUNDATIONKIT)/LinuxMutex.h \
	$(SRC_FOUNDATIONKIT)/LinuxPeer.h \
	$(SRC_FOUNDATIONKIT)/LinuxProcessIORedirector.h \
	$(SRC_FOUNDATIONKIT)/LinuxProcessPeer.h \
	$(SRC_FOUNDATIONKIT)/LinuxRegistry.h \
	$(SRC_FOUNDATIONKIT)/LinuxSemaphorePeer.h \
	$(SRC_FOUNDATIONKIT)/LinuxSystemPeer.h \
	$(SRC_FOUNDATIONKIT)/LinuxSystemToolkit.h \
	$(SRC_FOUNDATIONKIT)/LinuxThread.h



###########################################################
#GraphicsKit headers, which also pulls in 
#FoundationKit headers
###########################################################

GRAPHICSKIT_HDRS=$(FOUNDATIONKIT_HDRS) $(SRC_GRAPHICSKIT)/ImageEvent.h \
	$(SRC_GRAPHICSKIT)/AbstractImage.h \
	$(SRC_GRAPHICSKIT)/BasicFill.h \
	$(SRC_GRAPHICSKIT)/BasicRectangle.h \
	$(SRC_GRAPHICSKIT)/BasicStroke.h \
	$(SRC_GRAPHICSKIT)/Border.h \
	$(SRC_GRAPHICSKIT)/Circle.h \
	$(SRC_GRAPHICSKIT)/ClippingRegion.h \
	$(SRC_GRAPHICSKIT)/Color.h \
	$(SRC_GRAPHICSKIT)/ColorEtchedBorder.h \
	$(SRC_GRAPHICSKIT)/Composition.h \
	$(SRC_GRAPHICSKIT)/BezierCurve.h \
	$(SRC_GRAPHICSKIT)/Ellipse.h \
	$(SRC_GRAPHICSKIT)/Fill.h \
	$(SRC_GRAPHICSKIT)/Filter.h \
	$(SRC_GRAPHICSKIT)/Font.h \
	$(SRC_GRAPHICSKIT)/FontPeer.h \
	$(SRC_GRAPHICSKIT)/Glyph.h \
	$(SRC_GRAPHICSKIT)/GlyphCollection.h \
	$(SRC_GRAPHICSKIT)/GraphicsContext.h \
	$(SRC_GRAPHICSKIT)/GraphicsKitSelectLib.h \
	$(SRC_GRAPHICSKIT)/Image.h \
	$(SRC_GRAPHICSKIT)/ImageBits.h \
	$(SRC_GRAPHICSKIT)/ImageLoader.h \
	$(SRC_GRAPHICSKIT)/Point.h \
	$(SRC_GRAPHICSKIT)/Rect.h \
	$(SRC_GRAPHICSKIT)/Size.h \
	$(SRC_GRAPHICSKIT)/MagicFMLibType.h \
	$(SRC_GRAPHICSKIT)/Matrix2D.h \
	$(SRC_GRAPHICSKIT)/MatrixFunction.h \
	$(SRC_GRAPHICSKIT)/MgcBezierCurve2.h \
	$(SRC_GRAPHICSKIT)/MgcCurve2.h \
	$(SRC_GRAPHICSKIT)/MgcIntegrate.h \
	$(SRC_GRAPHICSKIT)/MgcMath.h \
	$(SRC_GRAPHICSKIT)/MgcRTLib.h \
	$(SRC_GRAPHICSKIT)/MgcSingleCurve2.h \
	$(SRC_GRAPHICSKIT)/MgcVector2.h \
	$(SRC_GRAPHICSKIT)/MicroTiles.h \
	$(SRC_GRAPHICSKIT)/OpenGLContext.h \
	$(SRC_GRAPHICSKIT)/OpenGLControlContext.h \
	$(SRC_GRAPHICSKIT)/Path.h \
	$(SRC_GRAPHICSKIT)/Printable.h \
	$(SRC_GRAPHICSKIT)/PrintContext.h \
	$(SRC_GRAPHICSKIT)/RenderableArea.h \
	$(SRC_GRAPHICSKIT)/Stroke.h \
	$(SRC_GRAPHICSKIT)/VCFOpenGL.h \
	$(SRC_GRAPHICSKIT)/Vector2D.h \
	$(SRC_GRAPHICSKIT)/GraphicsKit.h \
	$(SRC_GRAPHICSKIT)/GraphicsKitPrivate.h \
	$(SRC_GRAPHICSKIT)/NoGraphicsToolkitFoundException.h \
	$(SRC_GRAPHICSKIT)/ImageLoaderException.h \
	$(SRC_GRAPHICSKIT)/InvalidImage.h \
	$(SRC_GRAPHICSKIT)/GTKContext.h \
	$(SRC_GRAPHICSKIT)/GTKFont.h \
	$(SRC_GRAPHICSKIT)/GTKGraphicsToolkit.h \
	$(SRC_GRAPHICSKIT)/GTKImage.h \
	$(SRC_GRAPHICSKIT)/GraphicsToolKit.h




###########################################################
#ApplicationKit headers, which also pulls in 
#GraphicsKit headers (and by definition FoundationKit headers
###########################################################

APPKIT_HDRS=$(GRAPHICSKIT_HDRS) $(SRC_APPKIT)/ApplicationKit.h \
	$(SRC_APPKIT)/ApplicationKitPrivate.h \
	$(SRC_APPKIT)/AbstractApplication.h \
	$(SRC_APPKIT)/AbstractCommand.h \
	$(SRC_APPKIT)/AbstractComponentEditor.h \
	$(SRC_APPKIT)/AbstractListModel.h \
	$(SRC_APPKIT)/AbstractPropertyEditor.h \
	$(SRC_APPKIT)/AbstractScrollable.h \
	$(SRC_APPKIT)/AbstractTableModel.h \
	$(SRC_APPKIT)/AbstractTextModel.h \
	$(SRC_APPKIT)/AbstractTreeModel.h \
	$(SRC_APPKIT)/AbstractView.h \
	$(SRC_APPKIT)/AcceleratorKey.h \
	$(SRC_APPKIT)/ActiveXControlHost.h \
	$(SRC_APPKIT)/Application.h \
	$(SRC_APPKIT)/ApplicationKitSelectLib.h \
	$(SRC_APPKIT)/BasicTableItemEditor.h \
	$(SRC_APPKIT)/Button.h \
	$(SRC_APPKIT)/CheckBoxControl.h \
	$(SRC_APPKIT)/Clipboard.h \
	$(SRC_APPKIT)/DataObject.h \
	$(SRC_APPKIT)/ColumnItem.h \
	$(SRC_APPKIT)/ColumnModel.h \
	$(SRC_APPKIT)/ComboBoxControl.h \
	$(SRC_APPKIT)/Command.h \
	$(SRC_APPKIT)/CommandButton.h \
	$(SRC_APPKIT)/CommandGroup.h \
	$(SRC_APPKIT)/CommonColor.h \
	$(SRC_APPKIT)/CommonDialog.h \
	$(SRC_APPKIT)/CommonFileBrowse.h \
	$(SRC_APPKIT)/CommonFileDialog.h \
	$(SRC_APPKIT)/CommonFileOpen.h \
	$(SRC_APPKIT)/CommonFileSave.h \
	$(SRC_APPKIT)/CommonFont.h \
	$(SRC_APPKIT)/CommonPrint.h \
	$(SRC_APPKIT)/Component.h \
	$(SRC_APPKIT)/ComponentEditor.h \
	$(SRC_APPKIT)/ComponentEditorManager.h \
	$(SRC_APPKIT)/ComponentInfo.h \
	$(SRC_APPKIT)/Action.h \
	$(SRC_APPKIT)/Container.h \
	$(SRC_APPKIT)/Containers.h \
	$(SRC_APPKIT)/Control.h \
	$(SRC_APPKIT)/ControlContainer.h \
	$(SRC_APPKIT)/Cursor.h \
	$(SRC_APPKIT)/CursorManager.h \
	$(SRC_APPKIT)/CustomControl.h \
	$(SRC_APPKIT)/DefaultColumnItem.h \
	$(SRC_APPKIT)/DefaultColumnModel.h \
	$(SRC_APPKIT)/DefaultListItem.h \
	$(SRC_APPKIT)/DefaultListModel.h \
	$(SRC_APPKIT)/DefaultMenuItem.h \
	$(SRC_APPKIT)/DefaultPropertyEditors.h \
	$(SRC_APPKIT)/DefaultTableCellItem.h \
	$(SRC_APPKIT)/DefaultTableModel.h \
	$(SRC_APPKIT)/DefaultTabModel.h \
	$(SRC_APPKIT)/DefaultTabPage.h \
	$(SRC_APPKIT)/DefaultTextModel.h \
	$(SRC_APPKIT)/DefaultTreeItem.h \
	$(SRC_APPKIT)/DefaultTreeModel.h \
	$(SRC_APPKIT)/Desktop.h \
	$(SRC_APPKIT)/Dialog.h \
	$(SRC_APPKIT)/Frame.h \
	$(SRC_APPKIT)/HeaderControl.h \
	$(SRC_APPKIT)/HTMLBrowserControl.h \
	$(SRC_APPKIT)/ImageControl.h \
	$(SRC_APPKIT)/Item.h \
	$(SRC_APPKIT)/Label.h \
	$(SRC_APPKIT)/LibraryApplication.h \
	$(SRC_APPKIT)/ListBoxControl.h \
	$(SRC_APPKIT)/ListItem.h \
	$(SRC_APPKIT)/ListModel.h \
	$(SRC_APPKIT)/ListViewControl.h \
	$(SRC_APPKIT)/Menu.h \
	$(SRC_APPKIT)/MenuBar.h \
	$(SRC_APPKIT)/MenuItem.h \
	$(SRC_APPKIT)/MenuItemShortcut.h \
	$(SRC_APPKIT)/MessageDialog.h \
	$(SRC_APPKIT)/Model.h \
	$(SRC_APPKIT)/MultilineTextControl.h \
	$(SRC_APPKIT)/OpenGLControl.h \
	$(SRC_APPKIT)/Panel.h \
	$(SRC_APPKIT)/PopupMenu.h \
	$(SRC_APPKIT)/PropertyEditor.h \
	$(SRC_APPKIT)/PropertyEditorManager.h \
	$(SRC_APPKIT)/PushButton.h \
	$(SRC_APPKIT)/RadioButtonControl.h \
	$(SRC_APPKIT)/Scrollable.h \
	$(SRC_APPKIT)/ScrollBarControl.h \
	$(SRC_APPKIT)/ScrollbarManager.h \
	$(SRC_APPKIT)/Selectable.h \
	$(SRC_APPKIT)/Splitter.h \
	$(SRC_APPKIT)/StatusBar.h \
	$(SRC_APPKIT)/TabbedPages.h \
	$(SRC_APPKIT)/TableCellItem.h \
	$(SRC_APPKIT)/TableControl.h \
	$(SRC_APPKIT)/TableItemEditor.h \
	$(SRC_APPKIT)/TableModel.h \
	$(SRC_APPKIT)/TabModel.h \
	$(SRC_APPKIT)/TabPage.h \
	$(SRC_APPKIT)/TextControl.h \
	$(SRC_APPKIT)/TextModel.h \
	$(SRC_APPKIT)/TimerComponent.h \
	$(SRC_APPKIT)/ToggledButton.h \
	$(SRC_APPKIT)/Toolbar.h \
	$(SRC_APPKIT)/TreeControl.h \
	$(SRC_APPKIT)/TreeItem.h \
	$(SRC_APPKIT)/TreeListControl.h \
	$(SRC_APPKIT)/TreeModel.h \
	$(SRC_APPKIT)/UIApplication.h \
	$(SRC_APPKIT)/UndoRedoStack.h \
	$(SRC_APPKIT)/View.h \
	$(SRC_APPKIT)/Window.h \
	$(SRC_APPKIT)/Wizard.h \
	$(SRC_APPKIT)/DragSource.h \
	$(SRC_APPKIT)/DropTarget.h \
	$(SRC_APPKIT)/ButtonEvent.h \
	$(SRC_APPKIT)/ClipboardEvent.h \
	$(SRC_APPKIT)/ColumnItemEvent.h \
	$(SRC_APPKIT)/ColumnModelEvent.h \
	$(SRC_APPKIT)/ComponentEvent.h \
	$(SRC_APPKIT)/ControlEvent.h \
	$(SRC_APPKIT)/DragEvent.h \
	$(SRC_APPKIT)/DragScrollEvent.h \
	$(SRC_APPKIT)/DropEvent.h \
	$(SRC_APPKIT)/FocusEvent.h \
	$(SRC_APPKIT)/FrameEvent.h \
	$(SRC_APPKIT)/HelpEvent.h \
	$(SRC_APPKIT)/ImageListEvent.h \
	$(SRC_APPKIT)/ItemEditorEvent.h \
	$(SRC_APPKIT)/ItemEvent.h \
	$(SRC_APPKIT)/KeyboardEvent.h \
	$(SRC_APPKIT)/ListModelEvent.h \
	$(SRC_APPKIT)/MenuItemEvent.h \
	$(SRC_APPKIT)/ModelEvent.h \
	$(SRC_APPKIT)/MouseEvent.h \
	$(SRC_APPKIT)/ScrollEvent.h \
	$(SRC_APPKIT)/TableModelEvent.h \
	$(SRC_APPKIT)/TabModelEvent.h \
	$(SRC_APPKIT)/TextEvent.h \
	$(SRC_APPKIT)/ThreadEvent.h \
	$(SRC_APPKIT)/TimerEvent.h \
	$(SRC_APPKIT)/ToolTipEvent.h \
	$(SRC_APPKIT)/TreeModelEvent.h \
	$(SRC_APPKIT)/UndoRedoEvent.h \
	$(SRC_APPKIT)/ValidationEvent.h \
	$(SRC_APPKIT)/WhatsThisHelpEvent.h \
	$(SRC_APPKIT)/WindowEvent.h \
	$(SRC_APPKIT)/ApplicationException.h \
	$(SRC_APPKIT)/BadComponentStateException.h \
	$(SRC_APPKIT)/BadImageBitsException.h \
	$(SRC_APPKIT)/BadModelStateException.h \
	$(SRC_APPKIT)/COMException.h \
	$(SRC_APPKIT)/DataTypeNotSupportedException.h \
	$(SRC_APPKIT)/InvalidStateException.h \
	$(SRC_APPKIT)/NoToolKitFoundException.h \
	$(SRC_APPKIT)/ResourceException.h \
	$(SRC_APPKIT)/AppKitPeerConfig.h \
	$(SRC_APPKIT)/ApplicationPeer.h \
	$(SRC_APPKIT)/ButtonPeer.h \
	$(SRC_APPKIT)/ClipboardPeer.h \
	$(SRC_APPKIT)/CommonDialogPeer.h \
	$(SRC_APPKIT)/ContextPeer.h \
	$(SRC_APPKIT)/ControlPeer.h \
	$(SRC_APPKIT)/CursorPeer.h \
	$(SRC_APPKIT)/DataObjectPeer.h \
	$(SRC_APPKIT)/DesktopPeer.h \
	$(SRC_APPKIT)/DialogPeer.h \
	$(SRC_APPKIT)/DragDropPeer.h \
	$(SRC_APPKIT)/DropTargetPeer.h \
	$(SRC_APPKIT)/HTMLBrowserPeer.h \
	$(SRC_APPKIT)/ListviewPeer.h \
	$(SRC_APPKIT)/MenuBarPeer.h \
	$(SRC_APPKIT)/MenuItemPeer.h \
	$(SRC_APPKIT)/OpenGLPeer.h \
	$(SRC_APPKIT)/PopupMenuPeer.h \
	$(SRC_APPKIT)/PrintContextPeer.h \
	$(SRC_APPKIT)/PrintPeer.h \
	$(SRC_APPKIT)/ResourceStreamPeer.h \
	$(SRC_APPKIT)/ScrollbarPeer.h \
	$(SRC_APPKIT)/ScrollPeer.h \
	$(SRC_APPKIT)/TextPeer.h \
	$(SRC_APPKIT)/TreePeer.h \
	$(SRC_APPKIT)/WindowPeer.h \
	$(SRC_APPKIT)/HTMLBrowserPeer.h \
	$(SRC_APPKIT)/ComponentInputStream.h \
	$(SRC_APPKIT)/ComponentOutputStream.h \
	$(SRC_APPKIT)/ResourceStream.h \
	$(SRC_APPKIT)/ResourceStreamPeer.h \
	$(SRC_APPKIT)/VFFInputStream.h \
	$(SRC_APPKIT)/VFFOutputStream.h \
	$(SRC_APPKIT)/ModelViewKit.h \
	$(SRC_APPKIT)/Resource.h \
	$(SRC_APPKIT)/ResourceBundle.h \
	$(SRC_APPKIT)/UIMetricsManager.h \
	$(SRC_APPKIT)/UIToolkit.h




###########################################################
#NetworkKit headers, which also pulls in 
#FoundationKit headers
###########################################################

NETWORKKIT_HDRS=$(FOUNDATIONKIT_HDRS) $(SRC_NETWORKKIT)/DatagramSocket.h \
	$(SRC_NETWORKKIT)/NetToolkit.h \
	$(SRC_NETWORKKIT)/NetworkKitSelectLib.h \
	$(SRC_NETWORKKIT)/ServerSocketEvent.h \
	$(SRC_NETWORKKIT)/Socket.h \
	$(SRC_NETWORKKIT)/SocketEvent.h \
	$(SRC_NETWORKKIT)/SocketException.h \
	$(SRC_NETWORKKIT)/SocketListener.h \
	$(SRC_NETWORKKIT)/SocketListeningLoop.h \
	$(SRC_NETWORKKIT)/SocketPeer.h \
	$(SRC_NETWORKKIT)/URL.h \
	$(SRC_NETWORKKIT)/NetworkKit.h \
	$(SRC_NETWORKKIT)/NetworkKitPrivate.h



###########################################################
#RemoteObjectKit headers, which also pulls in 
#NetworkKit headers and FoundationKit headers
###########################################################

REMOTEOBJECTKIT_HDRS=$(NETWORKKIT_HDRS) $(SRC_REMOTEOBJKIT)/AbstractDistributedApplication.h \
	$(SRC_REMOTEOBJKIT)/ClassRegistryEntry.h \
	$(SRC_REMOTEOBJKIT)/ClassServerInstance.h \
	$(SRC_REMOTEOBJKIT)/DistributedClassRegistry.h \
	$(SRC_REMOTEOBJKIT)/DistributedException.h \
	$(SRC_REMOTEOBJKIT)/InstanceID.h \
	$(SRC_REMOTEOBJKIT)/Proxy.h \
	$(SRC_REMOTEOBJKIT)/RemoteCommon.h \
	$(SRC_REMOTEOBJKIT)/RemoteConfig.h \
	$(SRC_REMOTEOBJKIT)/RemoteObjectKit.h \
	$(SRC_REMOTEOBJKIT)/RemoteObjectKitSelectLib.h \
	$(SRC_REMOTEOBJKIT)/RemoteObjectKit.h



