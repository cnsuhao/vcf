/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:45:48  ddiego
*migration towards new directory structure
*
*Revision 1.5.8.1  2004/04/26 21:58:45  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.5  2003/05/17 20:37:15  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.4.22.1  2003/03/23 03:23:52  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.4  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

// URL.h

#ifndef _VCF_URL_H__
#define _VCF_URL_H__


namespace VCFNet
{

class NETKIT_API URL : public VCF::Object  
{
public:
	URL();

	virtual ~URL();

};


};

#endif // _VCF_URL_H__


