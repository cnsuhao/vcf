# Microsoft Developer Studio Project File - Name="VCF_RegExx_lib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=RegExx_lib - Win32 default Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VCF_RegExx_lib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VCF_RegExx_lib.mak" CFG="RegExx_lib - Win32 default Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RegExx_lib - Win32 vc71 DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc71 DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc71 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc71 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc70 DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc70 DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc70 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc70 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc6 DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc6 DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc6 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc6 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc5 DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc5 DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc5 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 vc5 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 icl7 DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 icl7 DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 icl7 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 icl7 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 icl6 DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 icl6 DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 icl6 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 icl6 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 bcc DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 bcc DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 bcc Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 bcc Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 default DLL Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 default DLL Release" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 default Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "RegExx_lib - Win32 default Release" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "RegExx_lib - Win32 vc71 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_d\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_d\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc71_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc71_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc71_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc71_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc71 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_vc71_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_vc71_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc71_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc71_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc71 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_sd\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_sd\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc71_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc71_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc71_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc71_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc71 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc71_s\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc71_s\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_vc71_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_vc71_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc71_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc71_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc70 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_d\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_d\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc70_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc70_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc70_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc70_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc70 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_vc70_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_vc70_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc70_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc70_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc70 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_sd\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_sd\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc70_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc70_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc70_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc70_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc70 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc70_s\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc70_s\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_vc70_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_vc70_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc70_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc70_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_d\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_d\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc6_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_sd\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_sd\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_s\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_s\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc6_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc5 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_d\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_d\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc5_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc5_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc5_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc5_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc5 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_vc5_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_vc5_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc5_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc5_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc5 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_sd\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_sd\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc5_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc5_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc5_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc5_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 vc5 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc5_s\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc5_s\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_vc5_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_vc5_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc5_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc5_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 icl7 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_d\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_d\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_icl7_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_icl7_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_icl7_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_icl7_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 icl7 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_icl7_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_icl7_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_icl7_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_icl7_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 icl7 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_sd\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_sd\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_icl7_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_icl7_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_icl7_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_icl7_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 icl7 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl7_s\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl7_s\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_icl7_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_icl7_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_icl7_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_icl7_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 icl6 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_d\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_d\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_icl6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_icl6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_icl6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_icl6_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 icl6 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_icl6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_icl6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_icl6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_icl6_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 icl6 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_sd\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_sd\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_icl6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_icl6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_icl6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_icl6_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 icl6 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_icl6_s\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_icl6_s\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_icl6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_icl6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_icl6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_icl6_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 bcc DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc_d\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc_d\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_bcc_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_bcc_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_bcc_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_bcc_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 bcc DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_bcc_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_bcc_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_bcc_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_bcc_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 bcc Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc_sd\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc_sd\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_bcc_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_bcc_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_bcc_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_bcc_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 bcc Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_bcc_s\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_bcc_s\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_bcc_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_bcc_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_bcc_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_bcc_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 default DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_d\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_d\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 default DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc6_s.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 default Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_sd\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_sd\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Od /GR /EHsc /W1 /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MDd /GR /EHsc /W1 /Od /I "..\..\src" /Zi /Gm /GZ /Fd..\..\lib\RegExx_vc6_sd.pdb /D "WIN32" /D "_LIB" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NO_MFC" /Fd"..\..\lib\RegExx_vc6_sd.pdb" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc6_sd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc6_sd.lib"

!ELSEIF  "$(CFG)" == "RegExx_lib - Win32 default Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\..\lib"
# PROP BASE Intermediate_Dir "msvc6prj_vc6_s\RegExx_lib"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib\"
# PROP Intermediate_Dir "msvc6prj_vc6_s\RegExx_lib\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /O2 /GR /EHsc /W1 /I "..\..\src" /Fd..\..\lib\RegExx_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD CPP /nologo /FD /MD /GR /EHsc /W1 /O1 /I "..\..\src" /Fd..\..\lib\RegExx_vc6_s.pdb /D "WIN32" /D "_LIB" /D "_MBCS" /D "_LIB" /D "NO_MFC" /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\RegExx_vc6_s.lib"
# ADD LIB32 /nologo /out:"..\..\lib\RegExx_vc6_s.lib"

!ENDIF

# Begin Target

# Name "RegExx_lib - Win32 vc71 DLL Debug"
# Name "RegExx_lib - Win32 vc71 DLL Release"
# Name "RegExx_lib - Win32 vc71 Debug"
# Name "RegExx_lib - Win32 vc71 Release"
# Name "RegExx_lib - Win32 vc70 DLL Debug"
# Name "RegExx_lib - Win32 vc70 DLL Release"
# Name "RegExx_lib - Win32 vc70 Debug"
# Name "RegExx_lib - Win32 vc70 Release"
# Name "RegExx_lib - Win32 vc6 DLL Debug"
# Name "RegExx_lib - Win32 vc6 DLL Release"
# Name "RegExx_lib - Win32 vc6 Debug"
# Name "RegExx_lib - Win32 vc6 Release"
# Name "RegExx_lib - Win32 vc5 DLL Debug"
# Name "RegExx_lib - Win32 vc5 DLL Release"
# Name "RegExx_lib - Win32 vc5 Debug"
# Name "RegExx_lib - Win32 vc5 Release"
# Name "RegExx_lib - Win32 icl7 DLL Debug"
# Name "RegExx_lib - Win32 icl7 DLL Release"
# Name "RegExx_lib - Win32 icl7 Debug"
# Name "RegExx_lib - Win32 icl7 Release"
# Name "RegExx_lib - Win32 icl6 DLL Debug"
# Name "RegExx_lib - Win32 icl6 DLL Release"
# Name "RegExx_lib - Win32 icl6 Debug"
# Name "RegExx_lib - Win32 icl6 Release"
# Name "RegExx_lib - Win32 bcc DLL Debug"
# Name "RegExx_lib - Win32 bcc DLL Release"
# Name "RegExx_lib - Win32 bcc Debug"
# Name "RegExx_lib - Win32 bcc Release"
# Name "RegExx_lib - Win32 default DLL Debug"
# Name "RegExx_lib - Win32 default DLL Release"
# Name "RegExx_lib - Win32 default Debug"
# Name "RegExx_lib - Win32 default Release"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\thirdparty\common\pcre\chartables.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\pcre\get.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\pcre\maketables.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\pcre\pcre.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\pcre\pcreposix.c
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\pcre\study.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\thirdparty\common\pcre\internal.h
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\pcre\pcre.h
# End Source File
# Begin Source File

SOURCE=..\..\src\thirdparty\common\pcre\pcreposix.h
# End Source File
# End Group
# End Target
# End Project

