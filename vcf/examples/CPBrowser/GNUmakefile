# =========================================================================
#     This makefile was generated by
#     Bakefile 0.2.9 (http://www.bakefile.org)
#     Do not modify, all changes will be overwritten!
# =========================================================================

include ../../build/bakefiles.gen/config.gnu

# -------------------------------------------------------------------------
# Do not modify the rest of this file!
# -------------------------------------------------------------------------

### Variables: ###

CPPDEPS = -MT$@ -MF`echo $@ | sed -e 's,\.o$$,.d,'` -MD -MP
OBJDIR = gnu$(OPTION_SELECTLIB)$(SUFFIX_LIBRARY)
AGG_FILENAME = AGG$(OPTION_SELECTLIB)$(SUFFIX_STATIC)
ZLIB_FILENAME = ZLib$(OPTION_SELECTLIB)$(SUFFIX_STATIC)
LIBJPEG_FILENAME = LibJPEG$(OPTION_SELECTLIB)$(SUFFIX_STATIC)
LIBPNG_FILENAME = LibPNG$(OPTION_SELECTLIB)$(SUFFIX_STATIC)
LIBXML_FILENAME = libxml$(OPTION_SELECTLIB)$(SUFFIX_STATIC)
LIBXSLT_FILENAME = libxslt$(OPTION_SELECTLIB)$(SUFFIX_STATIC)
FOUNDATIONKIT_FILENAME = FoundationKit$(OPTION_SELECTLIB)$(SUFFIX_LIBRARY)
GRAPHICSKIT_FILENAME = GraphicsKit$(OPTION_SELECTLIB)$(SUFFIX_LIBRARY)
APPLICATIONKIT_FILENAME = ApplicationKit$(OPTION_SELECTLIB)$(SUFFIX_LIBRARY)
HTMLKIT_FILENAME = HTMLKit$(OPTION_SELECTLIB)$(SUFFIX_LIBRARY)
INTERNETKIT_FILENAME = InternetKit$(OPTION_SELECTLIB)$(SUFFIX_LIBRARY)
XMLKIT_FILENAME = XMLKit$(OPTION_SELECTLIB)$(SUFFIX_LIBRARY)
ALLIN1_FILENAME = VCF$(OPTION_SELECTLIB)$(SUFFIX_LIBRARY)
CPBROWSER_CXXFLAGS = $(__DEBUG_INFO) $(__OPTIMIZE_4) $(__OPTION_THREADING_6) \
	$(__OPTION_WARNINGS_9) $(____OPTION_DEBUG_10_p) -Wno-multichar \
	-DVCF_DISABLE_PRAGMA_LINKING -I../../src \
	-I../../src/thirdparty/common/ZLib -I../../src/thirdparty/common/LibPNG \
	-I../../src/thirdparty/common/LibJPEG \
	-I../../src/thirdparty/common/agg/include $(__FOUNDATIONKIT_DLL_p) \
	$(__GRAPHICSKIT_DLL_p) $(__APPLICATIONKIT_DLL_p) $(__HTMLKIT_DLL_p) \
	$(__FOUNDATIONKIT_DLL_p) $(__INTERNETKIT_DLL_p) \
	-I../../src/thirdparty/common/libxml/include -DLIBXML_STATIC \
	-I../../src/thirdparty/common/libxslt -DLIBXML_STATIC -DLIBXSLT_STATIC \
	$(__FOUNDATIONKIT_DLL_p) $(__XMLKIT_DLL_p) $(____OPTION_CPP_RTTI_0_7) \
	$(____OPTION_CPP_EXCEPTIONS_1_8) $(CPPFLAGS) $(CXXFLAGS)
CPBROWSER_OBJECTS =  \
	../../lib/$(OBJDIR)/examples/CPBrowser/CPBrowser_CPBrowser.o

### Conditionally set variables: ###

ifeq ($(OPTION_DEBUG),0)
SUFFIX_STATIC = _s
endif
ifeq ($(OPTION_DEBUG),1)
SUFFIX_STATIC = _sd
endif
ifeq ($(OPTION_DEBUG),0)
SUFFIX_DYNAMIC = 
endif
ifeq ($(OPTION_DEBUG),1)
SUFFIX_DYNAMIC = _d
endif
ifeq ($(OPTION_SHARED),0)
SUFFIX_LIBRARY = $(SUFFIX_STATIC)
endif
ifeq ($(OPTION_SHARED),1)
SUFFIX_LIBRARY = $(SUFFIX_DYNAMIC)
endif
ifeq ($(OPTION_HTMLKIT),1)
ifeq ($(OPTION_INTERNETKIT),1)
ifeq ($(OPTION_XMLKIT),1)
__CPBrowser___depname = ../../examples/CPBrowser/CPBrowser
endif
endif
endif
ifeq ($(OPTION_DEBUG),0)
__OPTIMIZE_4 = -O2
endif
ifeq ($(OPTION_DEBUG),1)
__OPTIMIZE_4 = -O0
endif
ifeq ($(OPTION_THREADING),multi)
__OPTION_THREADING_5 = -pthread
endif
ifeq ($(OPTION_THREADING),single)
__OPTION_THREADING_5 = 
endif
ifeq ($(OPTION_THREADING),multi)
__OPTION_THREADING_6 = -D_THREAD_SAFE -pthread
endif
ifeq ($(OPTION_THREADING),single)
__OPTION_THREADING_6 = 
endif
ifeq ($(OPTION_CPP_RTTI),0)
____OPTION_CPP_RTTI_0_7 = -fno-rtti
endif
ifeq ($(OPTION_CPP_RTTI),1)
____OPTION_CPP_RTTI_0_7 = 
endif
ifeq ($(OPTION_CPP_EXCEPTIONS),0)
____OPTION_CPP_EXCEPTIONS_1_8 = -fno-exceptions
endif
ifeq ($(OPTION_CPP_EXCEPTIONS),1)
____OPTION_CPP_EXCEPTIONS_1_8 = 
endif
ifeq ($(OPTION_WARNINGS),no)
__OPTION_WARNINGS_9 = 
endif
ifeq ($(OPTION_WARNINGS),default)
__OPTION_WARNINGS_9 = 
endif
ifeq ($(OPTION_WARNINGS),max)
__OPTION_WARNINGS_9 = -W -Wall
endif
ifeq ($(OPTION_DEBUG),0)
____OPTION_DEBUG_10_p = -DNDEBUG
endif
ifeq ($(OPTION_DEBUG),1)
____OPTION_DEBUG_10_p = -D_DEBUG
endif
ifeq ($(OPTION_ALLIN1),0)
____CPBrowser_FOUNDATIONKIT_p = -l$(FOUNDATIONKIT_FILENAME)
endif
ifeq ($(OPTION_ALLIN1),1)
____CPBrowser_FOUNDATIONKIT_p = -l$(ALLIN1_FILENAME)
endif
ifeq ($(OPTION_ALLIN1),0)
____CPBrowser_GRAPHICSKIT_p = -l$(GRAPHICSKIT_FILENAME)
endif
ifeq ($(OPTION_SHARED),1)
__GRAPHICSKIT_DLL_p = -DGRAPHICSKIT_DLL
endif
ifeq ($(OPTION_ALLIN1),0)
____CPBrowser_APPLICATIONKIT_p = -l$(APPLICATIONKIT_FILENAME)
endif
ifeq ($(OPTION_SHARED),1)
__APPLICATIONKIT_DLL_p = -DAPPLICATIONKIT_DLL
endif
ifeq ($(OPTION_ALLIN1),0)
____CPBrowser_HTMLKIT_p = -l$(HTMLKIT_FILENAME)
endif
ifeq ($(OPTION_SHARED),1)
__HTMLKIT_DLL_p = -DHTMLKIT_DLL
endif
ifeq ($(OPTION_ALLIN1),1)
____CPBrowser_FOUNDATIONKIT_p_1 = -l$(ALLIN1_FILENAME)
endif
ifeq ($(OPTION_ALLIN1),0)
____CPBrowser_FOUNDATIONKIT_p_1 = -l$(FOUNDATIONKIT_FILENAME)
endif
ifeq ($(OPTION_ALLIN1),1)
____CPBrowser_FOUNDATIONKIT_p_1 = -l$(ALLIN1_FILENAME)
endif
ifeq ($(OPTION_ALLIN1),0)
____CPBrowser_FOUNDATIONKIT_p_1 = -l$(FOUNDATIONKIT_FILENAME)
endif
ifeq ($(OPTION_ALLIN1),0)
____CPBrowser_INTERNETKIT_p = -l$(INTERNETKIT_FILENAME)
endif
ifeq ($(OPTION_SHARED),1)
__INTERNETKIT_DLL_p = -DINTERNETKIT_DLL
endif
ifeq ($(OPTION_ALLIN1),1)
____CPBrowser_FOUNDATIONKIT_p_2 = -l$(ALLIN1_FILENAME)
endif
ifeq ($(OPTION_ALLIN1),0)
____CPBrowser_FOUNDATIONKIT_p_2 = -l$(FOUNDATIONKIT_FILENAME)
endif
ifeq ($(OPTION_ALLIN1),1)
____CPBrowser_FOUNDATIONKIT_p_2 = -l$(ALLIN1_FILENAME)
endif
ifeq ($(OPTION_ALLIN1),0)
____CPBrowser_FOUNDATIONKIT_p_2 = -l$(FOUNDATIONKIT_FILENAME)
endif
ifeq ($(OPTION_ALLIN1),1)
____CPBrowser_FOUNDATIONKIT_p_2 = -l$(ALLIN1_FILENAME)
endif
ifeq ($(OPTION_ALLIN1),0)
____CPBrowser_FOUNDATIONKIT_p_2 = -l$(FOUNDATIONKIT_FILENAME)
endif
ifeq ($(OPTION_ALLIN1),0)
____CPBrowser_XMLKIT_p = -l$(XMLKIT_FILENAME)
endif
ifeq ($(OPTION_SHARED),1)
__XMLKIT_DLL_p = -DXMLKIT_DLL
endif
ifeq ($(OPTION_DEBUG),0)
__DEBUG_INFO = 
endif
ifeq ($(OPTION_DEBUG),1)
__DEBUG_INFO = -g
endif
ifeq ($(OPTION_SHARED),1)
__FOUNDATIONKIT_DLL_p = -DFOUNDATIONKIT_DLL
endif


all: ../../lib/$(OBJDIR)/examples/CPBrowser
../../lib/$(OBJDIR)/examples/CPBrowser:
	@mkdir -p ../../lib/$(OBJDIR)/examples/CPBrowser

### Targets: ###

all: $(__CPBrowser___depname)

install: 

uninstall: 

clean: 
	rm -f ../../lib/$(OBJDIR)/examples/CPBrowser/*.o
	rm -f ../../lib/$(OBJDIR)/examples/CPBrowser/*.d
	rm -f ../../examples/CPBrowser/CPBrowser

ifeq ($(OPTION_HTMLKIT),1)
ifeq ($(OPTION_INTERNETKIT),1)
ifeq ($(OPTION_XMLKIT),1)
../../examples/CPBrowser/CPBrowser: $(CPBROWSER_OBJECTS)
	$(CXX) -o $@ $(CPBROWSER_OBJECTS)  $(__DEBUG_INFO) $(__OPTION_THREADING_5) -L../../lib  $(LDFLAGS) $(____CPBrowser_XMLKIT_p) $(____CPBrowser_FOUNDATIONKIT_p_2) -l$(LIBXSLT_FILENAME) -l$(LIBXML_FILENAME) $(____CPBrowser_INTERNETKIT_p) $(____CPBrowser_FOUNDATIONKIT_p_1) $(____CPBrowser_HTMLKIT_p) $(____CPBrowser_APPLICATIONKIT_p) $(____CPBrowser_GRAPHICSKIT_p) $(____CPBrowser_FOUNDATIONKIT_p) -l$(AGG_FILENAME) -l$(LIBJPEG_FILENAME) -l$(LIBPNG_FILENAME) -l$(ZLIB_FILENAME)  -ldl -luuid -lrt
endif
endif
endif

../../lib/$(OBJDIR)/examples/CPBrowser/CPBrowser_CPBrowser.o: ./../../examples/CPBrowser/CPBrowser.cpp
	$(CXX) -c -o $@ $(CPBROWSER_CXXFLAGS) $(CPPDEPS) $<

.PHONY: all install uninstall clean


# Dependencies tracking:
-include ../../lib/$(OBJDIR)/examples/CPBrowser/*.d
