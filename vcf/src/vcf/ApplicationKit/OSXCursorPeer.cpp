
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
#include "ApplicationKit.h"
#include "ApplicationKitPrivate.h"
#include "implementerKit/OSXCursorPeer.h"


using namespace VCF;

OSXCursorPeer::OSXCursorPeer( Cursor* cursor ):
	cursorID_(CursorManager::UNREGISTERED_ID),
	cursor_(cursor),
    cursorHandle_(0)
{
    cursorHandle_ = GetCCursor(0);
}

OSXCursorPeer::~OSXCursorPeer()
{
    if( NULL != cursorHandle_ ) {
        DisposeCCursor( cursorHandle_ );
    }
}

void OSXCursorPeer::createFromImage( Image* cursorImage, Point* hotSpot )
{
	
}

void OSXCursorPeer::createSystemCursor( const Cursor::SystemCursorType& systemCursor )
{
	
	cursorID_ = (long)systemCursor;
	switch ( systemCursor ) {
		case Cursor::SCT_DEFAULT : {
			//id = GDK_LEFT_PTR;
		}
		break;

		case Cursor::SCT_SPLIT_VERT : {
			//id = GDK_SB_V_DOUBLE_ARROW;
		}
		break;

		case Cursor::SCT_SPLIT_HORZ : {
			//id = GDK_SB_H_DOUBLE_ARROW;
		}
		break;

		case Cursor::SCT_SIZE_HORZ : {
			//id = GDK_SB_H_DOUBLE_ARROW;
		}
		break;

		case Cursor::SCT_SIZE_VERT : {
			//id = GDK_SB_V_DOUBLE_ARROW;
		}
		break;

		case Cursor::SCT_SIZE_NE_SW : {
			//id = GDK_TOP_LEFT_ARROW;
		}
		break;

		case Cursor::SCT_SIZE_NW_SE : {
			//id = GDK_TOP_RIGHT_CORNER;
		}
		break;

		case Cursor::SCT_TEXT : {
			//id = GDK_XTERM;
		}
		break;

		case Cursor::SCT_HELP : {
			//id = GDK_QUESTION_ARROW;
		}
		break;

		case Cursor::SCT_WAIT : {
			//id = GDK_WATCH;
		}
		break;

		case Cursor::SCT_WAITING : {
			//id = GDK_WATCH;
		}
		break;

		case Cursor::SCT_NOWAYHOSER : {
			//id = GDK_X_CURSOR;
		}
		break;

		case Cursor::SCT_CROSSHAIRS : {
			//id = GDK_CROSSHAIR;
		}
		break;
		
		case Cursor::SCT_POINTING_HAND : {
			//id = GDK_HAND2;
		}
		break;		
	}		
	
	
}

void OSXCursorPeer::createFromResourceName( const String& cursorName, const ulong32& instanceHandle )
{
	
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.3  2004/04/30 05:44:33  ddiego
*added OSX changes for unicode migration
*
*Revision 1.2  2004/04/03 15:48:47  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.1.2.1  2004/02/24 01:42:44  ddiego
*initial OSX ApplicationKit port checkin
*
*/




