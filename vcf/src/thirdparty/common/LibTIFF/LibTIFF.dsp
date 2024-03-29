# Microsoft Developer Studio Project File - Name="LibTIFF" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=LibTIFF - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "LibTIFF.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "LibTIFF.mak" CFG="LibTIFF - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LibTIFF - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibTIFF - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "LibTIFF - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "vc6\Release\"
# PROP Intermediate_Dir "vc6\Release\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O1 /I "$(VCF_ROOT)/src" /I "../libtiff/libtiff" /I "../zlib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FD /c
# SUBTRACT CPP /YX /FR
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"../../../../lib/LibTIFF_vc6_s.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../../../../lib/LibTIFF_vc6_s.lib"

!ELSEIF  "$(CFG)" == "LibTIFF - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "vc6\Debug\"
# PROP Intermediate_Dir "vc6\Debug\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "$(VCF_ROOT)/src" /I "../libtiff/libtiff" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /Fd"..\..\..\..\lib\LibTIFF_vc6_sd.pdb" /FD /GZ /c
# SUBTRACT CPP /YX /FR
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"../../../../lib/LibTIFF_vc6_sd.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../../../../lib/LibTIFF_vc6_sd.lib"

!ENDIF 

# Begin Target

# Name "LibTIFF - Win32 Release"
# Name "LibTIFF - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=tif_aux.c
# End Source File
# Begin Source File

SOURCE=tif_close.c
# End Source File
# Begin Source File

SOURCE=tif_codec.c
# End Source File
# Begin Source File

SOURCE=tif_color.c
# End Source File
# Begin Source File

SOURCE=tif_compress.c
# End Source File
# Begin Source File

SOURCE=tif_dir.c
# End Source File
# Begin Source File

SOURCE=tif_dirinfo.c
# End Source File
# Begin Source File

SOURCE=tif_dirread.c
# End Source File
# Begin Source File

SOURCE=tif_dirwrite.c
# End Source File
# Begin Source File

SOURCE=tif_dumpmode.c
# End Source File
# Begin Source File

SOURCE=tif_error.c
# End Source File
# Begin Source File

SOURCE=tif_extension.c
# End Source File
# Begin Source File

SOURCE=tif_fax3.c
# End Source File
# Begin Source File

SOURCE=tif_fax3sm.c
# End Source File
# Begin Source File

SOURCE=tif_flush.c
# End Source File
# Begin Source File

SOURCE=tif_getimage.c
# End Source File
# Begin Source File

SOURCE=tif_jpeg.c
# End Source File
# Begin Source File

SOURCE=tif_luv.c
# End Source File
# Begin Source File

SOURCE=tif_lzw.c
# End Source File
# Begin Source File

SOURCE=tif_next.c
# End Source File
# Begin Source File

SOURCE=tif_ojpeg.c
# End Source File
# Begin Source File

SOURCE=tif_open.c
# End Source File
# Begin Source File

SOURCE=tif_packbits.c
# End Source File
# Begin Source File

SOURCE=tif_pixarlog.c
# End Source File
# Begin Source File

SOURCE=tif_predict.c
# End Source File
# Begin Source File

SOURCE=tif_print.c
# End Source File
# Begin Source File

SOURCE=tif_read.c
# End Source File
# Begin Source File

SOURCE=tif_stream.cxx
# End Source File
# Begin Source File

SOURCE=tif_strip.c
# End Source File
# Begin Source File

SOURCE=tif_swab.c
# End Source File
# Begin Source File

SOURCE=tif_thunder.c
# End Source File
# Begin Source File

SOURCE=tif_tile.c
# End Source File
# Begin Source File

SOURCE=tif_version.c
# End Source File
# Begin Source File

SOURCE=tif_warning.c
# End Source File
# Begin Source File

SOURCE=tif_write.c
# End Source File
# Begin Source File

SOURCE=tif_zip.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=t4.h
# End Source File
# Begin Source File

SOURCE=tif_dir.h
# End Source File
# Begin Source File

SOURCE=tif_fax3.h
# End Source File
# Begin Source File

SOURCE=tif_predict.h
# End Source File
# Begin Source File

SOURCE=tiff.h
# End Source File
# Begin Source File

SOURCE=tiffconf.h
# End Source File
# Begin Source File

SOURCE=tiffio.h
# End Source File
# Begin Source File

SOURCE=tiffiop.h
# End Source File
# Begin Source File

SOURCE=uvcode.h
# End Source File
# End Group
# End Target
# End Project
