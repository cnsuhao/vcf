#ifndef _VCF_REFERENCES_H__
#define _VCF_REFERENCES_H__

// References.h

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.3.8.1  2004/04/26 21:58:48  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.3  2003/05/17 20:37:17  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.2.22.2  2003/03/23 03:23:53  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.2.22.1  2003/03/12 03:11:51  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.2  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/

//References.h

class RefCount {    

public:
    RefCount(){ 
		refCount_ = 0; 
	};

    virtual ~RefCount() { 
		//TRACE("goodbye(%d)\n", crefs); 
	};

    void addRef() { 
		++this->refCount_;
	};

    void removeRef(){
		if (--refCount_ == 0){
			delete this;
		}
		else{
			
		}
	};

private:
	int refCount_;
};

//template <class T> itNew


#endif // _VCF_REFERENCES_H__


