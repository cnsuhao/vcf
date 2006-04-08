#ifndef _VCF_FILL_H__
#define _VCF_FILL_H__
//Fill.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */




namespace VCF{


class GraphicsContext;
class Path;

/**
\class Fill Fill.h "vcf/GraphicsKit/Fill.h"
The Fill class is a high level class used to fill in a Path. A fill is
set on the current graphics context, and then a path is drawn.
\code
Fill* myFill = new MyFill();
GraphicsContext* ctx = getSomeGraphiceContext();//imaginary function to get a graphics context

Path* path = getSomePath();//imaginary function to get a path

//sets the fill
ctx->setCurrrentFill( myFill );

//draws the path!
ctx->draw( path );

delete myFill;
delete path;

\endcode

See the StrokesAndFills example (in vcf/examples/StrokesAndFills ) for a more
complete example of this.


The interface is quite simple, and more concrete details are completely up to the 
implement of the interface.
@see BasicFill
@see GraphicsContext
@see Path
*/
class GRAPHICSKIT_API Fill : public Interface{
public:

	virtual ~Fill(){};

	/**
	sets the context for the fill. The GraphicsContext will
	call this when the GraphicsContext::setCurrrentFill() method is 
	called.
	*/
	virtual void setContext( GraphicsContext* context ) = 0;

	/**
	renders the fill using the current path. The fill can retrieve the points for the
	path by calling either Path::getPoints() or Path::flattenPoints().
	*/
    virtual void render( Path* path ) = 0;
};

};


/**
*CVS Log info
*$Log$
*Revision 1.4  2006/04/07 02:35:41  ddiego
*initial checkin of merge from 0.6.9 dev branch.
*
*Revision 1.3.4.2  2006/03/26 22:37:35  ddiego
*minor update to source docs.
*
*Revision 1.3.4.1  2006/03/12 22:42:08  ddiego
*more doc updates - specific to graphicskit.
*
*Revision 1.3  2004/12/02 04:11:10  ddiego
*removed some old, extraneous files from graphics kit dir.
*
*Revision 1.2  2004/08/07 02:49:17  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.2  2004/04/29 04:10:26  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.8.4.1  2004/04/26 21:58:39  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.8  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.7.4.1  2003/10/28 04:06:11  ddiego
*updated the GraphicsContext and ContextPeer classes to support
*slider control drawing. adjusted the Slider control accordingly.
*Also changed some of the GraphicsKit headers to conform to the
*current header style.
*
*Revision 1.7  2003/05/17 20:37:09  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.6.10.1  2003/03/23 03:23:48  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.6  2002/09/12 03:26:04  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.5.12.1  2002/08/06 02:57:35  ddiego
*added base X11 files for GraphicsKit and made sure that the GraphicsKit compiles
*under linux (GCC). There is now a new dir under build/xmake called GraphicsKit
*where the xmake build script lives. This checkin also includes the base X11
*include (as part of GraphicsKitPrivate.h), as well as linking to the X11 libs
*
*Revision 1.5  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_FILL_H__


