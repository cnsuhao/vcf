

#ifndef _VCF_DICTIONARY_H__
#define _VCF_DICTIONARY_H__

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


namespace VCF {


class DictionaryEnumerator : public Enumerator< std::pair<const String,VariantData> >{
public:	

	typedef String KeyType;
	typedef VariantData ValueType;

	typedef std::map<KeyType,ValueType> MapType;
	typedef std::pair<const KeyType,ValueType> PairType;
	DictionaryEnumerator( MapType& container ): container_(&container){		
		reset();
	};

	DictionaryEnumerator(): container_(NULL){};

	virtual ~DictionaryEnumerator(){};

	virtual void initContainer( MapType &container ){
		container_ = &container;
		reset();	
	};

	virtual Enumerator<PairType>* getEnumerator(){
		reset();
		return (Enumerator<PairType>*)this;
	};



	virtual bool hasMoreElements(const bool& backward=false){
		bool result = false;

		if ( true == backward ){
			result = containerIterator_ != container_->begin();
		}
		else{
			result = containerIterator_ != container_->end();
		}		
		
		return result;
	};

	virtual PairType nextElement(){		
		if (containerIterator_ != container_->end() ){
			PairType result = *containerIterator_;
			containerIterator_ ++;
			return result;
		}
		else {
			return *container_->end();
		}		
	};

	virtual PairType prevElement(){		
		if (containerIterator_ != container_->begin() ){
			containerIterator_ --;			
			return *containerIterator_;
		}
		else {				
			return *container_->begin();
		}				
	};

	virtual void reset(const bool& backward=false){
		
		if ( backward ){			
			containerIterator_ = container_->end();			
		}
		else {
			containerIterator_ = container_->begin();			
		}
	};

private:
	MapType::iterator containerIterator_;
	MapType* container_;
};


/**
<p>
The Dictionary class is a utility class useful storing a collection
of key-value pairs. It is not a separate implementation, but instead
uses the STL std::map as it's underlying data member. Usage of the
class is the same as the std::map, and it is basically the same 
as working with a std::map<String,VariantData>. The class
is intended for use when you want to have a named collection 
of various values. Using the VariantData as the value type, allows
you to easily store any type of value. For example:
<pre>
Dictionary dict;

dict["size"] = 200;
dict["Name"] = "Bob";
</pre>
We now have two entries, one name "Name" and one named "size".
</p>
<p>
The other primary difference from a std::map<String,VariantData> is 
the support for persistence. The Dictionary class implements
the Persistable interface, and can be written to, or read from, an
OutputStream or InputStream (respectively). For example, to save to a file:
<pre>
FileOutputStream fs("test.dict.txt");
fs &lt;&lt; &amp;dict;
</pre>
And to read from a file:
<pre>
FileInputStream fs("test.dict.txt");
fs &gt;&gt; &amp;dict;
</pre>
</p>
*/
class FRAMEWORK_API Dictionary : public Persistable {
public:
	
	typedef std::map<String,VariantData> DictionaryMap;
	
	typedef String Key;
    typedef VariantData Value;

	typedef std::pair<const String,VariantData> pair;
    typedef ulong32 size_type;    


	typedef Enumerator<pair> Enumerator;



	Dictionary();

	Dictionary( const Dictionary& rhs );

	Dictionary& operator=( const Dictionary& rhs );

	virtual ~Dictionary();
	
	
    size_type size() const;

    size_type max_size() const;

    bool empty() const;


	Value& operator[](const Key& key);

	Value operator[](const Key& key) const;

	void insert( const Key& key, const Value& value );

	void remove( const Key& key );

	void clear();

	virtual void loadFromStream( InputStream* stream );

	virtual void saveToStream( OutputStream* stream );

	Dictionary::Enumerator* getEnumerator();
protected:
	DictionaryMap data_;
	DictionaryEnumerator dataContainer_;
};




};




/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:39  ddiego
*migration towards new directory structure
*
*Revision 1.5.2.1  2004/04/26 21:58:48  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.5  2004/04/03 19:03:35  ddiego
*Added enumeration support for the Dictionary class,
*and updated the Dictionary example accordingly.
*
*Revision 1.4  2004/01/20 01:54:55  ddiego
*merged some more changes from dev branch, primarily changes to
*teh RTTI API so that we now process enum sets correctly (i.e. a long
*that is a mask made of enum values).
*
*Revision 1.2.2.2  2004/01/06 04:40:53  ddiego
*added first handler and setting the first handler to the delegate
*
*Revision 1.2.2.1  2004/01/05 05:45:17  ddiego
**** empty log message ***
*
*Revision 1.2  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.1.2.2  2003/11/24 05:05:23  ddiego
*added some more docs, and some minor changes to the Win32ScrollPeer
*
*Revision 1.1.2.1  2003/11/21 20:30:14  ddiego
**** empty log message ***
*
*/

#endif // _VCF_DICTIONARY_H__


