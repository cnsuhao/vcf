/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:21  ddiego
*migration towards new directory structure
*
*Revision 1.3.8.1  2004/04/26 21:58:44  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.3  2003/05/17 20:37:13  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.2.2.1  2003/03/12 03:11:38  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.2  2003/02/26 04:30:41  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.1.2.2  2003/01/16 04:46:37  ddiego
*added support for default X11 cursors
*added support for translating coordinates from screen to client
*and client to screen, where  the screen is the RootWindow
*
*Revision 1.1.2.1  2002/12/30 03:59:25  ddiego
*more X11 porting code. Now have X11UIToolkit::runEventLoop partially implemented
*Can create and paint in a Window object! Woo hoo!
*Color class is crurently broken on linux, will fix pronto
*
*Auto generated header for class X11Cursor
*/


#ifndef _VCF_X11CURSOR_H__
#define _VCF_X11CURSOR_H__



namespace VCF {
	
/**

*/
class X11Cursor : public Object, public CursorPeer { 
public:

	X11Cursor( Cursor* cursor );

	virtual ~X11Cursor();
	
	virtual ulong32 getCursorHandleID(){
		return (ulong32)xCursor_;
	}

	virtual void createFromImage( Image* cursorImage, Point* hotSpot );

	virtual void createSystemCursor( const Cursor::SystemCursorType& systemCursor );

	virtual void createFromResourceName( const String& cursorName, const ulong32& instanceHandle=0 );

	virtual long getCursorID() {
		return cursorID_;
	}

	virtual void setCursorID( const long& cursorID ) {
		cursorID_ = cursorID;
	}	

	virtual Cursor* getCursor() {
		return  cursor_;
	}

	virtual void setCursor( Cursor* cursor ) {
		cursor_ = cursor;
	}
protected:

	bool isSharedCursor_;
	
	long cursorID_;
	Cursor* cursor_;
	xLib::Cursor xCursor_;	
};


};


#endif // _VCF_X11CURSOR_H__


