# Microsoft Developer Studio Project File - Name="VCF_ImageFormats_dll" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=ImageFormats_dll - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VCF_ImageFormats_dll.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VCF_ImageFormats_dll.mak" CFG="ImageFormats_dll - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ImageFormats_dll - Win32 vc80 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc80 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc80 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc80 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc71 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc71 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc71 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc71 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc70 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc70 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc70 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc70 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc6 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc6 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc6 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 vc6 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 icl7 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 icl7 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 icl7 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 icl7 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 icl6 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 icl6 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 icl6 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 icl6 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ImageFormats_dll - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ImageFormats_dll - Win32 vc80 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc80_d\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc80_d\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc80_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc80_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc80_d.lib ZLib_vc80_sd.lib libAGG_vc80_sd.lib LibJPEG_vc80_sd.lib LibPNG_vc80_sd.lib GraphicsKit_vc80_d.lib ApplicationKit_vc80_d.lib ..\..\lib\ZLib_vc80_sd.lib ..\..\lib\LibJPEG_vc80_sd.lib ..\..\lib\LibPNG_vc80_sd.lib ..\..\lib\LibMNG_vc80_sd.lib ..\..\lib\LibTIFF_vc80_sd.lib ..\..\lib\FreeImage_vc80_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc80_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc80_d.lib" /debug
# ADD LINK32 FoundationKit_vc80_d.lib ZLib_vc80_sd.lib libAGG_vc80_sd.lib LibJPEG_vc80_sd.lib LibPNG_vc80_sd.lib GraphicsKit_vc80_d.lib ApplicationKit_vc80_d.lib ..\..\lib\ZLib_vc80_sd.lib ..\..\lib\LibJPEG_vc80_sd.lib ..\..\lib\LibPNG_vc80_sd.lib ..\..\lib\LibMNG_vc80_sd.lib ..\..\lib\LibTIFF_vc80_sd.lib ..\..\lib\FreeImage_vc80_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc80_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc80_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc80 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc80\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc80\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc80.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc80.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc80.lib ZLib_vc80_s.lib libAGG_vc80_s.lib LibJPEG_vc80_s.lib LibPNG_vc80_s.lib GraphicsKit_vc80.lib ApplicationKit_vc80.lib ..\..\lib\ZLib_vc80_s.lib ..\..\lib\LibJPEG_vc80_s.lib ..\..\lib\LibPNG_vc80_s.lib ..\..\lib\LibMNG_vc80_s.lib ..\..\lib\LibTIFF_vc80_s.lib ..\..\lib\FreeImage_vc80_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc80.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc80.lib"
# ADD LINK32 FoundationKit_vc80.lib ZLib_vc80_s.lib libAGG_vc80_s.lib LibJPEG_vc80_s.lib LibPNG_vc80_s.lib GraphicsKit_vc80.lib ApplicationKit_vc80.lib ..\..\lib\ZLib_vc80_s.lib ..\..\lib\LibJPEG_vc80_s.lib ..\..\lib\LibPNG_vc80_s.lib ..\..\lib\LibMNG_vc80_s.lib ..\..\lib\LibTIFF_vc80_s.lib ..\..\lib\FreeImage_vc80_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc80.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc80.lib"

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc80 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc80_sd\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc80_sd\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc80_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc80_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc80_sd.lib ZLib_vc80_sd.lib libAGG_vc80_sd.lib LibJPEG_vc80_sd.lib LibPNG_vc80_sd.lib GraphicsKit_vc80_sd.lib ApplicationKit_vc80_sd.lib ..\..\lib\ZLib_vc80_sd.lib ..\..\lib\LibJPEG_vc80_sd.lib ..\..\lib\LibPNG_vc80_sd.lib ..\..\lib\LibMNG_vc80_sd.lib ..\..\lib\LibTIFF_vc80_sd.lib ..\..\lib\FreeImage_vc80_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc80_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc80_d.lib" /debug
# ADD LINK32 FoundationKit_vc80_sd.lib ZLib_vc80_sd.lib libAGG_vc80_sd.lib LibJPEG_vc80_sd.lib LibPNG_vc80_sd.lib GraphicsKit_vc80_sd.lib ApplicationKit_vc80_sd.lib ..\..\lib\ZLib_vc80_sd.lib ..\..\lib\LibJPEG_vc80_sd.lib ..\..\lib\LibPNG_vc80_sd.lib ..\..\lib\LibMNG_vc80_sd.lib ..\..\lib\LibTIFF_vc80_sd.lib ..\..\lib\FreeImage_vc80_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc80_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc80_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc80 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc80_s\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc80_s\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc80.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc80.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc80_s.lib ZLib_vc80_s.lib libAGG_vc80_s.lib LibJPEG_vc80_s.lib LibPNG_vc80_s.lib GraphicsKit_vc80_s.lib ApplicationKit_vc80_s.lib ..\..\lib\ZLib_vc80_s.lib ..\..\lib\LibJPEG_vc80_s.lib ..\..\lib\LibPNG_vc80_s.lib ..\..\lib\LibMNG_vc80_s.lib ..\..\lib\LibTIFF_vc80_s.lib ..\..\lib\FreeImage_vc80_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc80.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc80.lib"
# ADD LINK32 FoundationKit_vc80_s.lib ZLib_vc80_s.lib libAGG_vc80_s.lib LibJPEG_vc80_s.lib LibPNG_vc80_s.lib GraphicsKit_vc80_s.lib ApplicationKit_vc80_s.lib ..\..\lib\ZLib_vc80_s.lib ..\..\lib\LibJPEG_vc80_s.lib ..\..\lib\LibPNG_vc80_s.lib ..\..\lib\LibMNG_vc80_s.lib ..\..\lib\LibTIFF_vc80_s.lib ..\..\lib\FreeImage_vc80_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc80.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc80.lib"

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc71 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_d\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc71_d\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc71_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc71_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc71_d.lib ZLib_vc71_sd.lib libAGG_vc71_sd.lib LibJPEG_vc71_sd.lib LibPNG_vc71_sd.lib GraphicsKit_vc71_d.lib ApplicationKit_vc71_d.lib ..\..\lib\ZLib_vc71_sd.lib ..\..\lib\LibJPEG_vc71_sd.lib ..\..\lib\LibPNG_vc71_sd.lib ..\..\lib\LibMNG_vc71_sd.lib ..\..\lib\LibTIFF_vc71_sd.lib ..\..\lib\FreeImage_vc71_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc71_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc71_d.lib" /debug
# ADD LINK32 FoundationKit_vc71_d.lib ZLib_vc71_sd.lib libAGG_vc71_sd.lib LibJPEG_vc71_sd.lib LibPNG_vc71_sd.lib GraphicsKit_vc71_d.lib ApplicationKit_vc71_d.lib ..\..\lib\ZLib_vc71_sd.lib ..\..\lib\LibJPEG_vc71_sd.lib ..\..\lib\LibPNG_vc71_sd.lib ..\..\lib\LibMNG_vc71_sd.lib ..\..\lib\LibTIFF_vc71_sd.lib ..\..\lib\FreeImage_vc71_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc71_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc71_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc71 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc71\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc71.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc71.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc71.lib ZLib_vc71_s.lib libAGG_vc71_s.lib LibJPEG_vc71_s.lib LibPNG_vc71_s.lib GraphicsKit_vc71.lib ApplicationKit_vc71.lib ..\..\lib\ZLib_vc71_s.lib ..\..\lib\LibJPEG_vc71_s.lib ..\..\lib\LibPNG_vc71_s.lib ..\..\lib\LibMNG_vc71_s.lib ..\..\lib\LibTIFF_vc71_s.lib ..\..\lib\FreeImage_vc71_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc71.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc71.lib"
# ADD LINK32 FoundationKit_vc71.lib ZLib_vc71_s.lib libAGG_vc71_s.lib LibJPEG_vc71_s.lib LibPNG_vc71_s.lib GraphicsKit_vc71.lib ApplicationKit_vc71.lib ..\..\lib\ZLib_vc71_s.lib ..\..\lib\LibJPEG_vc71_s.lib ..\..\lib\LibPNG_vc71_s.lib ..\..\lib\LibMNG_vc71_s.lib ..\..\lib\LibTIFF_vc71_s.lib ..\..\lib\FreeImage_vc71_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc71.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc71.lib"

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc71 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_sd\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc71_sd\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc71_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc71_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc71_sd.lib ZLib_vc71_sd.lib libAGG_vc71_sd.lib LibJPEG_vc71_sd.lib LibPNG_vc71_sd.lib GraphicsKit_vc71_sd.lib ApplicationKit_vc71_sd.lib ..\..\lib\ZLib_vc71_sd.lib ..\..\lib\LibJPEG_vc71_sd.lib ..\..\lib\LibPNG_vc71_sd.lib ..\..\lib\LibMNG_vc71_sd.lib ..\..\lib\LibTIFF_vc71_sd.lib ..\..\lib\FreeImage_vc71_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc71_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc71_d.lib" /debug
# ADD LINK32 FoundationKit_vc71_sd.lib ZLib_vc71_sd.lib libAGG_vc71_sd.lib LibJPEG_vc71_sd.lib LibPNG_vc71_sd.lib GraphicsKit_vc71_sd.lib ApplicationKit_vc71_sd.lib ..\..\lib\ZLib_vc71_sd.lib ..\..\lib\LibJPEG_vc71_sd.lib ..\..\lib\LibPNG_vc71_sd.lib ..\..\lib\LibMNG_vc71_sd.lib ..\..\lib\LibTIFF_vc71_sd.lib ..\..\lib\FreeImage_vc71_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc71_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc71_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc71 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_s\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc71_s\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc71.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc71.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc71_s.lib ZLib_vc71_s.lib libAGG_vc71_s.lib LibJPEG_vc71_s.lib LibPNG_vc71_s.lib GraphicsKit_vc71_s.lib ApplicationKit_vc71_s.lib ..\..\lib\ZLib_vc71_s.lib ..\..\lib\LibJPEG_vc71_s.lib ..\..\lib\LibPNG_vc71_s.lib ..\..\lib\LibMNG_vc71_s.lib ..\..\lib\LibTIFF_vc71_s.lib ..\..\lib\FreeImage_vc71_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc71.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc71.lib"
# ADD LINK32 FoundationKit_vc71_s.lib ZLib_vc71_s.lib libAGG_vc71_s.lib LibJPEG_vc71_s.lib LibPNG_vc71_s.lib GraphicsKit_vc71_s.lib ApplicationKit_vc71_s.lib ..\..\lib\ZLib_vc71_s.lib ..\..\lib\LibJPEG_vc71_s.lib ..\..\lib\LibPNG_vc71_s.lib ..\..\lib\LibMNG_vc71_s.lib ..\..\lib\LibTIFF_vc71_s.lib ..\..\lib\FreeImage_vc71_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc71.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc71.lib"

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc70 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_d\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc70_d\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc70_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc70_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc70_d.lib ZLib_vc70_sd.lib libAGG_vc70_sd.lib LibJPEG_vc70_sd.lib LibPNG_vc70_sd.lib GraphicsKit_vc70_d.lib ApplicationKit_vc70_d.lib ..\..\lib\ZLib_vc70_sd.lib ..\..\lib\LibJPEG_vc70_sd.lib ..\..\lib\LibPNG_vc70_sd.lib ..\..\lib\LibMNG_vc70_sd.lib ..\..\lib\LibTIFF_vc70_sd.lib ..\..\lib\FreeImage_vc70_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc70_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc70_d.lib" /debug
# ADD LINK32 FoundationKit_vc70_d.lib ZLib_vc70_sd.lib libAGG_vc70_sd.lib LibJPEG_vc70_sd.lib LibPNG_vc70_sd.lib GraphicsKit_vc70_d.lib ApplicationKit_vc70_d.lib ..\..\lib\ZLib_vc70_sd.lib ..\..\lib\LibJPEG_vc70_sd.lib ..\..\lib\LibPNG_vc70_sd.lib ..\..\lib\LibMNG_vc70_sd.lib ..\..\lib\LibTIFF_vc70_sd.lib ..\..\lib\FreeImage_vc70_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc70_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc70_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc70 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc70\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc70.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc70.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc70.lib ZLib_vc70_s.lib libAGG_vc70_s.lib LibJPEG_vc70_s.lib LibPNG_vc70_s.lib GraphicsKit_vc70.lib ApplicationKit_vc70.lib ..\..\lib\ZLib_vc70_s.lib ..\..\lib\LibJPEG_vc70_s.lib ..\..\lib\LibPNG_vc70_s.lib ..\..\lib\LibMNG_vc70_s.lib ..\..\lib\LibTIFF_vc70_s.lib ..\..\lib\FreeImage_vc70_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc70.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc70.lib"
# ADD LINK32 FoundationKit_vc70.lib ZLib_vc70_s.lib libAGG_vc70_s.lib LibJPEG_vc70_s.lib LibPNG_vc70_s.lib GraphicsKit_vc70.lib ApplicationKit_vc70.lib ..\..\lib\ZLib_vc70_s.lib ..\..\lib\LibJPEG_vc70_s.lib ..\..\lib\LibPNG_vc70_s.lib ..\..\lib\LibMNG_vc70_s.lib ..\..\lib\LibTIFF_vc70_s.lib ..\..\lib\FreeImage_vc70_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc70.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc70.lib"

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc70 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_sd\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc70_sd\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc70_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc70_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc70_sd.lib ZLib_vc70_sd.lib libAGG_vc70_sd.lib LibJPEG_vc70_sd.lib LibPNG_vc70_sd.lib GraphicsKit_vc70_sd.lib ApplicationKit_vc70_sd.lib ..\..\lib\ZLib_vc70_sd.lib ..\..\lib\LibJPEG_vc70_sd.lib ..\..\lib\LibPNG_vc70_sd.lib ..\..\lib\LibMNG_vc70_sd.lib ..\..\lib\LibTIFF_vc70_sd.lib ..\..\lib\FreeImage_vc70_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc70_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc70_d.lib" /debug
# ADD LINK32 FoundationKit_vc70_sd.lib ZLib_vc70_sd.lib libAGG_vc70_sd.lib LibJPEG_vc70_sd.lib LibPNG_vc70_sd.lib GraphicsKit_vc70_sd.lib ApplicationKit_vc70_sd.lib ..\..\lib\ZLib_vc70_sd.lib ..\..\lib\LibJPEG_vc70_sd.lib ..\..\lib\LibPNG_vc70_sd.lib ..\..\lib\LibMNG_vc70_sd.lib ..\..\lib\LibTIFF_vc70_sd.lib ..\..\lib\FreeImage_vc70_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc70_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc70_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc70 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_s\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc70_s\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc70.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc70.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc70_s.lib ZLib_vc70_s.lib libAGG_vc70_s.lib LibJPEG_vc70_s.lib LibPNG_vc70_s.lib GraphicsKit_vc70_s.lib ApplicationKit_vc70_s.lib ..\..\lib\ZLib_vc70_s.lib ..\..\lib\LibJPEG_vc70_s.lib ..\..\lib\LibPNG_vc70_s.lib ..\..\lib\LibMNG_vc70_s.lib ..\..\lib\LibTIFF_vc70_s.lib ..\..\lib\FreeImage_vc70_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc70.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc70.lib"
# ADD LINK32 FoundationKit_vc70_s.lib ZLib_vc70_s.lib libAGG_vc70_s.lib LibJPEG_vc70_s.lib LibPNG_vc70_s.lib GraphicsKit_vc70_s.lib ApplicationKit_vc70_s.lib ..\..\lib\ZLib_vc70_s.lib ..\..\lib\LibJPEG_vc70_s.lib ..\..\lib\LibPNG_vc70_s.lib ..\..\lib\LibMNG_vc70_s.lib ..\..\lib\LibTIFF_vc70_s.lib ..\..\lib\FreeImage_vc70_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc70.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc70.lib"

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_d\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc6_d\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc6_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc6_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc6_d.lib ZLib_vc6_sd.lib libAGG_vc6_sd.lib LibJPEG_vc6_sd.lib LibPNG_vc6_sd.lib GraphicsKit_vc6_d.lib ApplicationKit_vc6_d.lib ..\..\lib\ZLib_vc6_sd.lib ..\..\lib\LibJPEG_vc6_sd.lib ..\..\lib\LibPNG_vc6_sd.lib ..\..\lib\LibMNG_vc6_sd.lib ..\..\lib\LibTIFF_vc6_sd.lib ..\..\lib\FreeImage_vc6_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc6_d.lib" /debug
# ADD LINK32 FoundationKit_vc6_d.lib ZLib_vc6_sd.lib libAGG_vc6_sd.lib LibJPEG_vc6_sd.lib LibPNG_vc6_sd.lib GraphicsKit_vc6_d.lib ApplicationKit_vc6_d.lib ..\..\lib\ZLib_vc6_sd.lib ..\..\lib\LibJPEG_vc6_sd.lib ..\..\lib\LibPNG_vc6_sd.lib ..\..\lib\LibMNG_vc6_sd.lib ..\..\lib\LibTIFF_vc6_sd.lib ..\..\lib\FreeImage_vc6_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc6_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc6\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc6.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc6.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc6.lib ZLib_vc6_s.lib libAGG_vc6_s.lib LibJPEG_vc6_s.lib LibPNG_vc6_s.lib GraphicsKit_vc6.lib ApplicationKit_vc6.lib ..\..\lib\ZLib_vc6_s.lib ..\..\lib\LibJPEG_vc6_s.lib ..\..\lib\LibPNG_vc6_s.lib ..\..\lib\LibMNG_vc6_s.lib ..\..\lib\LibTIFF_vc6_s.lib ..\..\lib\FreeImage_vc6_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc6.lib"
# ADD LINK32 FoundationKit_vc6.lib ZLib_vc6_s.lib libAGG_vc6_s.lib LibJPEG_vc6_s.lib LibPNG_vc6_s.lib GraphicsKit_vc6.lib ApplicationKit_vc6.lib ..\..\lib\ZLib_vc6_s.lib ..\..\lib\LibJPEG_vc6_s.lib ..\..\lib\LibPNG_vc6_s.lib ..\..\lib\LibMNG_vc6_s.lib ..\..\lib\LibTIFF_vc6_s.lib ..\..\lib\FreeImage_vc6_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc6.lib"

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_sd\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc6_sd\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc6_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_vc6_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc6_sd.lib ZLib_vc6_sd.lib libAGG_vc6_sd.lib LibJPEG_vc6_sd.lib LibPNG_vc6_sd.lib GraphicsKit_vc6_sd.lib ApplicationKit_vc6_sd.lib ..\..\lib\ZLib_vc6_sd.lib ..\..\lib\LibJPEG_vc6_sd.lib ..\..\lib\LibPNG_vc6_sd.lib ..\..\lib\LibMNG_vc6_sd.lib ..\..\lib\LibTIFF_vc6_sd.lib ..\..\lib\FreeImage_vc6_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc6_d.lib" /debug
# ADD LINK32 FoundationKit_vc6_sd.lib ZLib_vc6_sd.lib libAGG_vc6_sd.lib LibJPEG_vc6_sd.lib LibPNG_vc6_sd.lib GraphicsKit_vc6_sd.lib ApplicationKit_vc6_sd.lib ..\..\lib\ZLib_vc6_sd.lib ..\..\lib\LibJPEG_vc6_sd.lib ..\..\lib\LibPNG_vc6_sd.lib ..\..\lib\LibMNG_vc6_sd.lib ..\..\lib\LibTIFF_vc6_sd.lib ..\..\lib\FreeImage_vc6_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc6_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 vc6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_s\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc6_s\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc6.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_vc6.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_vc6_s.lib ZLib_vc6_s.lib libAGG_vc6_s.lib LibJPEG_vc6_s.lib LibPNG_vc6_s.lib GraphicsKit_vc6_s.lib ApplicationKit_vc6_s.lib ..\..\lib\ZLib_vc6_s.lib ..\..\lib\LibJPEG_vc6_s.lib ..\..\lib\LibPNG_vc6_s.lib ..\..\lib\LibMNG_vc6_s.lib ..\..\lib\LibTIFF_vc6_s.lib ..\..\lib\FreeImage_vc6_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc6.lib"
# ADD LINK32 FoundationKit_vc6_s.lib ZLib_vc6_s.lib libAGG_vc6_s.lib LibJPEG_vc6_s.lib LibPNG_vc6_s.lib GraphicsKit_vc6_s.lib ApplicationKit_vc6_s.lib ..\..\lib\ZLib_vc6_s.lib ..\..\lib\LibJPEG_vc6_s.lib ..\..\lib\LibPNG_vc6_s.lib ..\..\lib\LibMNG_vc6_s.lib ..\..\lib\LibTIFF_vc6_s.lib ..\..\lib\FreeImage_vc6_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_vc6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_vc6.lib"

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 icl7 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_d\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl7_d\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_icl7_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_icl7_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_icl7_d.lib ZLib_icl7_sd.lib libAGG_icl7_sd.lib LibJPEG_icl7_sd.lib LibPNG_icl7_sd.lib GraphicsKit_icl7_d.lib ApplicationKit_icl7_d.lib ..\..\lib\ZLib_icl7_sd.lib ..\..\lib\LibJPEG_icl7_sd.lib ..\..\lib\LibPNG_icl7_sd.lib ..\..\lib\LibMNG_icl7_sd.lib ..\..\lib\LibTIFF_icl7_sd.lib ..\..\lib\FreeImage_icl7_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl7_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl7_d.lib" /debug
# ADD LINK32 FoundationKit_icl7_d.lib ZLib_icl7_sd.lib libAGG_icl7_sd.lib LibJPEG_icl7_sd.lib LibPNG_icl7_sd.lib GraphicsKit_icl7_d.lib ApplicationKit_icl7_d.lib ..\..\lib\ZLib_icl7_sd.lib ..\..\lib\LibJPEG_icl7_sd.lib ..\..\lib\LibPNG_icl7_sd.lib ..\..\lib\LibMNG_icl7_sd.lib ..\..\lib\LibTIFF_icl7_sd.lib ..\..\lib\FreeImage_icl7_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl7_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl7_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 icl7 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl7\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_icl7.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_icl7.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_icl7.lib ZLib_icl7_s.lib libAGG_icl7_s.lib LibJPEG_icl7_s.lib LibPNG_icl7_s.lib GraphicsKit_icl7.lib ApplicationKit_icl7.lib ..\..\lib\ZLib_icl7_s.lib ..\..\lib\LibJPEG_icl7_s.lib ..\..\lib\LibPNG_icl7_s.lib ..\..\lib\LibMNG_icl7_s.lib ..\..\lib\LibTIFF_icl7_s.lib ..\..\lib\FreeImage_icl7_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl7.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl7.lib"
# ADD LINK32 FoundationKit_icl7.lib ZLib_icl7_s.lib libAGG_icl7_s.lib LibJPEG_icl7_s.lib LibPNG_icl7_s.lib GraphicsKit_icl7.lib ApplicationKit_icl7.lib ..\..\lib\ZLib_icl7_s.lib ..\..\lib\LibJPEG_icl7_s.lib ..\..\lib\LibPNG_icl7_s.lib ..\..\lib\LibMNG_icl7_s.lib ..\..\lib\LibTIFF_icl7_s.lib ..\..\lib\FreeImage_icl7_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl7.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl7.lib"

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 icl7 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_sd\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl7_sd\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_icl7_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_icl7_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_icl7_sd.lib ZLib_icl7_sd.lib libAGG_icl7_sd.lib LibJPEG_icl7_sd.lib LibPNG_icl7_sd.lib GraphicsKit_icl7_sd.lib ApplicationKit_icl7_sd.lib ..\..\lib\ZLib_icl7_sd.lib ..\..\lib\LibJPEG_icl7_sd.lib ..\..\lib\LibPNG_icl7_sd.lib ..\..\lib\LibMNG_icl7_sd.lib ..\..\lib\LibTIFF_icl7_sd.lib ..\..\lib\FreeImage_icl7_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl7_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl7_d.lib" /debug
# ADD LINK32 FoundationKit_icl7_sd.lib ZLib_icl7_sd.lib libAGG_icl7_sd.lib LibJPEG_icl7_sd.lib LibPNG_icl7_sd.lib GraphicsKit_icl7_sd.lib ApplicationKit_icl7_sd.lib ..\..\lib\ZLib_icl7_sd.lib ..\..\lib\LibJPEG_icl7_sd.lib ..\..\lib\LibPNG_icl7_sd.lib ..\..\lib\LibMNG_icl7_sd.lib ..\..\lib\LibTIFF_icl7_sd.lib ..\..\lib\FreeImage_icl7_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl7_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl7_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 icl7 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_s\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl7_s\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_icl7.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_icl7.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_icl7_s.lib ZLib_icl7_s.lib libAGG_icl7_s.lib LibJPEG_icl7_s.lib LibPNG_icl7_s.lib GraphicsKit_icl7_s.lib ApplicationKit_icl7_s.lib ..\..\lib\ZLib_icl7_s.lib ..\..\lib\LibJPEG_icl7_s.lib ..\..\lib\LibPNG_icl7_s.lib ..\..\lib\LibMNG_icl7_s.lib ..\..\lib\LibTIFF_icl7_s.lib ..\..\lib\FreeImage_icl7_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl7.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl7.lib"
# ADD LINK32 FoundationKit_icl7_s.lib ZLib_icl7_s.lib libAGG_icl7_s.lib LibJPEG_icl7_s.lib LibPNG_icl7_s.lib GraphicsKit_icl7_s.lib ApplicationKit_icl7_s.lib ..\..\lib\ZLib_icl7_s.lib ..\..\lib\LibJPEG_icl7_s.lib ..\..\lib\LibPNG_icl7_s.lib ..\..\lib\LibMNG_icl7_s.lib ..\..\lib\LibTIFF_icl7_s.lib ..\..\lib\FreeImage_icl7_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl7.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl7.lib"

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 icl6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_d\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl6_d\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_icl6_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_icl6_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_icl6_d.lib ZLib_icl6_sd.lib libAGG_icl6_sd.lib LibJPEG_icl6_sd.lib LibPNG_icl6_sd.lib GraphicsKit_icl6_d.lib ApplicationKit_icl6_d.lib ..\..\lib\ZLib_icl6_sd.lib ..\..\lib\LibJPEG_icl6_sd.lib ..\..\lib\LibPNG_icl6_sd.lib ..\..\lib\LibMNG_icl6_sd.lib ..\..\lib\LibTIFF_icl6_sd.lib ..\..\lib\FreeImage_icl6_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl6_d.lib" /debug
# ADD LINK32 FoundationKit_icl6_d.lib ZLib_icl6_sd.lib libAGG_icl6_sd.lib LibJPEG_icl6_sd.lib LibPNG_icl6_sd.lib GraphicsKit_icl6_d.lib ApplicationKit_icl6_d.lib ..\..\lib\ZLib_icl6_sd.lib ..\..\lib\LibJPEG_icl6_sd.lib ..\..\lib\LibPNG_icl6_sd.lib ..\..\lib\LibMNG_icl6_sd.lib ..\..\lib\LibTIFF_icl6_sd.lib ..\..\lib\FreeImage_icl6_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl6_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 icl6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl6\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_icl6.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_icl6.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_icl6.lib ZLib_icl6_s.lib libAGG_icl6_s.lib LibJPEG_icl6_s.lib LibPNG_icl6_s.lib GraphicsKit_icl6.lib ApplicationKit_icl6.lib ..\..\lib\ZLib_icl6_s.lib ..\..\lib\LibJPEG_icl6_s.lib ..\..\lib\LibPNG_icl6_s.lib ..\..\lib\LibMNG_icl6_s.lib ..\..\lib\LibTIFF_icl6_s.lib ..\..\lib\FreeImage_icl6_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl6.lib"
# ADD LINK32 FoundationKit_icl6.lib ZLib_icl6_s.lib libAGG_icl6_s.lib LibJPEG_icl6_s.lib LibPNG_icl6_s.lib GraphicsKit_icl6.lib ApplicationKit_icl6.lib ..\..\lib\ZLib_icl6_s.lib ..\..\lib\LibJPEG_icl6_s.lib ..\..\lib\LibPNG_icl6_s.lib ..\..\lib\LibMNG_icl6_s.lib ..\..\lib\LibTIFF_icl6_s.lib ..\..\lib\FreeImage_icl6_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl6.lib"

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 icl6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_sd\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl6_sd\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_icl6_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_icl6_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_icl6_sd.lib ZLib_icl6_sd.lib libAGG_icl6_sd.lib LibJPEG_icl6_sd.lib LibPNG_icl6_sd.lib GraphicsKit_icl6_sd.lib ApplicationKit_icl6_sd.lib ..\..\lib\ZLib_icl6_sd.lib ..\..\lib\LibJPEG_icl6_sd.lib ..\..\lib\LibPNG_icl6_sd.lib ..\..\lib\LibMNG_icl6_sd.lib ..\..\lib\LibTIFF_icl6_sd.lib ..\..\lib\FreeImage_icl6_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl6_d.lib" /debug
# ADD LINK32 FoundationKit_icl6_sd.lib ZLib_icl6_sd.lib libAGG_icl6_sd.lib LibJPEG_icl6_sd.lib LibPNG_icl6_sd.lib GraphicsKit_icl6_sd.lib ApplicationKit_icl6_sd.lib ..\..\lib\ZLib_icl6_sd.lib ..\..\lib\LibJPEG_icl6_sd.lib ..\..\lib\LibPNG_icl6_sd.lib ..\..\lib\LibMNG_icl6_sd.lib ..\..\lib\LibTIFF_icl6_sd.lib ..\..\lib\FreeImage_icl6_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl6_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 icl6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_s\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl6_s\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_icl6.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats_icl6.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_icl6_s.lib ZLib_icl6_s.lib libAGG_icl6_s.lib LibJPEG_icl6_s.lib LibPNG_icl6_s.lib GraphicsKit_icl6_s.lib ApplicationKit_icl6_s.lib ..\..\lib\ZLib_icl6_s.lib ..\..\lib\LibJPEG_icl6_s.lib ..\..\lib\LibPNG_icl6_s.lib ..\..\lib\LibMNG_icl6_s.lib ..\..\lib\LibTIFF_icl6_s.lib ..\..\lib\FreeImage_icl6_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl6.lib"
# ADD LINK32 FoundationKit_icl6_s.lib ZLib_icl6_s.lib libAGG_icl6_s.lib LibJPEG_icl6_s.lib LibPNG_icl6_s.lib GraphicsKit_icl6_s.lib ApplicationKit_icl6_s.lib ..\..\lib\ZLib_icl6_s.lib ..\..\lib\LibJPEG_icl6_s.lib ..\..\lib\LibPNG_icl6_s.lib ..\..\lib\LibMNG_icl6_s.lib ..\..\lib\LibTIFF_icl6_s.lib ..\..\lib\FreeImage_icl6_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_icl6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_icl6.lib"

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_d\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_d\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_d.lib ZLib_sd.lib libAGG_sd.lib LibJPEG_sd.lib LibPNG_sd.lib GraphicsKit_d.lib ApplicationKit_d.lib ..\..\lib\ZLib_sd.lib ..\..\lib\LibJPEG_sd.lib ..\..\lib\LibPNG_sd.lib ..\..\lib\LibMNG_sd.lib ..\..\lib\LibTIFF_sd.lib ..\..\lib\FreeImage_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_d.lib" /debug
# ADD LINK32 FoundationKit_d.lib ZLib_sd.lib libAGG_sd.lib LibJPEG_sd.lib LibPNG_sd.lib GraphicsKit_d.lib ApplicationKit_d.lib ..\..\lib\ZLib_sd.lib ..\..\lib\LibJPEG_sd.lib ..\..\lib\LibPNG_sd.lib ..\..\lib\LibMNG_sd.lib ..\..\lib\LibTIFF_sd.lib ..\..\lib\FreeImage_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit.lib ZLib_s.lib libAGG_s.lib LibJPEG_s.lib LibPNG_s.lib GraphicsKit.lib ApplicationKit.lib ..\..\lib\ZLib_s.lib ..\..\lib\LibJPEG_s.lib ..\..\lib\LibPNG_s.lib ..\..\lib\LibMNG_s.lib ..\..\lib\LibTIFF_s.lib ..\..\lib\FreeImage_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats.lib"
# ADD LINK32 FoundationKit.lib ZLib_s.lib libAGG_s.lib LibJPEG_s.lib LibPNG_s.lib GraphicsKit.lib ApplicationKit.lib ..\..\lib\ZLib_s.lib ..\..\lib\LibJPEG_s.lib ..\..\lib\LibPNG_s.lib ..\..\lib\LibMNG_s.lib ..\..\lib\LibTIFF_s.lib ..\..\lib\FreeImage_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats.lib"

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_sd\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_sd\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ImageFormats_d.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_sd.lib ZLib_sd.lib libAGG_sd.lib LibJPEG_sd.lib LibPNG_sd.lib GraphicsKit_sd.lib ApplicationKit_sd.lib ..\..\lib\ZLib_sd.lib ..\..\lib\LibJPEG_sd.lib ..\..\lib\LibPNG_sd.lib ..\..\lib\LibMNG_sd.lib ..\..\lib\LibTIFF_sd.lib ..\..\lib\FreeImage_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_d.lib" /debug
# ADD LINK32 FoundationKit_sd.lib ZLib_sd.lib libAGG_sd.lib LibJPEG_sd.lib LibPNG_sd.lib GraphicsKit_sd.lib ApplicationKit_sd.lib ..\..\lib\ZLib_sd.lib ..\..\lib\LibJPEG_sd.lib ..\..\lib\LibPNG_sd.lib ..\..\lib\LibMNG_sd.lib ..\..\lib\LibTIFF_sd.lib ..\..\lib\FreeImage_sd.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats_d.lib" /debug

!ELSEIF  "$(CFG)" == "ImageFormats_dll - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_s\ImageFormats_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_s\ImageFormats_dll"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ImageFormats.pdb /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "FREEIMAGE_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_CRT_SECURE_NO_DEPRECATE" /D "_SCL_SECURE_NO_DEPRECATE" /D "_CRT_NON_CONFORMING_SWPRINTFS" /D "_USRDLL" /D "IMAGEFORMATS_DLL" /D "IMAGEFORMATS_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
# ADD RSC /l 0x409 /d "FREEIMAGE_LIB" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /d "_CRT_SECURE_NO_DEPRECATE" /d "_SCL_SECURE_NO_DEPRECATE" /d "_CRT_NON_CONFORMING_SWPRINTFS" /i "..\..\src" /d "_USRDLL" /d "IMAGEFORMATS_DLL" /d IMAGEFORMATS_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 FoundationKit_s.lib ZLib_s.lib libAGG_s.lib LibJPEG_s.lib LibPNG_s.lib GraphicsKit_s.lib ApplicationKit_s.lib ..\..\lib\ZLib_s.lib ..\..\lib\LibJPEG_s.lib ..\..\lib\LibPNG_s.lib ..\..\lib\LibMNG_s.lib ..\..\lib\LibTIFF_s.lib ..\..\lib\FreeImage_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats.lib"
# ADD LINK32 FoundationKit_s.lib ZLib_s.lib libAGG_s.lib LibJPEG_s.lib LibPNG_s.lib GraphicsKit_s.lib ApplicationKit_s.lib ..\..\lib\ZLib_s.lib ..\..\lib\LibJPEG_s.lib ..\..\lib\LibPNG_s.lib ..\..\lib\LibMNG_s.lib ..\..\lib\LibTIFF_s.lib ..\..\lib\FreeImage_s.lib rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib urlmon.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ImageFormats.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ImageFormats.lib"

!ENDIF

# Begin Target

# Name "ImageFormats_dll - Win32 vc80 DLL Debug"
# Name "ImageFormats_dll - Win32 vc80 DLL Release"
# Name "ImageFormats_dll - Win32 vc80 Debug"
# Name "ImageFormats_dll - Win32 vc80 Release"
# Name "ImageFormats_dll - Win32 vc71 DLL Debug"
# Name "ImageFormats_dll - Win32 vc71 DLL Release"
# Name "ImageFormats_dll - Win32 vc71 Debug"
# Name "ImageFormats_dll - Win32 vc71 Release"
# Name "ImageFormats_dll - Win32 vc70 DLL Debug"
# Name "ImageFormats_dll - Win32 vc70 DLL Release"
# Name "ImageFormats_dll - Win32 vc70 Debug"
# Name "ImageFormats_dll - Win32 vc70 Release"
# Name "ImageFormats_dll - Win32 vc6 DLL Debug"
# Name "ImageFormats_dll - Win32 vc6 DLL Release"
# Name "ImageFormats_dll - Win32 vc6 Debug"
# Name "ImageFormats_dll - Win32 vc6 Release"
# Name "ImageFormats_dll - Win32 icl7 DLL Debug"
# Name "ImageFormats_dll - Win32 icl7 DLL Release"
# Name "ImageFormats_dll - Win32 icl7 Debug"
# Name "ImageFormats_dll - Win32 icl7 Release"
# Name "ImageFormats_dll - Win32 icl6 DLL Debug"
# Name "ImageFormats_dll - Win32 icl6 DLL Release"
# Name "ImageFormats_dll - Win32 icl6 Debug"
# Name "ImageFormats_dll - Win32 icl6 Release"
# Name "ImageFormats_dll - Win32 DLL Debug"
# Name "ImageFormats_dll - Win32 DLL Release"
# Name "ImageFormats_dll - Win32 Debug"
# Name "ImageFormats_dll - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\ImageFormats\ImageFormats.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\ImageFormats\ImageFormats.h
# End Source File
# Begin Source File

SOURCE=..\..\src\ImageFormats\ImageFormatsSelectLib.h
# End Source File
# End Group
# End Target
# End Project

