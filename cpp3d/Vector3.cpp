#include "stdafx.h"
#include "Vector3.hpp"
#include "Point3.hpp"

Vector3::Vector3(const Point3& rhs)
	: Vector3{ rhs.getX(), rhs.getY(), rhs.getZ(), rhs.getW() }
{
}

Vector3::operator Point3() const
{
	return	{ _x, _y, _z, _w };
}
