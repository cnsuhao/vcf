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
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"
#include "vcf/ApplicationKit/AbstractGTKControl.h"
#include "vcf/ApplicationKit/GTKToolbar.h"
#include "vcf/ApplicationKit/Toolbar.h"

//GTKToolbar.cpp

using namespace VCF;


GTKToolbar::GTKToolbar(Control* control):	
	currentlyModifyingItem_(false)
{
	control_ = (Control*)control;
}

void GTKToolbar::create( Control* control ) 
{
		
	control->getViewModel()->addModelHandler( 
		new ModelEventHandler<GTKToolbar>( this, &GTKToolbar::onModelChanged, "GTKToolbar::onModelChanged" ) );

}

gboolean GTKToolbar::handleEvent( GdkEvent* gtkEvent )
{
	return AbstractGTKControl::handleEvent( gtkEvent );
}

void GTKToolbar::onModelChanged( ModelEvent* e )
{
	if ( currentlyModifyingItem_ ) {
		return;
	}

	switch( e->getType() ) {

		case ToolbarItem::tbCaptionChanged : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;

			
		}
		break;		

		case ToolbarItem::tbSelected : {
		
		}
		break;

		case ToolbarItem::tbItemControlAdded : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;
		}
		break;

		
		case ToolbarItem::tbDimensionsChanged : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;
		}
		break;

		case ToolbarItem::tbAdded : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;
		}
		break;

		case ToolbarItem::tbRemoved : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;
		}
		break;

		case ToolbarItem::tbStateChanged : {
			ToolbarModelEvent* tme = (ToolbarModelEvent*)e;
		}
		break;		

		case ToolbarItem::tbIndexChanged  : {
			
		}
		break;

		default : {

		}
		break;
	}
}


void GTKToolbar::insertToolbarButton( const ulong32& index, ToolbarItem* item, bool showCaption )
{
	
}

void GTKToolbar::showButtonCaptions( const bool& val )
{
	
}

void GTKToolbar::setButtonCaptionPlacementHorizontal( const bool& val )
{
	
}

void GTKToolbar::setButtonSize( const Size& buttonSize )
{
	
	
}

void GTKToolbar::removeToolbarButton( ToolbarItem* item )
{
	
}

void GTKToolbar::onImageListImageChanged( ImageListEvent* e )
{
	ImageList* imageList = (ImageList*)e->getSource();

	switch ( e->getType() ) {
		case IMAGELIST_EVENT_WIDTH_CHANGED : case IMAGELIST_EVENT_HEIGHT_CHANGED :{
			int cx = imageList->getImageWidth();
			int cy = imageList->getImageHeight();


			
		}
		break;

		case IMAGELIST_EVENT_ITEM_ADDED : {

			
		}
		break;

		case IMAGELIST_EVENT_ITEM_DELETED : {
			
		}
		break;
	}
}

void GTKToolbar::setImageList( ImageList* imageList )
{
	
}





/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:17  ddiego
*migration towards new directory structure
*
*Revision 1.2  2003/12/18 05:16:01  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.1.2.1  2003/11/01 20:35:23  ddiego
*added GTKToolbar class impl - no real functionality at this point
*
*
*/




