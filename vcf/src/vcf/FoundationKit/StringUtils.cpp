//StringUtils.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#include "vcf/FoundationKit/FoundationKit.h"
#include "vcf/FoundationKit/FoundationKitPrivate.h"
#include "vcf/FoundationKit/DateTime.h"


#define TO_STRING_TXT_SIZE		50

using namespace VCF;

String StringUtils::weekdays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
String StringUtils::abbrevWeekdays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
String StringUtils::months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
String StringUtils::abbrevMonths[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };




void StringUtils::traceWithArgs( String text,... )
{
//#ifdef _DEBUG
	va_list argList;

	va_start( argList, text );     // Initialize variable arguments.

	VCFChar* buf = new VCFChar[MAX_TRACE_STRING];
	memset( buf, 0, MAX_TRACE_STRING*sizeof(VCFChar) );

#ifdef VCF_GCC
	vswprintf( buf, MAX_TRACE_STRING, text.c_str(), argList );
#else
	_vsnwprintf( buf, MAX_TRACE_STRING, text.c_str(), argList );
#endif

	va_end( argList );              // Reset variable arguments.

	StringUtils::trace( String(buf) );

	delete [] buf;
//#endif
}


void StringUtils::trace( const String& text )
{
#ifdef _DEBUG

#ifdef WIN32
	VCFWin32::Win32Utils::trace( text );
#else
	wprintf( text.c_str() );
#endif

#endif
}

String StringUtils::trimLeft( const String& text, const char& c )
{
	String result = text;

	for (int n=0; n<result.length(); ++n) {
		if (result[0] != c) {
			break;
		}
		result.erase(0,1);
	}

	return result;
}

String StringUtils::trimRight( const String& text, const char& c )
{
	String result = text;

	for (int n=result.length()-1; 0<=n; --n) {
		if (result[n] != c) {
			break;
		}
		result.erase(n,1);
	}

	return result;
}

String StringUtils::trim( const String& text, const char& c )
{
	String result;
	result = trimLeft(text, c);
	result = trimRight(result, c);
	return result;
}

void StringUtils::trimWhiteSpacesLeft( String& text )
{
	for (int n=0; n<text.length(); ++n) {
		if (text[0] == ' ' || text[0] == '\t'|| text[0] == '\r'|| text[0] == '\n' ) {
			text.erase(0,1);
		} else {
			break;
		}
	}
}

void StringUtils::trimWhiteSpacesRight( String& text )
{
	for (int n=text.length()-1; 0<=n; --n) {
		if (text[n] == ' ' || text[n] == '\t' || text[n] == '\r' || text[n] == '\n' ) {
			//text[n]=0;			// error: this doesn't update text.size()
			text.erase(n,1);
		} else {
			break;
		}
	}
}

void StringUtils::trimWhiteSpaces( String& text )
{
	trimWhiteSpacesLeft(text);
	trimWhiteSpacesRight(text);
}

String StringUtils::lowerCase( const String& text )
{
	String result;

	VCFChar* copyText = new VCFChar[text.size()+1];
	memset(copyText, 0, (text.size()+1)*sizeof(VCFChar) );
	text.copy( copyText, text.size() );

#ifdef _MSC_VER
	_wcslwr( copyText ); // not in ANSI standard library
#endif

	result = copyText;
	delete [] copyText;
	return result;
}

String StringUtils::upperCase( const VCF::String& text )
{
	String result;
	VCFChar* copyText = new VCFChar[text.size()+1];
	memset(copyText, 0, (text.size()+1)*sizeof(VCFChar) );
	text.copy( copyText, text.size() );

#ifdef _MSC_VER
	*_wcsupr( copyText );
#endif

	result = copyText;
	delete [] copyText;
	return result;
}

VCF::String StringUtils::toString( const int& value )
{
	VCFChar tmp[TO_STRING_TXT_SIZE];
	memset( tmp, 0, TO_STRING_TXT_SIZE * sizeof(VCFChar) );
#ifdef VCF_POSIX
	swprintf( tmp, sizeof(tmp)-1, L"%d", value  );
#else
	swprintf( tmp, L"%d", value );
#endif
	return String( tmp );
}

VCF::String StringUtils::toString( const long& value )
{
	VCFChar tmp[TO_STRING_TXT_SIZE];
	memset( tmp, 0, TO_STRING_TXT_SIZE * sizeof(VCFChar) );
#ifdef VCF_POSIX
	swprintf( tmp, sizeof(tmp)-1, L"%d", value  );
#else
	swprintf( tmp, L"%d", value );
#endif
	return String( tmp );
}

VCF::String StringUtils::toString( const float& value )
{
	VCFChar tmp[TO_STRING_TXT_SIZE];
	memset( tmp, 0, TO_STRING_TXT_SIZE * sizeof(VCFChar) );
#ifdef VCF_POSIX
	swprintf( tmp, sizeof(tmp)-1, L"%.5f", value  );
#else
	swprintf( tmp, L"%.5f", value );
#endif
	return String( tmp );
}

VCF::String StringUtils::toString( const double& value )
{
	VCFChar tmp[TO_STRING_TXT_SIZE];
	memset( tmp, 0, TO_STRING_TXT_SIZE * sizeof(VCFChar) );

#ifdef VCF_POSIX
	swprintf( tmp, sizeof(tmp)-1, L"%.5f", value  );
#else
	swprintf( tmp, L"%.5f", value );
#endif
	return String( tmp );
}

VCF::String StringUtils::toString( const ulong32& value )
{
	VCFChar tmp[TO_STRING_TXT_SIZE];
	memset( tmp, 0, TO_STRING_TXT_SIZE * sizeof(VCFChar) );
#ifdef VCF_POSIX
	swprintf( tmp, sizeof(tmp)-1, L"%d", (int)value  );
#else
	swprintf( tmp, L"%d", (int)value );
#endif
	return String( tmp );
}

VCF::String StringUtils::toString( const uint32& value )
{
	VCFChar tmp[TO_STRING_TXT_SIZE];
	memset( tmp, 0, TO_STRING_TXT_SIZE * sizeof(VCFChar) );
#ifdef VCF_POSIX
	swprintf( tmp, sizeof(tmp)-1, L"%d", value  );
#else
	swprintf( tmp, L"%d", value );
#endif
	return String( tmp );
}

VCF::String StringUtils::toString( const char& value )
{
	VCFChar tmp[TO_STRING_TXT_SIZE];
	memset( tmp, 0, TO_STRING_TXT_SIZE * sizeof(VCFChar) );

#ifdef VCF_POSIX
	swprintf( tmp, sizeof(tmp)-1, L"%c", value  );
#else
	swprintf( tmp, L"%c", value );
#endif
	return String( tmp );
}

VCF::String StringUtils::toString( const bool& value )
{
	return ( value == true ) ? L"true" : L"false";
}

VCF::String StringUtils::newUUID()
{
	VCF::String result = "";
#ifdef WIN32
	UUID id;
	if ( RPC_S_OK == ::UuidCreate( &id ) ){
		unsigned char *tmpid = NULL;

		RPC_STATUS rpcresult = UuidToString(  &id, &tmpid );

		if ( RPC_S_OUT_OF_MEMORY != rpcresult ) {
			result = VCF::String( (VCFChar*)tmpid );

			RpcStringFree( &tmpid );
		}
	}
#endif
	return result;
}

VCF::String StringUtils::format( VCF::String formatText, ... )
{
	VCF::String result = "";

	va_list argList;

	va_start( argList, formatText );     // Initialize variable arguments.

	VCFChar* buf = new VCFChar[MAX_TRACE_STRING];
	memset( buf, 0, MAX_TRACE_STRING*sizeof(VCFChar) );

#ifdef VCF_POSIX
	vswprintf( buf, MAX_TRACE_STRING, formatText.c_str(), argList );
#else
	_vsnwprintf( buf, MAX_TRACE_STRING, formatText.c_str(), argList );
#endif

	va_end( argList );              // Reset variable arguments.

	result = buf;

	delete [] buf;

	return result;
}

VCF::String StringUtils::getClassNameFromTypeInfo( const std::type_info& typeInfo  )
{
	VCF::String result = "";
#ifdef WIN32 //don't know if we really need this here
		std::string tmp = typeInfo.name();  //put back in when we find typeid
		//strip out the preceding "class" or "enum" or whatever
		std::string::size_type idx = tmp.find( " " );
		if ( idx != tmp.npos ) {
			tmp = tmp.substr( idx+1 );
		}

	#ifndef KEEP_NAMESPACE_IN_CLASSNAME

		std::string::size_type idx = tmp.find( "::" );
		if ( idx == tmp.npos ) {
			result = tmp;  // not part of a namespace
		} else {
			result = tmp.substr( idx + 2 );  // strip namespace off from string
		}

	#else

		result = tmp;

	#endif

#else
		result = typeInfo.name();
#endif

	return result;
}

int StringUtils::fromStringAsInt( const VCF::String& value )
{
	int result = 0;
	swscanf( value.c_str(), W_STR_INT_CONVERSION, &result );
	return result;
}

VCF::uint32 StringUtils::fromStringAsUInt( const VCF::String& value )
{
	uint32 result = 0;
	swscanf( value.c_str(), W_STR_ULONG_CONVERSION, &result );
	return result;
}

char StringUtils::fromStringAsChar( const VCF::String& value )
{
	char result = 0;
	swscanf( value.c_str(), W_STR_CHAR_CONVERSION, &result );
	return result;
}

short StringUtils::fromStringAsShort( const VCF::String& value )
{
	int result = 0;
	swscanf( value.c_str(), W_STR_SHORT_CONVERSION, &result );
	return (short)result;
}

float StringUtils::fromStringAsFloat( const VCF::String& value )
{
	float result = 0;
	swscanf( value.c_str(), W_STR_FLOAT_CONVERSION, &result );
	return result;
}

double StringUtils::fromStringAsDouble( const VCF::String& value )
{
	float result = 0;
	swscanf( value.c_str(), W_STR_DOUBLE_CONVERSION, &result );
	return result;
}

bool StringUtils::fromStringAsBool( const VCF::String& value )
{
	bool result = false;
	if ( value == W_STR_BOOL_CONVERSION_TRUE ){
		result = true;
	}
	else if ( value == W_STR_BOOL_CONVERSION_FALSE ){
		result = false;
	}

	return result;
}


VCF::String StringUtils::format( const DateTime& date, const String& formatting )
{
	String result;

	const VCFChar* P = formatting.c_str();
	const VCFChar* start = P;
	const VCFChar* current = P;
	int size = formatting.size();
	int pos = 0;
	unsigned long  y = date.getYear();
	unsigned long m = date.getMonth();
	unsigned long d = date.getDay();

	VCFChar tmp[256];

	bool hashCharFound = false;
	int formatArgCount = 1;

	while ( (P-start) < size ) {
		if ( ('%' == *P) || (hashCharFound) ) {

			P++;

			switch ( *P ) {
				case '#' : {
					hashCharFound = true;
					formatArgCount = 2;
					P --;
				}
				break;

				//	%% - Percent sign
				case '%' : {
					result.append( current, (P-current) -formatArgCount );
					result += "%";

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%a - Abbreviated weekday name
				case 'a' : {
					result.append( current, (P-current) -formatArgCount );

					result += StringUtils::abbrevWeekdays[date.getWeekDay()];

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%A - Full weekday name
				case 'A' : {
					result.append( current, (P-current) -formatArgCount );

					result += StringUtils::weekdays[date.getWeekDay()];

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%b - Abbreviated month name
				case 'b' : {
					result.append( current, (P-current) -formatArgCount );

					result += StringUtils::abbrevMonths[m-1];

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%B - Full month name
				case 'B' : {
					result.append( current, (P-current) -formatArgCount );

					result += StringUtils::months[m-1];

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%c - Date and time representation appropriate for locale
				case 'c' : {
					result.append( current, (P-current) -formatArgCount );

					result += L"{insert Locale date/time here}";

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%d - Day of month as decimal number (01 – 31)
				case 'd' : {
					result.append( current, (P-current) -formatArgCount );

					if ( hashCharFound ) {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%d", d );
					#else
						swprintf( tmp, L"%d", d );
					#endif

					}
					else {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%02d", d );
					#else
						swprintf( tmp, L"%02d", d );
					#endif
					}

					result += tmp;

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%D - Day of the year as decimal number	// added
				case 'D' : {
					result.append( current, (P-current) -formatArgCount );

					#ifdef VCF_POSIX
					swprintf( tmp, sizeof(tmp)-1, L"%d", date.getDayOfYear() );
					#else
					swprintf( tmp, L"%d", date.getDayOfYear() );
					#endif

					result += tmp;

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%H - Hour in 24-hour format (00 – 23)
				case 'H' : {
					result.append( current, (P-current) -formatArgCount );

					if ( hashCharFound ) {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%d", date.getHour() );
					#else
						swprintf( tmp, L"%d", date.getHour() );
					#endif
					}
					else {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%02d", date.getHour() );
					#else
						swprintf( tmp, L"%02d", date.getHour() );
					#endif
					}

					result += tmp;

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%I - Hour in 12-hour format (01 – 12)
				case 'I' : {
					result.append( current, (P-current) -formatArgCount );

					int h = date.getHour() % 12;
					if ( h == 0 ) {
						h = 12;
					}
					if ( hashCharFound ) {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%d", h );
					#else
						swprintf( tmp, L"%d", h );
					#endif
					}
					else {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%02d", h );
					#else
						swprintf( tmp, L"%02d", h );
					#endif
					}

					result += tmp;

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%j - Day of year as decimal number (001 – 366)
				case 'j' : {
					result.append( current, (P-current) -formatArgCount );



					if ( hashCharFound ) {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%d", date.getDayOfYear()  );
					#else
						swprintf( tmp, L"%d", date.getDayOfYear()  );
					#endif
						result += tmp;
					}
					else {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%03d", date.getDayOfYear()  );
					#else
						swprintf( tmp, L"%03d", date.getDayOfYear()  );
					#endif
						result += tmp;
					}


					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%m - Month as decimal number (01 – 12)
				case 'm' : {
					result.append( current, (P-current) -formatArgCount );

					if ( hashCharFound ) {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%d", m  );
					#else
						swprintf( tmp, L"%d", m  );
					#endif
					}
					else {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%02d", m  );
					#else
						swprintf( tmp, L"%02d", m  );
					#endif

					}


					result += tmp;

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%M - Minute as decimal number (00 – 59)
				case 'M' : {
					result.append( current, (P-current) -formatArgCount );

					if ( hashCharFound ) {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%d", date.getMinute()  );
					#else
						swprintf( tmp, L"%d", date.getMinute()  );
					#endif
					}
					else {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%02d", date.getMinute()  );
					#else
						swprintf( tmp, L"%02d", date.getMinute()  );
					#endif
					}


					result += tmp;

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%p - Current locale's A.M./P.M. indicator for 12-hour clock
				case 'p' : {
					result.append( current, (P-current) -formatArgCount );

					result += L"{Locale's AM/PM indicator}";

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%S - Second as decimal number (00 – 59)
				case 'S' : {
					result.append( current, (P-current) -formatArgCount );

					if ( hashCharFound ) {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%d", date.getSeconds()  );
					#else
						swprintf( tmp, L"%d", date.getSeconds()  );
					#endif
					}
					else {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%02d", date.getSeconds()  );
					#else
						swprintf( tmp, L"%02d", date.getSeconds()  );
					#endif
					}


					result += tmp;

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%U - Week of year as decimal number, with Sunday as first day of week (00 – 53)
				case 'U' : {
					result.append( current, (P-current) -formatArgCount );

					if ( hashCharFound ) {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%d", date.getWeekOfYearStartingSun()  );
					#else
						swprintf( tmp, L"%d", date.getWeekOfYearStartingSun()  );
					#endif
					}
					else {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%02d", date.getWeekOfYearStartingSun()  );
					#else
						swprintf( tmp, L"%02d", date.getWeekOfYearStartingSun()  );
					#endif
					}

					result += tmp;

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%w - Weekday as decimal number (0 – 6; Sunday is 0)
				case 'w' : {
					result.append( current, (P-current) -formatArgCount );

					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%d", (int)date.getWeekDay()  );
					#else
						swprintf( tmp, L"%d", (int)date.getWeekDay()  );
					#endif

					result += tmp;

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%W - Week of year as decimal number, with Monday as first day of week (00 – 53)
				case 'W' : {
					result.append( current, (P-current) -formatArgCount );

					if ( hashCharFound ) {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%d", date.getWeekOfYearStartingMon()  );
					#else
						swprintf( tmp, L"%d", date.getWeekOfYearStartingMon()  );
					#endif
					}
					else {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%02d", date.getWeekOfYearStartingMon()  );
					#else
						swprintf( tmp, L"%02d", date.getWeekOfYearStartingMon()  );
					#endif
					}

					result += tmp;

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;
				//	%x - Date representation for current locale
				case 'x' : {
					result.append( current, (P-current) -formatArgCount );

					result += L"{Locale's Date}";

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%X - Time representation for current locale
				case 'X' : {
					result.append( current, (P-current) -formatArgCount );

					result += L"{Locale's Time}";

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%y - Year without century, as decimal number (00 – 99)
				case 'y' : {
					result.append( current, (P-current) -formatArgCount );

					if ( hashCharFound ) {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%d", y % 100  );
					#else
						swprintf( tmp, L"%d", y % 100  );
					#endif
					}
					else {
					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%02d", y % 100  );
					#else
						swprintf( tmp, L"%02d", y % 100  );
					#endif
					}


					result += tmp;

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				//	%Y - Year with century, as decimal number
				case 'Y' : {
					result.append( current, (P-current) -formatArgCount );

					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%04d", y  );
					#else
						swprintf( tmp, L"%04d", y  );
					#endif


					result += tmp;

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				// %s - millisecond part
				case 's' : {
					result.append( current, (P-current) -formatArgCount );


					#ifdef VCF_POSIX
						swprintf( tmp, sizeof(tmp)-1, L"%04d", date.getMilliSeconds()  );
					#else
						swprintf( tmp, L"%04d", date.getMilliSeconds()  );
					#endif


					result += tmp;

					current = P + 1;
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;

				default : {
					hashCharFound = false;
					formatArgCount = 1;
				}
				break;
			}
		}
		P++;
	}

	if ( current < P ) {
		result.append( current, (P-current) );
	}

	return result;
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.3  2004/04/29 04:07:13  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.2  2004/04/28 18:42:26  ddiego
*migrating over changes for unicode strings.
*This contains fixes for the linux port and changes to the Makefiles
*
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.19.2.1  2004/04/21 02:17:27  ddiego
*checking in change to FoundationKit, GraphicsKit and Application
*Kit to support unicode in Win32
*
*Revision 1.19  2004/04/03 15:48:49  ddiego
*Merged over code from the 0-6-3 branch.
*
*Revision 1.17.2.5  2004/03/29 15:22:00  ddiego
*some minor fixes
*
*Revision 1.17.2.4  2004/03/21 00:39:24  ddiego
*merged vc7.1 changes into dev branch
*
*Revision 1.17.2.3  2004/02/21 03:27:10  ddiego
*updates for OSX porting
*
*Revision 1.17.2.2  2004/01/17 18:47:31  ddiego
*added a new example for DateTime calss and some other minor fixes to it
*
*Revision 1.17.2.1  2004/01/17 06:09:50  ddiego
*integrated the DateTime class into the VCF FoundationKit.
*
*Revision 1.17  2003/12/18 05:16:02  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.16.4.3  2003/11/10 01:57:43  ddiego
*add a fromString methods to StingUtils
*added some minor fixes to list box control and added a SelectionChanged
*Delegate to it
*add some minor fixes ot ComboBoxControl
*added an unknownColor() method to ColorNames class
*
*Revision 1.16.4.2  2003/08/20 22:55:20  ddiego
*got rid of some older methods for StringUtils, should be using the FilePath
*class instead
*
*Revision 1.16.4.1  2003/08/11 19:58:54  marcelloptr
*improvement: StringUtils::trimWhiteSpaces functions added
*
*Revision 1.16  2003/05/17 20:37:42  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.15.2.2  2003/03/23 04:06:34  marcelloptr
*minor fixes
*
*Revision 1.15.2.1  2003/03/23 03:23:59  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.15  2003/02/26 04:30:53  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.14.12.2  2003/01/08 03:49:21  ddiego
*fixes to ensure that move and size events get sent properly. Not sure
*I am happy with how it is currently working. Fix to X11Cursor so that the cursorID
*has a valid initial value.
*
*Revision 1.14.12.1  2002/12/28 21:51:20  marcelloptr
*Fixes and improvements for WM_COPYDATA, Point, Rect, Size, GraphicsContext and StringUtils
*
*Revision 1.14  2002/05/26 21:19:54  ddiego
*added and fixed xmake makefiles for FoundationKit and for the RTTI test
*so that this now runs under linux (should work fine for Solaris as well).
*Made some changes to Object for removing one of the operator delete() when
*using GCC
*Other minor changes to files to ensure that they end with a carriage return
*
*Revision 1.13  2002/05/09 03:10:45  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.12.4.2  2002/03/25 04:19:46  ddiego
*fixed some file checking problems in xmake and fixed some general
*code to be able to compile with GCC and Borland C++
*
*Revision 1.12.4.1  2002/03/20 21:56:57  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.12  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


