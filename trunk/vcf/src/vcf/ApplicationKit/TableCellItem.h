#ifndef _VCF_TABLECELLITEM_H__
#define _VCF_TABLECELLITEM_H__
//TableCellItem.h

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

class TableItemEditor;

#define TABLECELLITEM_CLASSID		"53EA0BA2-7068-11d4-8F12-00207811CFAB"

/**
\class TableCellItem TableCellItem.h "vcf/ApplicationKit/TableCellItem.h"
*/
class APPLICATIONKIT_API TableCellItem : public Item {
public:

	enum TableCellItemState {
		tcsNone = 0,
		tisSelected = 0x0002,
		tisReadonly = 0x0008,
		tcsFixed = 0x0010,
		tcsFocused = 0x0001,
		tcsDropHighlighted = 0x0004,
		tcsEditable = 0x0100
	};

	virtual ~TableCellItem(){};

	/**

	Calling this will create a new table item editor.

	The implementor is responsible for returning an
	editor that is properly initialized with the data 
	from the item.
	@return TableItemEditor an new instance of an editor, or
	NULL if no editing is supported. If isReadonly() returns
	true, then this should return NULL regardless of whether 
	or not the item implementation supports and editor or 
	not.

	@see isReadonly()
	*/
	virtual TableItemEditor* createItemEditor() = 0;

	virtual bool isSelected() = 0;

	/**
	Identifies if this item is in a readonly state, or if 
	it's possible to edit it. 
	*/
	virtual bool isReadonly() = 0;

	virtual bool isFixed() = 0;

	virtual bool isFocused() = 0;

	virtual bool isDropHighlighted() = 0;

	virtual bool isEditable() = 0;

	virtual void setSelected( const bool& val ) = 0;

	virtual void setReadonly( const bool& val ) = 0;

	virtual void setFocused( const bool& val ) = 0;

	virtual void setDropHighlighted( const bool& val ) = 0;

	virtual void setFixed( const bool& val ) = 0;

	virtual String getCaption() = 0;

	virtual void setCaption( const String& caption ) = 0;

	/**
	rerturns the width of the cell, taking into account the
	text of the cell, and any other formatting rules the 
	cell wants to consider.
	*/
	virtual double getTextCellWidth( GraphicsContext* context ) = 0;
	virtual double getTextCellHeight( GraphicsContext* context ) = 0;

	/**
	Returns a non modifiable color reference. If you need to 
	change the cell's color, you should call setColor().
	@see setColor()
	*/
	virtual const Color& getColor() = 0;

	virtual void setColor( Color* color ) = 0;

	/**
	Returns a non modifiable font reference. If you need to 
	change the cell's font, you should call setFont().
	@see setFont()
	*/
	virtual const Font& getFont() = 0;

	virtual void setFont( Font* font ) = 0;
};

}


#endif // _VCF_TABLECELLITEM_H__

/**
$Id$
*/
