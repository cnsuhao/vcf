#if     _MSC_VER > 1000
#pragma once
#endif




#ifndef _VCF_SLIDERCONTROL_H__
#define _VCF_SLIDERCONTROL_H__

/**
Copyright (c) 2000-2001, Jim Crafton
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
	Redistributions of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.

	Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in 
	the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

NB: This software will not save the world.
*/

//SliderControl.h


namespace VCF {


#define SLIDERCONTROL_CLASSID		"e5b77d23-4a5f-42e5-adba-e2bde202206e"


class APPKIT_API SliderControl : public CustomControl {
public:

	enum DisplayOrientation {
		doHorizontal = 0,
		doVertical
	};

	enum TickMarkStyle {
		tmsNone = 0,
		tmsTopLeft = 0x01,
		tmsBottomRight = 0x02
	};

	enum {
		PositionChangedEvent = 546600
	};

	SliderControl();

	DELEGATE(PositionChanged)

	virtual double getPreferredWidth();

	virtual double getPreferredHeight();

	virtual void paint( GraphicsContext* ctx );

	virtual void mouseDown( MouseEvent* e );

	virtual void mouseMove( MouseEvent* e );

	virtual void mouseUp( MouseEvent* e );

	virtual void keyDown( KeyboardEvent* e );

	virtual void keyUp( KeyboardEvent* e );



	DisplayOrientation getDisplayOrientation() {
		return orientation_;
	}

	void setDisplayOrientation( const DisplayOrientation& val );

	double getMinValue() {
		return minVal_;
	}

	void setMinValue( const double& val );

	double getMaxValue() {
		return maxVal_;
	}

	void setMaxValue( const double& val );

	double getPosition() {
		return position_;
	}

	void setPosition( const double& val );

	bool hasTickMarks() {
		return hasTickMarks_;
	}
	void setHasTickMarks( const bool& val );


	long getTickMarkStyle() {
		return tickMarkStyle_;
	}
	
	bool hasNoTickMarks();
	bool hasTickMarksOnTopLeft();
	bool hasTickMarksOnBottomRight();

	void setTickMarkStyle( const long& val );

	long getTickFrequency() {
		return tickFrequency_;
	}

	void setTickFrequency( const long& val );

	double getStepIncrement() {
		return stepIncrement_;
	}

	void setStepIncrement( const double& val );

	double getPageIncrement() {
		return pageIncrement_;
	}

	void setPageIncrement( const double& val );


protected:	

	DisplayOrientation orientation_;
	double minVal_;
	double maxVal_;
	double position_;
	bool hasTickMarks_;
	long tickMarkStyle_;
	long tickFrequency_;
	Point dragPosStart_;
	bool pressed_;
	double stepIncrement_;
	double pageIncrement_;

	void movePosition( MouseEvent* e );
};


};



/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 00:28:19  ddiego
*migration towards new directory structure
*
*Revision 1.2.4.1  2004/04/26 21:58:21  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.2  2003/12/18 05:15:57  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.1.2.3  2003/10/28 04:06:10  ddiego
*updated the GraphicsContext and ContextPeer classes to support
*slider control drawing. adjusted the Slider control accordingly.
*Also changed some of the GraphicsKit headers to conform to the
*current header style.
*
*Revision 1.1.2.2  2003/10/27 04:20:35  ddiego
*more tweaks to the Slider control
*
*Revision 1.1.2.1  2003/10/25 04:30:20  ddiego
*added two more examples one for progress bars and one for slider controls.
*also added two more control classes to the ApplicationKit, a SliderControl
*and a ProgressControl.
*
*/


#endif // _VCF_SLIDERCONTROL_H__



