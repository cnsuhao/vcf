/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:45:50  ddiego
*migration towards new directory structure
*
*Revision 1.8.8.1  2004/04/26 21:58:46  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.8  2003/05/17 20:37:16  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.7.2.2  2003/03/23 03:23:52  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.7.2.1  2003/03/12 03:11:48  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.7  2003/02/26 04:30:42  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.6.14.1  2003/01/08 00:19:48  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.6  2002/05/09 03:10:43  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.5.4.1  2002/04/03 19:37:17  zzack
*include style changed
*
*Revision 1.5  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

/**
*Copyright (c) 2000-2001, Jim Crafton
*All rights reserved.
*Redistribution and use in source and binary forms, with or without
*modification, are permitted provided that the following conditions
*are met:
*	Redistributions of source code must retain the above copyright
*	notice, this list of conditions and the following disclaimer.
*
*	Redistributions in binary form must reproduce the above copyright
*	notice, this list of conditions and the following disclaimer in 
*	the documentation and/or other materials provided with the distribution.
*
*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
*AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
*OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
*PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
*SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*NB: This software will not save the world.
*/

#ifndef _VCF_CLASSSERVERINSTANCE_H__
#define _VCF_CLASSSERVERINSTANCE_H__

// what should this be good for?
// absolutely nothing!
/*namespace VCFNet {
	class SocketEvent;
}*/

namespace VCFRemote {

class Proxy;

class REMOTEKIT_API ClassServerInstance : public VCF::ObjectWithEvents {

public:
	ClassServerInstance();

	virtual ~ClassServerInstance();

	Proxy* createInstance( const VCF::String& className );

	Proxy* createInstanceByClassID( const VCF::String& classID );

	VCF::VariantData* invoke( VCF::OutputStream* marshalledData ); 

	void onDataReceived( VCFNet::SocketEvent* event );
private:
	bool classSvrReturned_;
	char* data_;
	Proxy* newInstanceProxy_;
};

}; //end of namespace VCFRemote

#endif // _VCF_CLASSSERVERINSTANCE_H__


