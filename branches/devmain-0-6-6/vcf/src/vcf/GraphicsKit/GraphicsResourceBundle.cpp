//GraphicsResourceBundle.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/GraphicsKit/GraphicsKit.h"
#include "vcf/FoundationKit/ResourceBundle.h"
#include "vcf/FoundationKit/ResourceBundlePeer.h"
#include "vcf/GraphicsKit/GraphicsResourceBundlePeer.h"
#include "vcf/GraphicsKit/GraphicsResourceBundle.h"


using namespace VCF;



GraphicsResourceBundle::GraphicsResourceBundle():
	ResourceBundle(),
	graphicsResPeer_(NULL)
{
	delete peer_;
	graphicsResPeer_ = GraphicsToolkit::createGraphicsResourceBundlePeer();
	if ( NULL == graphicsResPeer_ ) {
		//throw exception! Missing peer implementation!
	}

	peer_ = dynamic_cast<ResourceBundlePeer*>( graphicsResPeer_ );
	if ( NULL == peer_ ) {
		//throw exception! Bad peer implementation!
	}
}

GraphicsResourceBundle::~GraphicsResourceBundle()
{

}

Image* GraphicsResourceBundle::getImage( const String& resourceName )
{
	return graphicsResPeer_->getImage( resourceName );
}

Image* GraphicsResourceBundle::getImage( const ulong32& resourceID )
{
	return getImage( StringUtils::toString(resourceID) );
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/08/27 03:50:47  ddiego
*finished off therest of the resource refactoring code. We
*can now load in resoruces either from the burned in data in the .exe
*or from resource file following the Apple bundle layout scheme.
*
*/

