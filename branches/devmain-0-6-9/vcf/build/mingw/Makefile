LIB = ../../lib

MSCC = "C:/vcpp2003Toolkit/bin/cl.exe"
MSLINK  = "C:/vcpp2003Toolkit/bin/link.exe"
MS_INCLUDES = "C:/vcpp2003Toolkit/include"
MS_PLATFORMSDKINCLUDES = "C:/Program Files/Microsoft SDK/Include"
MS_LIB = "C:/vcpp2003Toolkit/lib"
MS_PLATFORMSDKLIB = "C:/Program Files/Microsoft SDK/lib"

target: tools 
	@echo Please choose either debug, release or all '(for both debug and release)'


tools:
	@if ( test -f $(MSCC)  ) \
	then \
		echo "Visual C++ .Net 2003 compiler found.";\
	else \
		echo "Unable to find Visual C++ .Net 2003 compiler. Exiting Make.";\
		exit 1;\
	fi
	
	@if ( test -f $(MSLINK)  ) \
	then \
		echo "Visual C++ .Net 2003 linker found.";\
	else \
		echo "Unable to find Visual C++ .Net 2003 linker. Exiting Make.";\
		exit 1;\
	fi
	
	@if ( test -d $(MS_INCLUDES)  ) \
	then \
		echo "Visual C++ .Net 2003 includes directory found.";\
	else \
		echo "Unable to find Visual C++ .Net 2003 includes directory. You probably need to re-install it. Exiting Make.";\
		exit 1;\
	fi
	
	@if ( test -d $(MS_LIB)  ) \
	then \
		echo "Visual C++ .Net 2003 lib directory found.";\
	else \
		echo "Unable to find Visual C++ .Net 2003 lib directory. You probably need to re-install it. Exiting Make.";\
		exit 1;\
	fi
	
	@if ( test -d $(MS_PLATFORMSDKINCLUDES)  ) \
	then \
		echo "Microsoft Platform SDK includes directory found.";\
	else \
		echo "Unable to find Microsoft Platform SDK includes directory. Exiting Make.";\
		exit 1;\
	fi
	
	@if ( test -d $(MS_PLATFORMSDKLIB)  ) \
	then \
		echo "Microsoft Platform SDK lib directory found.";\
	else \
		echo "Unable to find Microsoft Platform SDK lib directory. Exiting Make.";\
		exit 1;\
	fi
		

all: VCF-static

## AllIn1
VCF-static: BUILD      = Static
VCF-static: KIT        = AllIn1
VCF-static: TARGET     = VCF_vc71_s.lib
VCF-static: AllIn1/Static/Makefile AllIn1-make-static
clean-VCF-static:
	 -rm AllIn1/Static/*
	 -rm $(LIB)/VCF_vc71_s.lib
	 

clean: clean-VCF-static


%Makefile: tools
	@[ -d $(LIB) ] || mkdir $(LIB); \
	[ -d $(KIT)/$(BUILD) ] || mkdir -p $(KIT)/$(BUILD); \
	\
	echo "BUILD  = $(BUILD)"                > ./$(KIT)/$(BUILD)/Makefile; \
	echo "KIT = $(KIT)"                    >> ./$(KIT)/$(BUILD)/Makefile; \
	echo "TARGET = $(TARGET)"              >> ./$(KIT)/$(BUILD)/Makefile; \
	echo "CXX = $(MSCC)"              >> ./$(KIT)/$(BUILD)/Makefile; \
	echo "LINKER = $(MSLINK)"              >> ./$(KIT)/$(BUILD)/Makefile; \
	echo "MS_PLATFORMSDKINCLUDES = $(MS_PLATFORMSDKINCLUDES)"              >> ./$(KIT)/$(BUILD)/Makefile; \
	echo "MS_PLATFORMSDKLIB = $(MS_PLATFORMSDKLIB)"              >> ./$(KIT)/$(BUILD)/Makefile; \
	echo "MS_INCLUDES = $(MS_INCLUDES)"              >> ./$(KIT)/$(BUILD)/Makefile; \
	echo "MS_LIB = $(MS_LIB)"              >> ./$(KIT)/$(BUILD)/Makefile; \
	echo "include ../../$(KIT).mak"        >> ./$(KIT)/$(BUILD)/Makefile; \
	echo "include ../../Makefile.mak"      >> ./$(KIT)/$(BUILD)/Makefile;

%make-static:
	$(MAKE) -C $(KIT)/$(BUILD) all


