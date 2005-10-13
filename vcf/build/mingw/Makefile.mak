## generic makefile included from builddir

# /out:"..\..\..\bin\FoundationKit_vc6_d.dll" /implib:"..\..\..\lib\FoundationKit_vc6_d.lib" 




SRC=../../../../src
LIB=../../../../lib
BIN=../../../../bin


VPATH = $(SRC)/vcf

OBJECTS  := $(SOURCES:.cpp=.obj) 

#Debug builds are NOT allowed

CXXFLAGS  = /nologo /W3 /GR /GX /O1 /D "NDEBUG" /D "_LIB" /FD /MT /Zm200
CXXFLAGS += /I "$(MS_PLATFORMSDKINCLUDES)" /I "$(MS_INCLUDES)" /I "$(SRC)" /D "WIN32"  /D "_WINDOWS" /D "_MBCS" 

PRECOMPCXXFLAGS = $(CXXFLAGS)

LDFLAGS   = -lib /nologo kernel32.lib user32.lib gdi32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /machine:I386 
LDFLAGS  += /libpath:"$(MS_PLATFORMSDKLIB)" 
LDFLAGS  += /libpath:"$(MS_LIB)" 
LDFLAGS  += /libpath:"$(LIB)" 
LDFLAGS += /out:"$(LIB)\$(TARGET)"  

## FoundationKit
ifeq ($(KIT), AllIn1)	
	
PRECOMPCPP = $(SRC)/vcf/ApplicationKit/ApplicationKit.cpp
PRECOMPOBJ := ApplicationKit.obj	
	CXXFLAGS +=  /Fp"ApplicationKit.pch" /YX
	PRECOMPCXXFLAGS += /Yc"vcf/ApplicationKit/ApplicationKit.h"		
	 
endif

## GraphicsKit
ifeq ($(KIT), GraphicsKit)
   ifeq ($(BUILD), Debug)
      OBJECTS += $(LIB)/libagg_d.a
      #OBJECTS += $(LIB)/libjpeg_d.a
      #OBJECTS += $(LIB)/libpng_d.a
   else
      OBJECTS += $(LIB)/libagg.a
      #OBJECTS += $(LIB)/libjpeg.a
      #OBJECTS += $(LIB)/libpng.a
   endif
   LDFLAGS += -lFoundationKit
endif

## ApplicationKit
ifeq ($(KIT), ApplicationKit)
   LDFLAGS += -lFoundationKit -lGraphicsKit
endif

## NetworkKit
ifeq ($(KIT), NetworkKit)
   LDFLAGS += -lFoundationKit
endif


## LibAGG
ifeq ($(KIT), LibAGG)
   CXXFLAGS += -I$(SRC)/thirdparty/common/agg/include
   VPATH = $(SRC)/thirdparty/common/agg/src
else
   
endif

## LibJPEG
#ifeq ($(KIT), LibJPEG)
   #CXXFLAGS += -I$(SRC)/thirdparty/common/LibJPEG
   #VPATH = $(SRC)/thirdparty/common/LibJPEG
#endif

## LibPNG
#ifeq ($(KIT), LibPNG)
   #CXXFLAGS += -I$(SRC)/thirdparty/common/LibPNG
   #VPATH = $(SRC)/thirdparty/common/LibPNG
#else
  # VPATH = $(SRC)/vcf/$(KIT)
#endif


CXXFLAGS += /c
LDFLAGS  := $(LDFLAGS:Kit=Kit_d)

all: AllIn1-make-static

AllIn1-make-static: $(TARGET)



$(PRECOMPOBJ):
	@echo "Creating pre-compiled header for $(KIT) using compiler $(CXX) " 
	$(CXX) $(PRECOMPCXXFLAGS) $(PRECOMPCPP)
	
	
%.obj: %.cpp
	$(CXX) $(CXXFLAGS) $<


$(TARGET): $(PRECOMPOBJ) $(OBJECTS)
	$(LINKER) $(LDFLAGS)  $^

