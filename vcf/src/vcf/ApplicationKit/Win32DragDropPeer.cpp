/**
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

#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/Win32DragDropPeer.h"
#include "vcf/ApplicationKit/COMUtils.h"

using namespace VCF;
using namespace VCFCOM;

Win32DragDropPeer::Win32DragDropPeer()	
{	
	comDragSrc_ = new COMDragSource(this);
	dataObj_ = new VCFCOM::COMDataObject();	
}

Win32DragDropPeer::~Win32DragDropPeer()
{
	delete comDragSrc_;
}

DragActionType Win32DragDropPeer::startDragDrop( DataObject* cdo )
{

	clipDataObj_ = cdo;
	
	dataObj_->setDataObject( clipDataObj_ );	

	dragDropEffect_ = 0;

	dragDropResult_ = ::DoDragDrop( dataObj_, comDragSrc_, 
									COMUtils::translateActionType( dragSrc_->getActionType() ), 
									&dragDropEffect_ );	
	

    DragSourceEvent eventEnd(dragSrc_, clipDataObj_);
	eventEnd.setType( DragSource::DRAG_END );

	dragSrc_->SourceEnd.fireEvent( &eventEnd );

	if (dragDropResult_ == DRAGDROP_S_DROP) {
	    DragSourceEvent eventDropped(dragSrc_,  clipDataObj_);
		eventDropped.setType( DragSource::DRAG_DROPPED );
		dragSrc_->SourceDropped.fireEvent( &eventDropped );
	}

	return (DragActionType) dragDropResult_;

}

void Win32DragDropPeer::setActionType(const VCF::DragActionType& actionType )
{
	actionType_ = actionType;
}


void Win32DragDropPeer::setDragSource(VCF::DragSource* DragSrc)
{
	dragSrc_ = DragSrc;
}

VCF::DragSource* Win32DragDropPeer::getDragSource()
{
	return dragSrc_;
}


HRESULT Win32DragDropPeer::GiveFeedback( DWORD dwEffect )
{
	DragSourceEvent event(dragSrc_, clipDataObj_);
	event.setType( DragSource::DRAG_GIVEFEEDBACK );

	dragSrc_->SourceGiveFeedback.fireEvent( &event );

	/**
	NOTE!!!
	To customize the cursor we should make some sort of call here
	and return NOT DRAGDROP_S_USEDEFAULTCURSORS, but just S_OK
	*/

	return DRAGDROP_S_USEDEFAULTCURSORS;
}

HRESULT Win32DragDropPeer::QueryContinueDrag( BOOL fEscapePressed, DWORD grfKeyState )
{
	DragSourceEvent event(dragSrc_, clipDataObj_);
	event.setType( DragSource::DRAG_CANCONTINUE );
	
    dragSrc_->SourceCanContinueDragOp.fireEvent( &event );

	HRESULT result = NO_ERROR;
	if ( true == ( 0 != fEscapePressed ) ){
		result =  DRAGDROP_S_CANCEL ;
	}

	if ( true != (grfKeyState & MK_LBUTTON) ) {
		result = DRAGDROP_S_DROP;
	}

	return result;
}



