//ColorEtchedBorder.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ColorEtchedBorder.h"

using namespace VCF;


ColorEtchedBorder::ColorEtchedBorder()
{

}

void ColorEtchedBorder::paint( Control* control, GraphicsContext* context )
{
	EtchedBorder::paint( control, context );
}

void ColorEtchedBorder::paint( Rect* bounds, GraphicsContext* context )
{

}

Rect ColorEtchedBorder::getClientRect( Control* control )
{
	Rect result;
	return result;
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 03:43:12  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:14  ddiego
*migration towards new directory structure
*
*Revision 1.4  2003/05/17 20:37:21  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.3.2.1  2003/03/23 03:23:55  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.3  2003/02/26 04:30:46  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.2.2.1  2002/12/27 23:04:46  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.2  2002/11/18 00:46:09  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.1.2.1  2002/10/01 20:34:59  ddiego
*borders
*
*/


