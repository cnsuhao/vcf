###########################################################
#
#
#CVS Log info
#$Log$
#Revision 1.2.10.1  2004/04/28 14:40:01  ddiego
#migration towards new directory structure
#
#Revision 1.2  2003/02/26 04:30:25  ddiego
#merge of code in the devmain-0-5-9 branch into the current tree.
#most additions are in the area of the current linux port, but the major
#addition to this release is the addition of a Condition class (currently
#still under development) and the change over to using the Delegate class
#exclusively from the older event handler macros.
#
#Revision 1.1.2.2  2003/02/08 17:55:44  ddiego
#modified the makefiles to have cvs Log entries, so we can keepo track of
#whats going on :)
#
#
#
#Object files for the NetworkKit 
#
###########################################################



###########################################################
#Debug files
###########################################################

$(OUTDIR_NK_D)/DatagramSocket.o : $(SRC_NETWORKKIT)/DatagramSocket.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS_D) $(SRC_NETWORKKIT)/DatagramSocket.cpp -o $(OUTDIR_NK_D)/DatagramSocket.o
	
$(OUTDIR_NK_D)/NetToolkit.o : $(SRC_NETWORKKIT)/NetToolkit.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS_D) $(SRC_NETWORKKIT)/NetToolkit.cpp -o $(OUTDIR_NK_D)/NetToolkit.o

$(OUTDIR_NK_D)/ServerSocketEvent.o : $(SRC_NETWORKKIT)/ServerSocketEvent.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS_D) $(SRC_NETWORKKIT)/ServerSocketEvent.cpp -o $(OUTDIR_NK_D)/ServerSocketEvent.o

$(OUTDIR_NK_D)/Socket.o : $(SRC_NETWORKKIT)/Socket.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS_D) $(SRC_NETWORKKIT)/Socket.cpp -o $(OUTDIR_NK_D)/Socket.o

$(OUTDIR_NK_D)/SocketEvent.o : $(SRC_NETWORKKIT)/SocketEvent.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS_D) $(SRC_NETWORKKIT)/SocketEvent.cpp -o $(OUTDIR_NK_D)/SocketEvent.o

$(OUTDIR_NK_D)/SocketListeningLoop.o : $(SRC_NETWORKKIT)/SocketListeningLoop.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS_D) $(SRC_NETWORKKIT)/SocketListeningLoop.cpp -o $(OUTDIR_NK_D)/SocketListeningLoop.o

$(OUTDIR_NK_D)/URL.o  : $(SRC_NETWORKKIT)/URL.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS_D) $(SRC_NETWORKKIT)/URL.cpp -o $(OUTDIR_NK_D)/URL.o
	
	

###########################################################
#Release files
###########################################################

$(OUTDIR_NK)/DatagramSocket.o : $(SRC_NETWORKKIT)/DatagramSocket.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS) $(SRC_NETWORKKIT)/DatagramSocket.cpp -o $(OUTDIR_NK)/DatagramSocket.o
	
$(OUTDIR_NK)/NetToolkit.o : $(SRC_NETWORKKIT)/NetToolkit.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS) $(SRC_NETWORKKIT)/NetToolkit.cpp -o $(OUTDIR_NK)/NetToolkit.o

$(OUTDIR_NK)/ServerSocketEvent.o : $(SRC_NETWORKKIT)/ServerSocketEvent.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS) $(SRC_NETWORKKIT)/ServerSocketEvent.cpp -o $(OUTDIR_NK)/ServerSocketEvent.o

$(OUTDIR_NK)/Socket.o : $(SRC_NETWORKKIT)/Socket.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS) $(SRC_NETWORKKIT)/Socket.cpp -o $(OUTDIR_NK)/Socket.o

$(OUTDIR_NK)/SocketEvent.o : $(SRC_NETWORKKIT)/SocketEvent.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS) $(SRC_NETWORKKIT)/SocketEvent.cpp -o $(OUTDIR_NK)/SocketEvent.o

$(OUTDIR_NK)/SocketListeningLoop.o : $(SRC_NETWORKKIT)/SocketListeningLoop.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS) $(SRC_NETWORKKIT)/SocketListeningLoop.cpp -o $(OUTDIR_NK)/SocketListeningLoop.o

$(OUTDIR_NK)/URL.o  : $(SRC_NETWORKKIT)/URL.cpp $(NETWORKKIT_HDRS)
	$(CXX) $(NK_CXX_FLAGS) $(SRC_NETWORKKIT)/URL.cpp -o $(OUTDIR_NK)/URL.o
	
	
	
	
	