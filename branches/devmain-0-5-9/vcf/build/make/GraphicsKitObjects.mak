###########################################################
#
#Object files for the GraphicsKit 
#
###########################################################



###########################################################
#Debug files
###########################################################

$(OUTDIR_GK_D)/GraphicsKit.o : $(SRC_GRF)/GraphicsKit.cpp $(GRAPHICSKIT_HDRS)
	$(CXX) $(GK_CXX_FLAGS_D) $(SRC_GRF)/GraphicsKit.cpp -o $(OUTDIR_GK_D)/GraphicsKit.o
	

$(OUTDIR_GK_D)/AbstractImage.o
$(OUTDIR_GK_D)/BasicFill.o
$(OUTDIR_GK_D)/BasicStroke.o
$(OUTDIR_GK_D)/Color.o
$(OUTDIR_GK_D)/Font.o
$(OUTDIR_GK_D)/FontState.o
$(OUTDIR_GK_D)/GlyphCollection.o
$(OUTDIR_GK_D)/GraphicsContext.o \
			$(OUTDIR_GK_D)/GraphicsObject.o \
			$(OUTDIR_GK_D)/Utils/GraphicsToolKit.o \
			$(OUTDIR_GK_D)/Events/ImageEvent.o \
			$(OUTDIR_GK_D)/Matrix2D.o \
			$(OUTDIR_GK_D)/Polygon.o \
			$(OUTDIR_GK_D)/Vector2D.o \
			$(OUTDIR_GK_D)/X11Font.o \
			$(OUTDIR_GK_D)/X11Image.o \
			$(OUTDIR_GK_D)/X11Context.o \
			$(OUTDIR_GK_D)/X11GraphicsToolkit.o \
			$(OUTDIR_GK_D)/MgcBezierCurve2.o \
			$(OUTDIR_GK_D)/MgcCurve2.o \
			$(OUTDIR_GK_D)/MgcVector2.o \
			$(OUTDIR_GK_D)/MgcIntegrate.o \
			$(OUTDIR_GK_D)/MgcSingleCurve2.o \
			$(OUTDIR_GK_D)/MgcMath.o 