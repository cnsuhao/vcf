//Rect.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


/* Generated by Together */
#include "vcf/GraphicsKit/GraphicsKit.h"

using namespace VCF;


VCF::Rect::Rect( const Rect& rect ):
    Object(rect),
    Persistable( rect )
{
	setRect( rect.left_, rect.top_, rect.right_, rect.bottom_ );
}

void VCF::Rect::normalize()
{
	double tmp;
	if ( left_ > right_ ) {
		tmp = left_;
		left_ = right_;
		right_ = tmp;
	}

	if ( top_ > bottom_ ) {
		tmp = top_;
		top_ = bottom_;
		bottom_ = tmp;
	}
}

bool VCF::Rect::containsPt( Point * point ) const
{
	bool result = false;
	if ( (point->x_ >= left_) && (point->y_ >= top_) &&
	     (point->x_ < right_) && (point->y_ < bottom_) ){
		result = true;
	}
	return result;
}

bool VCF::Rect::containsPtCloseTo( Point * point, const double& tolerance ) const
{
	bool result = false;
	if ( (point->x_ >= left_-tolerance) && (point->y_ >= top_-tolerance) &&
	     (point->x_ <= right_+tolerance) && (point->y_ <= bottom_+tolerance) ){
		result = true;
	}
	return result;
}

bool VCF::Rect::containsPtOpen( Point * point ) const
{
	bool result = false;
	if ( (point->x_ > left_) && (point->y_ > top_) &&
	     (point->x_ < right_) && (point->y_ < bottom_) ){
		result = true;
	}
	return result;
}

bool VCF::Rect::containsPtClose( Point * point ) const
{
	bool result = false;
	if ( (point->x_ >= left_) &&  (point->y_ >= top_) &&
	     (point->x_ <= right_) &&  (point->y_ <= bottom_) ){
		result = true;
	}
	return result;
}

bool VCF::Rect::containsRect( Rect* rect ) const
{
	bool result = false;

	if ( (left_ <= rect->left_) && (top_ <= rect->top_) && (right_ > rect->right_) && (bottom_ > rect->bottom_) ) {
		result = true;
	}

	return result;
}

bool VCF::Rect::containsRectOpen( Rect* rect ) const
{
	bool result = false;

	if ( (left_ < rect->left_) && (top_ < rect->top_) && (right_ > rect->right_) && (bottom_ > rect->bottom_) ) {
		result = true;
	}

	return result;
}

bool VCF::Rect::containsRectClose( Rect* rect ) const
{
	bool result = false;

	if ( (left_ <= rect->left_) && (top_ <= rect->top_) && (right_ >= rect->right_) && (bottom_ >= rect->bottom_) ) {
		result = true;
	}

	return result;
}

String VCF::Rect::toString() const
{
	String result = "";

	char tmp[256];
	memset(tmp, 0, 256 );
	sprintf( tmp, "%.3f,%.3f,%.3f,%.3f", left_, top_, right_, bottom_ );

	result = tmp;

	return result;
}

void VCF::Rect::saveToStream( OutputStream * stream )
{
	stream->write( left_ );
	stream->write( top_ );
	stream->write( right_ );
	stream->write( bottom_ );
}

void VCF::Rect::loadFromStream( InputStream * stream )
{
	stream->read( left_ );
	stream->read( top_ );
	stream->read( right_ );
	stream->read( bottom_ );
}

void VCF::Rect::add( const Rect* rect )
{
	left_   = VCF::minVal<double>( left_, rect->left_ );

	top_    = VCF::minVal<double>( top_, rect->top_ );

	right_  = VCF::maxVal<double>( right_, rect->right_ );

	bottom_ = VCF::maxVal<double>( bottom_, rect->bottom_ );

}

void VCF::Rect::subtract( const Rect* rect )
{
	bool rectWider = false;
	bool rectTaller = false;

	if ( (rect->left_ <= left_) && (rect->right_ >= right_)) {
		// rect is larger than *this, so let's cut the vertical dimension
		rectWider = true;
	}

	if ( (rect->top_ <= top_) && (rect->bottom_ >= bottom_)) {
		// rect is larger than *this, so let's cut the horizontal dimension
		rectTaller = true;
	}

	if ( rectWider && rectTaller ) {
		setRect( 0.0, 0.0, 0.0, 0.0);
		return;
	}

	if ( rectWider ) {
		if ( (top_ < rect->top_) && (bottom_ > rect->bottom_) ) {
			// rect would split *this: let's leave *this unchanged
			return;
		} else {
			if ( top_ < rect->top_ ) {
				// top of rect becomes bottom ot *this
				bottom_ = rect->top_;
			}
			if ( bottom_ > rect->bottom_ ) {
				// bottom of rect becomes top ot *this
				top_ = rect->bottom_;
			}
		}
	}

	if ( rectTaller )
	{
		if ( (left_ < rect->left_) && (right_ > rect->right_) ) {
			// rect would split *this: let's leave *this unchanged
			return;
		} else {
			if ( left_ < rect->left_ ) {
				// left of rect becomes right ot *this
				right_ = rect->left_;
			}
			if ( right_ > rect->right_ ) {
				// right of rect becomes left ot *this
				left_ = rect->right_;
			}
		}
	}
}

Rect VCF::Rect::makeIntersection( const Rect* rect )
{
	Rect result;

	bool horzIntersect = false;
	bool vertIntersect = false;

	if ( ((left_ < rect->left_) && (right_ > rect->left_)) ||
				((rect->left_ < left_ ) && (rect->right_ > left_)) ) {
		horzIntersect = true;
	}

	if ( ((top_ < rect->top_) && (bottom_ > rect->top_)) ||
				((rect->top_ < top_ ) && (rect->bottom_ > top_)) ) {
		vertIntersect = true;
	}

	if ( vertIntersect && horzIntersect ) {

		result.left_ = maxVal<double>( left_, rect->left_ );
		result.right_ = minVal<double>( right_, rect->right_ );

		result.top_ = maxVal<double>( top_, rect->top_ );
		result.bottom_ = minVal<double>( bottom_, rect->bottom_ );

	}

	return result;
}

Rect VCF::Rect::makeUnion( const Rect* rect )
{
	Rect result;

	throw NotImplementedException();

	return result;
}



/**
*CVS Log info
*$Log$
*Revision 1.2.2.2  2004/10/26 06:12:16  marcelloptr
*bugfix [1045603] forgotten const in Point and Rect; better formatting and documentation
*
*Revision 1.2  2004/08/07 02:49:18  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.2  2004/04/29 04:10:27  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 18:42:26  ddiego
*migrating over changes for unicode strings.
*This contains fixes for the linux port and changes to the Makefiles
*
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.16  2004/04/03 16:09:31  ddiego
*Found some more merge issues that needing resolving.
*
*Revision 1.15  2003/08/09 02:56:45  ddiego
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
*Revision 1.14.2.1  2003/05/30 04:13:11  ddiego
*added the commandLine class
*changed the intialization functions for teh FoundationKit, GraphicsKit, and
*ApplicationKit to take command line parameters
*FoundationKit now allows you to retreive the commandline (it's stored)
*start up has changed from appMain() to main()
*added a custom GTK widget class for use in the various GTK peers - this will
*allow us to specify absolute positioning and let the VCF handle layout
*issues
*Miscellaneous clean in various interfaces
*removed the Rect, Point, and Size classes from the FoundationKit
*and moved them to the GraphicsKit
*
*Revision 1.14  2003/05/17 20:37:49  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.13.2.4  2003/05/15 03:01:03  ddiego
*added initial osx source( FoundationKit only),
*plus some fixes to compile under GCC 3.x compilers
*
*Revision 1.13.2.3  2003/05/13 03:57:13  ddiego
*cleaned up the GraphicsKit, got rid of some old crap files, cleaned
*up the ContextPeer so that tehre are fewer methods to implement, and
*moved the repetitive fillPath and strokePath code that was copied into
*all the context peers back into the GraphicsContext where it belongs
*
*Revision 1.13.2.2  2003/03/23 03:24:01  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.13.2.1  2003/03/12 03:13:20  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.13  2003/02/26 04:30:57  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.12.14.4  2003/01/19 20:18:21  ddiego
*changes to try and optimize painting. didn't work for this go around :(
*
*Revision 1.12.14.3  2002/12/28 21:51:20  marcelloptr
*Fixes and improvements for WM_COPYDATA, Point, Rect, Size, GraphicsContext and StringUtils
*
*Revision 1.12.14.2  2002/12/27 23:05:08  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.12.14.1  2002/11/28 05:12:05  ddiego
*modifications to allow the VCF to compile with MinGW. This also cleans up
*some warnings with GCC - should improve the linux side as well.
*In addition this checkin includes new files for building the VCF under
*the DevC++ IDE. these are in the vcf/build/devcpp directory.
*
*Revision 1.12  2002/05/09 03:10:46  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.11  2002/03/21 04:01:22  ddiego
*fixed [ 532894 ] bug using the Frame::setClientBounds()
*
*Revision 1.10.4.1  2002/03/20 21:53:02  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.10  2002/03/04 05:11:43  ddiego
*fixes for bug [ 525232 ] TreeListControl no multi select
*
*Revision 1.9  2002/01/24 01:46:50  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


