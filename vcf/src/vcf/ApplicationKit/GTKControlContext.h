/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:17  ddiego
*migration towards new directory structure
*
*Revision 1.5.8.1  2004/04/26 21:58:42  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.5  2003/05/17 20:37:11  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.4.2.1  2003/04/17 04:29:48  ddiego
*updated scintilla, added gtk support for the application kit, with stubs
*for the basic peers.
*
*/


#ifndef _VCF_GTKCONTROLCONTEXT_H__
#define _VCF_GTKCONTROLCONTEXT_H__


namespace VCF {

class ControlPeer;

class ControlGraphicsContext;

class Control;

/**

*/
class GTKControlContext : public GTKContext { 
public:

	GTKControlContext( ControlPeer* controlPeer );

	virtual ~GTKControlContext();

	virtual void setContext( GraphicsContext* context );

	Control* getOwningControl();

	virtual void checkHandle();
	
	virtual void releaseHandle();
protected:
	ControlGraphicsContext* owningControlCtx_;	
};


};


#endif // _VCF_GTKCONTROLCONTEXT_H__


