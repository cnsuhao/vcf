//ResourceBundle.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"
#include "vcf/FoundationKit/ResourceBundlePeer.h"


using namespace VCF;


ResourceBundle::ResourceBundle():
	Object(),
	peer_(NULL)
{
	peer_ = SystemToolkit::createResourceBundlePeer();
}

ResourceBundle::~ResourceBundle()
{
	delete peer_;
}

String ResourceBundle::getString( const ulong32& resourceID )
{
	return getString( StringUtils::toString( resourceID ) );
}

String ResourceBundle::getString( const String& resourceName )
{
	return peer_->getString( resourceName );
}

String ResourceBundle::getVFF( const String& resourceName )
{
	return peer_->getVFF( resourceName );
}

Resource* ResourceBundle::getResource( const String& resourceName )
{
	return peer_->getResource( resourceName );
}

ProgramInfo* ResourceBundle::getProgramInfo()
{
	ProgramInfo* result = peer_->getProgramInfo();

	if ( NULL == result ) {

	}

	return result;
}





/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/09/15 21:14:28  ddiego
*added support for getting program info from resource bundle.
*
*Revision 1.1.2.1  2004/08/27 03:50:46  ddiego
*finished off therest of the resource refactoring code. We
*can now load in resoruces either from the burned in data in the .exe
*or from resource file following the Apple bundle layout scheme.
*
*/

