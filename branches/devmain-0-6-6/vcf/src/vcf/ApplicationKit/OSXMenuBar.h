#ifndef _VCF_OSXMENUBAR_H__
#define _VCF_OSXMENUBAR_H__
//OSXMenuBar.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/



#include "vcf/ApplicationKit/MenuBarPeer.h"


namespace VCF  {

class OSXMenuBar : public MenuBarPeer {
public:
	OSXMenuBar( MenuBar* menuBar );

	virtual ~OSXMenuBar();

	virtual void setFrame( Frame* frame );

	virtual void update();

	virtual void setMenuItems( MenuItem* item );
private:
	MenuItem* menuRoot_;
	Frame* frame_;

};

};


/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/11/10 06:16:40  ddiego
*started adding osx menu code
*
*/

#endif //_VCF_OSXMENUBAR_H__

