
#ifndef _WIN32GRAPHICSRESOURCEBUNDLE_H__
#define _WIN32GRAPHICSRESOURCEBUNDLE_H__

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif

#include "vcf/FoundationKit/Win32ResourceBundle.h"



namespace VCF  {

class GRAPHICSKIT_API Win32GraphicsResourceBundle : public Win32ResourceBundle, public GraphicsResourceBundle {
public:
	Win32GraphicsResourceBundle();

	virtual ~Win32GraphicsResourceBundle();

	/**
	*returns a resource string given a resource name
	*/
	virtual String getString( const String& resourceName ) {
		return Win32ResourceBundle::getString( resourceName );
	}

	/**
	*returns the text that represents an VFF file (where VFF stands
	*for "Visual Form File" ). This text is standard XML and contains
	*the component hierarchy and properties for creating a frame.
	*/
	virtual String getVFF( const String& resourceName ) {
		return Win32ResourceBundle::getVFF( resourceName );
	}

	/**
	*returns an Image based on a given resource name
	*/
	virtual Image* getImage( const String& resourceName );

	/**
	*returns a Resource object given the resource's name.
	*this function walks through all the app's resources, by type
	*and then by name. The first match is the resource returned.
	*/
	virtual Resource* getResource( const String& resourceName ) {
		return Win32ResourceBundle::getResource( resourceName );
	}
protected:
	
	
};

};










#endif //_WIN32GRAPHICSRESOURCEBUNDLE_H__



