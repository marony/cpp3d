#include "stdafx.h"
#include "Vector3.hpp"
#include "Point3.hpp"

Vector3::Vector3(const Point3& rhs)
	: Vector3{ rhs.get_x(), rhs.get_y(), rhs.get_z(), rhs.get_w() }
{
}

Vector3::operator Point3() const
{
	return	{ x_, y_, z_, w_ };
}
