#if     _MSC_VER > 1000
#pragma once
#endif




#ifndef _VCF_PROGRESSCONTROL_H__
#define _VCF_PROGRESSCONTROL_H__
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

//ProgressControl.h





namespace VCF { 



#define PROGRESSCONTROL_CLASSID		"afb8b792-f354-4234-884d-ecccd277f9e8"


/**
The ProgressControl is a class that displays a vertical or horizontal 
progress bar showing the position of within a given range of a task.
*/
class APPKIT_API ProgressControl : public CustomControl {
public:
	enum ProgressAlignment {
		paVertical = 0,
		paHorizontal
	};

	ProgressControl();

	virtual ~ProgressControl();

	ProgressAlignment getDisplayAlignment() {
		return displayAlignment_;
	}

	void setDisplayAlignment( ProgressAlignment val );

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

	bool getDisplayProgressText() {
		return displayProgressText_;
	}

	void setDisplayProgressText( const bool& val );

	bool getUseProgressFormatString() {
		return useProgressFormatString_;
	}

	void setUseProgressFormatString( const bool& val );
	
	String getProgressFormatString() {
		return progressFormatString_;
	}

	void setProgressFormatString( const String& val );


	virtual double getPreferredWidth();

	virtual double getPreferredHeight();

	virtual void paint( GraphicsContext* ctx );

	void stepIt();

	double getStepItIncrement() {
		return stepItIncrement_;
	}

	void setStepItIncrement( const double& val );

	Color* getProgressBarColor() {
		return progressBarColor_;
	}
	void setProgressBarColor( Color* val );

	Color* getProgressTextColor() {
		return progressTextColor_;
	}
	void setProgressTextColor( Color* val );
protected:
	ProgressAlignment displayAlignment_;
	double minVal_;
	double maxVal_;
	double position_;
	bool displayProgressText_;
	bool useProgressFormatString_;
	String progressFormatString_;
	double stepItIncrement_;
	Color* progressBarColor_;
	Color* progressTextColor_;
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
*Revision 1.1.2.1  2003/10/25 04:30:20  ddiego
*added two more examples one for progress bars and one for slider controls.
*also added two more control classes to the ApplicationKit, a SliderControl
*and a ProgressControl.
*
*/


#endif // _VCF_PROGRESSCONTROL_H__



