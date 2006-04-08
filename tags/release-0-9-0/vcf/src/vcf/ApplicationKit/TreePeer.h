#ifndef _VCF_TREEPEER_H__
#define _VCF_TREEPEER_H__
//TreePeer.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */





namespace VCF{

class ImageList;

class TreeItem;

class TreeModel;


/**
\class TreePeer TreePeer.h "vcf/ApplicationKit/TreePeer.h"  
*/

class APPLICATIONKIT_API TreePeer : public VCF::Interface {
public:
	virtual ~TreePeer(){};

    virtual TreeModel* getTreeModel() = 0;

	virtual void setTreeModel( TreeModel* model ) = 0;

    virtual double getItemIndent() = 0;

    virtual void setItemIndent( const double& indent ) = 0;

    virtual ImageList* getImageList() = 0;

    virtual void setImageList( ImageList* imageList ) = 0;

	virtual void setStateImageList( ImageList* imageList ) = 0;

	virtual void clear() = 0;

	virtual void addItem( TreeItem* item ) = 0;

	virtual Rect getItemImageRect( TreeItem* item ) = 0;

	virtual Rect getItemRect( TreeItem* item ) = 0;

	virtual bool getAllowLabelEditing() = 0;

	virtual void setAllowLabelEditing( const bool& allowLabelEditing ) = 0;
};

};


/**
*CVS Log info
*$Log$
*Revision 1.3  2006/04/07 02:35:26  ddiego
*initial checkin of merge from 0.6.9 dev branch.
*
*Revision 1.2.6.2  2006/03/16 03:23:09  ddiego
*fixes some font change notification issues in win32 peers.
*
*Revision 1.2.6.1  2006/03/14 02:25:47  ddiego
*large amounts of source docs updated.
*
*Revision 1.2  2004/08/07 02:49:10  ddiego
*merged in the devmain-0-6-5 branch to stable
*
*Revision 1.1.2.4  2004/07/16 05:07:18  ddiego
*added support for editing labels on a tree control
*
*Revision 1.1.2.3  2004/06/06 07:05:31  marcelloptr
*changed macros, text reformatting, copyright sections
*
*Revision 1.1.2.2  2004/04/29 03:43:15  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 00:28:19  ddiego
*migration towards new directory structure
*
*Revision 1.8.4.1  2004/04/26 21:58:41  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.8  2003/12/18 05:15:58  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.7.6.2  2003/09/21 04:15:35  ddiego
*moved the cvs info data to teh bottom of the header instead of the
*top so it is easier to get to the actual header class declarations
*instead of having to wade through all the cvs info stuff.
*
*Revision 1.7.6.1  2003/09/12 00:09:33  ddiego
*added better tabbing behaviour - fixed an earlier bug.
*Code is easier to understand and it simplified the implementation
*a bit as well
*Moved around the RTTI definitions for various Appkit classes to a
*single inline and stripped them from the various class headers
*
*Revision 1.7  2003/02/26 04:30:40  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.6.20.1  2002/12/25 22:38:00  ddiego
*more stupid fixes to get rid of the damn gcc no newline warning...grrr...
*
*Revision 1.6  2002/01/24 01:46:48  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_TREEPEER_H__


