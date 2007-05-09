#ifndef _VCF_RADIOBUTTONCONTROL_H__
#define _VCF_RADIOBUTTONCONTROL_H__
//RadioButtonControl.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


/* Generated by Together */


#ifndef _VCF_TOGGLEDBUTTON_H__
#	include "vcf/ApplicationKit/ToggledButton.h"
#endif // _VCF_TOGGLEDBUTTON_H__



namespace VCF {

#define RADIOBUTTONCONTROL_CLASSID		"DC2FDA9C-5D3E-4949-B4BE-160B409BA7AF"

/**
\class RadioButtonControl RadioButtonControl.h "vcf/ApplicationKit/RadioButtonControl.h"
class RadioButtonControl documentation.
*/
class APPLICATIONKIT_API RadioButtonControl : public ToggledButton {
public:

	RadioButtonControl();
	virtual ~RadioButtonControl();

	virtual void paint( GraphicsContext* context );

	virtual double getPreferredHeight();

	virtual double getPreferredWidth();

	bool getUseFixedRadioButtonSize() {
		return useFixedRadioButtonSize_;
	}

	void setUseFixedRadioButtonSize( const bool& fixedRadioButtonSize );

	double getFixedRadioButtonHeight() {
		return fixedRadioButtonHeight_;
	}

	void setFixedRadioButtonHeight( const double& fixedRadioButtonHeight );

	void setGroupID( const int32& groupID );

	int32 getGroupID(){
		return groupID_;
	}

	virtual void setChecked( const bool& checked );

	RadioButtonControl* getSelectedRadioButtonFromGroup();

	bool generatePropertyValue( const String& fullPropertyName, Property* property, VariantData* value, String& strValue );
protected:
	/**
	This is for internal use only - it simply calls the 
	super class's setChecked() method - no other
	functionality is provided.
	*/
	void internal_setChecked( const bool& val ) {
		ToggledButton::setChecked( val );
	}
	bool useFixedRadioButtonSize_;
	double fixedRadioButtonHeight_;
    int32 groupID_;


};


}; // namespace VCF


#endif // _VCF_RADIOBUTTONCONTROL_H__

/**
$Id$
*/
