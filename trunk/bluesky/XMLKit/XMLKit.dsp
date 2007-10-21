# Microsoft Developer Studio Project File - Name="XMLKit" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=XMLKit - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "XMLKit.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "XMLKit.mak" CFG="XMLKit - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "XMLKit - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "XMLKit - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "XMLKit - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "./libxml" /I "./libxml/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_CONSOLE" /D "USE_FOUNDATIONKIT_DLL" /D "HAVE_WIN32_THREADS" /D "HAVE_COMPILER_TLS" /FD /I$(VCF_ROOT)/src /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib rpcrt4.lib /nologo /subsystem:console /machine:I386 /libpath:$(VCF_ROOT)/lib

!ELSEIF  "$(CFG)" == "XMLKit - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "./libxml" /I "./libxml/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_CONSOLE" /D "USE_FOUNDATIONKIT_DLL" /D "HAVE_WIN32_THREADS" /D "HAVE_COMPILER_TLS" /FD /GZ /I$(VCF_ROOT)/src /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib rpcrt4.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:$(VCF_ROOT)/lib

!ENDIF 

# Begin Target

# Name "XMLKit - Win32 Release"
# Name "XMLKit - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\test.cpp
# End Source File
# Begin Source File

SOURCE=.\XMLKit.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DOM3.h
# End Source File
# Begin Source File

SOURCE=.\XMLKit.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "libxml"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\libxml\c14n.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\catalog.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\chvalid.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\debugXML.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\dict.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\DOCBparser.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\encoding.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\entities.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\error.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\globals.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\hash.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\HTMLparser.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\HTMLtree.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\legacy.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\list.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\nanoftp.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\nanohttp.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\parser.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\parserInternals.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\pattern.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\relaxng.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\SAX.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\SAX2.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\schematron.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\threads.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\tree.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\uri.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\valid.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xinclude.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xlink.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xmlIO.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xmlmemory.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xmlmodule.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xmlreader.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xmlregexp.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xmlsave.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xmlschemas.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xmlschemastypes.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xmlstring.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xmlunicode.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xmlwriter.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xpath.c"
# End Source File
# Begin Source File

SOURCE=".\libxml\xpointer.c"
# End Source File
# End Group
# End Target
# End Project
