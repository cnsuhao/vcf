/**
*CVS Log info
*$Log$
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




#ifndef _SKETCHVIEW_H__
#define _SKETCHVIEW_H__

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




#endif //_SKETCHVIEW_H__



