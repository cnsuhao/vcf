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

//VariantData.cpp
#include "vcf/FoundationKit/FoundationKit.h"
using namespace VCF;



String VariantData::toString()
{
	String result = "";
	switch ( type ) {
		case pdInt:{
			int i = *this;
			char tmp[VariantData::DefaultPropertyValLength];
			memset(tmp, 0, VariantData::DefaultPropertyValLength);
			sprintf( tmp, "%d", i );
			result += tmp;
		}
		break;

		case pdLong:{
			int i = (long)*this;
			char tmp[VariantData::DefaultPropertyValLength];
			memset(tmp, 0, VariantData::DefaultPropertyValLength);
			sprintf( tmp, "%d", i );
			result += tmp;
		}
		break;

		case pdShort:{
			short i = *this;
			char tmp[VariantData::DefaultPropertyValLength];
			memset(tmp, 0, VariantData::DefaultPropertyValLength);
			sprintf( tmp, "%d", i );
			result += tmp;
		}
		break;

		case pdULong:{
			unsigned long i = *this;
			char tmp[VariantData::DefaultPropertyValLength];
			memset(tmp, 0, VariantData::DefaultPropertyValLength);
			sprintf( tmp, "%d", (int)i );
			result += tmp;
		}
		break;

		case pdFloat:{
			float i = *this;
			char tmp[VariantData::DefaultPropertyValLength];
			memset(tmp, 0, VariantData::DefaultPropertyValLength);
			sprintf( tmp, "%.5f", i );
			result += tmp;
		}
		break;

		case pdChar:{
			char i = *this;
			char tmp[VariantData::DefaultPropertyValLength];
			memset(tmp, 0, VariantData::DefaultPropertyValLength);
			sprintf( tmp, "%c", i );
			result += tmp;
		}
		break;

		case pdDouble:{
			double i = *this;
			char tmp[VariantData::DefaultPropertyValLength];
			memset(tmp, 0, VariantData::DefaultPropertyValLength);
			sprintf( tmp, "%.5f", i );
			result += tmp;
		}
		break;

		case pdBool:{
			bool i = *this;								
			result += i ? "true":"false";
		}
		break;

		case pdObject:{				
			Object* object = *this;
			if ( NULL != object ){
				//result += object->toString();
				Persistable* persist = dynamic_cast<Persistable*>(object);
				if ( NULL != persist ){
					TextOutputStream tos;

					persist->saveToStream( &tos );

					result += tos.getTextBuffer();
				}
				else {
					result += object->toString();
				}
			}
			else{
				result += "null";
			}
		}
		break;

		case pdInterface:{				
			Interface* intrFace = *this;
			if ( NULL != intrFace ){
				Persistable* persist = dynamic_cast<Persistable*>(intrFace);
				if ( NULL != persist ){
					TextOutputStream tos;

					persist->saveToStream( &tos );

					result += tos.getTextBuffer();
				}
				else {
					result += "null";
				}
			}
			else{
				result += "null";
			}
		}
		break;

		case pdString:{
			result = StringVal;
		}
		break;

		case pdEnum:{
			Enum* enumObj = *this;
			if ( NULL != enumObj ){
				result += enumObj->toString();
			}
			else{
				result += "null";
			}
		}
		break;

		case pdUndefined:{
			//no-op
		}
		break;
	}
	return result;
}


void VariantData::setFromString( const String& value )
{
	bool unicodeEnabled = System::isUnicodeEnabled();

	switch( type ){
		case pdInt:{
			int i = 0;
			if ( unicodeEnabled ) {
				swscanf( value.c_str(), W_STR_INT_CONVERSION, &i );
			}
			else {
				sscanf( value.ansi_c_str(), STR_INT_CONVERSION, &i );				
			}

			IntVal = i;
		}
		break;

		case pdLong:{
			int i = 0;
			if ( unicodeEnabled ) {
				swscanf( value.c_str(), W_STR_LONG_CONVERSION, &i );
			}
			else {
				sscanf( value.ansi_c_str(), STR_LONG_CONVERSION, &i );
			}
			LongVal = i;
		}
		break;

		case pdShort:{
			int i = 0;
			if ( unicodeEnabled ) {
				swscanf( value.c_str(), W_STR_SHORT_CONVERSION, &i );
			}
			else {
				sscanf( value.ansi_c_str(), STR_SHORT_CONVERSION, &i );
			}
			ShortVal = i;
		}
		break;

		case pdULong:{
			int i = 0;
			
			if ( unicodeEnabled ) {
				swscanf( value.c_str(), W_STR_ULONG_CONVERSION, &i );
			}
			else {
				sscanf( value.ansi_c_str(), STR_ULONG_CONVERSION, &i );
			}
			ULongVal = i;
		}
		break;

		case pdFloat:{
			float i = 0.0f;
			
			if ( unicodeEnabled ) {
				swscanf( value.c_str(), W_STR_FLOAT_CONVERSION, &i );
			}
			else {
				sscanf( value.ansi_c_str(), STR_FLOAT_CONVERSION, &i );
			}

			FloatVal = i;
		}
		break;

		case pdChar:{		

			if ( unicodeEnabled ) {
				WideChar i = '\0';
				

				swscanf( value.c_str(), W_STR_CHAR_CONVERSION, &i );

				CharVal = i;
			}
			else {
				char i = '\0';
				
				sscanf( value.ansi_c_str(), STR_CHAR_CONVERSION, &i );

				CharVal = i;
			}

			
		}
		break;

		case pdDouble:{
			float f = 0;
			
			if ( unicodeEnabled ) {
				swscanf( value.c_str(), W_STR_DOUBLE_CONVERSION, &f );
			}
			else {
				sscanf( value.ansi_c_str(), STR_DOUBLE_CONVERSION, &f );
			}

			DblVal = f;
		}
		break;

		case pdBool:{
			if ( value == STR_BOOL_CONVERSION_TRUE ){
				BoolVal = true;
			}
			else if ( value == STR_BOOL_CONVERSION_FALSE ){
				BoolVal = false;
			}
		}
		break;

		case pdObject:{				
			if ( NULL != ObjVal ){
				Persistable* persist = dynamic_cast<Persistable*>(ObjVal);
				if ( NULL != persist ){
					
					BasicInputStream bis( value );
					TextInputStream tis( &bis );
					persist->loadFromStream( &tis );
				}
				else if ( (value == L"NULL") || (value == L"null") || (value == L"nil") || (value == L"0") ) {
					ObjVal = NULL;
				}
			}				
		}
		break;

		case pdInterface:{				
			if ( NULL != InterfaceVal ){
				Persistable* persist = dynamic_cast<Persistable*>(InterfaceVal);
				if ( NULL != persist ){
					
					BasicInputStream bis( value );
					TextInputStream tis( &bis );
					persist->loadFromStream( &tis );
				}
				else if ( (value == L"NULL") || (value == L"null") || (value == L"nil") || (value == L"0") ) {
					ObjVal = NULL;
				}
			}				
		}
		break;

		case pdString:{
			StringVal = value;
		}
		break;

		case pdEnum:{
			if ( NULL != EnumVal.getEnum() ){
				EnumVal.set( value );
			}
		}
		break;
	}
}

void VariantData::setValue( const VariantData& value )
{
	type = value.type;
	switch( type ){
		case pdInt:{
			IntVal = value.IntVal;
		}
		break;

		case pdLong:{
			LongVal = value.LongVal;
		}
		break;

		case pdDouble:{
			DblVal = value.DblVal;
		}
		break;

		case pdBool:{
			BoolVal = value.BoolVal;
		}
		break;

		case pdObject:{
			ObjVal = value.ObjVal;
		}
		break;

		case pdInterface:{
			InterfaceVal = value.InterfaceVal;
		}
		break;
		
		case pdString:{
			StringVal = value.StringVal;
		}
		break;

		case pdEnum:{
			EnumVal = value.EnumVal;
		}
		break;

		case pdUndefined : {				
			
		}
		break;

		case pdShort : {
			ShortVal = value.ShortVal;
		}

		case pdULong : {
			ULongVal = value.ULongVal;
		} 
		break;

		case pdFloat : {				
			FloatVal = value.FloatVal;
		}
		break;

		case pdChar : {
			CharVal = value.CharVal;
		}
		break;
	}
}

/**
*CVS Log info
*$Log$
*Revision 1.1.2.1  2004/04/28 03:29:41  ddiego
*migration towards new directory structure
*
*Revision 1.2.4.1  2004/04/21 02:17:24  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.2  2003/12/18 05:16:00  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.1.2.1  2003/10/25 04:30:20  ddiego
*added two more examples one for progress bars and one for slider controls.
*also added two more control classes to the ApplicationKit, a SliderControl
*and a ProgressControl.
*
*/




