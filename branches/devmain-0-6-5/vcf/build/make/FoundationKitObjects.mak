###########################################################
#
#CVS Log info
#$Log$
#Revision 1.4.2.1  2004/04/28 14:40:01  ddiego
#migration towards new directory structure
#
#Revision 1.4  2004/04/03 15:47:59  ddiego
#Merged over code from the 0-6-3 branch.
#
#Revision 1.3.2.2  2004/02/16 05:33:47  ddiego
#updated linux makefiles as a result of new locale support - pushed in stubs for locale peer impl, but no functionality at this point
#
#Revision 1.3.2.1  2004/02/16 03:00:25  ddiego
#*** empty log message ***
#
#Revision 1.3  2003/12/18 05:15:47  ddiego
#merge from devmain-0-6-2 branch into the stable branch
#
#Revision 1.2.6.5  2003/11/11 17:43:43  ddiego
#updated the makefile and foundationKit object to make a VariantData.obj
#file
#
#Revision 1.2.6.4  2003/10/04 20:13:44  ddiego
#updated the Makefiles - everything works now, including compiling
#building on GCC 3.3.1
#
#Revision 1.2.6.3  2003/10/03 04:33:03  ddiego
#add precompiled header target - doesn't seem to really work though
#
#Revision 1.2.6.2  2003/10/03 01:07:48  ddiego
#added/fixed problems to get it to compile under linux
#
#Revision 1.2.6.1  2003/10/02 04:50:34  ddiego
#changes to ensure the code compiles on linux. made a bunch of updates to
#the makefiles
#
#Revision 1.2  2003/02/26 04:30:25  ddiego
#merge of code in the devmain-0-5-9 branch into the current tree.
#most additions are in the area of the current linux port, but the major
#addition to this release is the addition of a Condition class (currently
#still under development) and the change over to using the Delegate class
#exclusively from the older event handler macros.
#
#Revision 1.1.2.5  2003/02/18 19:59:55  catwallader
#Added Condition classes. Also added comments to Thread and Mutex class
#headers.
#
#Revision 1.1.2.4  2003/02/12 19:33:44  catwallader
#Added PosixMutex class.
#
#Revision 1.1.2.3  2003/02/08 17:55:44  ddiego
#modified the makefiles to have cvs Log entries, so we can keepo track of
#whats going on :)
#
#
#
#
#Object files for the FoundationKit 
#
###########################################################

#precompiled headers



###########################################################
#Debug files
###########################################################


$(OUTDIR_FK_D)/BasicException.o : $(SRC_FOUNDATIONKIT)/BasicException.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/BasicException.cpp -o $(OUTDIR_FK_D)/BasicException.o

$(OUTDIR_FK_D)/BasicInputStream.o : $(SRC_FOUNDATIONKIT)/BasicInputStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/BasicInputStream.cpp -o $(OUTDIR_FK_D)/BasicInputStream.o

$(OUTDIR_FK_D)/BasicOutputStream.o : $(SRC_FOUNDATIONKIT)/BasicOutputStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/BasicOutputStream.cpp -o $(OUTDIR_FK_D)/BasicOutputStream.o

$(OUTDIR_FK_D)/Class.o : $(SRC_FOUNDATIONKIT)/Class.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/Class.cpp -o $(OUTDIR_FK_D)/Class.o

$(OUTDIR_FK_D)/ClassRegistry.o : $(SRC_FOUNDATIONKIT)/ClassRegistry.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/ClassRegistry.cpp -o $(OUTDIR_FK_D)/ClassRegistry.o
	
$(OUTDIR_FK_D)/DateTime.o : $(SRC_FOUNDATIONKIT)/DateTime.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/DateTime.cpp -o $(OUTDIR_FK_D)/DateTime.o
	
$(OUTDIR_FK_D)/Directory.o : $(SRC_FOUNDATIONKIT)/Directory.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/Directory.cpp -o $(OUTDIR_FK_D)/Directory.o

$(OUTDIR_FK_D)/ErrorLog.o : $(SRC_FOUNDATIONKIT)/ErrorLog.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/ErrorLog.cpp -o $(OUTDIR_FK_D)/ErrorLog.o

$(OUTDIR_FK_D)/Event.o : $(SRC_FOUNDATIONKIT)/Event.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/Event.cpp -o $(OUTDIR_FK_D)/Event.o

$(OUTDIR_FK_D)/EventHandler.o : $(SRC_FOUNDATIONKIT)/EventHandler.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/EventHandler.cpp -o $(OUTDIR_FK_D)/EventHandler.o

$(OUTDIR_FK_D)/File.o : $(SRC_FOUNDATIONKIT)/File.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/File.cpp -o $(OUTDIR_FK_D)/File.o

$(OUTDIR_FK_D)/FilePath.o : $(SRC_FOUNDATIONKIT)/FilePath.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/FilePath.cpp -o $(OUTDIR_FK_D)/FilePath.o

$(OUTDIR_FK_D)/FileStream.o : $(SRC_FOUNDATIONKIT)/FileStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/FileStream.cpp -o $(OUTDIR_FK_D)/FileStream.o

$(OUTDIR_FK_D)/FileUtils.o : $(SRC_FOUNDATIONKIT)/FileUtils.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/FileUtils.cpp -o $(OUTDIR_FK_D)/FileUtils.o

$(OUTDIR_FK_D)/FoundationKit.o : $(SRC_FOUNDATIONKIT)/FoundationKit.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/FoundationKit.cpp -o $(OUTDIR_FK_D)/FoundationKit.o

$(OUTDIR_FK_D)/InterfaceClass.o : $(SRC_FOUNDATIONKIT)/InterfaceClass.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/InterfaceClass.cpp -o $(OUTDIR_FK_D)/InterfaceClass.o

$(OUTDIR_FK_D)/Library.o : $(SRC_FOUNDATIONKIT)/Library.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/Library.cpp -o $(OUTDIR_FK_D)/Library.o

$(OUTDIR_FK_D)/Locales.o : $(SRC_FOUNDATIONKIT)/Locales.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/Locales.cpp -o $(OUTDIR_FK_D)/Locales.o

$(OUTDIR_FK_D)/MemoryStream.o : $(SRC_FOUNDATIONKIT)/MemoryStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/MemoryStream.cpp -o $(OUTDIR_FK_D)/MemoryStream.o

$(OUTDIR_FK_D)/MessageLoader.o : $(SRC_FOUNDATIONKIT)/MessageLoader.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/MessageLoader.cpp -o $(OUTDIR_FK_D)/MessageLoader.o
	
$(OUTDIR_FK_D)/StringsMessageLoader.o : $(SRC_FOUNDATIONKIT)/StringsMessageLoader.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/StringsMessageLoader.cpp -o $(OUTDIR_FK_D)/StringsMessageLoader.o	
	
$(OUTDIR_FK_D)/TextCodec.o : $(SRC_FOUNDATIONKIT)/TextCodec.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/TextCodec.cpp -o $(OUTDIR_FK_D)/TextCodec.o	
	
$(OUTDIR_FK_D)/Mutex.o : $(SRC_FOUNDATIONKIT)/Mutex.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/Mutex.cpp -o $(OUTDIR_FK_D)/Mutex.o

$(OUTDIR_FK_D)/Condition.o : $(SRC_FOUNDATIONKIT)/Condition.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/Condition.cpp -o $(OUTDIR_FK_D)/Condition.o

$(OUTDIR_FK_D)/Object.o : $(SRC_FOUNDATIONKIT)/Object.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/Object.cpp -o $(OUTDIR_FK_D)/Object.o

$(OUTDIR_FK_D)/ObjectWithEvents.o : $(SRC_FOUNDATIONKIT)/ObjectWithEvents.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/ObjectWithEvents.cpp -o $(OUTDIR_FK_D)/ObjectWithEvents.o

$(OUTDIR_FK_D)/Parser.o : $(SRC_FOUNDATIONKIT)/Parser.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/Parser.cpp -o $(OUTDIR_FK_D)/Parser.o

$(OUTDIR_FK_D)/PropertyChangeEvent.o : $(SRC_FOUNDATIONKIT)/PropertyChangeEvent.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/PropertyChangeEvent.cpp -o $(OUTDIR_FK_D)/PropertyChangeEvent.o


$(OUTDIR_FK_D)/CommandLine.o : $(SRC_FOUNDATIONKIT)/CommandLine.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/CommandLine.cpp -o $(OUTDIR_FK_D)/CommandLine.o

$(OUTDIR_FK_D)/Registry.o : $(SRC_FOUNDATIONKIT)/Registry.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/Registry.cpp -o $(OUTDIR_FK_D)/Registry.o

$(OUTDIR_FK_D)/Stream.o : $(SRC_FOUNDATIONKIT)/Stream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/Stream.cpp -o $(OUTDIR_FK_D)/Stream.o

$(OUTDIR_FK_D)/StringUtils.o : $(SRC_FOUNDATIONKIT)/StringUtils.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/StringUtils.cpp -o $(OUTDIR_FK_D)/StringUtils.o

$(OUTDIR_FK_D)/System.o : $(SRC_FOUNDATIONKIT)/System.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/System.cpp -o $(OUTDIR_FK_D)/System.o

$(OUTDIR_FK_D)/SystemToolkit.o : $(SRC_FOUNDATIONKIT)/SystemToolkit.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/SystemToolkit.cpp -o $(OUTDIR_FK_D)/SystemToolkit.o

$(OUTDIR_FK_D)/TextInputStream.o : $(SRC_FOUNDATIONKIT)/TextInputStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/TextInputStream.cpp -o $(OUTDIR_FK_D)/TextInputStream.o

$(OUTDIR_FK_D)/TextOutputStream.o : $(SRC_FOUNDATIONKIT)/TextOutputStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/TextOutputStream.cpp -o $(OUTDIR_FK_D)/TextOutputStream.o

$(OUTDIR_FK_D)/Thread.o : $(SRC_FOUNDATIONKIT)/Thread.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/Thread.cpp -o $(OUTDIR_FK_D)/Thread.o

$(OUTDIR_FK_D)/ThreadEvent.o : $(SRC_FOUNDATIONKIT)/ThreadEvent.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/ThreadEvent.cpp -o $(OUTDIR_FK_D)/ThreadEvent.o

$(OUTDIR_FK_D)/VariantData.o : $(SRC_FOUNDATIONKIT)/VariantData.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/VariantData.cpp -o $(OUTDIR_FK_D)/VariantData.o

$(OUTDIR_FK_D)/VCFMath.o : $(SRC_FOUNDATIONKIT)/VCFMath.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/VCFMath.cpp -o $(OUTDIR_FK_D)/VCFMath.o
	
$(OUTDIR_FK_D)/VCFString.o : $(SRC_FOUNDATIONKIT)/VCFString.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/VCFString.cpp -o $(OUTDIR_FK_D)/VCFString.o

$(OUTDIR_FK_D)/VCFProcess.o : $(SRC_FOUNDATIONKIT)/VCFProcess.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/VCFProcess.cpp -o $(OUTDIR_FK_D)/VCFProcess.o

$(OUTDIR_FK_D)/XMLParser.o : $(SRC_FOUNDATIONKIT)/XMLParser.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/XMLParser.cpp -o $(OUTDIR_FK_D)/XMLParser.o

$(OUTDIR_FK_D)/LinuxPeer.o : $(SRC_FOUNDATIONKIT)/LinuxPeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/LinuxPeer.cpp -o $(OUTDIR_FK_D)/LinuxPeer.o

$(OUTDIR_FK_D)/LinuxFilePeer.o : $(SRC_FOUNDATIONKIT)/LinuxFilePeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/LinuxFilePeer.cpp -o $(OUTDIR_FK_D)/LinuxFilePeer.o

$(OUTDIR_FK_D)/LinuxFileStream.o : $(SRC_FOUNDATIONKIT)/LinuxFileStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/LinuxFileStream.cpp -o $(OUTDIR_FK_D)/LinuxFileStream.o

$(OUTDIR_FK_D)/PosixThread.o : $(SRC_FOUNDATIONKIT)/PosixThread.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/PosixThread.cpp -o $(OUTDIR_FK_D)/PosixThread.o

$(OUTDIR_FK_D)/LinuxLibraryPeer.o : $(SRC_FOUNDATIONKIT)/LinuxLibraryPeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/LinuxLibraryPeer.cpp -o $(OUTDIR_FK_D)/LinuxLibraryPeer.o

$(OUTDIR_FK_D)/PosixMutex.o : $(SRC_FOUNDATIONKIT)/PosixMutex.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/PosixMutex.cpp -o $(OUTDIR_FK_D)/PosixMutex.o

$(OUTDIR_FK_D)/PosixCondition.o : $(SRC_FOUNDATIONKIT)/PosixCondition.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/PosixCondition.cpp -o $(OUTDIR_FK_D)/PosixCondition.o

$(OUTDIR_FK_D)/LinuxProcessPeer.o : $(SRC_FOUNDATIONKIT)/LinuxProcessPeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/LinuxProcessPeer.cpp -o $(OUTDIR_FK_D)/LinuxProcessPeer.o

$(OUTDIR_FK_D)/LinuxRegistry.o : $(SRC_FOUNDATIONKIT)/LinuxRegistry.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/LinuxRegistry.cpp -o $(OUTDIR_FK_D)/LinuxRegistry.o

$(OUTDIR_FK_D)/LinuxSemaphorePeer.o : $(SRC_FOUNDATIONKIT)/LinuxSemaphorePeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/LinuxSemaphorePeer.cpp -o $(OUTDIR_FK_D)/LinuxSemaphorePeer.o

$(OUTDIR_FK_D)/LinuxSystemPeer.o : $(SRC_FOUNDATIONKIT)/LinuxSystemPeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/LinuxSystemPeer.cpp -o $(OUTDIR_FK_D)/LinuxSystemPeer.o

$(OUTDIR_FK_D)/LinuxSystemToolkit.o : $(SRC_FOUNDATIONKIT)/LinuxSystemToolkit.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/LinuxSystemToolkit.cpp -o $(OUTDIR_FK_D)/LinuxSystemToolkit.o

$(OUTDIR_FK_D)/LinuxProcessIORedirector.o : $(SRC_FOUNDATIONKIT)/LinuxProcessIORedirector.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/LinuxProcessIORedirector.cpp -o $(OUTDIR_FK_D)/LinuxProcessIORedirector.o
	
$(OUTDIR_FK_D)/LinuxLocalePeer.o : $(SRC_FOUNDATIONKIT)/LinuxLocalePeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS_D) $(SRC_FOUNDATIONKIT)/LinuxLocalePeer.cpp -o $(OUTDIR_FK_D)/LinuxLocalePeer.o


###########################################################
#Release files
###########################################################


$(OUTDIR_FK)/BasicException.o : $(SRC_FOUNDATIONKIT)/BasicException.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/BasicException.cpp -o $(OUTDIR_FK)/BasicException.o

$(OUTDIR_FK)/BasicInputStream.o : $(SRC_FOUNDATIONKIT)/BasicInputStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/BasicInputStream.cpp -o $(OUTDIR_FK)/BasicInputStream.o

$(OUTDIR_FK)/BasicOutputStream.o : $(SRC_FOUNDATIONKIT)/BasicOutputStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/BasicOutputStream.cpp -o $(OUTDIR_FK)/BasicOutputStream.o

$(OUTDIR_FK)/Class.o : $(SRC_FOUNDATIONKIT)/Class.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/Class.cpp -o $(OUTDIR_FK)/Class.o

$(OUTDIR_FK)/ClassRegistry.o : $(SRC_FOUNDATIONKIT)/ClassRegistry.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/ClassRegistry.cpp -o $(OUTDIR_FK)/ClassRegistry.o

$(OUTDIR_FK)/CommandLine.o : $(SRC_FOUNDATIONKIT)/CommandLine.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/CommandLine.cpp -o $(OUTDIR_FK)/CommandLine.o
	
$(OUTDIR_FK)/DateTime.o : $(SRC_FOUNDATIONKIT)/DateTime.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/DateTime.cpp -o $(OUTDIR_FK)/DateTime.o
	
$(OUTDIR_FK)/Directory.o : $(SRC_FOUNDATIONKIT)/Directory.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/Directory.cpp -o $(OUTDIR_FK)/Directory.o

$(OUTDIR_FK)/ErrorLog.o : $(SRC_FOUNDATIONKIT)/ErrorLog.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/ErrorLog.cpp -o $(OUTDIR_FK)/ErrorLog.o

$(OUTDIR_FK)/Event.o : $(SRC_FOUNDATIONKIT)/Event.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/Event.cpp -o $(OUTDIR_FK)/Event.o

$(OUTDIR_FK)/EventHandler.o : $(SRC_FOUNDATIONKIT)/EventHandler.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/EventHandler.cpp -o $(OUTDIR_FK)/EventHandler.o

$(OUTDIR_FK)/File.o : $(SRC_FOUNDATIONKIT)/File.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/File.cpp -o $(OUTDIR_FK)/File.o

$(OUTDIR_FK)/FilePath.o : $(SRC_FOUNDATIONKIT)/FilePath.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/FilePath.cpp -o $(OUTDIR_FK)/FilePath.o

$(OUTDIR_FK)/FileStream.o : $(SRC_FOUNDATIONKIT)/FileStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/FileStream.cpp -o $(OUTDIR_FK)/FileStream.o

$(OUTDIR_FK)/FileUtils.o : $(SRC_FOUNDATIONKIT)/FileUtils.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/FileUtils.cpp -o $(OUTDIR_FK)/FileUtils.o

$(OUTDIR_FK)/FoundationKit.o : $(SRC_FOUNDATIONKIT)/FoundationKit.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/FoundationKit.cpp -o $(OUTDIR_FK)/FoundationKit.o

$(OUTDIR_FK)/InterfaceClass.o : $(SRC_FOUNDATIONKIT)/InterfaceClass.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/InterfaceClass.cpp -o $(OUTDIR_FK)/InterfaceClass.o

$(OUTDIR_FK)/Library.o : $(SRC_FOUNDATIONKIT)/Library.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/Library.cpp -o $(OUTDIR_FK)/Library.o

$(OUTDIR_FK)/Locales.o : $(SRC_FOUNDATIONKIT)/Locales.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/Locales.cpp -o $(OUTDIR_FK)/Locales.o

$(OUTDIR_FK)/MemoryStream.o : $(SRC_FOUNDATIONKIT)/MemoryStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/MemoryStream.cpp -o $(OUTDIR_FK)/MemoryStream.o

$(OUTDIR_FK)/MessageLoader.o : $(SRC_FOUNDATIONKIT)/MessageLoader.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/MessageLoader.cpp -o $(OUTDIR_FK)/MessageLoader.o
	
$(OUTDIR_FK)/StringsMessageLoader.o : $(SRC_FOUNDATIONKIT)/StringsMessageLoader.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/StringsMessageLoader.cpp -o $(OUTDIR_FK)/StringsMessageLoader.o	
	
$(OUTDIR_FK)/TextCodec.o : $(SRC_FOUNDATIONKIT)/TextCodec.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/TextCodec.cpp -o $(OUTDIR_FK)/TextCodec.o	
	
$(OUTDIR_FK)/Mutex.o : $(SRC_FOUNDATIONKIT)/Mutex.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/Mutex.cpp -o $(OUTDIR_FK)/Mutex.o

$(OUTDIR_FK)/Object.o : $(SRC_FOUNDATIONKIT)/Object.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/Object.cpp -o $(OUTDIR_FK)/Object.o

$(OUTDIR_FK)/ObjectWithEvents.o : $(SRC_FOUNDATIONKIT)/ObjectWithEvents.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/ObjectWithEvents.cpp -o $(OUTDIR_FK)/ObjectWithEvents.o

$(OUTDIR_FK)/Parser.o : $(SRC_FOUNDATIONKIT)/Parser.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/Parser.cpp -o $(OUTDIR_FK)/Parser.o


$(OUTDIR_FK)/PropertyChangeEvent.o : $(SRC_FOUNDATIONKIT)/PropertyChangeEvent.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/PropertyChangeEvent.cpp -o $(OUTDIR_FK)/PropertyChangeEvent.o

$(OUTDIR_FK)/Registry.o : $(SRC_FOUNDATIONKIT)/Registry.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/Registry.cpp -o $(OUTDIR_FK)/Registry.o

$(OUTDIR_FK)/Stream.o : $(SRC_FOUNDATIONKIT)/Stream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/Stream.cpp -o $(OUTDIR_FK)/Stream.o

$(OUTDIR_FK)/StringUtils.o : $(SRC_FOUNDATIONKIT)/StringUtils.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/StringUtils.cpp -o $(OUTDIR_FK)/StringUtils.o

$(OUTDIR_FK)/System.o : $(SRC_FOUNDATIONKIT)/System.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/System.cpp -o $(OUTDIR_FK)/System.o

$(OUTDIR_FK)/SystemToolkit.o : $(SRC_FOUNDATIONKIT)/SystemToolkit.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/SystemToolkit.cpp -o $(OUTDIR_FK)/SystemToolkit.o

$(OUTDIR_FK)/TextInputStream.o : $(SRC_FOUNDATIONKIT)/TextInputStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/TextInputStream.cpp -o $(OUTDIR_FK)/TextInputStream.o

$(OUTDIR_FK)/TextOutputStream.o : $(SRC_FOUNDATIONKIT)/TextOutputStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/TextOutputStream.cpp -o $(OUTDIR_FK)/TextOutputStream.o

$(OUTDIR_FK)/Thread.o : $(SRC_FOUNDATIONKIT)/Thread.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/Thread.cpp -o $(OUTDIR_FK)/Thread.o

$(OUTDIR_FK)/ThreadEvent.o : $(SRC_FOUNDATIONKIT)/ThreadEvent.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/ThreadEvent.cpp -o $(OUTDIR_FK)/ThreadEvent.o

$(OUTDIR_FK)/VariantData.o : $(SRC_FOUNDATIONKIT)/VariantData.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/VariantData.cpp -o $(OUTDIR_FK)/VariantData.o

$(OUTDIR_FK)/VCFMath.o : $(SRC_FOUNDATIONKIT)/VCFMath.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/VCFMath.cpp -o $(OUTDIR_FK)/VCFMath.o

$(OUTDIR_FK)/VCFString.o : $(SRC_FOUNDATIONKIT)/VCFString.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/VCFString.cpp -o $(OUTDIR_FK)/VCFString.o
	
$(OUTDIR_FK)/Condition.o : $(SRC_FOUNDATIONKIT)/Condition.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/Condition.cpp -o $(OUTDIR_FK)/Condition.o
	
$(OUTDIR_FK)/VCFProcess.o : $(SRC_FOUNDATIONKIT)/VCFProcess.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/VCFProcess.cpp -o $(OUTDIR_FK)/VCFProcess.o

$(OUTDIR_FK)/XMLParser.o : $(SRC_FOUNDATIONKIT)/XMLParser.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/XMLParser.cpp -o $(OUTDIR_FK)/XMLParser.o

$(OUTDIR_FK)/LinuxPeer.o : $(SRC_FOUNDATIONKIT)/LinuxPeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/LinuxPeer.cpp -o $(OUTDIR_FK)/LinuxPeer.o

$(OUTDIR_FK)/LinuxFilePeer.o : $(SRC_FOUNDATIONKIT)/LinuxFilePeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/LinuxFilePeer.cpp -o $(OUTDIR_FK)/LinuxFilePeer.o

$(OUTDIR_FK)/LinuxFileStream.o : $(SRC_FOUNDATIONKIT)/LinuxFileStream.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/LinuxFileStream.cpp -o $(OUTDIR_FK)/LinuxFileStream.o

$(OUTDIR_FK)/PosixThread.o : $(SRC_FOUNDATIONKIT)/PosixThread.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/PosixThread.cpp -o $(OUTDIR_FK)/PosixThread.o

$(OUTDIR_FK)/PosixMutex.o : $(SRC_FOUNDATIONKIT)/PosixMutex.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/PosixMutex.cpp -o $(OUTDIR_FK)/PosixMutex.o
	
$(OUTDIR_FK)/PosixCondition.o : $(SRC_FOUNDATIONKIT)/PosixCondition.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/PosixCondition.cpp -o $(OUTDIR_FK)/PosixCondition.o	
	
$(OUTDIR_FK)/LinuxLibraryPeer.o : $(SRC_FOUNDATIONKIT)/LinuxLibraryPeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/LinuxLibraryPeer.cpp -o $(OUTDIR_FK)/LinuxLibraryPeer.o

$(OUTDIR_FK)/LinuxMutex.o : $(SRC_FOUNDATIONKIT)/LinuxMutex.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/LinuxMutex.cpp -o $(OUTDIR_FK)/LinuxMutex.o

$(OUTDIR_FK)/LinuxProcessPeer.o : $(SRC_FOUNDATIONKIT)/LinuxProcessPeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/LinuxProcessPeer.cpp -o $(OUTDIR_FK)/LinuxProcessPeer.o

$(OUTDIR_FK)/LinuxRegistry.o : $(SRC_FOUNDATIONKIT)/LinuxRegistry.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/LinuxRegistry.cpp -o $(OUTDIR_FK)/LinuxRegistry.o

$(OUTDIR_FK)/LinuxSemaphorePeer.o : $(SRC_FOUNDATIONKIT)/LinuxSemaphorePeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/LinuxSemaphorePeer.cpp -o $(OUTDIR_FK)/LinuxSemaphorePeer.o

$(OUTDIR_FK)/LinuxSystemPeer.o : $(SRC_FOUNDATIONKIT)/LinuxSystemPeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/LinuxSystemPeer.cpp -o $(OUTDIR_FK)/LinuxSystemPeer.o

$(OUTDIR_FK)/LinuxSystemToolkit.o : $(SRC_FOUNDATIONKIT)/LinuxSystemToolkit.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/LinuxSystemToolkit.cpp -o $(OUTDIR_FK)/LinuxSystemToolkit.o

$(OUTDIR_FK)/LinuxProcessIORedirector.o : $(SRC_FOUNDATIONKIT)/LinuxProcessIORedirector.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/LinuxProcessIORedirector.cpp -o $(OUTDIR_FK)/LinuxProcessIORedirector.o

$(OUTDIR_FK)/LinuxLocalePeer.o : $(SRC_FOUNDATIONKIT)/LinuxLocalePeer.cpp $(FOUNDATIONKIT_HDRS)
	$(CXX) $(CXX_FLAGS) $(SRC_FOUNDATIONKIT)/LinuxLocalePeer.cpp -o $(OUTDIR_FK)/LinuxLocalePeer.o
	

