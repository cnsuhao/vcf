# Microsoft Developer Studio Project File - Name="Win32HTMLBrowser_StaticLib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Win32HTMLBrowser_StaticLib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Win32HTMLBrowser_StaticLib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Win32HTMLBrowser_StaticLib.mak" CFG="Win32HTMLBrowser_StaticLib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32HTMLBrowser_StaticLib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Win32HTMLBrowser_StaticLib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "Win32HTMLBrowser_StaticLib"
# PROP Scc_LocalPath "..\..\.."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Win32HTMLBrowser_StaticLib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Win32HTMLBrowser_StaticLib___Win32_Release"
# PROP BASE Intermediate_Dir "Win32HTMLBrowser_StaticLib___Win32_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\lib"
# PROP Intermediate_Dir "vc7/ReleaseS\obj"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "$(VCF_INCLUDE)" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"..\..\..\lib\Win32HTMLBrowser_vc7_s.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\..\lib\Win32HTMLBrowser_vc7_s.lib"

!ELSEIF  "$(CFG)" == "Win32HTMLBrowser_StaticLib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Win32HTMLBrowser_StaticLib___Win32_Debug"
# PROP BASE Intermediate_Dir "Win32HTMLBrowser_StaticLib___Win32_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\lib"
# PROP Intermediate_Dir "vc7/DebugS\obj"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "$(VCF_INCLUDE)" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR /YX /Fd"..\..\..\lib/Win32HTMLBrowser_vc7_sd.pdb" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"..\..\..\lib\Win32HTMLBrowser_vc7_sd.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\..\lib\Win32HTMLBrowser_vc7_sd.lib"

!ENDIF 

# Begin Target

# Name "Win32HTMLBrowser_StaticLib - Win32 Release"
# Name "Win32HTMLBrowser_StaticLib - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\..\src\ImplementerKit\Win32HTMLBrowser.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\ImplementerKit\Win32HTMLBrowserApplication.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\..\include\implementerKit\Win32HTMLBrowser.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\implementerKit\Win32HTMLBrowserApplication.h
# End Source File
# End Group
# End Target
# End Project