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

#ifndef _VCF_ABSTRACTCONTAINER_H__
#define _VCF_ABSTRACTCONTAINER_H__


namespace VCF {

class Control;

class ControlEvent;

class MouseEvent;

class GraphicsContext;

class MouseHandler;

class Rect;


/**
AbstractContainer implements the basics of a 
container with the exception of actual layout rules,
therefore resizeChildren is not implemented. It 
isleft to implementers to decide on there own
layout rules for resizeChildren().
It responds to all mouse and paint events
of the Control to which is attached to, and forwards
them correctly to the child controls. This is event
forwarding only takes place if the child control
is a lighweight control.
When the attached control is resized, the AbstractContainer
will detect this as well and call resizeChildren() where 
appropriate.
*/
class APPKIT_API AbstractContainer : public Container, public ObjectWithEvents, 
									public EnumeratorContainer<std::vector<Control*>, Control*>{
public:	
	
	

	AbstractContainer();
	
	virtual ~AbstractContainer();	

	void init();

	virtual void add( Control * child );

    virtual void add( Control * child, const AlignmentType& alignment );

	virtual void remove( Control* child );	

	virtual void paintChildren( GraphicsContext* context );

	virtual Enumerator<Control*>* getChildren();

	virtual unsigned long getChildCount();

	virtual Control* findControl( const String& controlName );

	virtual Control* getControlAtIndex( const ulong32& index );

	virtual long getControlIndex( Control* control );

	virtual void updateTabOrder( Control* child, ulong32& newTabOrder );
	
	virtual void getTabList( std::vector<Control*>& tabList );

	virtual void insertBeforeControl( Control * child, const AlignmentType& alignment, Control* afterControl );	

	virtual void insertAtIndex( Control * child, const AlignmentType& alignment, const ulong32& index );	

	virtual void sendControlToFront( Control* child );

	virtual void sendControlToBack( Control* child );

	virtual void setContainerControl( Control* control );

	virtual Control* getContainerControl(){
		return controlContainer_;
	}
protected:
	std::vector<Control*> controls_;	
	std::map<long,Control*> tabOrderMap_;
	long currentTabControlIndex_;
	Control* controlContainer_;
	EventHandler* controlHandler_;	
	EventHandler* mouseHandler_;	

	void containerResized( ControlEvent* event ); 
	void onMouseEvent( MouseEvent* event ); 
};

};

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:12  ddiego
*migration towards new directory structure
*
*Revision 1.2.4.1  2004/04/26 21:58:17  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.2  2003/12/18 05:15:56  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.1.2.2  2003/09/12 00:09:32  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.1.2.1  2003/08/18 19:52:32  ddiego
*changed the Container from being a class you derive from to a separate
*intance that is created and assigned dynamically to any Control.
*
*/


#endif // _VCF_ABSTRACTCONTAINER_H__

