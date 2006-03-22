#ifndef _VCF_SKETCHVIEW_H__
#define _VCF_SKETCHVIEW_H__
//SketchView.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


#define SKETCHVIEW_CLASSID		"f297d0f2-4ece-4fb7-86ef-bea8b395e4af"
/**
class SketchView documentation
*/
class SketchView : public VCF::Object, public VCF::AbstractView {
public:
	BEGIN_CLASSINFO( SketchView, "SketchView", "VCF::Object", SKETCHVIEW_CLASSID )
	END_CLASSINFO( SketchView )

	SketchView();
	virtual ~SketchView();

	virtual void paintView( VCF::GraphicsContext* ctx );
protected:

};


/**
*CVS Log info
*$Log$
*Revision 1.2.6.3  2004/04/29 03:40:56  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.2  2003/08/09 02:56:42  ddiego
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
*Revision 1.1.2.2  2003/07/28 23:49:58  ddiego
*check in of the weekend's work from July 25
*learned how to use agg image renedering, now have to integrate it into the
*GraphicsKit - alos enabled setting a viewable bounds that sets the agg cliprect
*as well, useful for later optimizations
*
*Revision 1.1.2.1  2003/07/17 03:02:46  ddiego
*added sketch example
*
*/


#endif // _VCF_SKETCHVIEW_H__

