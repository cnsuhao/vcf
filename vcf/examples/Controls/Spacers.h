//ControlsAbout.h

#ifndef _SPACERS_H__
#define _SPACERS_H__


/**
*Class VerticalSpacer
*/
class VerticalSpacer : public VCF::CustomControl {
public :
	VerticalSpacer() : VCF::CustomControl( false ){
		setHeight( 1 );
		isTransparent_ = true;		
	}
	
	VerticalSpacer(double height) : VCF::CustomControl( false ){		
		setHeight( height );
		isTransparent_ = true;
	}

	virtual ~VerticalSpacer(){}

protected :

private :

};


/**
*Class HorizontalSpacer
*/
class HorizontalSpacer : public VCF::CustomControl {
public :
	HorizontalSpacer() : VCF::CustomControl( false ){
		setWidth( 1 );
		isTransparent_ = true;
	}
	
	HorizontalSpacer(double width) : VCF::CustomControl( false ){		
		setWidth( width );		
		isTransparent_ = true;
	}

	virtual ~HorizontalSpacer(){}

protected :

private :

};




#endif //_SPACERS_H__