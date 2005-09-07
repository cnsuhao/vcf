# Microsoft Developer Studio Project File - Name="VCF_ApplicationKit" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=ApplicationKit - Win32 default Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VCF_ApplicationKit.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VCF_ApplicationKit.mak" CFG="ApplicationKit - Win32 default Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ApplicationKit - Win32 vc71 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 vc71 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 vc71 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 vc71 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 vc70 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 vc70 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 vc70 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 vc70 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 vc6 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 vc6 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 vc6 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 vc6 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 vc5 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 vc5 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 vc5 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 vc5 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 icl7 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 icl7 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 icl7 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 icl7 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 icl6 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 icl6 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 icl6 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 icl6 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 bcc DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 bcc DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 bcc Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 bcc Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 default DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 default DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ApplicationKit - Win32 default Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "ApplicationKit - Win32 default Release" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ApplicationKit - Win32 vc71 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_d\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_d\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_vc71_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc71_d\ApplicationKit_vc71_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_vc71_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc71_d\ApplicationKit_vc71_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /Fd"..\..\bin\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_vc71_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_vc71_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\ApplicationKit_vc71_d.lib" /out:"..\..\bin\ApplicationKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc71 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_vc71.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc71\ApplicationKit_vc71.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_vc71.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc71\ApplicationKit_vc71.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_vc71.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_vc71.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\ApplicationKit_vc71.lib" /out:"..\..\bin\ApplicationKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc71 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_sd\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_sd\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_vc71_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc71_sd\ApplicationKit_vc71_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_vc71_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc71_sd\ApplicationKit_vc71_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc71_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc71_sd.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc71 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_s\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_s\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_vc71_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc71_s\ApplicationKit_vc71_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_vc71_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc71_s\ApplicationKit_vc71_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc71_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc71_s.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc70 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_d\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_d\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_vc70_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc70_d\ApplicationKit_vc70_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_vc70_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc70_d\ApplicationKit_vc70_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /Fd"..\..\bin\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_vc70_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_vc70_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\ApplicationKit_vc70_d.lib" /out:"..\..\bin\ApplicationKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc70 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_vc70.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc70\ApplicationKit_vc70.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_vc70.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc70\ApplicationKit_vc70.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_vc70.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_vc70.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\ApplicationKit_vc70.lib" /out:"..\..\bin\ApplicationKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc70 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_sd\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_sd\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_vc70_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc70_sd\ApplicationKit_vc70_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_vc70_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc70_sd\ApplicationKit_vc70_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc70_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc70_sd.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc70 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_s\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_s\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_vc70_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc70_s\ApplicationKit_vc70_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_vc70_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc70_s\ApplicationKit_vc70_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc70_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc70_s.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_d\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_d\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_vc6_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6_d\ApplicationKit_vc6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_vc6_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6_d\ApplicationKit_vc6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /Fd"..\..\bin\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_vc6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_vc6_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\ApplicationKit_vc6_d.lib" /out:"..\..\bin\ApplicationKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_vc6.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6\ApplicationKit_vc6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_vc6.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6\ApplicationKit_vc6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_vc6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_vc6.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\ApplicationKit_vc6.lib" /out:"..\..\bin\ApplicationKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_sd\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_sd\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_vc6_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6_sd\ApplicationKit_vc6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_vc6_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6_sd\ApplicationKit_vc6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_s\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_s\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_vc6_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6_s\ApplicationKit_vc6_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_vc6_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6_s\ApplicationKit_vc6_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc6_s.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc5 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_d\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_d\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_vc5_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc5_d\ApplicationKit_vc5_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_vc5_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc5_d\ApplicationKit_vc5_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /Fd"..\..\bin\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_vc5_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_vc5_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\ApplicationKit_vc5_d.lib" /out:"..\..\bin\ApplicationKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc5 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_vc5.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc5\ApplicationKit_vc5.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_vc5.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc5\ApplicationKit_vc5.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_vc5.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_vc5.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\ApplicationKit_vc5.lib" /out:"..\..\bin\ApplicationKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc5 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_sd\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_sd\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_vc5_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc5_sd\ApplicationKit_vc5_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_vc5_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc5_sd\ApplicationKit_vc5_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc5_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc5_sd.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc5 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_s\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_s\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_vc5_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc5_s\ApplicationKit_vc5_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_vc5_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc5_s\ApplicationKit_vc5_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc5_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc5_s.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl7 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_d\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_d\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_icl7_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl7_d\ApplicationKit_icl7_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_icl7_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl7_d\ApplicationKit_icl7_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /Fd"..\..\bin\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_icl7_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_icl7_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\ApplicationKit_icl7_d.lib" /out:"..\..\bin\ApplicationKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl7 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_icl7.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl7\ApplicationKit_icl7.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_icl7.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl7\ApplicationKit_icl7.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_icl7.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_icl7.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\ApplicationKit_icl7.lib" /out:"..\..\bin\ApplicationKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl7 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_sd\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_sd\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_icl7_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl7_sd\ApplicationKit_icl7_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_icl7_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl7_sd\ApplicationKit_icl7_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_icl7_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_icl7_sd.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl7 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_s\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_s\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_icl7_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl7_s\ApplicationKit_icl7_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_icl7_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl7_s\ApplicationKit_icl7_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_icl7_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_icl7_s.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_d\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_d\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_icl6_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl6_d\ApplicationKit_icl6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_icl6_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl6_d\ApplicationKit_icl6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /Fd"..\..\bin\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_icl6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_icl6_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\ApplicationKit_icl6_d.lib" /out:"..\..\bin\ApplicationKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_icl6.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl6\ApplicationKit_icl6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_icl6.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl6\ApplicationKit_icl6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_icl6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_icl6.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\ApplicationKit_icl6.lib" /out:"..\..\bin\ApplicationKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_sd\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_sd\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_icl6_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl6_sd\ApplicationKit_icl6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_icl6_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl6_sd\ApplicationKit_icl6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_icl6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_icl6_sd.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_s\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_s\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_icl6_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl6_s\ApplicationKit_icl6_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_icl6_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_icl6_s\ApplicationKit_icl6_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_icl6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_icl6_s.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 bcc DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc_d\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc_d\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_bcc_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_bcc_d\ApplicationKit_bcc_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_bcc_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_bcc_d\ApplicationKit_bcc_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /Fd"..\..\bin\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_bcc_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_bcc_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\ApplicationKit_bcc_d.lib" /out:"..\..\bin\ApplicationKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 bcc DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_bcc.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_bcc\ApplicationKit_bcc.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_bcc.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_bcc\ApplicationKit_bcc.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_bcc.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_bcc.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\ApplicationKit_bcc.lib" /out:"..\..\bin\ApplicationKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 bcc Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc_sd\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc_sd\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_bcc_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_bcc_sd\ApplicationKit_bcc_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_bcc_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_bcc_sd\ApplicationKit_bcc_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_bcc_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_bcc_sd.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 bcc Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc_s\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc_s\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_bcc_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_bcc_s\ApplicationKit_bcc_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_bcc_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_bcc_s\ApplicationKit_bcc_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_bcc_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_bcc_s.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 default DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_d\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_d\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_vc6_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6_d\ApplicationKit_vc6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\ApplicationKit_vc6_d.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6_d\ApplicationKit_vc6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /Fd"..\..\bin\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_vc6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_vc6_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\ApplicationKit_vc6_d.lib" /out:"..\..\bin\ApplicationKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 default DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_vc6.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6\ApplicationKit_vc6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\ApplicationKit_vc6.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6\ApplicationKit_vc6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_GRAPHICSKIT_DLL" /D "_USRDLL" /D "APPLICATIONKIT_DLL" /D "APPLICATIONKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_GRAPHICSKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "APPLICATIONKIT_DLL" /d APPLICATIONKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\ApplicationKit_vc6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\ApplicationKit_vc6.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\ApplicationKit_vc6.lib" /out:"..\..\bin\ApplicationKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 default Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_sd\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_sd\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_vc6_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6_sd\ApplicationKit_vc6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\ApplicationKit_vc6_sd.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6_sd\ApplicationKit_vc6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\ApplicationKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 default Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_s\ApplicationKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_s\ApplicationKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_vc6_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6_s\ApplicationKit_vc6_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\ApplicationKit_vc6_s.pdb /Yu"vcf\ApplicationKit\ApplicationKit.h" /Fp"msvc6prj_vc6_s\ApplicationKit_vc6_s.pch" /D "WIN32" /D "_LIB" /D "USE_GRAPHICSKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\ApplicationKit_vc6_s.lib"

!ENDIF

# Begin Target

# Name "ApplicationKit - Win32 vc71 DLL Debug"
# Name "ApplicationKit - Win32 vc71 DLL Release"
# Name "ApplicationKit - Win32 vc71 Debug"
# Name "ApplicationKit - Win32 vc71 Release"
# Name "ApplicationKit - Win32 vc70 DLL Debug"
# Name "ApplicationKit - Win32 vc70 DLL Release"
# Name "ApplicationKit - Win32 vc70 Debug"
# Name "ApplicationKit - Win32 vc70 Release"
# Name "ApplicationKit - Win32 vc6 DLL Debug"
# Name "ApplicationKit - Win32 vc6 DLL Release"
# Name "ApplicationKit - Win32 vc6 Debug"
# Name "ApplicationKit - Win32 vc6 Release"
# Name "ApplicationKit - Win32 vc5 DLL Debug"
# Name "ApplicationKit - Win32 vc5 DLL Release"
# Name "ApplicationKit - Win32 vc5 Debug"
# Name "ApplicationKit - Win32 vc5 Release"
# Name "ApplicationKit - Win32 icl7 DLL Debug"
# Name "ApplicationKit - Win32 icl7 DLL Release"
# Name "ApplicationKit - Win32 icl7 Debug"
# Name "ApplicationKit - Win32 icl7 Release"
# Name "ApplicationKit - Win32 icl6 DLL Debug"
# Name "ApplicationKit - Win32 icl6 DLL Release"
# Name "ApplicationKit - Win32 icl6 Debug"
# Name "ApplicationKit - Win32 icl6 Release"
# Name "ApplicationKit - Win32 bcc DLL Debug"
# Name "ApplicationKit - Win32 bcc DLL Release"
# Name "ApplicationKit - Win32 bcc Debug"
# Name "ApplicationKit - Win32 bcc Release"
# Name "ApplicationKit - Win32 default DLL Debug"
# Name "ApplicationKit - Win32 default DLL Release"
# Name "ApplicationKit - Win32 default Debug"
# Name "ApplicationKit - Win32 default Release"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractApplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractCommand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractComponentEditor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractContainer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractListModel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractScrollable.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractTableModel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractTreeModel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractWin32Component.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AcceleratorKey.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Action.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Application.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ApplicationKit.cpp
# ADD BASE CPP /Yc"vcf\ApplicationKit\ApplicationKit.h"
# ADD CPP /Yc"vcf\ApplicationKit\ApplicationKit.h"
# End Source File
# Begin Source File

SOURCE=..\..\build\resources\win32\ApplicationKit.rc

!IF  "$(CFG)" == "ApplicationKit - Win32 vc71 DLL Debug"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc71 DLL Release"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc71 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc71 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc70 DLL Debug"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc70 DLL Release"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc70 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc70 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc6 DLL Debug"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc6 DLL Release"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc6 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc6 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc5 DLL Debug"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc5 DLL Release"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc5 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 vc5 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl7 DLL Debug"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl7 DLL Release"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl7 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl7 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl6 DLL Debug"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl6 DLL Release"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl6 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 icl6 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 bcc DLL Debug"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 bcc DLL Release"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 bcc Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 bcc Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 default DLL Debug"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 default DLL Release"


!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 default Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ApplicationKit - Win32 default Release"

# PROP Exclude_From_Build 1

!ENDIF

# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ApplicationResourceBundle.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Basic3DBorder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\BasicTableItemEditor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ButtonEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\COMDataObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\COMUtils.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CheckBoxControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Clipboard.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ClipboardEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ColorEtchedBorder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ColumnItemEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ColumnModelEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ComboBoxControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommandButton.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommandGroup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonColorDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonFileBrowseDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonFileDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonFileOpenDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonFileSaveDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonFontDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonPrintDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Component.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ComponentEditorManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ComponentInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Containers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Control.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ControlContainer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ControlEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ControlGraphicsContext.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Cursor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CursorManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CustomControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DataObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultColumnItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultColumnModel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultListItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultListModel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultMenuItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultPropertyEditors.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTabModel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTabPage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTableCellItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTableModel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTextModel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTreeItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTreeModel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Desktop.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Dialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DocumentManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DragSource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DropTarget.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\EtchedBorder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\FocusEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Frame.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\HTMLBrowserControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\HeaderControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\HelpEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ImageControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ImageList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ImageListEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ItemEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\KeyboardEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Label.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\LibraryApplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Light3DBorder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\LightweightComponent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ListBoxControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ListModelEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ListViewControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Menu.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MenuBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MenuManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MessageDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Model.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MouseEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MultilineTextControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Panel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\PopupMenu.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ProgressControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\PropertyEditorManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\PushButton.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\RadioButtonControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ScrollbarManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\SliderControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Splitter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\StatusBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\SystemTray.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TabModelEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TabbedPages.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TableControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TableModelEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TextControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TimerComponent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TimerEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TitledBorder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ToggledButton.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ToolTipEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Toolbar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ToolbarDock.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TreeControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TreeListControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TreeModelEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\UIToolkit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\UndoRedoEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\UndoRedoStack.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\VFFInputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\VFFOutputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ValidationEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\WhatsThisHelpEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32AppResourceBundle.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Application.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Button.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Clipboard.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32ColorDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Component.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32ControlContext.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32CursorPeer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Desktop.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Dialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32DragDropPeer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32DropTargetPeer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Edit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32FileOpenDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32FileSaveDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32FolderBrowseDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32FontDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Listview.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32MenuBar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32MenuItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32MenuManagerPeer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Object.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32PopupMenu.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32PrintDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32ScrollPeer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32SystemTrayPeer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32TextPeer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32ToolKit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Toolbar.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Tree.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Window.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Window.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\WindowEvent.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractApplication.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractCommand.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractComponentEditor.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractContainer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractListModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractPropertyEditor.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractScrollable.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractTableModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractTreeModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractView.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AbstractWin32Component.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AcceleratorKey.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Action.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ActionEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ActiveXControlHost.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\AppKitPeerConfig.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Application.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ApplicationException.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ApplicationKit.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ApplicationKitPrivate.h
# End Source File
# Begin Source File

SOURCE=..\..\src\ApplicationKitRTTI.inl
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ApplicationKitSelectLib.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ApplicationPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ApplicationResourceBundle.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\BadComponentStateException.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\BadImageBitsException.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\BadModelStateException.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Basic3DBorder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\BasicTableItemEditor.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Border.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Button.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ButtonEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ButtonPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\COMDataObject.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\COMUtils.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CheckBoxControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Clipboard.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ClipboardEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ClipboardPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ColorEtchedBorder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ColumnItem.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ColumnItemEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ColumnLayoutContainer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ColumnModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ColumnModelEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ComboBoxControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Command.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommandButton.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommandGroup.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonColorDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonDialogPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonFileBrowseDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonFileDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonFileOpenDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonFileSaveDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonFontDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CommonPrintDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Component.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ComponentEditor.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ComponentEditorManager.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ComponentEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ComponentInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Container.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Containers.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Control.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ControlContainer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ControlEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ControlGraphicsContext.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ControlPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ControlsKit.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Cursor.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CursorManager.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CursorPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\CustomControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DataObject.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DataObjectPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DataTypeNotSupportedException.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultColumnItem.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultColumnModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultListItem.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultListModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultMenuItem.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultPropertyEditors.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTabModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTabPage.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTableCellItem.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTableModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTextModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTreeItem.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DefaultTreeModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Desktop.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DesktopPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Dialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DialogPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DocManagerPolicy.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Document.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DocumentBasedApplication.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DocumentManager.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DragDropPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DragEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DragScrollEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DragSource.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DropEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DropTarget.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\DropTargetPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\EnumObject.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\EtchedBorder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\FocusEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Frame.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\FrameEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\HTMLBrowserControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\HTMLBrowserPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\HeaderControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\HelpEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\HorizontalLayoutContainer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ImageControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ImageList.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ImageListEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Item.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ItemEditorEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ItemEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\KeyboardEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Label.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\LibraryApplication.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Light3DBorder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\LightweightComponent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ListBoxControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ListItem.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ListModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ListModelEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ListViewControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ListviewPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Menu.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MenuBar.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MenuBarPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MenuItem.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MenuItemEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MenuItemPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MenuManager.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MenuManagerPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MessageDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Model.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ModelEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ModelViewKit.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MouseEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\MultilineTextControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Panel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\PopupMenu.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\PopupMenuPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ProgressControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\PropertyEditor.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\PropertyEditorManager.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\PushButton.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\RadioButtonControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ScrollBarControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ScrollEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ScrollPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Scrollable.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ScrollbarManager.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ScrollbarPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Selectable.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\SelectionListener.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\SliderControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Splitter.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\StatusBar.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\SystemTray.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\SystemTrayPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TabModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TabModelEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TabPage.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TabbedPages.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TableCellItem.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TableControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TableItemEditor.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TableModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TableModelEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TextControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TextEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TextModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TextPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TimerComponent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TimerEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TitledBorder.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ToggledButton.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ToolTipEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Toolbar.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ToolbarDock.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ToolbarPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TreeControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TreeItem.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TreeListControl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TreeModel.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TreeModelEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\TreePeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\UIMetricsManager.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\UIPolicyManager.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\UIToolkit.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\UndoRedoEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\UndoRedoStack.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\VCFCOM.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\VFFInputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\VFFOutputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\ValidationEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\View.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\WhatsThisHelpEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32AppResourceBundle.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Application.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Button.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Clipboard.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32ColorDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Component.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32ControlContext.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32CursorPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Desktop.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Dialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32DragDropPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32DropTargetPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Edit.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32FileOpenDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32FileSaveDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32FolderBrowseDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32FontDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32HTMLBrowserSelectLib.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32ListBox.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Listview.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32MenuBar.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32MenuItem.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32MenuManagerPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Object.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32PopupMenu.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32PrintDialog.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32ScrollPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32SystemTrayPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32TextPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32ToolKit.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Toolbar.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Tree.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Win32Window.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Window.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\WindowEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\WindowPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\ApplicationKit\Wizard.h
# End Source File
# End Group
# End Target
# End Project

