/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.2  2003/08/09 02:56:45  ddiego
*merge over from the devmain-0-6-1 branch
*Changes
*Features:
*-Added additional implementation to better support the MVC architecture in
*the VCF
*
*-Added a Document/View architecure that is similar to MFC's or NextSteps's
*Doc/View architectures
*
*-Integrated the Anti Grain Graphics library into the GraphicsKit. There is
*now basic support for it in terms of drawing vector shapes
*(fills and strokes). Image support will come in the next release
*
*-Added several documented graphics tutorials
*
*Bugfixes:
*
*[ 775744 ] wrong buttons on a dialog
*[ 585239 ] Painting weirdness in a modal dialog ?
*[ 585238 ] Modal dialog which makes a modal Dialog
*[ 509004 ] Opening a modal Dialog causes flicker
*[ 524878 ] onDropped not called for MLTcontrol
*
*Plus an issue with some focus and getting the right popup window to activate
*has also been fixed
*
*Revision 1.1.2.2  2003/07/21 03:08:30  ddiego
*added bezier curve editing to Sketchit, fixed a bug in not saving
*bitmaps, added PackageInfo to the ApplicationKit
*
*Revision 1.1.2.1  2003/06/16 03:09:39  ddiego
*beginning to add support for AGG into the VCF GraphicsKit
*added some missing files
*added some changes to the new version of xmake
*
*/

/**
*Copyright (c) 2000-2001, Jim Crafton
*All rights reserved.
*Redistribution and use in source and binary forms, with or without
*modification, are permitted provided that the following conditions
*are met:
*	Redistributions of source code must retain the above copyright
*	notice, this list of conditions and the following disclaimer.
*
*	Redistributions in binary form must reproduce the above copyright
*	notice, this list of conditions and the following disclaimer in 
*	the documentation and/or other materials provided with the distribution.
*
*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
*AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
*OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
*PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
*SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*NB: This software will not save the world.
*/

#include "vcf/ApplicationKit/ApplicationKit.h"

using namespace VCF;

PackageInfo::PackageInfo( const String& packageName, const String& packageUUID, 
							const String& staticLibName, const String& sharedLibName,
							long linkageFlags,
							const String& author, const String& company, 
							const String& copyright, const String& additionalInfo)
{
	packageName_ = packageName;
	packageUUID_ = packageUUID;
	author_ = author;
	copyright_ = company;
	company_ = copyright;
	additionalInfo_ = additionalInfo;	
	staticLibName_ = staticLibName;
	sharedLibName_ = sharedLibName;
	linkageFlags_ = linkageFlags;
}

Enumerator<String>* PackageInfo::getRequiredStaticLibs()
{
	return reqStaticLibsContainer_.getEnumerator();
}

void PackageInfo::addRequiredStaticLib( const String& libName )
{
	requiredStaticLibs_.push_back( libName );
}

void PackageInfo::removeRequiredStaticLib( const String& libName )
{
	std::vector<String>::iterator found = 
		std::find( requiredStaticLibs_.begin(), requiredStaticLibs_.end(), libName );
	if ( found != requiredStaticLibs_.end() ) {
		requiredStaticLibs_.erase( found );
	}
}

void PackageInfo::removeAllRequiredStaticLibs()
{
	requiredStaticLibs_.clear();
}

Enumerator<String>* PackageInfo::getRequiredSharedLibs()
{
	return reqSharedLibsContainer_.getEnumerator();
}

void PackageInfo::addRequiredSharedLib( const String& libName )
{
	requiredSharedLibs_.push_back( libName );
}

void PackageInfo::removeRequiredSharedLib( const String& libName )
{
	std::vector<String>::iterator found = 
		std::find( requiredSharedLibs_.begin(), requiredSharedLibs_.end(), libName );
	if ( found != requiredSharedLibs_.end() ) {
		requiredSharedLibs_.erase( found );
	}
}

void PackageInfo::removeAllRequiredSharedLibs()
{
	requiredSharedLibs_.clear();
}

Enumerator<String>* PackageInfo::getSupportedPlatforms()
{
	return supportedPlatformsContainer_.getEnumerator();
}

void PackageInfo::addSupportedPlatform( const String& platform )
{
	supportedPlatforms_.push_back( platform );
}

void PackageInfo::removeSupportedPlatform( const String& platform )
{
	std::vector<String>::iterator found = 
		std::find( supportedPlatforms_.begin(), supportedPlatforms_.end(), platform );
	if ( found != supportedPlatforms_.end() ) {
		supportedPlatforms_.erase( found );
	}
}

void PackageInfo::removeAllSupportedPlatforms()
{
	supportedPlatforms_.clear();
}



