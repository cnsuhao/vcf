#ifndef _TEXTEDITWINDOW_H__
#define _TEXTEDITWINDOW_H__


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




#endif //_TEXTEDITWINDOW_H__



