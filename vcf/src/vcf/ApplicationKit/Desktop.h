#if     _MSC_VER > 1000
#pragma once
#endif


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
//Desktop.h

#ifndef _VCF_DESKTOP_H__
#define _VCF_DESKTOP_H__





namespace VCF  {

class GraphicsContext;

class DesktopPeer;

/**
*Class Desktop 
*the desktop represents the Windowing systems bottom most
*and is usuall the first window the User sees when the system starts
*up. The Desktop is also sometimes refered to as the Shell, as in
*MS Windows. A desktop may or may not allow files, i.e. it in fact is 
*an actual location on the filesystem 
*/
class APPKIT_API Desktop : public VCF::Object { 
public:
	static Desktop* create();

	Desktop();

	virtual ~Desktop();

	GraphicsContext* getContext() {
		return context_;
	}

	/**
	*Prepares the desktop for painting.
	*MUST be called before calling getContext(), or errors
	*may occur
	*@param Rect* specifies an optional rectangular region to clip 
	*the drawing to. The rectangles coords are screen coords.
	*/
	void beginPainting( Rect* clippingRect = NULL);

	/**
	*called after finished painting on the desktop 
	*allows for native Windowing system cleanup to happen
	*/
	void endPainting();

	bool supportsVirtualDirectories();


	bool hasFileSystemDirectory();

	String getDirectory();		

	DesktopPeer* getDesktopPeer() {
		return peer_;
	}

	static Desktop* getDesktop() {
		return Desktop::desktopInstance;
	}

	ulong32 getWidth();
	
	ulong32 getHeight();

	Rect getUsableBounds();

	/**
	*called by the UIToolkit. repeated calls after the first initialization
	*do nothing
	*/
	void init();
protected:
	

	static Desktop* desktopInstance;
	GraphicsContext* context_;
	bool paintingInitialized_;
	DesktopPeer* peer_;
private:
};


}; //end of namespace VCF




/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:16  ddiego
*migration towards new directory structure
*
*Revision 1.13.4.1  2004/04/26 21:58:19  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.13  2003/12/18 05:15:57  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.12.4.2  2003/09/21 04:15:34  ddiego
*moved the cvs info data to teh bottom of the header instead of the
*top so it is easier to get to the actual header class declarations
*instead of having to wade through all the cvs info stuff.
*
*Revision 1.12.4.1  2003/09/12 00:09:32  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.12  2003/05/17 20:37:03  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.11.22.2  2003/04/17 04:29:45  ddiego
*updated scintilla, added gtk support for the application kit, with stubs
*for the basic peers.
*
*Revision 1.11.22.1  2003/03/12 03:09:33  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.11  2002/01/24 01:46:47  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

#endif // _VCF_DESKTOP_H__


