# Microsoft Developer Studio Project File - Name="GraphicsKitGtk" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=GraphicsKitGtk - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GraphicsKit-gtk.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GraphicsKit-gtk.mak" CFG="GraphicsKitGtk - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GraphicsKitGtk - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "GraphicsKitGtk - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GraphicsKitGtk - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release\"
# PROP Intermediate_Dir "Release\"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "GraphicsKitGtk_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "GraphicsKitGtk_EXPORTS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386 /out:"..\..\..\bin\GraphicsKit_gtk_vc70.dll" /debug /libpath:"..\..\..\lib"
# SUBTRACT LINK32

!ELSEIF  "$(CFG)" == "GraphicsKitGtk - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\lib\"
# PROP Intermediate_Dir "Debug\"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "GraphicsKitGtk_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "$(VCF_INCLUDE)" /D "VCF_GTK" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "USE_FRAMEWORK_DLL" /D "GRAPHICSKIT_DLL" /D "GRAPHICSKIT_EXPORTS" /YX"GraphicsKit.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib gtk-win32-2.0.lib gdk-win32-2.0.lib atk-1.0.lib gdk_pixbuf-2.0.lib pangowin32-1.0.lib pango-1.0.lib gobject-2.0.lib gmodule-2.0.lib glib-2.0.lib intl.lib iconv.lib /nologo /dll /machine:I386 /out:"..\..\..\bin\GraphicsKit_gtk_vc70_d.dll" /debug /pdbtype:sept /libpath:"..\..\..\lib"
# SUBTRACT LINK32

!ENDIF 

# Begin Target

# Name "GraphicsKitGtk - Win32 Release"
# Name "GraphicsKitGtk - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\..\src\Graphics\AbstractImage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\BasicFill.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\BasicStroke.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\graphics\BezierCurve.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\Color.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\Font.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\GlyphCollection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\GraphicsContext.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\graphics\GraphicsKit.cpp

!IF  "$(CFG)" == "GraphicsKitGtk - Win32 Release"

!ELSEIF  "$(CFG)" == "GraphicsKitGtk - Win32 Debug"

# ADD CPP /Yc"GraphicsKit.h"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\Utils\GraphicsToolKit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Events\ImageEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\Matrix2D.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\MgcBezierCurve2.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\MgcCurve2.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\MgcIntegrate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\MgcMath.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\MgcSingleCurve2.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\MgcVector2.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\core\Point.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\core\Rect.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\Graphics\Vector2D.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\..\include\graphics\AbstractImage.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\AlphaGamma.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\BasicFill.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\BasicRectangle.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\BasicStroke.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\BezierCurve.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Circle.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\ClippingRegion.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Color.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\implementer\Contextpeer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Curve.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Ellipse.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Fill.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Filter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Font.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\FontPeer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Glyph.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\GlyphCollection.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\GraphicsContext.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\GraphicsKitGtk.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\GraphicsObject.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\GraphicsResourceMgr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\utils\GraphicsToolKit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Image.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\ImageBits.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\ImageList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\ImageLoader.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\exceptions\ImageLoaderException.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Matrix2D.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Path.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\core\Point.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\core\Rect.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\core\Size.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Stroke.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\graphics\Vector2D.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "Peers"

# PROP Default_Filter "*.cpp;*.h"
# Begin Source File

SOURCE=..\..\..\src\ImplementerKit\GTKContext.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\implementerKit\GTKContext.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\ImplementerKit\GTKFont.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\implementerKit\GTKFont.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\ImplementerKit\GTKGraphicsToolkit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\implementerKit\GTKGraphicsToolkit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\ImplementerKit\GTKImage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\include\implementerKit\GTKImage.h
# End Source File
# End Group
# End Target
# End Project
