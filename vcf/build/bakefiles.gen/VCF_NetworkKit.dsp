# Microsoft Developer Studio Project File - Name="VCF_NetworkKit" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=NetworkKit - Win32 default Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VCF_NetworkKit.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VCF_NetworkKit.mak" CFG="NetworkKit - Win32 default Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "NetworkKit - Win32 vc71 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 vc71 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 vc71 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 vc71 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 vc70 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 vc70 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 vc70 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 vc70 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 vc6 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 vc6 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 vc6 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 vc6 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 vc5 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 vc5 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 vc5 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 vc5 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 icl7 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 icl7 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 icl7 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 icl7 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 icl6 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 icl6 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 icl6 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 icl6 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 bcc DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 bcc DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 bcc Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 bcc Release" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 default DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 default DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "NetworkKit - Win32 default Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "NetworkKit - Win32 default Release" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "NetworkKit - Win32 vc71 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_d\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_d\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_vc71_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc71_d\NetworkKit_vc71_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_vc71_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc71_d\NetworkKit_vc71_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /Fd"..\..\bin\NetworkKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_vc71_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_vc71_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\NetworkKit_vc71_d.lib" /out:"..\..\bin\NetworkKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc71 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_vc71.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc71\NetworkKit_vc71.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_vc71.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc71\NetworkKit_vc71.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_vc71.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_vc71.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\NetworkKit_vc71.lib" /out:"..\..\bin\NetworkKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc71 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_sd\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_sd\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_vc71_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc71_sd\NetworkKit_vc71_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_vc71_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc71_sd\NetworkKit_vc71_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\NetworkKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_vc71_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_vc71_sd.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc71 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_s\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_s\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\NetworkKit_vc71_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc71_s\NetworkKit_vc71_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\NetworkKit_vc71_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc71_s\NetworkKit_vc71_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_vc71_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_vc71_s.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc70 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_d\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_d\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_vc70_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc70_d\NetworkKit_vc70_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_vc70_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc70_d\NetworkKit_vc70_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /Fd"..\..\bin\NetworkKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_vc70_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_vc70_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\NetworkKit_vc70_d.lib" /out:"..\..\bin\NetworkKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc70 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_vc70.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc70\NetworkKit_vc70.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_vc70.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc70\NetworkKit_vc70.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_vc70.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_vc70.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\NetworkKit_vc70.lib" /out:"..\..\bin\NetworkKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc70 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_sd\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_sd\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_vc70_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc70_sd\NetworkKit_vc70_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_vc70_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc70_sd\NetworkKit_vc70_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\NetworkKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_vc70_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_vc70_sd.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc70 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_s\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_s\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\NetworkKit_vc70_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc70_s\NetworkKit_vc70_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\NetworkKit_vc70_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc70_s\NetworkKit_vc70_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_vc70_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_vc70_s.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_d\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_d\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_vc6_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6_d\NetworkKit_vc6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_vc6_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6_d\NetworkKit_vc6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /Fd"..\..\bin\NetworkKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_vc6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_vc6_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\NetworkKit_vc6_d.lib" /out:"..\..\bin\NetworkKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_vc6.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6\NetworkKit_vc6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_vc6.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6\NetworkKit_vc6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_vc6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_vc6.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\NetworkKit_vc6.lib" /out:"..\..\bin\NetworkKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_sd\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_sd\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_vc6_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6_sd\NetworkKit_vc6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_vc6_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6_sd\NetworkKit_vc6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\NetworkKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_s\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_s\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\NetworkKit_vc6_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6_s\NetworkKit_vc6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\NetworkKit_vc6_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6_s\NetworkKit_vc6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_vc6_s.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc5 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_d\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_d\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_vc5_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc5_d\NetworkKit_vc5_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_vc5_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc5_d\NetworkKit_vc5_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /Fd"..\..\bin\NetworkKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_vc5_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_vc5_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\NetworkKit_vc5_d.lib" /out:"..\..\bin\NetworkKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc5 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_vc5.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc5\NetworkKit_vc5.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_vc5.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc5\NetworkKit_vc5.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_vc5.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_vc5.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\NetworkKit_vc5.lib" /out:"..\..\bin\NetworkKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc5 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_sd\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_sd\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_vc5_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc5_sd\NetworkKit_vc5_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_vc5_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc5_sd\NetworkKit_vc5_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\NetworkKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_vc5_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_vc5_sd.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 vc5 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_s\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_s\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\NetworkKit_vc5_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc5_s\NetworkKit_vc5_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\NetworkKit_vc5_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc5_s\NetworkKit_vc5_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_vc5_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_vc5_s.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 icl7 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_d\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_d\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_icl7_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl7_d\NetworkKit_icl7_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_icl7_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl7_d\NetworkKit_icl7_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /Fd"..\..\bin\NetworkKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_icl7_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_icl7_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\NetworkKit_icl7_d.lib" /out:"..\..\bin\NetworkKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 icl7 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_icl7.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl7\NetworkKit_icl7.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_icl7.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl7\NetworkKit_icl7.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_icl7.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_icl7.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\NetworkKit_icl7.lib" /out:"..\..\bin\NetworkKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 icl7 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_sd\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_sd\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_icl7_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl7_sd\NetworkKit_icl7_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_icl7_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl7_sd\NetworkKit_icl7_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\NetworkKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_icl7_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_icl7_sd.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 icl7 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_s\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_s\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\NetworkKit_icl7_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl7_s\NetworkKit_icl7_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\NetworkKit_icl7_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl7_s\NetworkKit_icl7_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_icl7_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_icl7_s.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 icl6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_d\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_d\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_icl6_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl6_d\NetworkKit_icl6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_icl6_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl6_d\NetworkKit_icl6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /Fd"..\..\bin\NetworkKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_icl6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_icl6_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\NetworkKit_icl6_d.lib" /out:"..\..\bin\NetworkKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 icl6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_icl6.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl6\NetworkKit_icl6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_icl6.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl6\NetworkKit_icl6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_icl6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_icl6.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\NetworkKit_icl6.lib" /out:"..\..\bin\NetworkKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 icl6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_sd\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_sd\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_icl6_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl6_sd\NetworkKit_icl6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_icl6_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl6_sd\NetworkKit_icl6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\NetworkKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_icl6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_icl6_sd.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 icl6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_s\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_s\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\NetworkKit_icl6_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl6_s\NetworkKit_icl6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\NetworkKit_icl6_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_icl6_s\NetworkKit_icl6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_icl6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_icl6_s.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 bcc DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc_d\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc_d\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_bcc_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_bcc_d\NetworkKit_bcc_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_bcc_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_bcc_d\NetworkKit_bcc_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /Fd"..\..\bin\NetworkKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_bcc_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_bcc_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\NetworkKit_bcc_d.lib" /out:"..\..\bin\NetworkKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 bcc DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_bcc.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_bcc\NetworkKit_bcc.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_bcc.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_bcc\NetworkKit_bcc.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_bcc.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_bcc.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\NetworkKit_bcc.lib" /out:"..\..\bin\NetworkKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 bcc Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc_sd\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc_sd\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_bcc_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_bcc_sd\NetworkKit_bcc_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_bcc_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_bcc_sd\NetworkKit_bcc_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\NetworkKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_bcc_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_bcc_sd.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 bcc Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc_s\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc_s\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\NetworkKit_bcc_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_bcc_s\NetworkKit_bcc_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\NetworkKit_bcc_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_bcc_s\NetworkKit_bcc_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_bcc_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_bcc_s.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 default DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_d\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_d\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_vc6_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6_d\NetworkKit_vc6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\..\bin\NetworkKit_vc6_d.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6_d\NetworkKit_vc6_d.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /Fd"..\..\bin\NetworkKit_vc6_sd.pdb" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_DEBUG" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /d "_DEBUG" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_vc6_d.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_vc6_d.lib" /debug
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /debug /machine:i386 /implib:"..\..\lib\NetworkKit_vc6_d.lib" /out:"..\..\bin\NetworkKit_vc6_sd.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 default DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_vc6.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6\NetworkKit_vc6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\..\bin\NetworkKit_vc6.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6\NetworkKit_vc6.pch" /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /c
# ADD BASE MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD MTL /nologo /D "WIN32" /D "_USRDLL" /D "DLL_EXPORTS" /D "USE_FOUNDATIONKIT_DLL" /D "_USRDLL" /D "NETKIT_DLL" /D "NETKIT_EXPORTS" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
# ADD RSC /l 0x409 /d "USE_FOUNDATIONKIT_DLL" /i "..\..\src" /d "_USRDLL" /d "NETKIT_DLL" /d NETKIT_EXPORTS
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /out:"..\..\lib\..\bin\NetworkKit_vc6.dll" /libpath:"..\..\lib" /implib:"..\..\lib\NetworkKit_vc6.lib"
# ADD LINK32 rpcrt4.lib odbc32.lib odbccp32.lib version.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib ws2_32.lib opengl32.lib glu32.lib glaux.lib oleacc.lib /nologo /dll /machine:i386 /implib:"..\..\lib\NetworkKit_vc6.lib" /out:"..\..\bin\NetworkKit_vc6_s.lib" /libpath:"..\..\lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 default Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_sd\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_sd\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_vc6_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6_sd\NetworkKit_vc6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\NetworkKit_vc6_sd.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6_sd\NetworkKit_vc6_sd.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\NetworkKit_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "NetworkKit - Win32 default Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_s\NetworkKit"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_s\NetworkKit\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\NetworkKit_vc6_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6_s\NetworkKit_vc6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\NetworkKit_vc6_s.pdb /Yu"vcf\NetworkKit\NetworkKit.h" /Fp"msvc6prj_vc6_s\NetworkKit_vc6_s.pch" /D "WIN32" /D "_LIB" /D "USE_FOUNDATIONKIT_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\NetworkKit_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\NetworkKit_vc6_s.lib"

!ENDIF

# Begin Target

# Name "NetworkKit - Win32 vc71 DLL Debug"
# Name "NetworkKit - Win32 vc71 DLL Release"
# Name "NetworkKit - Win32 vc71 Debug"
# Name "NetworkKit - Win32 vc71 Release"
# Name "NetworkKit - Win32 vc70 DLL Debug"
# Name "NetworkKit - Win32 vc70 DLL Release"
# Name "NetworkKit - Win32 vc70 Debug"
# Name "NetworkKit - Win32 vc70 Release"
# Name "NetworkKit - Win32 vc6 DLL Debug"
# Name "NetworkKit - Win32 vc6 DLL Release"
# Name "NetworkKit - Win32 vc6 Debug"
# Name "NetworkKit - Win32 vc6 Release"
# Name "NetworkKit - Win32 vc5 DLL Debug"
# Name "NetworkKit - Win32 vc5 DLL Release"
# Name "NetworkKit - Win32 vc5 Debug"
# Name "NetworkKit - Win32 vc5 Release"
# Name "NetworkKit - Win32 icl7 DLL Debug"
# Name "NetworkKit - Win32 icl7 DLL Release"
# Name "NetworkKit - Win32 icl7 Debug"
# Name "NetworkKit - Win32 icl7 Release"
# Name "NetworkKit - Win32 icl6 DLL Debug"
# Name "NetworkKit - Win32 icl6 DLL Release"
# Name "NetworkKit - Win32 icl6 Debug"
# Name "NetworkKit - Win32 icl6 Release"
# Name "NetworkKit - Win32 bcc DLL Debug"
# Name "NetworkKit - Win32 bcc DLL Release"
# Name "NetworkKit - Win32 bcc Debug"
# Name "NetworkKit - Win32 bcc Release"
# Name "NetworkKit - Win32 default DLL Debug"
# Name "NetworkKit - Win32 default DLL Release"
# Name "NetworkKit - Win32 default Debug"
# Name "NetworkKit - Win32 default Release"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\DatagramSocket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\NetToolkit.cpp
# ADD BASE CPP /Yc"vcf\NetworkKit\NetworkKit.h"
# ADD CPP /Yc"vcf\NetworkKit\NetworkKit.h"
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\ServerSocketEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\Socket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\SocketEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\SocketListeningLoop.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\URL.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\Win32DatagramSocketPeer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\Win32SocketPeer.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\DatagramSocket.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\NetToolkit.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\NetworkKit.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\NetworkKitPrivate.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\NetworkKitSelectLib.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\ServerSocketEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\Socket.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\SocketEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\SocketException.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\SocketListener.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\SocketListeningLoop.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\SocketPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\URL.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\Win32DatagramSocketPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vcf\NetworkKit\Win32SocketPeer.h
# End Source File
# End Group
# End Target
# End Project

