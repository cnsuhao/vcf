/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:45:50  ddiego
*migration towards new directory structure
*
*Revision 1.4  2003/05/17 20:37:51  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.3.16.1  2003/03/23 03:24:02  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.3  2002/05/09 03:10:46  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.2.4.1  2002/04/03 19:37:17  zzack
*include style changed
*
*Revision 1.2  2002/01/24 01:46:50  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

//DistributedException.h
/**
This program is free software; you can redistribute it and/or
modify it as you choose. In fact, you can do anything you would like
with it, so long as credit is given if used in commercial applications.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

NB: This software will not save the world. 
*/
#include "vcf/RemoteObjectKit/RemoteObjectKit.h"

using namespace VCF;

using namespace VCFRemote;


DistributedException::DistributedException():
	BasicException("")
{

}

DistributedException::~DistributedException()
{

}


