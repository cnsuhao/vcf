#ifndef _TEXTEDITWINDOW_H__
#define _TEXTEDITWINDOW_H__
//TextEditWindow.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#define TEXTEDITWINDOW_CLASSID		"60614ad0-b9bb-40d4-94f3-34ceb0683c85"


/**
Include this file to access the various RTTI macros
for declaring RTTI information for your class(es)
*/
#include "vcf/FoundationKit/RTTIMacros.h"

/**
class TextEditWindow documentation
*/
class TextEditWindow  : public VCF::Window{
public: 
	_class_rtti_( TextEditWindow, "VCF::Window", TEXTEDITWINDOW_CLASSID )
	_class_rtti_end_

	TextEditWindow();
	virtual ~TextEditWindow();


protected:
	void onDocInitialized( VCF::Event* e ) ;	
	void onSelectionChanged( VCF::Event* e );
	void onModelChanged( VCF::Event* e );
	void initMenus();
	void initToolbar();

	void viewToolbarClicked( VCF::MenuItemEvent* e );
	void updateViewToolbar( VCF::MenuItemEvent* e );

	bool docSelectionChanging_;
};


/**
*CVS Log info
*$Log$
*Revision 1.2.2.2  2005/05/04 20:47:20  marcelloptr
*standard file formatting and cvs log section added
*
*/


#endif //_TEXTEDITWINDOW_H__



