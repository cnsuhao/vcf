/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:45:48  ddiego
*migration towards new directory structure
*
*Revision 1.5  2003/05/17 20:37:50  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.4.16.1  2003/03/23 03:24:01  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.4  2002/05/09 03:10:46  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.3.4.1  2002/03/22 17:32:31  zzack
*changed to new include style
*
*Revision 1.3  2002/01/24 01:46:50  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

// ServerSocketEvent.cpp

#include "vcf/NetworkKit/NetworkKit.h"

using namespace VCFNet;
using namespace VCF;

ServerSocketEvent::ServerSocketEvent( Object* source ):
	Event( source )
{

}

ServerSocketEvent::~ServerSocketEvent()
{

}


