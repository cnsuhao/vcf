# Microsoft Developer Studio Project File - Name="VCF_InternetKit" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104
# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=InternetKit - Win32 icl6 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VCF_InternetKit.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VCF_InternetKit.mak" CFG="InternetKit - Win32 icl6 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "InternetKit - Win32 vc71 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InternetKit - Win32 vc71 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InternetKit - Win32 vc71 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "InternetKit - Win32 vc71 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "InternetKit - Win32 vc70 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InternetKit - Win32 vc70 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InternetKit - Win32 vc70 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "InternetKit - Win32 vc70 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "InternetKit - Win32 vc6 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InternetKit - Win32 vc6 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InternetKit - Win32 vc6 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "InternetKit - Win32 vc6 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "InternetKit - Win32 vc5 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InternetKit - Win32 vc5 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InternetKit - Win32 vc5 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "InternetKit - Win32 vc5 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "InternetKit - Win32 icl7 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InternetKit - Win32 icl7 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InternetKit - Win32 icl7 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "InternetKit - Win32 icl7 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "InternetKit - Win32 icl6 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InternetKit - Win32 icl6 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InternetKit - Win32 icl6 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "InternetKit - Win32 icl6 Release" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "InternetKit - Win32 vc71 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_d\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc71_d\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\InternetKit_vc71_d.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc71_d\InternetKit_vc71_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\InternetKit_vc71_d.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc71_d\InternetKit_vc71_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc71_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc71_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc71_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc71_d.lib" /debug

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc71 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc71\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\InternetKit_vc71.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc71\InternetKit_vc71.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\InternetKit_vc71.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc71\InternetKit_vc71.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc71.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc71.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc71.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc71.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc71 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_sd\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc71_sd\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\InternetKit_vc71_sd.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc71_sd\InternetKit_vc71_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\InternetKit_vc71_sd.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc71_sd\InternetKit_vc71_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\InternetKit_vc71_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\InternetKit_vc71_sd.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc71 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_s\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc71_s\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\InternetKit_vc71_s.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc71_s\InternetKit_vc71_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\InternetKit_vc71_s.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc71_s\InternetKit_vc71_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\InternetKit_vc71_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\InternetKit_vc71_s.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc70 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_d\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc70_d\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\InternetKit_vc70_d.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc70_d\InternetKit_vc70_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\InternetKit_vc70_d.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc70_d\InternetKit_vc70_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc70_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc70_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc70_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc70_d.lib" /debug

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc70 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc70\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\InternetKit_vc70.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc70\InternetKit_vc70.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\InternetKit_vc70.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc70\InternetKit_vc70.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc70.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc70.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc70.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc70.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc70 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_sd\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc70_sd\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\InternetKit_vc70_sd.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc70_sd\InternetKit_vc70_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\InternetKit_vc70_sd.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc70_sd\InternetKit_vc70_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\InternetKit_vc70_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\InternetKit_vc70_sd.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc70 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_s\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc70_s\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\InternetKit_vc70_s.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc70_s\InternetKit_vc70_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\InternetKit_vc70_s.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc70_s\InternetKit_vc70_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\InternetKit_vc70_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\InternetKit_vc70_s.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_d\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc6_d\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\InternetKit_vc6_d.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc6_d\InternetKit_vc6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\InternetKit_vc6_d.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc6_d\InternetKit_vc6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc6_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc6_d.lib" /debug

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc6\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\InternetKit_vc6.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc6\InternetKit_vc6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\InternetKit_vc6.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc6\InternetKit_vc6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc6.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc6.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_sd\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc6_sd\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\InternetKit_vc6_sd.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc6_sd\InternetKit_vc6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\InternetKit_vc6_sd.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc6_sd\InternetKit_vc6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\InternetKit_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\InternetKit_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_s\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc6_s\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\InternetKit_vc6_s.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc6_s\InternetKit_vc6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\InternetKit_vc6_s.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc6_s\InternetKit_vc6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\InternetKit_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\InternetKit_vc6_s.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc5 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_d\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc5_d\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\InternetKit_vc5_d.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc5_d\InternetKit_vc5_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\InternetKit_vc5_d.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc5_d\InternetKit_vc5_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc5_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc5_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc5_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc5_d.lib" /debug

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc5 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc5\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\InternetKit_vc5.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc5\InternetKit_vc5.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\InternetKit_vc5.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc5\InternetKit_vc5.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc5.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc5.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_vc5.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_vc5.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc5 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_sd\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc5_sd\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\InternetKit_vc5_sd.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc5_sd\InternetKit_vc5_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\InternetKit_vc5_sd.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc5_sd\InternetKit_vc5_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\InternetKit_vc5_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\InternetKit_vc5_sd.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 vc5 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_s\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_vc5_s\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\InternetKit_vc5_s.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc5_s\InternetKit_vc5_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\InternetKit_vc5_s.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_vc5_s\InternetKit_vc5_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\InternetKit_vc5_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\InternetKit_vc5_s.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 icl7 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_d\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl7_d\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\InternetKit_icl7_d.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl7_d\InternetKit_icl7_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\InternetKit_icl7_d.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl7_d\InternetKit_icl7_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_icl7_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_icl7_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_icl7_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_icl7_d.lib" /debug

!ELSEIF  "$(CFG)" == "InternetKit - Win32 icl7 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl7\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\InternetKit_icl7.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl7\InternetKit_icl7.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\InternetKit_icl7.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl7\InternetKit_icl7.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_icl7.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_icl7.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_icl7.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_icl7.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 icl7 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_sd\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl7_sd\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\InternetKit_icl7_sd.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl7_sd\InternetKit_icl7_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\InternetKit_icl7_sd.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl7_sd\InternetKit_icl7_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\InternetKit_icl7_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\InternetKit_icl7_sd.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 icl7 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_s\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl7_s\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\InternetKit_icl7_s.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl7_s\InternetKit_icl7_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\InternetKit_icl7_s.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl7_s\InternetKit_icl7_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\InternetKit_icl7_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\InternetKit_icl7_s.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 icl6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_d\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl6_d\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\InternetKit_icl6_d.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl6_d\InternetKit_icl6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\InternetKit_icl6_d.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl6_d\InternetKit_icl6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_icl6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_icl6_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_icl6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_icl6_d.lib" /debug

!ELSEIF  "$(CFG)" == "InternetKit - Win32 icl6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl6\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\InternetKit_icl6.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl6\InternetKit_icl6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\InternetKit_icl6.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl6\InternetKit_icl6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "INTERNETKIT_DLL" /D "INTERNETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "INTERNETKIT_DLL" /d INTERNETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_icl6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_icl6.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\InternetKit_icl6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\InternetKit_icl6.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 icl6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_sd\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl6_sd\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\InternetKit_icl6_sd.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl6_sd\InternetKit_icl6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\InternetKit_icl6_sd.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl6_sd\InternetKit_icl6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\InternetKit_icl6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\InternetKit_icl6_sd.lib"

!ELSEIF  "$(CFG)" == "InternetKit - Win32 icl6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_s\InternetKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "msvc6prj_icl6_s\InternetKit"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\InternetKit_icl6_s.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl6_s\InternetKit_icl6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\InternetKit_icl6_s.pdb /Yu"vcf\InternetKit\InternetKit.h" /Fp"msvc6prj_icl6_s\InternetKit_icl6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\InternetKit_icl6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\InternetKit_icl6_s.lib"

!ENDIF

# Begin Target

# Name "InternetKit - Win32 vc71 DLL Debug"
# Name "InternetKit - Win32 vc71 DLL Release"
# Name "InternetKit - Win32 vc71 Debug"
# Name "InternetKit - Win32 vc71 Release"
# Name "InternetKit - Win32 vc70 DLL Debug"
# Name "InternetKit - Win32 vc70 DLL Release"
# Name "InternetKit - Win32 vc70 Debug"
# Name "InternetKit - Win32 vc70 Release"
# Name "InternetKit - Win32 vc6 DLL Debug"
# Name "InternetKit - Win32 vc6 DLL Release"
# Name "InternetKit - Win32 vc6 Debug"
# Name "InternetKit - Win32 vc6 Release"
# Name "InternetKit - Win32 vc5 DLL Debug"
# Name "InternetKit - Win32 vc5 DLL Release"
# Name "InternetKit - Win32 vc5 Debug"
# Name "InternetKit - Win32 vc5 Release"
# Name "InternetKit - Win32 icl7 DLL Debug"
# Name "InternetKit - Win32 icl7 DLL Release"
# Name "InternetKit - Win32 icl7 Debug"
# Name "InternetKit - Win32 icl7 Release"
# Name "InternetKit - Win32 icl6 DLL Debug"
# Name "InternetKit - Win32 icl6 DLL Release"
# Name "InternetKit - Win32 icl6 Debug"
# Name "InternetKit - Win32 icl6 Release"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\vcf\InternetKit\InternetKit.cpp
# ADD BASE CPP /Yc"vcf\InternetKit\InternetKit.h"
# ADD CPP /Yc"vcf\InternetKit\InternetKit.h"
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\InternetKit\InternetToolkit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\InternetKit\Win32InternetToolkit.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\vcf\InternetKit\InternetKit.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\InternetKit\InternetToolkit.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\InternetKit\URL.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\InternetKit\Win32InternetToolkit.h
# End Source File
# End Group
# End Target
# End Project

