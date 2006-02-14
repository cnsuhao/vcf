//Win32HTMLDOMElements.cpp

#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"

#include <exdisp.h>		// Defines of stuff like IWebBrowser2. This is an include file with Visual C 6 and above
#include <mshtml.h>		// Defines of stuff like IHTMLDocument2. This is an include file with Visual C 6 and above
#include <mshtmhst.h>	// Defines of stuff like IDocHostUIHandler. This is an include file with Visual C 6 and above

#include "thirdparty/win32/comet/threading.h"
#include "thirdparty/win32/comet/uuid.h"
#include "thirdparty/win32/comet/bstr.h"
#include "thirdparty/win32/comet/safearray.h"
#include "vcf/ApplicationKit/Win32HResult.h"

#include "vcf/ApplicationKit/HTMLDOMElements.h"

#include <vector>


#define COM_PTR(ifc) \
namespace comet { \
template<> struct comtype<ifc> { \
	static const IID& uuid() { \
        static const IID iid = IID_##ifc; \
        return iid; \
	} \
    typedef nil base;\
};\
};\
typedef comet::com_ptr<ifc> ifc##Ptr;\
\


COM_PTR(IHTMLDocument2)
COM_PTR(IHTMLElement)
COM_PTR(IHTMLElementCollection)
COM_PTR(IWebBrowser2)






using namespace comet;
typedef VCF::hresult hresult;


namespace VCF {
	
	class HTMLElementCollectionPeer : public IHTMLElementCollectionPtr {
	public:
		HTMLElementCollectionPeer():IHTMLElementCollectionPtr(){}

		template<typename Itf>
		HTMLElementCollectionPeer( const impl::com_cast_t<Itf>& x ) throw () : IHTMLElementCollectionPtr(x) {}	
	};
	
	class HTMLElementPeer : public IHTMLElementPtr {
	public:
		HTMLElementPeer():IHTMLElementPtr(){}

		template<typename Itf>
		HTMLElementPeer( const impl::com_cast_t<Itf>& x ) throw () : IHTMLElementPtr(x) {}

	};
	
	
	class HTMLDocumentPeer : public IHTMLDocument2Ptr {
	public:
		HTMLDocumentPeer():IHTMLDocument2Ptr(){}

		template<typename Itf>
		HTMLDocumentPeer( const impl::com_cast_t<Itf>& x ) throw () : IHTMLDocument2Ptr(x) {}
	};
	
};



VCF::HTMLElementCollection::HTMLElementCollection():
	currentItem_(NULL),peer_(NULL)
{
	peer_ = new HTMLElementCollectionPeer();
}

VCF::HTMLElementCollection::HTMLElementCollection( const VCF::HTMLElementCollection& rhs ):
	currentItem_(NULL),peer_(NULL) 
{
	peer_ = new VCF::HTMLElementCollectionPeer();
	*peer_ = *rhs.peer_;
}

VCF::HTMLElementCollection::~HTMLElementCollection()
{
	delete currentItem_;
	delete peer_;
}


bool VCF::HTMLElementCollection::null() const 
{
	return peer_->is_null();
}

VCF::HTMLElementCollection& VCF::HTMLElementCollection::operator= ( const VCF::HTMLElementCollection& rhs ) 
{
	*peer_ = *rhs.peer_;
	return *this;
}

void VCF::HTMLElementCollection::setPeer( VCF::HTMLElementCollectionPeer* collection )
{
	*peer_ = *collection;
}

VCF::String VCF::HTMLElementCollection::toString() const 
{
	bstr_t res;
	
	if ( *peer_ ) {
		(*peer_)->toString( res.out() );
	}
	
	return res.c_str();
}

void VCF::HTMLElementCollection::setLength( long len ) {
	if ( *peer_ ) {
		(*peer_)->put_length( (long)len );
	}
}

long VCF::HTMLElementCollection::getLength() const {
	long result = 0;
	if ( *peer_ ) {
		(*peer_)->get_length( &result );
	}
	return result;
}


VCF::HTMLElement* VCF::HTMLElementCollection::item( const VCF::String& name, long index )
{
	VCF::HTMLElement* result = NULL;
	
	variant_t tmpName = index;
	variant_t tmpIndex = index;
	
	com_ptr<IDispatch> disp;
	(*peer_)->item( tmpName.in(), tmpIndex.in(), disp.out() );
	if ( NULL != disp ) {
		VCF::HTMLElementPeer item = com_cast( disp );
		if ( item ) {
			if ( NULL == currentItem_ ) {
				currentItem_ = new VCF::HTMLElement();
			}
			
			currentItem_->setPeer( &item );
			result = currentItem_;
		}
	}

	return result;
}


VCF::HTMLElement* VCF::HTMLElementCollection::item( const VCF::String& name )
{
	VCF::HTMLElement* result = NULL;
	variant_t tmpName = name.c_str();
	variant_t tmpIndex = name.c_str();
	
	com_ptr<IDispatch> disp;
	(*peer_)->item( tmpName.in(), tmpIndex.in(), disp.out() );
	if ( NULL != disp ) {
		VCF::HTMLElementPeer item = com_cast( disp );
		if ( item ) {
			if ( NULL == currentItem_ ) {
				currentItem_ = new VCF::HTMLElement();
			}
			
			currentItem_->setPeer( &item );
			result = currentItem_;
		}
	}

	return result;
}

VCF::HTMLElement* VCF::HTMLElementCollection::item( long index )
{
	VCF::HTMLElement* result = NULL;

	variant_t tmpName = index;
	variant_t tmpIndex = index;
	
	com_ptr<IDispatch> disp;
	(*peer_)->item( tmpName.in(), tmpIndex.in(), disp.out() );
	if ( NULL != disp ) {
		VCF::HTMLElementPeer item = com_cast( disp );
		if ( item ) {
			if ( NULL == currentItem_ ) {
				currentItem_ = new VCF::HTMLElement();
			}
			
			currentItem_->setPeer( &item );
			result = currentItem_;
		}
	}

	return result;
}


VCF::HTMLElement* VCF::HTMLElementCollection::operator[](long index)
{
	return item(index);
}

VCF::HTMLElement* VCF::HTMLElementCollection::operator[](const VCF::String& name)
{
	return item(name);
}


VCF::HTMLElementCollection VCF::HTMLElementCollection::tags( const VCF::String& tag ) {
	VCF::HTMLElementCollection result;
	
	
	variant_t tmpTag = tag.c_str();
	
	com_ptr<IDispatch> collection;
	
	(*peer_)->tags( tmpTag.in(), collection.out() );
	
	if (collection) {
		*(result.peer_) = com_cast(collection);
	}
	
	return result;
}









VCF::HTMLElement::HTMLElement():
	peer_(NULL)
{
	peer_ = new VCF::HTMLElementPeer();
}

VCF::HTMLElement::HTMLElement( const VCF::HTMLElement& rhs ):
	peer_(NULL)
{
	peer_ = new VCF::HTMLElementPeer();
	*peer_ = *rhs.peer_;
}

VCF::HTMLElement::~HTMLElement()
{
	delete peer_;
}

VCF::HTMLElement& VCF::HTMLElement::operator= ( const VCF::HTMLElement& rhs ) 
{
	*peer_ = *rhs.peer_;
	return *this;
}

void VCF::HTMLElement::setPeer( VCF::HTMLElementPeer* element )
{
	*peer_ = *element;
}

bool VCF::HTMLElement::null() const {
	return peer_->is_null();
}

void VCF::HTMLElement::setAttribute( const VCF::String& attributeName,
				  const VCF::String& attributeValue,
				  bool caseSensitive ) {
	
	bstr_t name = attributeName.c_str();
	variant_t val = attributeValue.c_str();
	(*peer_)->setAttribute( name.in(), val.in(), caseSensitive ? TRUE:FALSE );
}

VCF::String VCF::HTMLElement::getAttribute(const VCF::String& attributeName, bool caseSensitive) const 
{
	VCF::String result;
	
	variant_t tmp;
	bstr_t name = attributeName.c_str();
	
	(*peer_)->getAttribute(name.in(), caseSensitive ? TRUE:FALSE, tmp.out() );
	
	result = (AnsiString)tmp;
	
	return result;
}

bool VCF::HTMLElement::removeAttribute( const VCF::String& attributeName, bool caseSensitive ) {
	VARIANT_BOOL result = FALSE;
	bstr_t name = attributeName.c_str();
	(*peer_)->removeAttribute( name.in(), caseSensitive ? TRUE:FALSE, &result );
	return result ? true : false;
}

void VCF::HTMLElement::setClassName( const VCF::String& className ) {
	
	(*peer_)->put_className( bstr_t(className.c_str()).in() );
}

VCF::String VCF::HTMLElement::getClassName() const {
	bstr_t tmp;
	(*peer_)->get_className( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLElement::setID( const VCF::String& id ) {
	
	(*peer_)->put_id( bstr_t(id.c_str()).in() );
}

VCF::String VCF::HTMLElement::getID() const {
	bstr_t tmp;
	(*peer_)->get_id( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::String VCF::HTMLElement::getTagName() const {
	bstr_t tmp;
	(*peer_)->get_tagName( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::HTMLElement VCF::HTMLElement::getParent() const 
{
	VCF::HTMLElement result;
	VCF::HTMLElementPeer parent;
	(*peer_)->get_parentElement( parent.out() );
	
	result.setPeer( &parent );

	return result;
}

void VCF::HTMLElement::setTitle( const VCF::String& title ) {
	(*peer_)->put_title( bstr_t(title.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getTitle() const {
	bstr_t tmp;
	(*peer_)->get_title( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLElement::setLanguage( const VCF::String& language ) {
	(*peer_)->put_language( bstr_t(language.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getLanguage() const {
	bstr_t tmp;
	(*peer_)->get_language( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLElement::scrollIntoView( bool atTop ) {
	(*peer_)->scrollIntoView( variant_t(atTop).in() );
}

bool VCF::HTMLElement::contains( const HTMLElement& child ) const {
	VARIANT_BOOL result = FALSE;
	
	(*peer_)->contains( child.peer_->in(), &result );
	
	return result ? true : false;
}

long VCF::HTMLElement::getSourceIndex() const {
	long result = 0;
	
	(*peer_)->get_sourceIndex( &result );
	
	return result;
}

void VCF::HTMLElement::setLang( const VCF::String& language ) {
	(*peer_)->put_lang( bstr_t(language.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getLang() const {
	bstr_t tmp;
	(*peer_)->get_lang( tmp.out() );
	return VCF::String(tmp.c_str());
}

long VCF::HTMLElement::getOffsetLeft() const {
	long result = 0;
	
	(*peer_)->get_offsetLeft( &result );
	
	return result;
}

long VCF::HTMLElement::getOffsetTop() const {
	long result = 0;
	
	(*peer_)->get_offsetTop( &result );
	
	return result;
}

long VCF::HTMLElement::getOffsetWidth() const {
	long result = 0;
	
	(*peer_)->get_offsetWidth( &result );
	
	return result;
}

long VCF::HTMLElement::getOffsetHeight() const {
	long result = 0;
	
	(*peer_)->get_offsetHeight( &result );
	
	return result;
}

VCF::HTMLElement VCF::HTMLElement::getOffsetParent() const {
	VCF::HTMLElement result;
	VCF::HTMLElementPeer parent;
	(*peer_)->get_offsetParent( parent.out() );
	
	result.setPeer( &parent );

	return result;
}

void VCF::HTMLElement::setInnerHTML( const VCF::String& html ) {
	(*peer_)->put_innerHTML( bstr_t(html.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getInnerHTML() const {
	bstr_t tmp;
	(*peer_)->get_innerHTML( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLElement::setInnerText( const VCF::String& text ) {
	(*peer_)->put_innerText( bstr_t(text.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getInnerText() const {
	bstr_t tmp;
	(*peer_)->get_innerText( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLElement::setOuterHTML( const VCF::String& html ) {
	(*peer_)->put_outerHTML( bstr_t(html.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getOuterHTML() const {
	bstr_t tmp;
	(*peer_)->get_outerHTML( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLElement::setOuterText( const VCF::String& text ) {
	(*peer_)->put_outerText( bstr_t(text.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getOuterText() const {
	bstr_t tmp;
	(*peer_)->get_outerText( tmp.out() );
	return VCF::String(tmp.c_str());
}


void VCF::HTMLElement::insertAdjacentHTML( const VCF::String& where, const VCF::String& html ) {
	(*peer_)->insertAdjacentHTML( bstr_t(where.c_str()).in(), bstr_t(html.c_str()).in() );		
}

void VCF::HTMLElement::insertAdjacentText( const VCF::String& where, const VCF::String& text ) {
	(*peer_)->insertAdjacentText( bstr_t(where.c_str()).in(), bstr_t(text.c_str()).in() );		
}

VCF::HTMLElement VCF::HTMLElement::getParentTextEdit() const {
	VCF::HTMLElement result;

	VCF::HTMLElementPeer parent;
	(*peer_)->get_parentTextEdit( parent.out() );
	
	result.setPeer( &parent );

	return result;
}

bool VCF::HTMLElement::getIsTextEdit() const {
	VARIANT_BOOL result = FALSE;
	(*peer_)->get_isTextEdit( &result );
	return result ? true : false;
}

void VCF::HTMLElement::click() {
	(*peer_)->click();
}

VCF::String VCF::HTMLElement::toString() const {
	bstr_t tmp;
	(*peer_)->toString( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::HTMLElementCollection VCF::HTMLElement::getChildren() {
	VCF::HTMLElementCollection result;
	com_ptr<IDispatch> collection;
	(*peer_)->get_children( collection.out() );
	if (collection) {
		*result.peer_ = com_cast(collection);
	}
	
	return result;
}

VCF::HTMLElementCollection VCF::HTMLElement::getAll() {
	VCF::HTMLElementCollection result;
	com_ptr<IDispatch> collection;
	(*peer_)->get_all( collection.out() );
	if (collection) {
		*result.peer_ = com_cast(collection);
	}
	
	return result;
}
