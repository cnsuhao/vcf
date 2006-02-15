//Win32HTMLBrowser.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


//Win32HTMLBrowser.h
#include "vcf/ApplicationKit/ApplicationKit.h"
#include "vcf/ApplicationKit/ApplicationKitPrivate.h"



#include "vcf/ApplicationKit/Win32HTMLBrowser.h"
#include "vcf/ApplicationKit/HTMLBrowserControl.h"



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


VCF::HTMLElement::HTMLElement( VCF::HTMLElementPeer* element ):
	peer_(NULL)
{
	peer_ = new VCF::HTMLElementPeer();
	*peer_ = *element;
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

bool VCF::HTMLElement::null() const 
{
	return peer_->is_null();
}

void VCF::HTMLElement::setAttribute( const VCF::String& attributeName,
				  const VCF::String& attributeValue,
				  bool caseSensitive ) 
{
	
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

bool VCF::HTMLElement::removeAttribute( const VCF::String& attributeName, bool caseSensitive ) 
{
	VARIANT_BOOL result = FALSE;
	bstr_t name = attributeName.c_str();
	(*peer_)->removeAttribute( name.in(), caseSensitive ? TRUE:FALSE, &result );
	return result ? true : false;
}

void VCF::HTMLElement::setClassName( const VCF::String& className ) 
{
	
	(*peer_)->put_className( bstr_t(className.c_str()).in() );
}

VCF::String VCF::HTMLElement::getClassName() const 
{
	bstr_t tmp;
	(*peer_)->get_className( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLElement::setID( const VCF::String& id ) 
{
	
	(*peer_)->put_id( bstr_t(id.c_str()).in() );
}

VCF::String VCF::HTMLElement::getID() const 
{
	bstr_t tmp;
	(*peer_)->get_id( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::String VCF::HTMLElement::getTagName() const 
{
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

void VCF::HTMLElement::setTitle( const VCF::String& title ) 
{
	(*peer_)->put_title( bstr_t(title.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getTitle() const 
{
	bstr_t tmp;
	(*peer_)->get_title( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLElement::setLanguage( const VCF::String& language ) 
{
	(*peer_)->put_language( bstr_t(language.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getLanguage() const 
{
	bstr_t tmp;
	(*peer_)->get_language( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLElement::scrollIntoView( bool atTop ) 
{
	(*peer_)->scrollIntoView( variant_t(atTop).in() );
}

bool VCF::HTMLElement::contains( const HTMLElement& child ) const 
{
	VARIANT_BOOL result = FALSE;
	
	(*peer_)->contains( child.peer_->in(), &result );
	
	return result ? true : false;
}

long VCF::HTMLElement::getSourceIndex() const 
{
	long result = 0;
	
	(*peer_)->get_sourceIndex( &result );
	
	return result;
}

void VCF::HTMLElement::setLang( const VCF::String& language ) 
{
	(*peer_)->put_lang( bstr_t(language.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getLang() const 
{
	bstr_t tmp;
	(*peer_)->get_lang( tmp.out() );
	return VCF::String(tmp.c_str());
}

long VCF::HTMLElement::getOffsetLeft() const 
{
	long result = 0;
	
	(*peer_)->get_offsetLeft( &result );
	
	return result;
}

long VCF::HTMLElement::getOffsetTop() const 
{
	long result = 0;
	
	(*peer_)->get_offsetTop( &result );
	
	return result;
}

long VCF::HTMLElement::getOffsetWidth() const 
{
	long result = 0;
	
	(*peer_)->get_offsetWidth( &result );
	
	return result;
}

long VCF::HTMLElement::getOffsetHeight() const 
{
	long result = 0;
	
	(*peer_)->get_offsetHeight( &result );
	
	return result;
}

VCF::HTMLElement VCF::HTMLElement::getOffsetParent() const 
{
	VCF::HTMLElement result;
	VCF::HTMLElementPeer parent;
	(*peer_)->get_offsetParent( parent.out() );
	
	result.setPeer( &parent );

	return result;
}

void VCF::HTMLElement::setInnerHTML( const VCF::String& html ) 
{
	(*peer_)->put_innerHTML( bstr_t(html.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getInnerHTML() const 
{
	bstr_t tmp;
	(*peer_)->get_innerHTML( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLElement::setInnerText( const VCF::String& text ) 
{
	(*peer_)->put_innerText( bstr_t(text.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getInnerText() const 
{
	bstr_t tmp;
	(*peer_)->get_innerText( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLElement::setOuterHTML( const VCF::String& html ) 
{
	(*peer_)->put_outerHTML( bstr_t(html.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getOuterHTML() const 
{
	bstr_t tmp;
	(*peer_)->get_outerHTML( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLElement::setOuterText( const VCF::String& text ) 
{
	(*peer_)->put_outerText( bstr_t(text.c_str()).in() );		
}

VCF::String VCF::HTMLElement::getOuterText() const {
	bstr_t tmp;
	(*peer_)->get_outerText( tmp.out() );
	return VCF::String(tmp.c_str());
}


void VCF::HTMLElement::insertAdjacentHTML( const VCF::String& where, const VCF::String& html ) 
{
	(*peer_)->insertAdjacentHTML( bstr_t(where.c_str()).in(), bstr_t(html.c_str()).in() );		
}

void VCF::HTMLElement::insertAdjacentText( const VCF::String& where, const VCF::String& text ) 
{
	(*peer_)->insertAdjacentText( bstr_t(where.c_str()).in(), bstr_t(text.c_str()).in() );		
}

VCF::HTMLElement VCF::HTMLElement::getParentTextEdit() const 
{
	VCF::HTMLElement result;

	VCF::HTMLElementPeer parent;
	(*peer_)->get_parentTextEdit( parent.out() );
	
	result.setPeer( &parent );

	return result;
}

bool VCF::HTMLElement::getIsTextEdit() const 
{
	VARIANT_BOOL result = FALSE;
	(*peer_)->get_isTextEdit( &result );
	return result ? true : false;
}

void VCF::HTMLElement::click() {
	(*peer_)->click();
}

VCF::String VCF::HTMLElement::toString() const 
{
	bstr_t tmp;
	(*peer_)->toString( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::HTMLElementCollection VCF::HTMLElement::getChildren() 
{
	VCF::HTMLElementCollection result;
	com_ptr<IDispatch> collection;
	(*peer_)->get_children( collection.out() );
	if (collection) {
		*result.peer_ = com_cast(collection);
	}
	
	return result;
}

VCF::HTMLElementCollection VCF::HTMLElement::getAll() 
{
	VCF::HTMLElementCollection result;
	com_ptr<IDispatch> collection;
	(*peer_)->get_all( collection.out() );
	if (collection) {
		*result.peer_ = com_cast(collection);
	}
	
	return result;
}












VCF::HTMLDocument::HTMLDocument()
{
	peer_ = new VCF::HTMLDocumentPeer();
}

VCF::HTMLDocument::HTMLDocument( const VCF::HTMLDocument& rhs )
{
	peer_ = new VCF::HTMLDocumentPeer();
	*peer_ = *rhs.peer_;
}

VCF::HTMLDocument::~HTMLDocument()
{
	delete peer_;
}

VCF::HTMLDocument& VCF::HTMLDocument::operator= ( const VCF::HTMLDocument& rhs ) {
	*peer_ = *rhs.peer_;
	return *this;
}

void VCF::HTMLDocument::setPeer( HTMLDocumentPeer* doc )
{
	*peer_ = *doc;
}

bool VCF::HTMLDocument::null() const {
	return peer_->is_null();
}

VCF::HTMLElementCollection VCF::HTMLDocument::getAll() {
	VCF::HTMLElementCollection result;		
	(*peer_)->get_all( result.peer_->out() );		
	return result;
}

VCF::HTMLElement VCF::HTMLDocument::getBody() const {
	VCF::HTMLElementPeer element;
	(*peer_)->get_body( element.out() );
	
	return VCF::HTMLElement(&element);
}

VCF::HTMLElement VCF::HTMLDocument::getActiveElement() const {
	VCF::HTMLElementPeer element;
	(*peer_)->get_activeElement( element.out() );
	
	return VCF::HTMLElement(&element);
}


VCF::HTMLElementCollection VCF::HTMLDocument::getImages() {
	VCF::HTMLElementCollection result;		
	(*peer_)->get_images( result.peer_->out() );		
	return result;
}

VCF::HTMLElementCollection VCF::HTMLDocument::getApplets() {
	VCF::HTMLElementCollection result;		
	(*peer_)->get_applets( result.peer_->out() );		
	return result;
}

VCF::HTMLElementCollection VCF::HTMLDocument::getLinks() {
	VCF::HTMLElementCollection result;		
	(*peer_)->get_links( result.peer_->out() );		
	return result;
}

VCF::HTMLElementCollection VCF::HTMLDocument::getForms() {
	VCF::HTMLElementCollection result;		
	(*peer_)->get_forms( result.peer_->out() );		
	return result;
}

VCF::HTMLElementCollection VCF::HTMLDocument::getAnchors() {
	VCF::HTMLElementCollection result;		
	(*peer_)->get_anchors( result.peer_->out() );		
	return result;
}

void VCF::HTMLDocument::setTitle( const VCF::String& title ) {
	(*peer_)->put_title( bstr_t(title.c_str()).in() );		
}

VCF::String VCF::HTMLDocument::getTitle() const {
	bstr_t tmp;
	(*peer_)->get_title( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::HTMLElementCollection VCF::HTMLDocument::getScripts() {
	VCF::HTMLElementCollection result;		
	(*peer_)->get_scripts( result.peer_->out() );		
	return result;
}


VCF::String VCF::HTMLDocument::getReadyState() const {
	bstr_t tmp;
	(*peer_)->get_readyState( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::HTMLElementCollection VCF::HTMLDocument::getEmbeds() {
	VCF::HTMLElementCollection result;		
	(*peer_)->get_embeds( result.peer_->out() );		
	return result;
}

VCF::HTMLElementCollection VCF::HTMLDocument::getPlugins() {
	VCF::HTMLElementCollection result;		
	(*peer_)->get_plugins( result.peer_->out() );		
	return result;
}

VCF::String VCF::HTMLDocument::getReferrer() const {
	bstr_t tmp;
	(*peer_)->get_referrer( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::String VCF::HTMLDocument::getLastModified() const {
	bstr_t tmp;
	(*peer_)->get_lastModified( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLDocument::setURL( const VCF::String& url ) {
	(*peer_)->put_URL( bstr_t(url.c_str()).in() );		
}

VCF::String VCF::HTMLDocument::getURL() const {
	bstr_t tmp;
	(*peer_)->get_URL( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLDocument::setDomain( const VCF::String& domain ) {
	(*peer_)->put_domain( bstr_t(domain.c_str()).in() );		
}

VCF::String VCF::HTMLDocument::getDomain() const {
	bstr_t tmp;
	(*peer_)->get_domain( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLDocument::setCookie( const VCF::String& cookie ) {
	(*peer_)->put_cookie( bstr_t(cookie.c_str()).in() );		
}

VCF::String VCF::HTMLDocument::getCookie() const {
	bstr_t tmp;
	(*peer_)->get_cookie( tmp.out() );
	return VCF::String(tmp.c_str());
}

bool VCF::HTMLDocument::getExpando() const {
	VARIANT_BOOL result = FALSE;
	(*peer_)->get_expando( &result );
	return result ? true : false;
}

void VCF::HTMLDocument::setExpando( bool expando ) {
	(*peer_)->put_expando( expando ? TRUE : FALSE );
}

void VCF::HTMLDocument::setCharset( const VCF::String& val ) {
	(*peer_)->put_charset( bstr_t(val.c_str()).in() );		
}

VCF::String VCF::HTMLDocument::getCharset() const {
	bstr_t tmp;
	(*peer_)->get_charset( tmp.out() );
	return VCF::String(tmp.c_str());
}

void VCF::HTMLDocument::setDefaultCharset( const VCF::String& val ) {
	(*peer_)->put_defaultCharset( bstr_t(val.c_str()).in() );		
}

VCF::String VCF::HTMLDocument::getDefaultCharset() const {
	bstr_t tmp;
	(*peer_)->get_defaultCharset( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::String VCF::HTMLDocument::getMimeType() const {
	bstr_t tmp;
	(*peer_)->get_mimeType( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::String VCF::HTMLDocument::getFileSize() const {
	bstr_t tmp;
	(*peer_)->get_fileSize( tmp.out() );
	return VCF::String(tmp.c_str());
}

int VCF::HTMLDocument::getIntFileSize() const {
	bstr_t tmp;
	(*peer_)->get_fileSize( tmp.out() );
	return atoi(tmp.s_str().c_str());
}

VCF::String VCF::HTMLDocument::getFileCreatedDate() const {
	bstr_t tmp;
	(*peer_)->get_fileCreatedDate( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::String VCF::HTMLDocument::getFileModifiedDate() const {
	bstr_t tmp;
	(*peer_)->get_fileModifiedDate( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::String VCF::HTMLDocument::getFileUpdatedDate() const {
	bstr_t tmp;
	(*peer_)->get_fileUpdatedDate( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::String VCF::HTMLDocument::getSecurity() const {
	bstr_t tmp;
	(*peer_)->get_security( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::String VCF::HTMLDocument::getProtocol() const {
	bstr_t tmp;
	(*peer_)->get_protocol( tmp.out() );
	return VCF::String(tmp.c_str());
}

VCF::String VCF::HTMLDocument::getNameProp() const {
	bstr_t tmp;
	(*peer_)->get_nameProp( tmp.out() );
	return VCF::String(tmp.c_str());
} 

VCF::String VCF::HTMLDocument::toString() const {
	bstr_t tmp;
	(*peer_)->toString( tmp.out() );
	return VCF::String(tmp.c_str());
} 

void VCF::HTMLDocument::write( const VCF::String& text ) {
	
	safearray_t<variant_t> sarr;
	
	variant_t v = text.c_str();
	sarr.push_back(v);
	
	(*peer_)->write( sarr.in() );
}

void VCF::HTMLDocument::writeln( const VCF::String& text ) {
	
	safearray_t<variant_t> sarr;
	
	variant_t v = text.c_str();
	sarr.push_back(v);
	
	(*peer_)->writeln( sarr.in() );
}

VCF::HTMLElement VCF::HTMLDocument::createElement( const VCF::String& elementTag ) const {
	VCF::HTMLElementPeer element;
	(*peer_)->createElement( bstr_t(elementTag.c_str()).in(), element.out() );
	
	return VCF::HTMLElement(&element);
}

void VCF::HTMLDocument::setDesignMode( bool val ) {
	bstr_t mode = val ? "on" : "off";
	(*peer_)->put_designMode( mode.in() );
}

bool VCF::HTMLDocument::getDesignMode() const {
	bool result = false;
	bstr_t mode;
	(*peer_)->get_designMode( mode.out() );
	
	if ( mode.s_str() == "off" ) {
		result = false;
	}
	else if ( mode.s_str() == "on" ) {
		result = true;
	}
	
	return result;
}

VCF::HTMLElement VCF::HTMLDocument::elementFromPoint( long x, long y )
{
	VCF::HTMLElement result;

	VCF::HTMLElementPeer element;
	(*peer_)->elementFromPoint( x, y, element.out() );

	if ( !element.is_null() ) {
		result.setPeer( &element );
	}

	return result;
}

void VCF::HTMLDocument::copy() {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "Copy";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}

void VCF::HTMLDocument::cut() {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "Cut";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}

void VCF::HTMLDocument::paste() {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "Paste";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}

void VCF::HTMLDocument::selectAll() {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "SelectAll";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}

void VCF::HTMLDocument::underline() {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "Underline";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}

void VCF::HTMLDocument::bold() {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "Bold";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}

void VCF::HTMLDocument::italic () {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "Italic";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}

void VCF::HTMLDocument::justifyLeft () {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "JustifyLeft";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}

void VCF::HTMLDocument::justifyRight () {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "JustifyRight";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}

void VCF::HTMLDocument::justifyCenter () {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "JustifyCenter";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}

void VCF::HTMLDocument::justifyFull () {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "JustifyFull";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}

void VCF::HTMLDocument::outdent () {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "Outdent ";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}

void VCF::HTMLDocument::indent () {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "Indent";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}

void VCF::HTMLDocument::clearSelection () {
	variant_t v;
	VARIANT_BOOL res;
	bstr_t cmd = "Unselect";
	(*peer_)->execCommand( cmd.in(), TRUE, v.in(), &res );
}





using namespace VCF;


STDMETHODIMP HTMLEventHandler::Invoke( DISPID dispIdMember, REFIID riid, LCID lcid, 
										WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, 
										EXCEPINFO* pExcepInfo, UINT* puArgErr ) 
{
	if ( 0 == dispIdMember && NULL != handler ) {
		HTMLElementEvent e(eventSource,HTMLBrowserControl::heElementClicked);
		e.elementID = elementID;
		
		handler->invoke( &e );
		
		return S_OK;
	}
	
	return E_NOTIMPL;
}







Win32HTMLBrowser::Win32HTMLBrowser():
	browserHwnd_(NULL)	
{
	uiStyle_ = DOCHOSTUIFLAG_NO3DBORDER;
}

Win32HTMLBrowser::~Win32HTMLBrowser()
{
	clearHTMLHandlers();
}

void Win32HTMLBrowser::create( VCF::Control* owningControl )
{
	{
		String className = "VCF::Win32HTMLBrowser";
		if ( true != isRegistered() ){
			registerWin32Class( className, wndProc_  );
		}

		CreateParams params = createParams();

		Win32ToolKit* toolkit = (Win32ToolKit*)UIToolkit::internal_getDefaultUIToolkit();
		HWND parent = toolkit->getDummyParent();

		if ( System::isUnicodeEnabled() ) {

			hwnd_ = ::CreateWindowExW( params.second, className.c_str(),
										L"",	params.first,
										0, 0,
										1,
										1,
										parent,
										NULL, ::GetModuleHandleW(NULL), NULL );
		}
		else {
			hwnd_ = ::CreateWindowExA( params.second, className.ansi_c_str(),
										"",	params.first,
										0, 0,
										1,
										1,
										parent,
										NULL, ::GetModuleHandleA(NULL), NULL );
		}


		if ( NULL != hwnd_ ){
			Win32Object::registerWin32Object( this );

			//embed the browser 
			embed( hwnd_ );
		}
		else {
			throw RuntimeException( MAKE_ERROR_MSG_2("Unable to create hwnd") );
		}


	}


	setCreated( true );
}

void Win32HTMLBrowser::setFocused()
{
	AbstractWin32Component::setFocused();
	//::SetFocus( browserHwnd_ );
}

void Win32HTMLBrowser::setVisible( const bool& val )
{
	AbstractWin32Component::setVisible( val );

	if ( val ) {
		//::ShowWindow( browserHwnd_, SW_SHOW );
	}
	else {
		//::ShowWindow( browserHwnd_, SW_HIDE );
	}
}

bool Win32HTMLBrowser::handleEventMessages( UINT message, WPARAM wParam, LPARAM lParam, LRESULT& wndResult, WNDPROC defaultWndProc )
{
	bool result = false;
	switch ( message ) {

		case WM_DESTROY : {

			unembed();

			result = AbstractWin32Component::handleEventMessages( message, wParam, lParam, wndResult );

			
		}
		break;

		case WM_PAINT : {
			if ( System::isUnicodeEnabled() ) {
				wndResult = DefWindowProcW(hwnd_, message, wParam, lParam);
				result = true;
			}
			else {
				wndResult = DefWindowProcA(hwnd_, message, wParam, lParam);
				result = true;
			}
		}
		break;

		case WM_ERASEBKGND : {
			wndResult = 0;
			result = true;
		}
		break;


		case WM_SIZE : {
			result = AbstractWin32Component::handleEventMessages( message, wParam, lParam, wndResult );
			
			resize( LOWORD(lParam), HIWORD(lParam) );
		}
		break;

		default : {
			result = AbstractWin32Component::handleEventMessages( message, wParam,lParam, wndResult, defaultWndProc );

		}
		break;
	}

	return  result;
}

Win32Object::CreateParams Win32HTMLBrowser::createParams()
{
	Win32Object::CreateParams result;
	result.second = 0;
	//WS_CLIPSIBLINGS and friends cause TONS of flicker
	//during repaints, so we get rid of them.
	result.first = WS_CHILD;//  | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	return result;
}


String Win32HTMLBrowser::getCurrentURL()
{
	return WebBrowserCtrl::getCurrentURL();
}

void Win32HTMLBrowser::setCurrentURL( const String& url )
{
	loadingURL_ = url;
	openURL( url );
}

void Win32HTMLBrowser::goBack()
{
	back();
}

void Win32HTMLBrowser::goForward()
{
	forward();
}

void Win32HTMLBrowser::goHome()
{
	home();
}

void Win32HTMLBrowser::refresh()
{
	WebBrowserCtrl::refresh();
}

bool Win32HTMLBrowser::isLoadingURL()
{
	return busy();
}

void Win32HTMLBrowser::stopLoadingURL()
{
	WebBrowserCtrl::stop();
}

void Win32HTMLBrowser::setFromHTML( const String& html )
{
	if ( busy() ) {
		//barf!
		throw RuntimeException( "The browser is still loading it's document and you can't set the document's HTML while it's loading." );
	}

	HTMLDocument doc = getDocument();
	if ( !doc.null() ) {
		doc.write( html );
	}
}

String Win32HTMLBrowser::getTitle()
{
	String result;

	HTMLDocument doc = getDocument();
	if ( !doc.null() ) {
		result = doc.getTitle();
	}

	return result;
}

void Win32HTMLBrowser::edit( const bool& val )
{
	HTMLDocument doc = getDocument();
	if ( !doc.null() ) {
		doc.setDesignMode( val );
	}
	else {
		throw RuntimeException( "Can't edit a null document." );
	}
}

void Win32HTMLBrowser::copy()
{
	HTMLDocument doc = getDocument();
	if ( !doc.null() ) {
		doc.copy();
	}
	else {
		throw RuntimeException( "Can't copy from a null document." );
	}
}

void Win32HTMLBrowser::selectAll()
{
	HTMLDocument doc = getDocument();
	if ( !doc.null() ) {
		doc.selectAll();
	}
	else {
		throw RuntimeException( "Can't make a selection from a null document." );
	}
}

void Win32HTMLBrowser::setAllowsPopupWindows( bool val )
{
//no-op
}

void Win32HTMLBrowser::setAllowsScrollbars( bool val )
{
	uiStyle_ = val ? (uiStyle_ ^ DOCHOSTUIFLAG_SCROLL_NO)
                                      : (uiStyle_ | DOCHOSTUIFLAG_SCROLL_NO);	
}

void Win32HTMLBrowser::setAllowsTextSelection( bool val )
{
	uiStyle_ = val ? (uiStyle_ ^ DOCHOSTUIFLAG_DIALOG)
                                      : (uiStyle_ | DOCHOSTUIFLAG_DIALOG);
}

String Win32HTMLBrowser::getElementHTMLText( const String& elementName )
{
	return getElementText( true, elementName );
}

void Win32HTMLBrowser::setElementHTMLText( const String& elementName, const String& html )
{
	setElementText( true, elementName, html );
}

String Win32HTMLBrowser::getElementText( const String& elementName )
{
	return getElementText( false, elementName );
}

void Win32HTMLBrowser::setElementText( const String& elementName, const String& text )
{
	setElementText( false, elementName, text );
}

String Win32HTMLBrowser::getActiveElementID()
{
	String result;

	com_ptr<IDispatch> disp;
	IHTMLDocument2Ptr doc;
	browser_->get_Document( disp.out() );
	doc = com_cast( disp );
	if ( doc ) {
		IHTMLElementPtr item;
		doc->get_activeElement( item.out() );
		bstr_t tmp;
		item->get_id( tmp.out() );

		result = tmp.c_str();

		item->get_tagName( tmp.out() );
	}

	return result;
}

String Win32HTMLBrowser::getElementIDFromPoint( Point* pt )
{
	String result;

	com_ptr<IDispatch> disp;
	IHTMLDocument2Ptr doc;
	browser_->get_Document( disp.out() );
	doc = com_cast( disp );
	if ( doc ) {
		IHTMLElementPtr item;
		doc->elementFromPoint( (long)pt->x_, (long)pt->y_, item.out() );
		bstr_t tmp;
		item->get_id( tmp.out() );

		result = tmp.c_str();
	}

	return result;
}

String Win32HTMLBrowser::getElementText( bool textIsHTML, const String& elementName )
{
	String result;

	VCF::HTMLElementPeer item;

	VCF::HTMLElementCollectionPeer collection;	
	com_ptr<IDispatch> disp;
	IHTMLDocument2Ptr doc;
	browser_->get_Document( disp.out() );
	doc = com_cast( disp );
	if ( doc ) {
		doc->get_all( collection.out() );
		if ( collection ) {
			VCF::HTMLElementCollection coll2;
			coll2.setPeer( &collection );
			long len = coll2.getLength();
			
			for (int i=0;i<len;i++ ) {
				VCF::HTMLElement* f = coll2[i];
				if ( NULL != f ) {
					if ( elementName == f->getID() ) {							
						item = *f->getPeer();
						break;
					}
				}
			}			
		}
	}	

	if ( !item.is_null() ) {
		bstr_t val;
		if ( textIsHTML ) {
			item->get_innerHTML( val.out() );
		}
		else {
			item->get_innerText( val.out() );
		}

		result = val.c_str();
	}

	return result;
}

void Win32HTMLBrowser::setElementText( bool textIsHTML, const String& elementName, const String& text )
{
	VCF::HTMLElementPeer item;
	
	HTMLElementCollectionPeer collection;
	com_ptr<IDispatch> disp;
	IHTMLDocument2Ptr doc;
	browser_->get_Document( disp.out() );
	doc = com_cast( disp );
	if ( doc ) {
		doc->get_all( collection.out() );
		if ( collection ) {
			VCF::HTMLElementCollection coll2;
			coll2.setPeer( &collection );
			long len = coll2.getLength();
			
			for (int i=0;i<len;i++ ) {
				VCF::HTMLElement* f = coll2[i];
				if ( NULL != f ) {
					if ( elementName == f->getID() ) {							
						item = *f->getPeer();
						break;
					}
				}
			}			
		}
	}
	

	if ( !item.is_null() ) {
		bstr_t val = text.c_str();						

		if ( textIsHTML ) {
			item->put_innerHTML( val.in() );
		}
		else {
			item->put_innerText( val.in() );
		}
	}
}


bool Win32HTMLBrowser::setElementClickedEventHandler( const String& elementName, EventHandler* handler )
{
	bool result = false;

	VCF::HTMLElementCollectionPeer collection;	
	com_ptr<IDispatch> disp;
	IHTMLDocument2Ptr doc;
	browser_->get_Document( disp.out() );
	doc = com_cast( disp );
	if ( doc ) {
		doc->get_all( collection.out() );
		if ( collection ) {
			VCF::HTMLElementCollection coll2;
			coll2.setPeer( &collection );

			long len = coll2.getLength();

			for (int i=0;i<len;i++ ) {
				VCF::HTMLElement* f = coll2[i];
				if ( NULL != f ) {
					if ( elementName == f->getID() ) {
						String name = handler->getHandlerName();

						HTMLEventHandler* htmlHandler = getElementEventHandler(name);
						if ( NULL == htmlHandler ) {
							htmlHandler = new HTMLEventHandler();
							eventHandlers_[name] = htmlHandler;
						}

						htmlHandler->eventSource = peerControl_;
						htmlHandler->handler = handler;
						htmlHandler->elementID = elementName;

						variant_t e;
						com_ptr<IDispatch> idisp = htmlHandler;

						e = idisp;							
						(*f->getPeer())->put_onclick( e.in() );

						result = true;
						break;
					}
				}
			}			
		}
	}

	return result;
}

VCF::HTMLDocument Win32HTMLBrowser::getDocument()
{
	VCF::HTMLDocument result;

	VCF::HTMLDocumentPeer doc;
	com_ptr<IDispatch> disp;
	browser_->get_Document( disp.out() );
	
	if ( disp ) {
		doc = com_cast(disp);
		result.setPeer( &doc );
	}	

	return result;
}

void Win32HTMLBrowser::onDownloadComplete()
{

}

void Win32HTMLBrowser::onProgressChange( long x, long y )
{
	HTMLEvent e(peerControl_,HTMLBrowserControl::heURLLoading);
	e.maxValue = y;
	e.value = x;

	HTMLBrowserControl* browserCtrl = (HTMLBrowserControl*)peerControl_;
	browserCtrl->URLLoading.fireEvent( &e );
}

void Win32HTMLBrowser::onStatusTextChange( BSTR val )
{
	HTMLEvent e(peerControl_,HTMLBrowserControl::heStatusChanged);
	bstr_t tmp(val);
	e.status = tmp.c_str();

	HTMLBrowserControl* browserCtrl = (HTMLBrowserControl*)peerControl_;
	browserCtrl->StatusChanged.fireEvent( &e );
}

void Win32HTMLBrowser::onDownloadBegin()
{
	HTMLEvent e(peerControl_,HTMLBrowserControl::heURLLoadingBegun);
	HTMLBrowserControl* browserCtrl = (HTMLBrowserControl*)peerControl_;
	browserCtrl->URLLoadingBegun.fireEvent( &e );
}

void Win32HTMLBrowser::onTitleChange( BSTR Text)
{
	HTMLEvent e(peerControl_,HTMLBrowserControl::heTitleChanged);
	bstr_t tmp(Text);
	e.status = tmp.c_str();
	HTMLBrowserControl* browserCtrl = (HTMLBrowserControl*)peerControl_;
	browserCtrl->TitleChanged.fireEvent( &e );
}

void Win32HTMLBrowser::onBeforeNavigate2( LPDISPATCH pDisp, 
							   VARIANT* URL, 
							   VARIANT* Flags, 
							   VARIANT* TargetFrameName, 
							   VARIANT* PostData, 
							   VARIANT* Headers, 
							   VARIANT_BOOL* Cancel )
{

}

void Win32HTMLBrowser::onNewWindow2( LPDISPATCH* ppDisp, VARIANT_BOOL* Cancel)
{
	HTMLBrowserControl* browserCtrl = (HTMLBrowserControl*)peerControl_;

	if ( !browserCtrl->getAllowsPopupWindows() ) {
		*Cancel = TRUE;
	}
	else {
		
		HTMLEvent e(peerControl_,HTMLBrowserControl::heNewWindowDisplayed);
		HTMLBrowserControl* browserCtrl = (HTMLBrowserControl*)peerControl_;
		
		browserCtrl->NewWindowDisplayed.fireEvent( &e );
	}
}

void Win32HTMLBrowser::onDocumentComplete( LPDISPATCH pDisp, VARIANT* URL)
{
	HTMLEvent e(peerControl_,HTMLBrowserControl::heURLLoaded);
	HTMLBrowserControl* browserCtrl = (HTMLBrowserControl*)peerControl_;

	if ( NULL != URL && URL->vt == VT_BSTR ) {
		bstr_t tmp;
		tmp = URL->bstrVal;
		e.url = tmp.c_str();
	}

	browserCtrl->URLLoaded.fireEvent( &e );
}

void Win32HTMLBrowser::onWindowClosing( VARIANT_BOOL IsChildWindow, VARIANT_BOOL* Cancel )
{

}

void Win32HTMLBrowser::onFileDownload( VARIANT_BOOL* Cancel )
{

}

void Win32HTMLBrowser::onNavigateError( LPDISPATCH pDisp, 
							 VARIANT* URL, 
							 VARIANT* Frame, 
							 VARIANT* StatusCode, 
							 VARIANT_BOOL* Cancel)
{
	HTMLEvent e(peerControl_,HTMLBrowserControl::heURLLoadingBegun);
	HTMLBrowserControl* browserCtrl = (HTMLBrowserControl*)peerControl_;

	if ( NULL != URL && URL->vt == VT_BSTR ) {
		bstr_t tmp;
		tmp = URL->bstrVal;
		e.url = tmp.c_str();
	}

	hresult hr = (HRESULT) StatusCode->lVal;
	e.status = hr.toString();

	browserCtrl->URLLoadError.fireEvent( &e );
}

STDMETHODIMP Win32HTMLBrowser::ShowContextMenu( DWORD hWndID, POINT *ppt, 
								IUnknown *pcmdtReserved, IDispatch *pdispReserved)
{
	HTMLBrowserControl* browserCtrl = (HTMLBrowserControl*)peerControl_;

	ControlPopupMenuMenuEvent e(this,Control::BEFORE_POPUP_MENU);
	e.popupMenu = peerControl_->getPopupMenu();
	peerControl_->BeforePopupMenu.fireEvent( &e );
	if ( (NULL != e.popupMenu) && !e.cancelPopup ) {
		//point is in screen coords
		Point pt(ppt->x, ppt->y);
		//convert to client coords

		peerControl_->translateFromScreenCoords( &pt );
		e.popupMenu->popup( &pt );

		return S_OK; //we've handled this!
	}
	else if ( !browserCtrl->getAllowDefaultContextMenu() ) {
		//do nothing - we don't want the default context menu to show up!
		return S_OK;
	}

	return E_NOTIMPL;
}

STDMETHODIMP Win32HTMLBrowser::GetHostInfo( DOCHOSTUIINFO *pInfo ) 
{
	pInfo->cbSize = sizeof(DOCHOSTUIINFO);
	pInfo->dwFlags = uiStyle_;

	pInfo->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT;

	return S_OK;
}

STDMETHODIMP Win32HTMLBrowser::OnDocWindowActivate( BOOL fEnable ) 
{
	return E_NOTIMPL;
}

STDMETHODIMP Win32HTMLBrowser::OnFrameWindowActivate( BOOL fEnable ) 
{
	return E_NOTIMPL;
}

STDMETHODIMP Win32HTMLBrowser::QueryService( REFGUID guidService, REFIID riid, void **ppv )
{
	HTMLBrowserControl* browserCtrl = (HTMLBrowserControl*)peerControl_;
	if ( riid == IID_IAuthenticate && !browserCtrl->getUseDefaultAuthenticationUI() ) {		
		IAuthenticateImpl* authenticater = this;

		*ppv = (IAuthenticate*) authenticater;

		return S_OK;
	}
	return E_NOINTERFACE;
}

STDMETHODIMP Win32HTMLBrowser::Authenticate( HWND* phwnd, LPWSTR* pszUsername, 
							LPWSTR* pszPassword)
{	
	HTMLAuthenticationEvent e(peerControl_, loadingURL_ );

	HTMLBrowserControl* browserCtrl = (HTMLBrowserControl*)peerControl_;
	browserCtrl->AuthenticationRequested.fireEvent( &e );

	if ( e.authenticationCancelled ) {
		return E_ACCESSDENIED;
	}

	if ( e.userName.empty() && e.password.empty() ) {
		return E_ACCESSDENIED;
	}

	*phwnd = NULL;

	*pszUsername = (LPWSTR) CoTaskMemAlloc( e.userName.size_in_bytes() + sizeof(WCHAR) );
	memset( *pszUsername, 0, e.userName.size_in_bytes() + sizeof(WCHAR) );
	e.userName.copy( *pszUsername, e.userName.size() );

	*pszPassword = (LPWSTR) CoTaskMemAlloc( e.password.size_in_bytes() + sizeof(WCHAR) );
	memset( *pszPassword, 0, e.password.size_in_bytes() + sizeof(WCHAR) );
	e.password.copy( *pszPassword, e.password.size() );

	return S_OK;
}



using namespace VCF;


void initWin32HTMLBrowserLib( HMODULE module )
{
	if ( module == NULL ) {
		module = GetModuleHandle(NULL);
	}

	REGISTER_CLASSINFO( Win32HTMLBrowser );
}

void terminateWin32HTMLBrowserLib()
{
	
}



#ifdef _USRDLL

BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    switch ( ul_reason_for_call ) {
		case DLL_PROCESS_ATTACH:  {
			initWin32HTMLBrowserLib((HINSTANCE) hModule);
		}
		break;

		case DLL_THREAD_ATTACH: {

		}
		break;

		case DLL_THREAD_DETACH:  {

		}
		break;

		case DLL_PROCESS_DETACH:  {
			terminateWin32HTMLBrowserLib();
		}
		break;
    }
    return TRUE;
}

#endif


/**
*CVS Log info
*$Log$
*Revision 1.4.2.7  2006/02/15 05:14:33  ddiego
*more browser code.
*
*Revision 1.4.2.6  2006/02/14 22:04:24  ddiego
*more html updates.
*
*Revision 1.4.2.5  2006/02/14 05:13:09  ddiego
*more browser updates.
*
*Revision 1.4.2.4  2006/02/13 22:11:59  ddiego
*added further html support and better browser example code.
*
*Revision 1.4.2.3  2006/02/13 05:10:32  ddiego
*added better html browser support.
*
*Revision 1.4.2.2  2006/02/10 02:26:44  ddiego
*vc80 updates for comet.
*
*Revision 1.4.2.1  2006/02/09 04:54:02  ddiego
*added missing lib tiff project for vc80. Also removed
*ATL dependency and comdef.h dependency. We are now using comet for
*basic COM types, and I have a new chunk of code that implements the
*basics for hosting the browser.
*
*Revision 1.4  2005/07/09 23:14:58  ddiego
*merging in changes from devmain-0-6-7 branch.
*
*Revision 1.3.2.1  2005/02/21 19:07:10  ddiego
*fixed missing code from createParam changes in win32 html browser kit
*
*Revision 1.3  2004/12/01 04:31:39  ddiego
*merged over devmain-0-6-6 code. Marcello did a kick ass job
*of fixing a nasty bug (1074768VCF application slows down modal dialogs.)
*that he found. Many, many thanks for this Marcello.
*
*Revision 1.2.2.1  2004/09/08 01:16:49  ddiego
*fixed incorrect win32htmlbrowser function due to changes from weekend.
*
*Revision 1.2  2004/08/07 02:49:11  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.3  2004/07/30 17:27:14  kiklop74
*Added first release of Borland midifications for VCF
*
*Revision 1.1.2.2  2004/04/29 03:43:15  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:20  ddiego
*migration towards new directory structure
*
*Revision 1.10.4.3  2004/04/26 16:43:34  ddiego
*checked in some minor fixes to some of the other
*libraries due to switch over to unicode
*
*Revision 1.10.4.2  2004/04/21 02:17:25  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.10.4.1  2004/04/07 03:25:57  ddiego
*fixed Win32HTMLBrowser ATL assert bug. The problem was a minor
*to teh ATL CComModule.Init() function. In VC6 version it just needed
*an HINSTANCE and and object map, in VC7 it also needs a GUID for the lib.
*Of course this is helpfully set to an INVALID default parameter, which is
*nice, I suppose.
*
*Revision 1.10  2003/12/18 05:16:01  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.9.2.1  2003/09/02 02:11:14  ddiego
*fixed some glitches in drag drop. also cleaned up the drag drop event
*classes. Began some fixes to the html browser implementation on Win32
*
*Revision 1.9  2003/08/09 02:56:46  ddiego
*merge over from the devmain-0-6-1 branch
*Changes
*Features:
*-Added additional implementation to better support the MVC architecture in
*the VCF
*
*-Added a Document/View architecure that is similar to MFC's or NextSteps's
*Doc/View architectures
*
*-Integrated the Anti Grain Graphics library into the GraphicsKit. There is
*now basic support for it in terms of drawing vector shapes
*(fills and strokes). Image support will come in the next release
*
*-Added several documented graphics tutorials
*
*Bugfixes:
*
*[ 775744 ] wrong buttons on a dialog
*[ 585239 ] Painting weirdness in a modal dialog ?
*[ 585238 ] Modal dialog which makes a modal Dialog
*[ 509004 ] Opening a modal Dialog causes flicker
*[ 524878 ] onDropped not called for MLTcontrol
*
*Plus an issue with some focus and getting the right popup window to activate
*has also been fixed
*
*Revision 1.8.2.1  2003/08/06 21:28:02  ddiego
*minor changes
*
*Revision 1.8  2003/05/17 20:37:36  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.7.2.2  2003/03/23 03:23:57  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.7.2.1  2003/03/12 03:12:38  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.7  2003/02/26 04:30:51  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.6.2.2  2002/12/28 01:56:22  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.6.2.1  2002/12/27 23:04:54  marcelloptr
*Improved macros for automatic import/export of libraries. - Warning fixes. - Other Minor Changes.
*
*Revision 1.6  2002/11/18 00:46:09  ddiego
*this is the merge over of all the bug fixes and features (mostly
*VCF Builder stuff) from the devmain-0-5-8 branch
*
*Revision 1.5.10.1  2002/11/06 01:03:02  ddiego
*bug fixes, made the Win32HTMLBrowser get rid of the ATL.dll dependencies
*also made changes to the VCF Builder installer
*
*Revision 1.5  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.4.4.1  2002/04/08 20:55:30  zzack
*changed include style
*
*Revision 1.4  2002/01/29 04:41:43  ddiego
*fixed leak in Win32Button, plus cleaned up some other GetDC stuff and
*fixed the Tab problem in Win98.
*
*Revision 1.3  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


