//AbstractComponentEditor.h
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
#include "vcf/ApplicationKit/VFFOutputStream.h"

using namespace VCF;


AbstractComponentEditor::AbstractComponentEditor()
{
	commandCount_ = 0;
	defaultCommandIndex_ = 0;
	component_ = NULL;
}

AbstractComponentEditor::~AbstractComponentEditor()
{
	
}

void AbstractComponentEditor::initialize()
{
	if ( NULL != component_ ) {
		component_->setComponentState( Component::csDesigning );
	}
}


Command* AbstractComponentEditor::getCommand( const ulong32& index )
{
	return NULL;
}

void AbstractComponentEditor::setComponent( Component* component )
{
	component_ = component;
}

String AbstractComponentEditor::getComponentVFFFragment()
{
	String result;

	if ( NULL != component_ ) {
		TextOutputStream tos;
		VFFOutputStream vos(&tos);		
		
		vos.writeComponent( component_ );
		result = tos.getTextBuffer();
	}
	else {
		//throw exception here
	}

	return result;
}


/**
*AbstractControlEditor
*/

AbstractControlEditor::AbstractControlEditor()
{

}

AbstractControlEditor::~AbstractControlEditor()
{

}

bool AbstractControlEditor::isParentValid( Control* parent )
{
	return true;
}

Control* AbstractControlEditor::getControl()
{
	return dynamic_cast<Control*>( getComponent() );
}

void AbstractControlEditor::setControl( Control* control )
{
	setComponent( control );
}

void AbstractControlEditor::mouseDown( MouseEvent* event )
{

}

void AbstractControlEditor::mouseMove( MouseEvent* event )
{

}

void AbstractControlEditor::mouseUp( MouseEvent* event )
{

}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:12  ddiego
*migration towards new directory structure
*
*Revision 1.8  2004/04/03 15:48:43  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.7  2004/01/20 01:54:56  ddiego
*merged some more changes from dev branch, primarily changes to
*teh RTTI API so that we now process enum sets correctly (i.e. a long
*that is a mask made of enum values).
*
*Revision 1.6.6.1  2004/01/16 04:30:46  ddiego
*some more minor mods to menus and the Component class. Added some utility
*methods for determining the state of a component, and added two new
*delegates for firing events when the component is loaded and saved,
*as well as value changes for the COmponentState enum so that some of
*the values of the component state can be OR'd together.
*
*Revision 1.6  2003/05/17 20:37:43  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.5.2.2  2003/03/23 03:23:59  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.5.2.1  2003/03/12 03:12:53  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.5  2003/02/26 04:30:53  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.4.14.1  2003/01/08 00:19:56  marcelloptr
*mispellings and newlines at the end of all source files
*
*Revision 1.4  2002/05/09 03:10:45  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.3.4.2  2002/04/27 15:52:36  ddiego
*Changed a bunch of files include and made it a bit faster and added better include
*guards in the common headers
*
*Revision 1.3.4.1  2002/04/08 20:55:31  zzack
*changed include style
*
*Revision 1.3  2002/02/14 05:04:52  ddiego
*documentation...
*
*Revision 1.2  2002/01/24 01:46:50  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/



