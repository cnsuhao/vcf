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

Matrix2D::Matrix2D ( const agg::trans_affine& matrix )
{
	identity();

	double m[6] = {0,0,0,0,0,0};

	matrix.store_to( m );

	matrix_[0][0] = m[0];
	matrix_[0][1] = m[1];
	matrix_[1][0] = m[2];
	matrix_[1][1] = m[3];
	matrix_[2][0] = m[4];
	matrix_[2][1] = m[5];
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

Matrix2D& Matrix2D::multiply( const Matrix2D& rhs )
{	
/*
	matrix_[0][0] = m1.matrix_[0][0] * m2.matrix_[0][0] + m1.matrix_[0][1] * m2.matrix_[1][0];
	matrix_[0][1] = m1.matrix_[0][0] * m2.matrix_[0][1] + m1.matrix_[0][1] * m2.matrix_[1][1];
	matrix_[0][2] = 0.0;
	
	matrix_[1][0] = m1.matrix_[1][0] * m2.matrix_[0][0] + m1.matrix_[1][1] * m2.matrix_[1][0];
	matrix_[1][1] = m1.matrix_[1][0] * m2.matrix_[0][1] + m1.matrix_[1][1] * m2.matrix_[1][1];
	matrix_[1][2] = 0.0;
	
	matrix_[2][0] = (m1.matrix_[2][0] * m2.matrix_[0][0]) + (m1.matrix_[2][1] * m2.matrix_[1][0]) + m2.matrix_[2][0];
	matrix_[2][1] = (m1.matrix_[2][0] * m2.matrix_[0][1]) + (m1.matrix_[2][1] * m2.matrix_[1][1]) + m2.matrix_[2][1];
	matrix_[2][2] = 1.0;
	*/

	double m00,m10,m20;

	m00 = matrix_[0][0] * rhs.matrix_[0][0] + matrix_[0][1] * rhs.matrix_[1][0];	
	m10 = matrix_[1][0] * rhs.matrix_[0][0] + matrix_[1][1] * rhs.matrix_[1][0];
	m20 = (matrix_[2][0] * rhs.matrix_[0][0]) + (matrix_[2][1] * rhs.matrix_[1][0]) + rhs.matrix_[2][0];


	matrix_[0][1] = matrix_[0][0] * rhs.matrix_[0][1] + matrix_[0][1] * rhs.matrix_[1][1];	
	matrix_[1][1] = matrix_[1][0] * rhs.matrix_[0][1] + matrix_[1][1] * rhs.matrix_[1][1];	
	matrix_[2][1] = (matrix_[2][0] * rhs.matrix_[0][1]) + (matrix_[2][1] * rhs.matrix_[1][1]) + rhs.matrix_[2][1];
	
	matrix_[0][0] = m00;
	matrix_[1][0] = m10;
	matrix_[2][0] = m20;


	matrix_[0][2] = 0.0;
	matrix_[1][2] = 0.0;
	matrix_[2][2] = 1.0;

	return *this;	
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


Point Matrix2D::apply( Point* point ) const
{
	Point result;

	result.x_ = point->x_ * (matrix_[0][0]) +
							point->y_ * (matrix_[1][0]) +
								(matrix_[2][0]);

	result.y_ = point->x_ * (matrix_[0][1]) +
							point->y_ * (matrix_[1][1]) +
								(matrix_[2][1]);

	return result;
}

Rect Matrix2D::apply( Rect* rect ) const
{
	double x1,x2,y1,y2;
	x1 = rect->left_ * (matrix_[0][0]) +
							rect->top_ * (matrix_[1][0]) +
								(matrix_[2][0]);

	y1 = rect->left_ * (matrix_[0][1]) +
							rect->top_ * (matrix_[1][1]) +
								(matrix_[2][1]);

	x2 = rect->right_ * (matrix_[0][0]) +
							rect->bottom_ * (matrix_[1][0]) +
								(matrix_[2][0]);

	y2 = rect->right_ * (matrix_[0][1]) +
							rect->bottom_ * (matrix_[1][1]) +
								(matrix_[2][1]);

	return Rect(x1,y1,x2,y2);
}

void Matrix2D::apply( double& x, double& y ) const
{
	double tmpX = x;
	double tmpY = y;

	x = tmpX * (matrix_[0][0]) +
							tmpY * (matrix_[1][0]) +
								(matrix_[2][0]);

	y = tmpX * (matrix_[0][1]) +
							tmpY * (matrix_[1][1]) +
								(matrix_[2][1]);


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

bool Matrix2D::isIdentity(double epsilon ) const
{
	//based on Maxim Shemanarev AGG matrix code ! Thanks !
	return (fabs(matrix_[0][0] - 1.0) < epsilon) &&
           (fabs(matrix_[0][1] - 0.0) < epsilon) &&
           (fabs(matrix_[1][0] - 0.0) < epsilon) && 
           (fabs(matrix_[1][1] - 1.0) < epsilon) &&
           (fabs(matrix_[2][0] - 0.0) < epsilon) &&
           (fabs(matrix_[2][1] - 0.0) < epsilon);
}



double Matrix2D::getRotation() const
{
	//based on Maxim Shemanarev AGG matrix code ! Thanks !
	double x1 = 0.0;
	double y1 = 0.0;
	double x2 = 1.0;
	double y2 = 0.0;
	
	apply(x1, y1);
	apply(x2, y2);

	return atan2(y2-y1, x2-x1);
}

double Matrix2D::getScaleX() const 
{
	double result = 0;
	double y = 0;

	getScale( result, y );

	return result;
}

double Matrix2D::getScaleY() const 
{
	double result = 0;
	double x = 0;

	getScale( x, result );

	return result;
}


double Matrix2D::getShearX() const 
{
	double result = 0;
	double y = 0;

	getShear( result, y );

	return result;
}

double Matrix2D::getShearY() const 
{
	double result = 0;
	double x = 0;

	getShear( x, result );

	return result;
}

double Matrix2D::getTranslateX() const 
{
	double result = 0;
	double y = 0;

	getTranslation( result, y );

	return result;
}

double Matrix2D::getTranslateY() const 
{
	double result = 0;
	double x = 0;

	getTranslation( x, result );

	return result;
}

void Matrix2D::getShear( double& x, double& y ) const
{

}

void Matrix2D::getScale( double& x, double& y ) const
{
	//based on Maxim Shemanarev AGG matrix code ! Thanks !
	double x1 = 0.0;
	double y1 = 0.0;
	double x2 = 1.0;
	double y2 = 1.0;
	Matrix2D rot;
	rot.rotate( -getRotation() );

	rot.multiply( *this );

	rot.apply(x1, y1);
	rot.apply(x2, y2);
	
	x = x2 - x1;
	y = y2 - y1;
}

void Matrix2D::getTranslation( double& x, double& y ) const
{
	//based on Maxim Shemanarev AGG matrix code ! Thanks !
	Matrix2D rot;
	rot.rotate( -getRotation() );

	rot.multiply( *this );
    
    rot.apply(x, y);
}

Matrix2D& Matrix2D::operator= ( const agg::trans_affine& matrix )
{
	identity();

	double m[6] = {0,0,0,0,0,0};

	matrix.store_to( m );

	matrix_[0][0] = m[0];
	matrix_[0][1] = m[1];
	matrix_[1][0] = m[2];
	matrix_[1][1] = m[3];
	matrix_[2][0] = m[4];
	matrix_[2][1] = m[5];

	return *this;
}
	
Matrix2D::operator agg::trans_affine () const
{
	return agg::trans_affine( matrix_[0][0], matrix_[0][1],
								matrix_[1][0], matrix_[1][1],
								matrix_[2][0], matrix_[2][1]  );
}

/**
$Id$
*/
