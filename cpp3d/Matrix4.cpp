#include "stdafx.h"
#include "Matrix4.hpp"

// TODO: Ç±ÇÃï”ÇËÇÃÉRÅ[ÉhÇÕçìÇ¢ÇÃÇ≈Ç»ÇÒÇ∆Ç©ÅcÇ∑ÇÈ

// çsóÒìØémÇÃâ¡éZ
Matrix4	Matrix4::operator+(const Matrix4& rhs) const
{
	return{ _elements[0] + rhs._elements[0], _elements[1] + rhs._elements[1], _elements[2] + rhs._elements[2], _elements[3] + rhs._elements[3],
		_elements[4] + rhs._elements[4], _elements[5] + rhs._elements[5], _elements[6] + rhs._elements[6], _elements[7] + rhs._elements[7],
		_elements[8] + rhs._elements[8], _elements[9] + rhs._elements[9], _elements[10] + rhs._elements[10], _elements[11] + rhs._elements[11],
		_elements[12] + rhs._elements[12], _elements[13] + rhs._elements[13], _elements[14] + rhs._elements[14], _elements[15] + rhs._elements[15]
	};
}

// çsóÒìØémÇÃå∏éZ
Matrix4	Matrix4::operator-(const Matrix4& rhs) const
{
	return{ _elements[0] - rhs._elements[0], _elements[1] - rhs._elements[1], _elements[2] - rhs._elements[2], _elements[3] - rhs._elements[3],
		_elements[4] - rhs._elements[4], _elements[5] - rhs._elements[5], _elements[6] - rhs._elements[6], _elements[7] - rhs._elements[7],
		_elements[8] - rhs._elements[8], _elements[9] - rhs._elements[9], _elements[10] - rhs._elements[10], _elements[11] - rhs._elements[11],
		_elements[12] - rhs._elements[12], _elements[13] - rhs._elements[13], _elements[14] - rhs._elements[14], _elements[15] - rhs._elements[15]
	};
}

// èÊéZ
Matrix4	Matrix4::operator*(double a) const
{
	return{ _elements[0] * a, _elements[1] * a, _elements[2] * a, _elements[3] * a,
		_elements[4] * a, _elements[5] * a, _elements[6] * a, _elements[7] * a,
		_elements[8] * a, _elements[9] * a, _elements[10] * a, _elements[11] * a,
		_elements[12] * a, _elements[13] * a, _elements[14] * a, _elements[15] * a
	};
}

// êœ
Vector3	Matrix4::operator*(const Vector3& vector) const
{
	return{
		_elements[0] * vector.getX() + _elements[1] * vector.getY() + _elements[2] * vector.getZ() + _elements[3] * vector.getW(),
		_elements[4] * vector.getX() + _elements[5] * vector.getY() + _elements[6] * vector.getZ() + _elements[7] * vector.getW(),
		_elements[8] * vector.getX() + _elements[9] * vector.getY() + _elements[10] * vector.getZ() + _elements[11] * vector.getW(),
		_elements[12] * vector.getX() + _elements[13] * vector.getY() + _elements[14] * vector.getZ() + _elements[15] * vector.getW()
	};
}

// êœ
Point3	Matrix4::operator*(const Point3& point) const
{
	return{
		_elements[0] * point.getX() + _elements[1] * point.getY() + _elements[2] * point.getZ() + _elements[3] * point.getW(),
		_elements[4] * point.getX() + _elements[5] * point.getY() + _elements[6] * point.getZ() + _elements[7] * point.getW(),
		_elements[8] * point.getX() + _elements[9] * point.getY() + _elements[10] * point.getZ() + _elements[11] * point.getW(),
		_elements[12] * point.getX() + _elements[13] * point.getY() + _elements[14] * point.getZ() + _elements[15] * point.getW()
	};
}

// êœ
Matrix4	Matrix4::operator*(const Matrix4& rhs) const
{
	return{ _elements[0] * rhs._elements[0] + _elements[1] * rhs._elements[4] + _elements[2] * rhs._elements[8] + _elements[3] * rhs._elements[12],
		_elements[0] * rhs._elements[1] + _elements[1] * rhs._elements[5] + _elements[2] * rhs._elements[9] + _elements[3] * rhs._elements[13],
		_elements[0] * rhs._elements[2] + _elements[1] * rhs._elements[6] + _elements[2] * rhs._elements[10] + _elements[3] * rhs._elements[14],
		_elements[0] * rhs._elements[3] + _elements[1] * rhs._elements[7] + _elements[2] * rhs._elements[11] + _elements[3] * rhs._elements[15],
		_elements[4] * rhs._elements[0] + _elements[5] * rhs._elements[4] + _elements[6] * rhs._elements[8] + _elements[7] * rhs._elements[12],
		_elements[4] * rhs._elements[1] + _elements[5] * rhs._elements[5] + _elements[6] * rhs._elements[9] + _elements[7] * rhs._elements[13],
		_elements[4] * rhs._elements[2] + _elements[5] * rhs._elements[6] + _elements[6] * rhs._elements[10] + _elements[7] * rhs._elements[14],
		_elements[4] * rhs._elements[3] + _elements[5] * rhs._elements[7] + _elements[6] * rhs._elements[11] + _elements[7] * rhs._elements[15],
		_elements[8] * rhs._elements[0] + _elements[9] * rhs._elements[4] + _elements[10] * rhs._elements[8] + _elements[11] * rhs._elements[12],
		_elements[8] * rhs._elements[1] + _elements[9] * rhs._elements[5] + _elements[10] * rhs._elements[9] + _elements[11] * rhs._elements[13],
		_elements[8] * rhs._elements[2] + _elements[9] * rhs._elements[6] + _elements[10] * rhs._elements[10] + _elements[11] * rhs._elements[14],
		_elements[8] * rhs._elements[3] + _elements[9] * rhs._elements[7] + _elements[10] * rhs._elements[11] + _elements[11] * rhs._elements[15],
		_elements[12] * rhs._elements[0] + _elements[13] * rhs._elements[4] + _elements[14] * rhs._elements[8] + _elements[15] * rhs._elements[12],
		_elements[12] * rhs._elements[1] + _elements[13] * rhs._elements[5] + _elements[14] * rhs._elements[9] + _elements[15] * rhs._elements[13],
		_elements[12] * rhs._elements[2] + _elements[13] * rhs._elements[6] + _elements[14] * rhs._elements[10] + _elements[15] * rhs._elements[14],
		_elements[12] * rhs._elements[3] + _elements[13] * rhs._elements[7] + _elements[14] * rhs._elements[11] + _elements[15] * rhs._elements[15]
	};
}
