//MainWindow.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#ifndef _MAINWINDOW_H__
#define _MAINWINDOW_H__

#include "vcf/ApplicationKit/ControlsKit.h"

/**
*Class MainWindow documentation
*/
class MainWindow : public VCF::Window { 
public:
	MainWindow();

	virtual ~MainWindow();
	void onHelpAbout( VCF::MenuItemEvent* e );
protected:

private:
	//Our primary TabbedPages control
	VCF::TabbedPages* mainPages;
	VCF::TabModel* mainPagesModel;

	//individual TabPage
	VCF::TabPage* listBoxPage;
	VCF::TabPage* bordersPage;
	
	//related to ListBoxTabPage
	void makeListBoxPage();
	void listBox1Change( VCF::ItemEvent* );
	void onbtnRemove( VCF::ButtonEvent* );
	void onbtnDeselect( VCF::ButtonEvent* );
	void onbtnAddItemClicked( VCF::ButtonEvent* );
	void onrbSingleSelClicked( VCF::ButtonEvent* );
	void onrbMultiSelClicked( VCF::ButtonEvent* );
	void onrbExtendedSelClicked( VCF::ButtonEvent* );
	VCF::ListBoxControl* listBox1;
	VCF::TextControl* txtCtrlAddToListBox;

	//related to bordersTabPage
	void makeBordersPage();
	
	

};


#endif //_MAINWINDOW_H__


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/08/30 03:50:47  dougtinkham
*added copyright
*
*/
