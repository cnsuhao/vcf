# Microsoft Developer Studio Project File - Name="libAGG" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=libAGG - Win32 GTK Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "libAGG.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "libAGG.mak" CFG="libAGG - Win32 GTK Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "libAGG - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libAGG - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "libAGG - Win32 GTK Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "libAGG - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "vc70\Release\"
# PROP Intermediate_Dir "vc70\Release\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O1 /I "$(VCF_INCLUDE)" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"../../../lib/libAGG_vc70_s.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../../../lib/libAGG_vc70_s.lib"

!ELSEIF  "$(CFG)" == "libAGG - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "vc70\Debug\"
# PROP Intermediate_Dir "vc70\Debug\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "$(VCF_INCLUDE)" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /Fd"..\..\..\lib\libAGG_vc70_sd.pdb" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"../../../lib/libAGG_vc70_sd.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../../../lib/libAGG_vc70_sd.lib"

!ELSEIF  "$(CFG)" == "libAGG - Win32 GTK Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "libAGG___Win32_GTK_Debug"
# PROP BASE Intermediate_Dir "libAGG___Win32_GTK_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "vc70\libAGG___Win32_GTK_Debug\"
# PROP Intermediate_Dir "vc70\libAGG___Win32_GTK_Debug\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "$(VCF_INCLUDE)/../thirdparty/common/agg/include/" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "$(VCF_INCLUDE)/../thirdparty/common/agg/include/" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /Fd"..\..\..\lib\libAGG_vc70_sd.pdb" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"../../../lib/libAGG_vc70_sd.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/libAGG_vc70_sd.lib"
# ADD LIB32 /nologo /out:"../../../lib/libAGG_vc70_sd.lib"

!ENDIF 

# Begin Target

# Name "libAGG - Win32 Release"
# Name "libAGG - Win32 Debug"
# Name "libAGG - Win32 GTK Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\..\src\thirdparty\common\agg\src\agg_affine_matrix.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\thirdparty\common\agg\src\agg_bspline.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\thirdparty\common\agg\src\agg_curves.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\thirdparty\common\agg\src\agg_gen_stroke.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\thirdparty\common\agg\src\agg_gsv_text.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\thirdparty\common\agg\src\agg_path_storage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\thirdparty\common\agg\src\agg_rasterizer_scanline_aa.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\thirdparty\common\agg\src\agg_scanline_u8.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# End Target
# End Project
