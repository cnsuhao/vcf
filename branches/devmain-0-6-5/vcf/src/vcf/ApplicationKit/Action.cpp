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

//Action.cpp

#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/Action.h"
#include "vcf/ApplicationKit/ActionEvent.h"


using namespace VCF;


Action::Action()
{
	targetsContainer_.initContainer(targets_);
}

Action::Action( Component* owner ):
	Component(owner)
{
	targetsContainer_.initContainer(targets_);
}

Action::Action( const String& name, Component* owner ):
	Component(name, owner)
{
	targetsContainer_.initContainer(targets_);
}

Action::Action( const String& name ):
	Component(name)
{
	targetsContainer_.initContainer(targets_);
}

Action::~Action()
{

}


void Action::update()
{
	ActionEvent event( this, Action::UpdateEvent );

	Update.fireEvent( &event );


	std::vector<Component*>::iterator it = targets_.begin();

	while ( it != targets_.end() ) {
		(*it)->handleEvent( &event );
		it ++;
	}
}

void Action::perform( Event* event )
{
	if ( NULL != event ) {
		Performed.fireEvent( event );
	}
	else {
		ActionEvent e( this, Action::ActionPerformedEvent );
		Performed.fireEvent( &e );
	}
}

void Action::addTarget( Component* target )
{
	std::vector<Component*>::iterator found = std::find( targets_.begin(), targets_.end(), target );
	//don't allow duplicate entries
	if ( found == targets_.end() ) {
		targets_.push_back( target );
		target->setAction( this );
	}
}

void Action::removeTarget( Component* target )
{
	std::vector<Component*>::iterator found = std::find( targets_.begin(), targets_.end(), target );
	
	if ( found != targets_.end() ) {
		targets_.erase( found );
	}
}

Enumerator<Component*>* Action::getTargets()
{
	return targetsContainer_.getEnumerator();
}

unsigned long Action::getTargetCount()
{
	return targets_.size();
}




/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:13  ddiego
*migration towards new directory structure
*
*Revision 1.2  2003/12/18 05:16:00  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.1.2.2  2003/12/13 15:56:08  ddiego
**** empty log message ***
*
*Revision 1.1.2.1  2003/12/02 05:50:05  ddiego
*added preliminary support for teh Action class. This will make it easier
*to hook up complimentary UI elements (such as a "copy" menu item, and a
*"copy" toolbar item) and have tehm respond to update and actions via a
*single source.
*Got rid of the old toolbar button and separator class. Merged in Marcellos
*new fixes for the Container and Splitter classes.
*Some misc fixes to the Toolbar, groups and checks now work correctly.
*
*/




