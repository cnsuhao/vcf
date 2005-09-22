# Microsoft Developer Studio Project File - Name="VCF_GraphicsKit" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104
# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=GraphicsKit - Win32 icl6 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VCF_GraphicsKit.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VCF_GraphicsKit.mak" CFG="GraphicsKit - Win32 icl6 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GraphicsKit - Win32 vc71 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GraphicsKit - Win32 vc71 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GraphicsKit - Win32 vc71 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "GraphicsKit - Win32 vc71 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "GraphicsKit - Win32 vc70 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GraphicsKit - Win32 vc70 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GraphicsKit - Win32 vc70 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "GraphicsKit - Win32 vc70 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "GraphicsKit - Win32 vc6 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GraphicsKit - Win32 vc6 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GraphicsKit - Win32 vc6 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "GraphicsKit - Win32 vc6 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "GraphicsKit - Win32 vc5 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GraphicsKit - Win32 vc5 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GraphicsKit - Win32 vc5 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "GraphicsKit - Win32 vc5 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "GraphicsKit - Win32 icl7 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GraphicsKit - Win32 icl7 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GraphicsKit - Win32 icl7 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "GraphicsKit - Win32 icl7 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "GraphicsKit - Win32 icl6 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GraphicsKit - Win32 icl6 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GraphicsKit - Win32 icl6 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "GraphicsKit - Win32 icl6 Release" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GraphicsKit - Win32 vc71 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_d\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_d\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\GraphicsKit_vc71_d.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc71_d\GraphicsKit_vc71_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\GraphicsKit_vc71_d.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc71_d\GraphicsKit_vc71_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /Fd"..\..\bin\GraphicsKit_icl6_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\GraphicsKit_vc71_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\GraphicsKit_vc71_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\GraphicsKit_vc71_d.lib" /out:"..\..\bin\GraphicsKit_icl6_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc71 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\GraphicsKit_vc71.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc71\GraphicsKit_vc71.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\GraphicsKit_vc71.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc71\GraphicsKit_vc71.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\GraphicsKit_vc71.dll" /libpath:"..\..\lib" /implib:"..\..\lib\GraphicsKit_vc71.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /implib:"..\..\lib\GraphicsKit_vc71.lib" /out:"..\..\bin\GraphicsKit_icl6_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc71 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_sd\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_sd\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\GraphicsKit_vc71_sd.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc71_sd\GraphicsKit_vc71_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\GraphicsKit_vc71_sd.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc71_sd\GraphicsKit_vc71_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /Fd"..\..\lib\GraphicsKit_icl6_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc71_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc71_sd.lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc71 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_s\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_s\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\GraphicsKit_vc71_s.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc71_s\GraphicsKit_vc71_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\GraphicsKit_vc71_s.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc71_s\GraphicsKit_vc71_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc71_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc71_s.lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc70 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_d\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_d\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\GraphicsKit_vc70_d.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc70_d\GraphicsKit_vc70_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\GraphicsKit_vc70_d.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc70_d\GraphicsKit_vc70_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /Fd"..\..\bin\GraphicsKit_icl6_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\GraphicsKit_vc70_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\GraphicsKit_vc70_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\GraphicsKit_vc70_d.lib" /out:"..\..\bin\GraphicsKit_icl6_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc70 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\GraphicsKit_vc70.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc70\GraphicsKit_vc70.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\GraphicsKit_vc70.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc70\GraphicsKit_vc70.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\GraphicsKit_vc70.dll" /libpath:"..\..\lib" /implib:"..\..\lib\GraphicsKit_vc70.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /implib:"..\..\lib\GraphicsKit_vc70.lib" /out:"..\..\bin\GraphicsKit_icl6_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc70 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_sd\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_sd\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\GraphicsKit_vc70_sd.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc70_sd\GraphicsKit_vc70_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\GraphicsKit_vc70_sd.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc70_sd\GraphicsKit_vc70_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /Fd"..\..\lib\GraphicsKit_icl6_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc70_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc70_sd.lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc70 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_s\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_s\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\GraphicsKit_vc70_s.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc70_s\GraphicsKit_vc70_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\GraphicsKit_vc70_s.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc70_s\GraphicsKit_vc70_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc70_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc70_s.lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_d\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_d\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\GraphicsKit_vc6_d.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc6_d\GraphicsKit_vc6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\GraphicsKit_vc6_d.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc6_d\GraphicsKit_vc6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /Fd"..\..\bin\GraphicsKit_icl6_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\GraphicsKit_vc6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\GraphicsKit_vc6_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\GraphicsKit_vc6_d.lib" /out:"..\..\bin\GraphicsKit_icl6_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\GraphicsKit_vc6.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc6\GraphicsKit_vc6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\GraphicsKit_vc6.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc6\GraphicsKit_vc6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\GraphicsKit_vc6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\GraphicsKit_vc6.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /implib:"..\..\lib\GraphicsKit_vc6.lib" /out:"..\..\bin\GraphicsKit_icl6_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_sd\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_sd\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\GraphicsKit_vc6_sd.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc6_sd\GraphicsKit_vc6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\GraphicsKit_vc6_sd.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc6_sd\GraphicsKit_vc6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /Fd"..\..\lib\GraphicsKit_icl6_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_s\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_s\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\GraphicsKit_vc6_s.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc6_s\GraphicsKit_vc6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\GraphicsKit_vc6_s.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc6_s\GraphicsKit_vc6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc6_s.lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc5 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_d\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_d\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\GraphicsKit_vc5_d.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc5_d\GraphicsKit_vc5_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\GraphicsKit_vc5_d.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc5_d\GraphicsKit_vc5_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /Fd"..\..\bin\GraphicsKit_icl6_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\GraphicsKit_vc5_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\GraphicsKit_vc5_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\GraphicsKit_vc5_d.lib" /out:"..\..\bin\GraphicsKit_icl6_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc5 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\GraphicsKit_vc5.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc5\GraphicsKit_vc5.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\GraphicsKit_vc5.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc5\GraphicsKit_vc5.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\GraphicsKit_vc5.dll" /libpath:"..\..\lib" /implib:"..\..\lib\GraphicsKit_vc5.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /implib:"..\..\lib\GraphicsKit_vc5.lib" /out:"..\..\bin\GraphicsKit_icl6_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc5 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_sd\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_sd\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\GraphicsKit_vc5_sd.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc5_sd\GraphicsKit_vc5_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\GraphicsKit_vc5_sd.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc5_sd\GraphicsKit_vc5_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /Fd"..\..\lib\GraphicsKit_icl6_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc5_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc5_sd.lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 vc5 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_s\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_s\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\GraphicsKit_vc5_s.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc5_s\GraphicsKit_vc5_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\GraphicsKit_vc5_s.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_vc5_s\GraphicsKit_vc5_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc5_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\GraphicsKit_vc5_s.lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 icl7 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_d\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_d\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\GraphicsKit_icl7_d.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl7_d\GraphicsKit_icl7_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\GraphicsKit_icl7_d.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl7_d\GraphicsKit_icl7_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /Fd"..\..\bin\GraphicsKit_icl6_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\GraphicsKit_icl7_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\GraphicsKit_icl7_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\GraphicsKit_icl7_d.lib" /out:"..\..\bin\GraphicsKit_icl6_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 icl7 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\GraphicsKit_icl7.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl7\GraphicsKit_icl7.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\GraphicsKit_icl7.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl7\GraphicsKit_icl7.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\GraphicsKit_icl7.dll" /libpath:"..\..\lib" /implib:"..\..\lib\GraphicsKit_icl7.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /implib:"..\..\lib\GraphicsKit_icl7.lib" /out:"..\..\bin\GraphicsKit_icl6_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 icl7 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_sd\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_sd\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\GraphicsKit_icl7_sd.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl7_sd\GraphicsKit_icl7_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\GraphicsKit_icl7_sd.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl7_sd\GraphicsKit_icl7_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /Fd"..\..\lib\GraphicsKit_icl6_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\GraphicsKit_icl7_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\GraphicsKit_icl7_sd.lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 icl7 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_s\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_s\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\GraphicsKit_icl7_s.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl7_s\GraphicsKit_icl7_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\GraphicsKit_icl7_s.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl7_s\GraphicsKit_icl7_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\GraphicsKit_icl7_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\GraphicsKit_icl7_s.lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 icl6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_d\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_d\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\GraphicsKit_icl6_d.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl6_d\GraphicsKit_icl6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\GraphicsKit_icl6_d.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl6_d\GraphicsKit_icl6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /Fd"..\..\bin\GraphicsKit_icl6_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /d "_DEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\GraphicsKit_icl6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\GraphicsKit_icl6_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\GraphicsKit_icl6_d.lib" /out:"..\..\bin\GraphicsKit_icl6_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 icl6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\GraphicsKit_icl6.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl6\GraphicsKit_icl6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\GraphicsKit_icl6.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl6\GraphicsKit_icl6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_USRDLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "NDEBUG" /d "_WINDOWS" /d "_WIN32" /d "WIN32" /i "..\..\src" /d "_USRDLL" /d "GRAPHICSKIT_DLL" /d GRAPHICSKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\GraphicsKit_icl6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\GraphicsKit_icl6.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib oleacc.lib glaux.lib /nologo /dll /machine:i386 /implib:"..\..\lib\GraphicsKit_icl6.lib" /out:"..\..\bin\GraphicsKit_icl6_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 icl6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_sd\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_sd\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\GraphicsKit_icl6_sd.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl6_sd\GraphicsKit_icl6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\GraphicsKit_icl6_sd.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl6_sd\GraphicsKit_icl6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_DEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /Fd"..\..\lib\GraphicsKit_icl6_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\GraphicsKit_icl6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\GraphicsKit_icl6_sd.lib"

!ELSEIF  "$(CFG)" == "GraphicsKit - Win32 icl6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_s\GraphicsKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_s\GraphicsKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\GraphicsKit_icl6_s.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl6_s\GraphicsKit_icl6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\GraphicsKit_icl6_s.pdb /Yu"vcf\GraphicsKit\GraphicsKit.h" /Fp"msvc6prj_icl6_s\GraphicsKit_icl6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "NDEBUG" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_LIB" /D "_MBCS" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\GraphicsKit_icl6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\GraphicsKit_icl6_s.lib"

!ENDIF

# Begin Target

# Name "GraphicsKit - Win32 vc71 DLL Debug"
# Name "GraphicsKit - Win32 vc71 DLL Release"
# Name "GraphicsKit - Win32 vc71 Debug"
# Name "GraphicsKit - Win32 vc71 Release"
# Name "GraphicsKit - Win32 vc70 DLL Debug"
# Name "GraphicsKit - Win32 vc70 DLL Release"
# Name "GraphicsKit - Win32 vc70 Debug"
# Name "GraphicsKit - Win32 vc70 Release"
# Name "GraphicsKit - Win32 vc6 DLL Debug"
# Name "GraphicsKit - Win32 vc6 DLL Release"
# Name "GraphicsKit - Win32 vc6 Debug"
# Name "GraphicsKit - Win32 vc6 Release"
# Name "GraphicsKit - Win32 vc5 DLL Debug"
# Name "GraphicsKit - Win32 vc5 DLL Release"
# Name "GraphicsKit - Win32 vc5 Debug"
# Name "GraphicsKit - Win32 vc5 Release"
# Name "GraphicsKit - Win32 icl7 DLL Debug"
# Name "GraphicsKit - Win32 icl7 DLL Release"
# Name "GraphicsKit - Win32 icl7 Debug"
# Name "GraphicsKit - Win32 icl7 Release"
# Name "GraphicsKit - Win32 icl6 DLL Debug"
# Name "GraphicsKit - Win32 icl6 DLL Release"
# Name "GraphicsKit - Win32 icl6 Debug"
# Name "GraphicsKit - Win32 icl6 Release"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\AbstractImage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\BasicFill.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\BasicStroke.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\BezierCurve.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Color.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Font.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\GraphicsContext.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\GraphicsKit.cpp
# ADD BASE CPP /Yc"vcf\GraphicsKit\GraphicsKit.h"
# ADD CPP /Yc"vcf\GraphicsKit\GraphicsKit.h"
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\GraphicsResourceBundle.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\GraphicsToolKit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\ImageEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Matrix2D.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Point.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\PrintSession.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Rect.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32Context.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32Font.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32FontManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32GraphicsResourceBundle.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32GraphicsToolkit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32Image.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32PrintSession.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\AbstractImage.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\AggCommon.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\BasicFill.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\BasicRectangle.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\BasicStroke.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\BezierCurve.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Circle.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Color.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Composition.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\ContextPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\DrawUIState.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Ellipse.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Fill.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Filter.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Font.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\FontPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\GraphicsContext.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\GraphicsKit.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\GraphicsKitPrivate.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\GraphicsKitRTTI.inl
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\GraphicsKitSelectLib.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\GraphicsResourceBundle.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\GraphicsResourceBundlePeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\GraphicsToolKit.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Image.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\ImageBits.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\ImageEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\ImageLoader.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\ImageLoaderException.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\ImageTile.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\InvalidImage.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Kernel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Layer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\MagicFMLibType.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Matrix2D.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\NoGraphicsToolkitFoundException.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Path.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\PixelFormats.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Point.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\PrintContext.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\PrintEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\PrintSession.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\PrintSessionPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Printable.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Rect.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Size.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Stroke.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\TileManager.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\UVMap.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32Context.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32Font.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32FontManager.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32GraphicsResourceBundle.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32GraphicsToolkit.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32Image.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\GraphicsKit\Win32PrintSession.h
# End Source File
# End Group
# End Target
# End Project

