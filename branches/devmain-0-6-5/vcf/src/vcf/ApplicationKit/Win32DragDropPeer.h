#if     _MSC_VER > 1000
#pragma once
#endif

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
*EXEMPLARY, OR CONSEQUENTIALy DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
*PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
*SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*NB: This software will not save the world.
*/


#ifndef _VCF_WIN32DRAGDROPPEER_H__
#define _VCF_WIN32DRAGDROPPEER_H__


#ifndef _VCF_COMDATAOBJECT_H__
#	include "vcf/ApplicationKit/COMDataObject.h"
#endif // _VCF_COMDATAOBJECT_H__


namespace VCF {

class Win32DragDropPeer : public DragDropPeer, public Object
{
public:

	Win32DragDropPeer();
	virtual ~Win32DragDropPeer(); 

    virtual DragActionType startDragDrop( DataObject* data );
	
	virtual DragSource* getDragSource();

	virtual void setDragSource( VCF::DragSource*  dragSource );

	void setActionType( const DragActionType& actionType );
	
	class COMDragSource : public IDropSource {
	public:
		COMDragSource(Win32DragDropPeer* owningPeer):owningPeer_(owningPeer){};
		
		virtual ~COMDragSource() {};
		
		virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void** ppvObj) {
			if ( iid == IID_IUnknown ) {
				*ppvObj = (IUnknown*)(this);
				((IUnknown*)(*ppvObj))->AddRef();
				return S_OK;
			}
			else if ( iid == IID_IDropSource ) {
				*ppvObj = (IDropSource*)(this);
				((IUnknown*)(*ppvObj))->AddRef();
				return S_OK;
			}
			return E_NOINTERFACE;
		}
		
		virtual ULONG STDMETHODCALLTYPE AddRef(void) {
			
			return 1;
		}
		
		virtual ULONG STDMETHODCALLTYPE Release(void) {
			
			
			return 1;
		}	
		
		//COM CALLS
		STDMETHOD(QueryContinueDrag)( BOOL fEscapePressed, DWORD grfKeyState ) {
			return owningPeer_->QueryContinueDrag( fEscapePressed, grfKeyState );
		}

		STDMETHOD(GiveFeedback)( DWORD dwEffect ) {
			return owningPeer_->GiveFeedback( dwEffect );
		}
		
		
	private:
		Win32DragDropPeer * owningPeer_;		
	};
protected:

	friend class COMDragSource;
	HRESULT GiveFeedback( DWORD dwEffect );

	HRESULT QueryContinueDrag( BOOL fEscapePressed, DWORD grfKeyState );

    VCFCOM::COMDataObject * dataObj_;

	COMDragSource* comDragSrc_;

	VCF::DragSource * dragSrc_;

	VCF::DataObject * clipDataObj_;

	HRESULT dragDropResult_;
		
	DWORD dragDropEffect_; 

	DragActionType actionType_;
};

};

#endif // _VCF_WIN32DRAGDROPPEER_H__


