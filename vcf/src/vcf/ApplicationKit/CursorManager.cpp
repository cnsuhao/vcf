/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:16  ddiego
*migration towards new directory structure
*
*Revision 1.4  2003/05/17 20:37:47  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.3.22.2  2003/03/23 03:24:00  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.3.22.1  2003/03/12 03:13:04  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.3  2002/01/24 01:46:50  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

//CursorManager.h
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

#include "vcf/ApplicationKit/ApplicationKit.h"

using namespace VCF;



CursorManager* CursorManager::create()
{
	if ( NULL == CursorManager::cursorMgrInstance ) {
		CursorManager::cursorMgrInstance = new CursorManager();
		CursorManager::cursorMgrInstance->init();
	}

	return CursorManager::cursorMgrInstance;
}


CursorManager* CursorManager::getCursorManager()
{
	return CursorManager::cursorMgrInstance;
}

CursorManager::CursorManager()
{
	cursorIDCount_ = (long)(Cursor::SCT_WAIT) + 1;	
}

CursorManager::~CursorManager()
{
	std::map<long,Cursor*>::iterator it = cursorMap_.begin();
	while ( it != cursorMap_.end() ) {
		Cursor* cursor = it->second;
		delete cursor;
		cursor = NULL;
		it ++;
	}
	cursorMap_.clear();
}

Cursor* CursorManager::getCursor( const long& cursorID )
{
	Cursor* result = NULL;
	std::map<long,Cursor*>::iterator found = cursorMap_.find( cursorID );
	if ( found != cursorMap_.end() ) {
		result = found->second;
	}
	else {
		
		if ( (cursorID >= (long)Cursor::SCT_DEFAULT) && (cursorID <= (long)Cursor::SCT_WAIT) ) {
			result = new Cursor( (Cursor::SystemCursorType)cursorID );
		}
	}

	return result;
}

void CursorManager::registerCursor( Cursor* cursor )
{
	long cursorID = cursor->getCursorID();
	std::map<long,Cursor*>::iterator found = cursorMap_.find( cursorID );
	if ( found == cursorMap_.end() ) {
		//only add the cursor to the map if it isn't already there
		if ( (cursorID == CursorManager::UNREGISTERED_ID) || 
			((cursorID >= Cursor::SCT_DEFAULT) && (cursorID <= Cursor::SCT_WAIT)) ) {
			if ( cursorID == CursorManager::UNREGISTERED_ID ) {
				cursorID = cursorIDCount_;
				cursor->getPeer()->setCursorID( cursorID );
				cursorIDCount_ ++;
			}
			cursorMap_[cursorID] = cursor;
		}
		else {
			//this is bad - somehow the cursor has an ID but is not present in the
			//map - possibly throw an exception ?
		}
	}
}


