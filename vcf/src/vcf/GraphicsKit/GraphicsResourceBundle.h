

#ifndef _GRAPHICSRESOURCEBUNDLE_H__
#define _GRAPHICSRESOURCEBUNDLE_H__


/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif

namespace VCF {


class Image;
/**
*A ResourceBundle is used to represent a collection of resources. ResourceBundle's can
*be attached to external files or applications.
*/
class GRAPHICSKIT_API GraphicsResourceBundle : public ResourceBundle
{
public:

	virtual ~GraphicsResourceBundle(){};

	/**
	*returns an Image based on a given resource name
	*/
	virtual Image* getImage( const String& resourceName ) = 0;

};


};


#endif //_GRAPHICSRESOURCEBUNDLE_H__






