//Matrix2D.cpp

/*
Copyright 2000-2004 The VCF Project.
Please see License.txt in the top level directory
where you installed the VCF.
*/


/* Generated by Together */
#include "vcf/GraphicsKit/GraphicsKit.h"

using namespace VCF;

Matrix2D::Matrix2D()
{
	identity();
}

Matrix2D::Matrix2D( const Matrix2D& matrix ):
    Object(matrix)
{
	memcpy( matrix_, matrix.matrix_, 9 * sizeof(double) );
}

Matrix2D::~Matrix2D()
{

}

void Matrix2D::transpose( Matrix2D* dest )
{
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			dest->matrix_[i][j] = matrix_[j][i];
		}
	}
}

void Matrix2D::reflect( const bool& reflectX, const bool& reflectY )
{
	identity();
	if ( true == reflectX ){
		matrix_[1][1] = -1;
	}
	if ( true == reflectY ){
		matrix_[0][0] = -1;
	}
}

void Matrix2D::rotate( const double& theta )
{
	identity();
	matrix_[0][0] = cos( Math::degreesToRadians(theta) );
	matrix_[0][1] = sin( Math::degreesToRadians(theta) );
	matrix_[1][0] = -matrix_[0][1];
	matrix_[1][1] = matrix_[0][0];
}

void Matrix2D::shear( const double& shearX, const double& shearY )
{
	/**
	*the shear values come into us as degrees - we need to converto
	*radians
	*/
	identity();
	matrix_[1][0] = Math::degreesToRadians( shearX );
	matrix_[0][1] = Math::degreesToRadians( shearY );
}

void Matrix2D::scale( const double& scaleX, const double& scaleY )
{
	identity();
	matrix_[0][0] = scaleX;
	matrix_[1][1] = scaleY;
}

void Matrix2D::identity()
{
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			if ( i == j ){
				matrix_[i][j] = 1.0;
			}
			else {
				matrix_[i][j] = 0.0;
			}
		}
	}
}

Matrix2D* Matrix2D::multiply( Matrix2D* m1, Matrix2D* m2 )
{
	if ( (NULL != m1) && (NULL != m2) ) {
		matrix_[0][0] = m1->matrix_[0][0] * m2->matrix_[0][0] + m1->matrix_[0][1] * m2->matrix_[1][0];
		matrix_[0][1] = m1->matrix_[0][0] * m2->matrix_[0][1] + m1->matrix_[0][1] * m2->matrix_[1][1];
		matrix_[0][2] = 0.0;

		matrix_[1][0] = m1->matrix_[1][0] * m2->matrix_[0][0] + m1->matrix_[1][1] * m2->matrix_[1][0];
		matrix_[1][1] = m1->matrix_[1][0] * m2->matrix_[0][1] + m1->matrix_[1][1] * m2->matrix_[1][1];
		matrix_[1][2] = 0.0;

		matrix_[2][0] = (m1->matrix_[2][0] * m2->matrix_[0][0]) + (m1->matrix_[2][1] * m2->matrix_[1][0]) + m2->matrix_[2][0];
		matrix_[2][1] = (m1->matrix_[2][0] * m2->matrix_[0][1]) + (m1->matrix_[2][1] * m2->matrix_[1][1]) + m2->matrix_[2][1];
		matrix_[2][2] = 1.0;
		return this;
	}
	else {
		return NULL;
	}
}

void Matrix2D::translate( const double& transX, const double& transY )
{
	identity();
	matrix_[2][0] = transX;
	matrix_[2][1] = transY;
}

void Matrix2D::invert()
{
	//based on Maxim Shemanarev AGG matrix code ! Thanks !
	double determinant  = 1.0 / (matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0]);

	double t0 =  matrix_[1][1] * determinant;
	matrix_[1][1] =  matrix_[0][0] * determinant;
	matrix_[0][1] = -matrix_[0][1] * determinant;
	matrix_[1][0] = -matrix_[1][0] * determinant;

	double t4 = -matrix_[2][0] * t0 - matrix_[2][1] * matrix_[1][0];
	matrix_[2][1] = -matrix_[2][0] * matrix_[0][1] - matrix_[2][1] * matrix_[1][1];

	matrix_[0][0] = t0;
	matrix_[2][0] = t4;
}

Point* Matrix2D::apply( Point* point )
{
	return NULL;
}

bool Matrix2D::isEqual( Object* object )const
{
	Matrix2D* m = dynamic_cast<Matrix2D*>(object);
	if ( NULL != m ){
		for ( int i=0;i<3;i++){
			for (int j=0;j<3;j++){
				if ( matrix_[i][j] != m->matrix_[i][j] ){
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

void Matrix2D::copy( Object* source )
{
	Matrix2D* m = dynamic_cast<Matrix2D*>( source );
	memcpy( matrix_, m->matrix_, 9 * sizeof(double) );
	/**
	slow way
	if ( NULL != m ){
		for ( int i=0;i<3;i++){
			for (int j=0;j<3;j++){
				matrix_[i][j] = m->matrix_[i][j];
			}
		}
	}
	*/
}

Matrix2D& Matrix2D::operator=( const Matrix2D& matrix )
{
	copy( (Object*)&matrix );
	return *this;
}

bool Matrix2D::operator == ( const Matrix2D& matrix )const
{
	return isEqual( (Object*)&matrix );
}

double Matrix2D::operator[]( MatrixElementIndex index ) const
{
	double result = 0.0;
	switch ( index ){
		case Matrix2D::mei00 : {
			result = matrix_[0][0];
		}
		break;

		case Matrix2D::mei01 : {
			result = matrix_[0][1];
		}
		break;

		case Matrix2D::mei02 : {
			result = matrix_[0][2];
		}
		break;

		case Matrix2D::mei10 : {
			result = matrix_[1][0];
		}
		break;

		case Matrix2D::mei11 : {
			result = matrix_[1][1];
		}
		break;

		case Matrix2D::mei12 : {
			result = matrix_[1][2];
		}
		break;

		case Matrix2D::mei20 : {
			result = matrix_[2][0];
		}
		break;

		case Matrix2D::mei21 : {
			result = matrix_[2][1];
		}
		break;

		case Matrix2D::mei22 : {
			result = matrix_[2][2];
		}
		break;
	}

	return result;
}

double& Matrix2D::operator[]( MatrixElementIndex index )
{
	if ( index > Matrix2D::mei22 ) {
		throw OutOfBoundsException( MAKE_ERROR_MSG_2("Index specified is out of bound for Matrix array") );
	}
	return matrix_[index/3][index%3];
}


/**
*CVS Log info
*$Log$
*Revision 1.1.2.2  2004/04/29 04:10:27  marcelloptr
*reformatting of source files: macros and csvlog and copyright sections
*
*Revision 1.1.2.1  2004/04/28 03:40:31  ddiego
*migration towards new directory structure
*
*Revision 1.11  2003/08/09 02:56:45  ddiego
*merge over from the devmain-0-6-1 branch
*Changes
*Features:
*-Added additional implementation to better support the MVC architecture in
*the VCF
*
*-Added a Document/View architecure that is similar to MFC's or NextSteps's
*Doc/View architectures
*
*-Integrated the Anti Grain Graphics library into the GraphicsKit. There is
*now basic support for it in terms of drawing vector shapes
*(fills and strokes). Image support will come in the next release
*
*-Added several documented graphics tutorials
*
*Bugfixes:
*
*[ 775744 ] wrong buttons on a dialog
*[ 585239 ] Painting weirdness in a modal dialog ?
*[ 585238 ] Modal dialog which makes a modal Dialog
*[ 509004 ] Opening a modal Dialog causes flicker
*[ 524878 ] onDropped not called for MLTcontrol
*
*Plus an issue with some focus and getting the right popup window to activate
*has also been fixed
*
*Revision 1.10.2.3  2003/07/18 04:38:54  ddiego
*got more work done on the sketch examples plus fixed a bug in the application
*of a transform ot a path
*
*Revision 1.10.2.2  2003/07/16 04:59:07  ddiego
*added some changes to the fil and stroke classes to allow changing whether
*they use anti-aliasing or not. Also implemented Matrix2D::invert(),
*plus properly implemented clone() on the DefaultMenuItem class.
*
*Revision 1.10.2.1  2003/07/05 04:04:45  ddiego
*added more AGG support
*  added a common AGG header to use when accessing the AGG API directly
*  see the graphics/AggCommon.h header for this
*  Made some minor changes to Path to work a bit simpler
*  Implemented Polygon completely,
*  Implemented BasicFill and BasicStroke - using AGG
*
*Revision 1.10  2003/05/17 20:37:22  ddiego
*this is the checkin for the 0.6.1 release - represents the merge over from
*the devmain-0-6-0 branch plus a few minor bug fixes
*
*Revision 1.9.2.3  2003/04/07 03:39:31  ddiego
*did some documentation work, and got everything to compile cleanly with some
*of the new additions, particularly the chnages inteh Image/ImageBits classes.
*
*Revision 1.9.2.2  2003/03/23 03:23:55  marcelloptr
*3 empty lines at the end of the files
*
*Revision 1.9.2.1  2003/03/12 03:12:02  ddiego
*switched all member variable that used the "m_"<name> prefix to
* <name>"_" suffix nameing standard.
*Also changed all vcf builder files to accomadate this.
*Changes were made to the Stream classes to NOT multiple inheritance and to
*be a little more correct. Changes include breaking the FileStream into two
*distinct classes, one for input and one for output.
*
*Revision 1.9  2003/02/26 04:30:46  ddiego
*merge of code in the devmain-0-5-9 branch into the current tree.
*most additions are in the area of the current linux port, but the major
*addition to this release is the addition of a Condition class (currently
*still under development) and the change over to using the Delegate class
*exclusively from the older event handler macros.
*
*Revision 1.8.8.1  2002/11/28 05:12:04  ddiego
*modifications to allow the VCF to compile with MinGW. This also cleans up
*some warnings with GCC - should improve the linux side as well.
*In addition this checkin includes new files for building the VCF under
*the DevC++ IDE. these are in the vcf/build/devcpp directory.
*
*Revision 1.8  2002/09/12 03:26:05  ddiego
*merged over the changes from the devmain-0-5-5b branch
*
*Revision 1.7.6.1  2002/08/06 02:57:36  ddiego
*added base X11 files for GraphicsKit and made sure that the GraphicsKit compiles
*under linux (GCC). There is now a new dir under build/xmake called GraphicsKit
*where the xmake build script lives. This checkin also includes the base X11
*include (as part of GraphicsKitPrivate.h), as well as linking to the X11 libs
*
*Revision 1.7  2002/05/09 03:10:44  ddiego
*merged over code from development branch devmain-0-5-1a into the main CVS trunk
*
*Revision 1.6.4.1  2002/04/03 19:37:17  zzack
*include style changed
*
*Revision 1.6  2002/01/24 01:46:49  ddiego
*added a cvs "log" comment to the top of all files in vcf/src and vcf/include
*to facilitate change tracking
*
*/


