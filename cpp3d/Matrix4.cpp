#include "stdafx.h"
#include "Matrix4.hpp"

// TODO: Ç±ÇÃï”ÇËÇÃÉRÅ[ÉhÇÕçìÇ¢ÇÃÇ≈Ç»ÇÒÇ∆Ç©ÅcÇ∑ÇÈ

// çsóÒìØémÇÃâ¡éZ
Matrix4	Matrix4::operator+(const Matrix4& rhs) const
{
	return{ elements_[0] + rhs.elements_[0], elements_[1] + rhs.elements_[1], elements_[2] + rhs.elements_[2], elements_[3] + rhs.elements_[3],
		elements_[4] + rhs.elements_[4], elements_[5] + rhs.elements_[5], elements_[6] + rhs.elements_[6], elements_[7] + rhs.elements_[7],
		elements_[8] + rhs.elements_[8], elements_[9] + rhs.elements_[9], elements_[10] + rhs.elements_[10], elements_[11] + rhs.elements_[11],
		elements_[12] + rhs.elements_[12], elements_[13] + rhs.elements_[13], elements_[14] + rhs.elements_[14], elements_[15] + rhs.elements_[15]
	};
}

// çsóÒìØémÇÃå∏éZ
Matrix4	Matrix4::operator-(const Matrix4& rhs) const
{
	return{ elements_[0] - rhs.elements_[0], elements_[1] - rhs.elements_[1], elements_[2] - rhs.elements_[2], elements_[3] - rhs.elements_[3],
		elements_[4] - rhs.elements_[4], elements_[5] - rhs.elements_[5], elements_[6] - rhs.elements_[6], elements_[7] - rhs.elements_[7],
		elements_[8] - rhs.elements_[8], elements_[9] - rhs.elements_[9], elements_[10] - rhs.elements_[10], elements_[11] - rhs.elements_[11],
		elements_[12] - rhs.elements_[12], elements_[13] - rhs.elements_[13], elements_[14] - rhs.elements_[14], elements_[15] - rhs.elements_[15]
	};
}

// èÊéZ
Matrix4	Matrix4::operator*(double a) const
{
	return{ elements_[0] * a, elements_[1] * a, elements_[2] * a, elements_[3] * a,
		elements_[4] * a, elements_[5] * a, elements_[6] * a, elements_[7] * a,
		elements_[8] * a, elements_[9] * a, elements_[10] * a, elements_[11] * a,
		elements_[12] * a, elements_[13] * a, elements_[14] * a, elements_[15] * a
	};
}

// êœ
Vector3	Matrix4::operator*(const Vector3& vector) const
{
	return{
		elements_[0] * vector.get_x() + elements_[1] * vector.get_y() + elements_[2] * vector.get_z() + elements_[3] * vector.get_w(),
		elements_[4] * vector.get_x() + elements_[5] * vector.get_y() + elements_[6] * vector.get_z() + elements_[7] * vector.get_w(),
		elements_[8] * vector.get_x() + elements_[9] * vector.get_y() + elements_[10] * vector.get_z() + elements_[11] * vector.get_w(),
		elements_[12] * vector.get_x() + elements_[13] * vector.get_y() + elements_[14] * vector.get_z() + elements_[15] * vector.get_w()
	};
}

// êœ
Point3	Matrix4::operator*(const Point3& point) const
{
	return{
		elements_[0] * point.get_x() + elements_[1] * point.get_y() + elements_[2] * point.get_z() + elements_[3] * point.get_w(),
		elements_[4] * point.get_x() + elements_[5] * point.get_y() + elements_[6] * point.get_z() + elements_[7] * point.get_w(),
		elements_[8] * point.get_x() + elements_[9] * point.get_y() + elements_[10] * point.get_z() + elements_[11] * point.get_w(),
		elements_[12] * point.get_x() + elements_[13] * point.get_y() + elements_[14] * point.get_z() + elements_[15] * point.get_w()
	};
}

// êœ
Matrix4	Matrix4::operator*(const Matrix4& rhs) const
{
	return{ elements_[0] * rhs.elements_[0] + elements_[1] * rhs.elements_[4] + elements_[2] * rhs.elements_[8] + elements_[3] * rhs.elements_[12],
		elements_[0] * rhs.elements_[1] + elements_[1] * rhs.elements_[5] + elements_[2] * rhs.elements_[9] + elements_[3] * rhs.elements_[13],
		elements_[0] * rhs.elements_[2] + elements_[1] * rhs.elements_[6] + elements_[2] * rhs.elements_[10] + elements_[3] * rhs.elements_[14],
		elements_[0] * rhs.elements_[3] + elements_[1] * rhs.elements_[7] + elements_[2] * rhs.elements_[11] + elements_[3] * rhs.elements_[15],
		elements_[4] * rhs.elements_[0] + elements_[5] * rhs.elements_[4] + elements_[6] * rhs.elements_[8] + elements_[7] * rhs.elements_[12],
		elements_[4] * rhs.elements_[1] + elements_[5] * rhs.elements_[5] + elements_[6] * rhs.elements_[9] + elements_[7] * rhs.elements_[13],
		elements_[4] * rhs.elements_[2] + elements_[5] * rhs.elements_[6] + elements_[6] * rhs.elements_[10] + elements_[7] * rhs.elements_[14],
		elements_[4] * rhs.elements_[3] + elements_[5] * rhs.elements_[7] + elements_[6] * rhs.elements_[11] + elements_[7] * rhs.elements_[15],
		elements_[8] * rhs.elements_[0] + elements_[9] * rhs.elements_[4] + elements_[10] * rhs.elements_[8] + elements_[11] * rhs.elements_[12],
		elements_[8] * rhs.elements_[1] + elements_[9] * rhs.elements_[5] + elements_[10] * rhs.elements_[9] + elements_[11] * rhs.elements_[13],
		elements_[8] * rhs.elements_[2] + elements_[9] * rhs.elements_[6] + elements_[10] * rhs.elements_[10] + elements_[11] * rhs.elements_[14],
		elements_[8] * rhs.elements_[3] + elements_[9] * rhs.elements_[7] + elements_[10] * rhs.elements_[11] + elements_[11] * rhs.elements_[15],
		elements_[12] * rhs.elements_[0] + elements_[13] * rhs.elements_[4] + elements_[14] * rhs.elements_[8] + elements_[15] * rhs.elements_[12],
		elements_[12] * rhs.elements_[1] + elements_[13] * rhs.elements_[5] + elements_[14] * rhs.elements_[9] + elements_[15] * rhs.elements_[13],
		elements_[12] * rhs.elements_[2] + elements_[13] * rhs.elements_[6] + elements_[14] * rhs.elements_[10] + elements_[15] * rhs.elements_[14],
		elements_[12] * rhs.elements_[3] + elements_[13] * rhs.elements_[7] + elements_[14] * rhs.elements_[11] + elements_[15] * rhs.elements_[15]
	};
}
