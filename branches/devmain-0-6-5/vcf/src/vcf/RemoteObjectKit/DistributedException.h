/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:45:50  ddiego
*migration towards new directory structure
*
*Revision 1.4.24.1  2004/04/26 21:58:46  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.4  2002/05/09 03:10:43  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.3.4.1  2002/04/03 19:37:17  zzack
*include style changed
*
*Revision 1.3  2002/01/24 01:46:48  ddiego
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

#ifndef _VCF_DISTRIBUTEDEXCEPTION_H__
#define _VCF_DISTRIBUTEDEXCEPTION_H__




namespace VCFRemote  {

/**
*Class DistributedException documentation
*/
class REMOTEKIT_API DistributedException : public VCF::BasicException { 
public:
	DistributedException();

	virtual ~DistributedException();

protected:

private:
};


}; //end of namespace VCFRemote

#endif // _VCF_DISTRIBUTEDEXCEPTION_H__


