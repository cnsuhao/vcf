#######################################################
# MAKEFILE for building libAGG_bcc_s(d).lib           #
#                                                     #
#                                                     #
# (c) 2004 by Darko Miletic                           #
# e-mail: kiklop@fibertel.com.ar                      # 
#######################################################
.autodepend

!ifndef BMODE
BMODE = RELEASE
!endif

!if $(BMODE) != RELEASE && $(BMODE) != DEBUG
!  error Illegal value for BMODE option
!endif

!include <..\defaultmake.inc>

CPPFLAGS=$(CPPFLAGS) -w-8027 -w-inl -w-8057 -w-8004

!if $(BMODE) == RELEASE
	USERDEFINES=NDEBUG
	OBJDIR=bcc\Release$(TDIR)
	LPARAMS=/P64
	!message Building release version of project
!else
	USERDEFINES=_DEBUG
	OBJDIR=bcc\Debug$(TDIR)
	LPARAMS=/P256
	!message Building debug version of project
!endif

PROJECT=$(PROJECT1)
SYSDEFINES=_LIB
OUTDIR=..\..\..\lib
TDIR=S

LIBNAME=libAGG_bcc_s$(DBG).lib
DLLNAME=
INCDIR=..\..\..\src
LIBDIR=..\..\..\lib
SRC=
OBJ=.\$(OBJDIR)
BIN=.\$(OUTDIR)
RESFILE=
SYSDEFINES=STRICT;WIN32;_MBCS;NO_MFC;$(SYSDEFINES)

################################
# Target
################################
PROJECT1=$(BIN)\$(LIBNAME)
PROJECT2=$(BIN)\$(DLLNAME)
OBJFILES=$(OBJ)\agg_arc.obj  \
	$(OBJ)\agg_bezier_arc.obj  \
	$(OBJ)\agg_bspline.obj  \
	$(OBJ)\agg_curves.obj  \
	$(OBJ)\agg_path_storage.obj  \
	$(OBJ)\agg_rasterizer_scanline_aa.obj  \
	$(OBJ)\agg_trans_affine.obj  \
	$(OBJ)\agg_vcgen_bspline.obj  \
	$(OBJ)\agg_vcgen_stroke.obj
         
LIBFILES=ODBC32.LIB UUID.LIB
DEFFILE=
ALLOBJS=$(OBJFILES)

all: dirs $(RESFILE) $(PROJECT)

cleanobj:: 
	-@echo Deleting intermediate files for project
	-@if exist $(OBJ)\*.obj del $(OBJ)\*.obj
	-@if exist $(OBJ)\*.res del $(OBJ)\*.res
	-@if exist $(OBJ)\. rd $(OBJ)
!if $(BMODE) == RELEASE
	-@if exist $(BIN)\*.tds del $(BIN)\*.tds
	-@if exist $(BIN)\*.map del $(BIN)\*.map
!endif

cleantgt::
	-@echo Deleting output files for project
	-@if exist $(PROJECT) del $(PROJECT)

clean: cleanobj cleantgt

dirs::
	-@echo Creating output directory
	-@md bcc
	-@md $(OBJ)
	-@md $(BIN)
	
##################################
# Output
##################################
$(PROJECT1): $(OBJFILES)
  @$(LB) $(LPARAMS) $(BIN)\$(LIBNAME) /a$(OBJFILES)

    
#Dependencies - explicit rules
$(OBJ)\agg_arc.obj:                      ..\..\..\src\thirdparty\common\agg\src\agg_arc.cpp                   
$(OBJ)\agg_bezier_arc.obj:               ..\..\..\src\thirdparty\common\agg\src\agg_bezier_arc.cpp            
$(OBJ)\agg_bspline.obj:                  ..\..\..\src\thirdparty\common\agg\src\agg_bspline.cpp               
$(OBJ)\agg_curves.obj:                   ..\..\..\src\thirdparty\common\agg\src\agg_curves.cpp                
$(OBJ)\agg_path_storage.obj:             ..\..\..\src\thirdparty\common\agg\src\agg_path_storage.cpp          
$(OBJ)\agg_rasterizer_scanline_aa.obj:   ..\..\..\src\thirdparty\common\agg\src\agg_rasterizer_scanline_aa.cpp
$(OBJ)\agg_trans_affine.obj:             ..\..\..\src\thirdparty\common\agg\src\agg_trans_affine.cpp          
$(OBJ)\agg_vcgen_bspline.obj:            ..\..\..\src\thirdparty\common\agg\src\agg_vcgen_bspline.cpp         
$(OBJ)\agg_vcgen_stroke.obj:             ..\..\..\src\thirdparty\common\agg\src\agg_vcgen_stroke.cpp          