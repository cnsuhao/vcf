#if     _MSC_VER > 1000
#pragma once
#endif



#ifndef _VCF_BEZIERCURVE_H__
#define _VCF_BEZIERCURVE_H__
/**
Copyright (c) 2000-2001, Jim Crafton
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
	Redistributions of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.

	Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in 
	the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

NB: This software will not save the world.
*/


namespace VCF {

/**
class BezierCurve documentation
*/
class GRAPHICSKIT_API BezierCurve : public VCF::Object, public VCF::Path {
public: 
	BezierCurve();

	virtual ~BezierCurve();
	
	virtual void applyTransform( const Matrix2D& transform );

	virtual bool contains( const Rect& rect);

    virtual bool contains( const Point& pt );

    virtual bool intersects( const Point& pt );

    virtual bool intersects( const Rect& rect );

    virtual Rect getBounds();

    virtual WindingRule getWindingRule() {
		return windingRule_;
	}

	virtual void setWindingRule( WindingRule rule ) {
		windingRule_ = rule;
	}
	
	virtual Enumerator<PathPoint>* getPoints( Matrix2D* transform );

	virtual void flattenPoints( std::vector<Point>& flattenedPoints );

	void curveTo( const double& cx1, const double& cy1,
					const double& cx2, const double& cy2,
					const double& x, const double& y);

	void curve( const double& x1, const double& y1,
					const double& cx1, const double& cy1,
					const double& cx2, const double& cy2,
					const double& x2, const double& y2);

	void lineTo( const double& x, const double& y );

	void moveTo( const double& x, const double& y );
	
	void rectangle( const Rect& rectangle );

	void polyTo( std::vector<Point>& points );

	void polyline( std::vector<Point>& points );

	void close();

	void clear();
protected:		
	Path::WindingRule windingRule_;
	long currentMoveToIndex_;
	std::vector<PathPoint> points_;
	std::vector<PathPoint> transformedPoints_;	
	EnumeratorContainer<std::vector<PathPoint>,PathPoint> pointsContainer_;

};



};


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:40:30  ddiego
*migration towards new directory structure
*
*Revision 1.3.4.1  2004/04/26 21:58:38  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.3  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.2.2.1  2003/10/28 04:06:11  ddiego
*updated the GraphicsContext and ContextPeer classes to support
*slider control drawing. adjusted the Slider control accordingly.
*Also changed some of the GraphicsKit headers to conform to the
*current header style.
*
*Revision 1.2  2003/08/09 02:56:43  ddiego
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
*Revision 1.1.2.1  2003/07/28 23:49:58  ddiego
*check in of the weekend's work from July 25
*learned how to use agg image renedering, now have to integrate it into the
*GraphicsKit - alos enabled setting a viewable bounds that sets the agg cliprect
*as well, useful for later optimizations
*
*/

#endif // _VCF_BEZIERCURVE_H__



