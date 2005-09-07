# Microsoft Developer Studio Project File - Name="VCF_LibTIFF_lib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=LibTIFF_lib - Win32 default Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VCF_LibTIFF_lib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VCF_LibTIFF_lib.mak" CFG="LibTIFF_lib - Win32 default Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LibTIFF_lib - Win32 vc71 DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc71 DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc71 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc71 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc70 DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc70 DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc70 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc70 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc6 DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc6 DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc6 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc6 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc5 DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc5 DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc5 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 vc5 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 icl7 DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 icl7 DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 icl7 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 icl7 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 icl6 DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 icl6 DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 icl6 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 icl6 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 bcc DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 bcc DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 bcc Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 bcc Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 default DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 default DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 default Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF_lib - Win32 default Release" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "LibTIFF_lib - Win32 vc71 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_d\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_d\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc71_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc71_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc71_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc71_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc71 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc71_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc71_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc71_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc71_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc71 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_sd\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_sd\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc71_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc71_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc71_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc71_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc71 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_s\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_s\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc71_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc71_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc71_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc71_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc70 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_d\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_d\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc70_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc70_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc70_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc70_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc70 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc70_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc70_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc70_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc70_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc70 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_sd\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_sd\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc70_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc70_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc70_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc70_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc70 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_s\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_s\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc70_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc70_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc70_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc70_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_d\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_d\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_sd\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_sd\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_s\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_s\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc5 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_d\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_d\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc5_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc5_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc5_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc5_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc5 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc5_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc5_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc5_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc5_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc5 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_sd\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_sd\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc5_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc5_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc5_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc5_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 vc5 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_s\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_s\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc5_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc5_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc5_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc5_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 icl7 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_d\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_d\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_icl7_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_icl7_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_icl7_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_icl7_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 icl7 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_icl7_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_icl7_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_icl7_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_icl7_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 icl7 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_sd\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_sd\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_icl7_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_icl7_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_icl7_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_icl7_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 icl7 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_s\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_s\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_icl7_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_icl7_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_icl7_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_icl7_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 icl6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_d\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_d\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_icl6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_icl6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_icl6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_icl6_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 icl6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_icl6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_icl6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_icl6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_icl6_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 icl6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_sd\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_sd\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_icl6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_icl6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_icl6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_icl6_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 icl6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_s\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_s\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_icl6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_icl6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_icl6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_icl6_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 bcc DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc_d\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc_d\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_bcc_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_bcc_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_bcc_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_bcc_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 bcc DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_bcc_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_bcc_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_bcc_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_bcc_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 bcc Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc_sd\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc_sd\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_bcc_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_bcc_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_bcc_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_bcc_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 bcc Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc_s\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc_s\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_bcc_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_bcc_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_bcc_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_bcc_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 default DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_d\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_d\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 default DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 default Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_sd\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_sd\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\LibTIFF_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\LibTIFF_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "LibTIFF_lib - Win32 default Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_s\LibTIFF_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_s\LibTIFF_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\LibTIFF_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\LibTIFF_vc6_s.lib"

!ENDIF

# Begin Target

# Name "LibTIFF_lib - Win32 vc71 DLL Debug"
# Name "LibTIFF_lib - Win32 vc71 DLL Release"
# Name "LibTIFF_lib - Win32 vc71 Debug"
# Name "LibTIFF_lib - Win32 vc71 Release"
# Name "LibTIFF_lib - Win32 vc70 DLL Debug"
# Name "LibTIFF_lib - Win32 vc70 DLL Release"
# Name "LibTIFF_lib - Win32 vc70 Debug"
# Name "LibTIFF_lib - Win32 vc70 Release"
# Name "LibTIFF_lib - Win32 vc6 DLL Debug"
# Name "LibTIFF_lib - Win32 vc6 DLL Release"
# Name "LibTIFF_lib - Win32 vc6 Debug"
# Name "LibTIFF_lib - Win32 vc6 Release"
# Name "LibTIFF_lib - Win32 vc5 DLL Debug"
# Name "LibTIFF_lib - Win32 vc5 DLL Release"
# Name "LibTIFF_lib - Win32 vc5 Debug"
# Name "LibTIFF_lib - Win32 vc5 Release"
# Name "LibTIFF_lib - Win32 icl7 DLL Debug"
# Name "LibTIFF_lib - Win32 icl7 DLL Release"
# Name "LibTIFF_lib - Win32 icl7 Debug"
# Name "LibTIFF_lib - Win32 icl7 Release"
# Name "LibTIFF_lib - Win32 icl6 DLL Debug"
# Name "LibTIFF_lib - Win32 icl6 DLL Release"
# Name "LibTIFF_lib - Win32 icl6 Debug"
# Name "LibTIFF_lib - Win32 icl6 Release"
# Name "LibTIFF_lib - Win32 bcc DLL Debug"
# Name "LibTIFF_lib - Win32 bcc DLL Release"
# Name "LibTIFF_lib - Win32 bcc Debug"
# Name "LibTIFF_lib - Win32 bcc Release"
# Name "LibTIFF_lib - Win32 default DLL Debug"
# Name "LibTIFF_lib - Win32 default DLL Release"
# Name "LibTIFF_lib - Win32 default Debug"
# Name "LibTIFF_lib - Win32 default Release"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\fax3sm_winnt.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_aux.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_close.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_codec.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_compress.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_dir.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_dirinfo.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_dirread.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_dirwrite.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_dumpmode.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_error.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_fax3.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_flush.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_getimage.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_jpeg.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_luv.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_lzw.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_next.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_open.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_packbits.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_pixarlog.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_predict.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_print.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_read.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_strip.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_swab.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_thunder.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_tile.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_version.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_warning.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_win32.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_write.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_zip.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\t4.h
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_dir.h
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_fax3.h
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tif_predict.h
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tiff.h
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tiffcomp.h
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tiffconf.h
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tiffio.h
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\tiffiop.h
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\FreeImage\Source\LibTIFF\uvcode.h
# End Source File
# End Group
# End Target
# End Project

