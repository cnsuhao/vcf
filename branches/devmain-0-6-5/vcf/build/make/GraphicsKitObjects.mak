###########################################################
#
#CVS Log info
#$Log$
#Revision 1.4.4.1  2004/04/28 14:40:01  ddiego
#migration towards new directory structure
#
#Revision 1.4  2003/12/18 05:15:47  ddiego
#merge from devmain-0-6-2 branch into the stable branch
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
#Object files for the GraphicsKit 
#
###########################################################



###########################################################
#Debug files
###########################################################

$(OUTDIR_GK_D)/GraphicsKit.o : $(SRC_GRAPHICSKIT)/GraphicsKit.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/GraphicsKit.cpp -o $(OUTDIR_GK_D)/GraphicsKit.o
	

$(OUTDIR_GK_D)/AbstractImage.o : $(SRC_GRAPHICSKIT)/AbstractImage.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/AbstractImage.cpp -o $(OUTDIR_GK_D)/AbstractImage.o
	
$(OUTDIR_GK_D)/Rect.o : $(SRC_GRAPHICSKIT)/Rect.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/Rect.cpp -o $(OUTDIR_GK_D)/Rect.o	
	
$(OUTDIR_GK_D)/Point.o : $(SRC_GRAPHICSKIT)/Point.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/Point.cpp -o $(OUTDIR_GK_D)/Point.o		
	
$(OUTDIR_GK_D)/BasicFill.o : $(SRC_GRAPHICSKIT)/BasicFill.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/BasicFill.cpp -o $(OUTDIR_GK_D)/BasicFill.o
	
$(OUTDIR_GK_D)/BasicStroke.o : $(SRC_GRAPHICSKIT)/BasicStroke.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/BasicStroke.cpp -o $(OUTDIR_GK_D)/BasicStroke.o
	
$(OUTDIR_GK_D)/Color.o : $(SRC_GRAPHICSKIT)/Color.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/Color.cpp -o $(OUTDIR_GK_D)/Color.o
	
$(OUTDIR_GK_D)/Font.o : $(SRC_GRAPHICSKIT)/Font.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/Font.cpp -o $(OUTDIR_GK_D)/Font.o
	
$(OUTDIR_GK_D)/GlyphCollection.o : $(SRC_GRAPHICSKIT)/GlyphCollection.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/GlyphCollection.cpp -o $(OUTDIR_GK_D)/GlyphCollection.o
	
$(OUTDIR_GK_D)/GraphicsContext.o : $(SRC_GRAPHICSKIT)/GraphicsContext.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/GraphicsContext.cpp -o $(OUTDIR_GK_D)/GraphicsContext.o
	
$(OUTDIR_GK_D)/GraphicsToolKit.o : $(SRC_GRAPHICSKIT)/GraphicsToolKit.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/GraphicsToolKit.cpp -o $(OUTDIR_GK_D)/GraphicsToolKit.o
	
$(OUTDIR_GK_D)/ImageEvent.o : $(SRC_GRAPHICSKIT)/ImageEvent.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/ImageEvent.cpp -o $(OUTDIR_GK_D)/ImageEvent.o
	
$(OUTDIR_GK_D)/Matrix2D.o : $(SRC_GRAPHICSKIT)/Matrix2D.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/Matrix2D.cpp -o $(OUTDIR_GK_D)/Matrix2D.o
	
$(OUTDIR_GK_D)/BezierCurve.o : $(SRC_GRAPHICSKIT)/BezierCurve.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/BezierCurve.cpp -o $(OUTDIR_GK_D)/BezierCurve.o
	
$(OUTDIR_GK_D)/Vector2D.o : $(SRC_GRAPHICSKIT)/Vector2D.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/Vector2D.cpp -o $(OUTDIR_GK_D)/Vector2D.o
	
$(OUTDIR_GK_D)/GTKFont.o : $(SRC_GRAPHICSKIT)/GTKFont.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/GTKFont.cpp -o $(OUTDIR_GK_D)/GTKFont.o
	
$(OUTDIR_GK_D)/GTKImage.o : $(SRC_GRAPHICSKIT)/GTKImage.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/GTKImage.cpp -o $(OUTDIR_GK_D)/GTKImage.o
	
$(OUTDIR_GK_D)/GTKContext.o : $(SRC_GRAPHICSKIT)/GTKContext.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/GTKContext.cpp -o $(OUTDIR_GK_D)/GTKContext.o
	
$(OUTDIR_GK_D)/GTKGraphicsToolkit.o : $(SRC_GRAPHICSKIT)/GTKGraphicsToolkit.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/GTKGraphicsToolkit.cpp -o $(OUTDIR_GK_D)/GTKGraphicsToolkit.o
	
$(OUTDIR_GK_D)/MgcBezierCurve2.o : $(SRC_GRAPHICSKIT)/MgcBezierCurve2.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/MgcBezierCurve2.cpp -o $(OUTDIR_GK_D)/MgcBezierCurve2.o
	
$(OUTDIR_GK_D)/MgcCurve2.o : $(SRC_GRAPHICSKIT)/MgcCurve2.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/MgcCurve2.cpp -o $(OUTDIR_GK_D)/MgcCurve2.o
	
$(OUTDIR_GK_D)/MgcVector2.o : $(SRC_GRAPHICSKIT)/MgcVector2.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/MgcVector2.cpp -o $(OUTDIR_GK_D)/MgcVector2.o
	
$(OUTDIR_GK_D)/MgcIntegrate.o : $(SRC_GRAPHICSKIT)/MgcIntegrate.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/MgcIntegrate.cpp -o $(OUTDIR_GK_D)/MgcIntegrate.o
	
$(OUTDIR_GK_D)/MgcSingleCurve2.o : $(SRC_GRAPHICSKIT)/MgcSingleCurve2.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/MgcSingleCurve2.cpp -o $(OUTDIR_GK_D)/MgcSingleCurve2.o
	
$(OUTDIR_GK_D)/MgcMath.o  : $(SRC_GRAPHICSKIT)/MgcMath.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRAPHICSKIT)/MgcMath.cpp -o $(OUTDIR_GK_D)/MgcMath.o
	




###########################################################
#Release files
###########################################################

$(OUTDIR_GK)/GraphicsKit.o : $(SRC_GRAPHICSKIT)/GraphicsKit.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/GraphicsKit.cpp -o $(OUTDIR_GK)/GraphicsKit.o	

$(OUTDIR_GK)/AbstractImage.o : $(SRC_GRAPHICSKIT)/AbstractImage.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/AbstractImage.cpp -o $(OUTDIR_GK)/AbstractImage.o
	
$(OUTDIR_GK)/BasicFill.o : $(SRC_GRAPHICSKIT)/BasicFill.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/BasicFill.cpp -o $(OUTDIR_GK)/BasicFill.o
	
$(OUTDIR_GK)/BasicStroke.o : $(SRC_GRAPHICSKIT)/BasicStroke.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/BasicStroke.cpp -o $(OUTDIR_GK)/BasicStroke.o
	
$(OUTDIR_GK)/Color.o : $(SRC_GRAPHICSKIT)/Color.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/Color.cpp -o $(OUTDIR_GK)/Color.o
	
$(OUTDIR_GK)/Font.o : $(SRC_GRAPHICSKIT)/Font.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/Font.cpp -o $(OUTDIR_GK)/Font.o
	
$(OUTDIR_GK)/GlyphCollection.o : $(SRC_GRAPHICSKIT)/GlyphCollection.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/GlyphCollection.cpp -o $(OUTDIR_GK)/GlyphCollection.o
	
$(OUTDIR_GK)/GraphicsContext.o : $(SRC_GRAPHICSKIT)/GraphicsContext.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/GraphicsContext.cpp -o $(OUTDIR_GK)/GraphicsContext.o
	
	
$(OUTDIR_GK)/GraphicsToolKit.o : $(SRC_GRAPHICSKIT)/GraphicsToolKit.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/GraphicsToolKit.cpp -o $(OUTDIR_GK)/GraphicsToolKit.o
	
$(OUTDIR_GK)/ImageEvent.o : $(SRC_GRAPHICSKIT)/ImageEvent.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/ImageEvent.cpp -o $(OUTDIR_GK)/ImageEvent.o
	
$(OUTDIR_GK)/Matrix2D.o : $(SRC_GRAPHICSKIT)/Matrix2D.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/Matrix2D.cpp -o $(OUTDIR_GK)/Matrix2D.o
	
$(OUTDIR_GK)/BezierCurve.o : $(SRC_GRAPHICSKIT)/BezierCurve.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/BezierCurve.cpp -o $(OUTDIR_GK)/BezierCurve.o
	
$(OUTDIR_GK)/Vector2D.o : $(SRC_GRAPHICSKIT)/Vector2D.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/Vector2D.cpp -o $(OUTDIR_GK)/Vector2D.o
	
$(OUTDIR_GK)/GTKFont.o : $(SRC_GRAPHICSKIT)/GTKFont.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/GTKFont.cpp -o $(OUTDIR_GK)/GTKFont.o
	
$(OUTDIR_GK)/GTKImage.o : $(SRC_GRAPHICSKIT)/GTKImage.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/GTKImage.cpp -o $(OUTDIR_GK)/GTKImage.o
	
$(OUTDIR_GK)/GTKContext.o : $(SRC_GRAPHICSKIT)/GTKContext.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/GTKContext.cpp -o $(OUTDIR_GK)/GTKContext.o
	
$(OUTDIR_GK)/GTKGraphicsToolkit.o : $(SRC_GRAPHICSKIT)/GTKGraphicsToolkit.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/GTKGraphicsToolkit.cpp -o $(OUTDIR_GK)/GTKGraphicsToolkit.o
	
$(OUTDIR_GK)/MgcBezierCurve2.o : $(SRC_GRAPHICSKIT)/MgcBezierCurve2.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/MgcBezierCurve2.cpp -o $(OUTDIR_GK)/MgcBezierCurve2.o
	
$(OUTDIR_GK)/MgcCurve2.o : $(SRC_GRAPHICSKIT)/MgcCurve2.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/MgcCurve2.cpp -o $(OUTDIR_GK)/MgcCurve2.o
	
$(OUTDIR_GK)/MgcVector2.o : $(SRC_GRAPHICSKIT)/MgcVector2.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/MgcVector2.cpp -o $(OUTDIR_GK)/MgcVector2.o
	
$(OUTDIR_GK)/MgcIntegrate.o : $(SRC_GRAPHICSKIT)/MgcIntegrate.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/MgcIntegrate.cpp -o $(OUTDIR_GK)/MgcIntegrate.o
	
$(OUTDIR_GK)/MgcSingleCurve2.o : $(SRC_GRAPHICSKIT)/MgcSingleCurve2.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/MgcSingleCurve2.cpp -o $(OUTDIR_GK)/MgcSingleCurve2.o
	
$(OUTDIR_GK)/MgcMath.o  : $(SRC_GRAPHICSKIT)/MgcMath.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/MgcMath.cpp -o $(OUTDIR_GK)/MgcMath.o
	
$(OUTDIR_GK)/Rect.o : $(SRC_GRAPHICSKIT)/Rect.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/Rect.cpp -o $(OUTDIR_GK)/Rect.o	
	
$(OUTDIR_GK)/Point.o : $(SRC_GRAPHICSKIT)/Point.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS) $(SRC_GRAPHICSKIT)/Point.cpp -o $(OUTDIR_GK)/Point.o			


