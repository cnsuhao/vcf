#ifndef _VCF_STRINGUTILS_H__
#define _VCF_STRINGUTILS_H__
//StringUtils.h

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


#if _MSC_VER > 1000
#   pragma once
#endif


#define MAX_TRACE_STRING		5000



/**
*The StringUtils class is a collection of static
*utility methods for operating on strings.
*/
// forward declaration needed for bcc32
class type_info;

namespace VCF {

class DateTime;

class FRAMEWORK_API StringUtils  {
public:

	/**
	*outs the text to the debugger output
	*@param String the text to output
	*/
	static void trace( const VCF::String& text );

	/**
	*Similar to trace() but allows variable arguments. Uses the
	*same formatting rules as printf().
	*@param String the text to trace out after formatting. See printf()
	*for formatting rules.
	*/
	static void traceWithArgs( VCF::String text,... );

	/**
	*formats a string. Uses the same formatting rules as
	*sprintf().
	*@param String the format text to use
	*@return String the formatted string
	*/
	static VCF::String format( VCF::String formatText, ... );

	/**
	*trim all the occurrences of a specified character
	* at the beginning of the string
	* until it is met the first character from the left that is different
	*@param String the text to trim
	*@param char the character to trim
	*@return String the trimmed string
	*/
	static VCF::String trimLeft( const VCF::String& text, const char& c );

	/**
	*trim all the occurrences of a specified character
	* at the end of the string
	* until it is met the first character from the right that is different
	*@param String the text to trim
	*@param char the character to trim
	*@return String the trimmed string
	*/
	static VCF::String trimRight( const VCF::String& text, const char& c );

	/**
	*trim all the occurrences of a specified character
	* at the beginning and the end of the string
	* i.e. calls trimLeft + trimRight
	*@param String the text to trim
	*@param char the character to trim
	*@return String the trimmed string
	*/
	static VCF::String trim( const VCF::String& text, const char& c );

	/**
	*trim all the occurrences of any <space>, <tab>, <CR> and <LF>
	* at the beginning of the string
	* until it is met the first character from the left that is not a whitespace one
	*@param String the text to trim
	*/
	static void trimWhiteSpacesLeft( VCF::String& text );

	/**
	*trim all the occurrences of any <space>, <tab>, <CR> and <LF>
	* at the end of the string
	* until it is met the first character from the right that is not a whitespace one
	*@param String the text to trim
	*/
	static void trimWhiteSpacesRight( VCF::String& text );

	/**
	*trim all the occurrences of any <<space>, <tab>, <CR> and <LF>
	* at the beginning and the end of the string
	* i.e. calls trimWhiteSpacesLeft + trimWhiteSpacesRight
	*@param String the text to trim
	*/
	static void trimWhiteSpaces( VCF::String& text );

	/**
	*converts the string to lower case
	*@param String the text to convert
	*@return String the converted string
	*/
	static VCF::String lowerCase( const VCF::String& text );

	/**
	*converts the string to upper case
	*@param String the text to convert
	*@return String the converted string
	*/
	static VCF::String upperCase( const VCF::String& text );

	/**
	*converts the value to a string
	*@param int the value to convert
	*@return String the string representation of the int value
	*/
	static VCF::String toString( const int& value );

	/**
	*converts the value to a string
	*@param long the value to convert
	*@return String the string representation of the long value
	*/
	static VCF::String toString( const long& value );

	/**
	*converts the value to a string
	*@param float the value to convert
	*@return String the string representation of the float value
	*/
	static VCF::String toString( const float& value );

	/**
	*converts the value to a string
	*@param double the value to convert
	*@return String the string representation of the double value
	*/
	static VCF::String toString( const double& value );

	/**
	*converts the value to a string
	*@param unsigned long the value to convert
	*@return String the string representation of the unsigned long value
	*/
	static VCF::String toString( const VCF::ulong32& value );

	/**
	*converts the value to a string
	*@param unsigned int the value to convert
	*@return String the string representation of the unsigned int value
	*/
	static VCF::String toString( const VCF::uint32& value );

	/**
	*converts the value to a string
	*@param char int the value to convert
	*@return String the string representation of the char value
	*/
	static VCF::String toString( const char& value );

	/**
	*converts the value to a string
	*@param char bool the value to convert
	*@return String the string representation of the bool value
	*(either "true" or "false")
	*/
	static VCF::String toString( const bool& value );

	/**
	converts the value to an int
	@param String the value to convert
	@return int the integer representation of the String value
	*/
	static int fromStringAsInt( const VCF::String& value );

	/**
	converts the value to an int
	@param String the value to convert
	@return int the integer representation of the String value
	*/
	static VCF::uint32 fromStringAsUInt( const VCF::String& value );

	/**
	converts the value to an int
	@param String the value to convert
	@return int the integer representation of the String value
	*/
	static char fromStringAsChar( const VCF::String& value );

	/**
	converts the value to an int
	@param String the value to convert
	@return int the integer representation of the String value
	*/
	static short fromStringAsShort( const VCF::String& value );

	/**
	converts the value to an int
	@param String the value to convert
	@return int the integer representation of the String value
	*/
	static float fromStringAsFloat( const VCF::String& value );

	/**
	converts the value to an int
	@param String the value to convert
	@return int the integer representation of the String value
	*/
	static double fromStringAsDouble( const VCF::String& value );

	/**
	converts the value to an int
	@param String the value to convert
	@return int the integer representation of the String value
	*/
	static bool fromStringAsBool( const VCF::String& value );

	/**
	*generates a new UUID and returns the string representation
	*@return String the new UUID as a string value
	*/
	static VCF::String newUUID();

	/**
	*gets the class name from a type_info struct.
	*@param type_info the value returned from the
	*expression :
	*<pre>
	*	typeid(AClass)
	*</pre>
	*@return String the name of the class the typeInfo references
	*/
	static VCF::String getClassNameFromTypeInfo( const std::type_info& typeInfo  );

	/**
	Formats a string from date time object using the various argument/formatting
	tags in the formatting string. For example, a date that equals "Jan 2, 2005",
	and a formatting string of "%a %B %#d, %Y" will return string that equals
	"Sunday January 2, 2005". A listing of the possible format codes follows:
	<table>
	  <tr>
	    <td>Format code</td> <td>Meaning</td>
	  </tr>
	  <tr>
	    <td>%%</td>
		<td>outputs just a "%" character</td>
	  </tr>
	  <tr>
	    <td>%a</td>
		<td>Abbreviated weekday name</td>
	  </tr>
	  <tr>
	    <td>%A</td>
		<td>Full weekday name</td>
	  </tr>
	  <tr>
	    <td>%b</td>
		<td>Abbreviated month name</td>
	  </tr>
	  <tr>
	    <td>%B</td>
		<td>Full month name</td>
	  </tr>
	  <tr>
	    <td>%c</td>
		<td>Date and time representation appropriate for locale</td>
	  </tr>
	  <tr>
	    <td>%d </td>
		<td>Day of month as decimal number (01 – 31)</td>
	  </tr>
	  <tr>
	    <td>%D</td>
		<td>Day of the year as decimal number</td>
	  </tr>
	  <tr>
	    <td>%H</td>
		<td>Hour in 24-hour format (00 – 23)</td>
	  </tr>
	  <tr>
	    <td>%I</td>
		<td>Hour in 12-hour format (01 – 12)</td>
	  </tr>
	  <tr>
	    <td>%j </td>
		<td>Day of year as decimal number (001 – 366)</td>
	  </tr>
	  <tr>
	    <td>%m</td>
		<td>Month as decimal number (01 – 12) </td>
	  </tr>
	  <tr>
	    <td>%M</td>
		<td>Minute as decimal number (00 – 59) </td>
	  </tr>
	  <tr>
	    <td>%p</td>
		<td>Current locale's A.M./P.M. indicator for 12-hour clock</td>
	  </tr>
	  <tr>
	    <td>%S</td>
		<td>Second as decimal number (00 – 59) </td>
	  </tr>
	  <tr>
	    <td>%U</td>
		<td>Week of year as decimal number, with Sunday as first day of week (00 – 53) </td>
	  </tr>
	  <tr>
	    <td>%w</td>
		<td>Weekday as decimal number (0 – 6; Sunday is 0) </td>
	  </tr>
	  <tr>
	    <td>%W</td>
		<td>Week of year as decimal number, with Monday as first day of week (00 – 53) </td>
	  </tr>
	  <tr>
	    <td>%x</td>
		<td>Date representation for current locale</td>
	  </tr>
	  <tr>
	    <td>%X</td>
		<td>Time representation for current locale </td>
	  </tr>
	  <tr>
	    <td>%y</td>
		<td>Year without century, as decimal number (00 – 99)</td>
	  </tr>
	  <tr>
	    <td>%Y</td>
		<td>Year with century, as decimal number</td>
	  </tr>
	  <tr>
	    <td>%s</td>
		<td>millisecond part</td>
	  </tr>
	</table>
	@param Date the date to use
	@param String a string with formatting codes in it.
	@return String the newly formatted string
	*/
	static VCF::String format( const DateTime& date, const String& formatting );

protected:
	static String weekdays[];
	static String abbrevWeekdays[];
	static String months[];
	static String abbrevMonths[];
};

};//end of namespace VCF


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 04:07:13  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:29:40  ddiego
*migration towards new directory structure
*
*Revision 1.14.2.1  2004/04/26 21:58:48  marcelloptr
*changes for dir reorganization: _VCF_MACRO_H__
*
*Revision 1.14  2004/01/20 01:54:55  ddiego
*merged some more changes from dev branch, primarily changes to
*teh RTTI API so that we now process enum sets correctly (i.e. a long
*that is a mask made of enum values).
*
*Revision 1.13.2.2  2004/01/17 18:47:30  ddiego
*added a new example for DateTime calss and some other minor fixes to it
*
*Revision 1.13.2.1  2004/01/17 06:09:50  ddiego
*integrated the DateTime class into the VCF FoundationKit.
*
*Revision 1.13  2003/12/18 05:15:59  ddiego
*merge from devmain-0-6-2 branch into the stable branch
*
*Revision 1.12.4.4  2003/11/10 01:57:43  ddiego
*add a fromString methods to StingUtils
*added some minor fixes to list box control and added a SelectionChanged
*Delegate to it
*add some minor fixes ot ComboBoxControl
*added an unknownColor() method to ColorNames class
*
*Revision 1.12.4.3  2003/10/23 04:24:51  ddiego
*more musical chairs with headers again, in yet another attempt to make
*them more efficent to speed up compiles.
*Removed all teh template RTTI classes and put them all in one header
*called VCFRTTIImpl.h. This should help compile speeds a bit.
*The next step is to look at some of the event classes and remove ones
*that aren't really neccessary - I'd estimate that 50% of the current
*event classes are unneccessary and can be removed.
*
*Revision 1.12.4.2  2003/08/20 22:55:20  ddiego
*got rid of some older methods for StringUtils, should be using the FilePath
*class instead
*
*Revision 1.12.4.1  2003/08/11 19:58:53  marcelloptr
*improvement: StringUtils::trimWhiteSpaces functions added
*
*Revision 1.12  2003/05/17 20:37:17  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.11.2.1  2003/03/23 03:23:53  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.11  2003/02/26 04:30:43  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.10.14.1  2002/12/28 21:51:19  marcelloptr
*Fixes and improvements for WM_COPYDATA, Point, Rect, Size, GraphicsContext and StringUtils
*
*Revision 1.10  2002/05/09 03:10:43  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.9.4.2  2002/03/25 04:19:46  ddiego
*fixed some file checking problems in xmake and fixed some general
*code to be able to compile with GCC and Borland C++
*
*Revision 1.9.4.1  2002/03/20 21:56:56  zzack
*Changed Include Style of FoundationKit
*
*Revision 1.9  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


#endif // _VCF_STRINGUTILS_H__


