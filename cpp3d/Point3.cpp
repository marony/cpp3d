#include "stdafx.h"
#include "Point3.hpp"
#include "Vector3.hpp"
#include "SFML/Graphics.hpp"

Point3::Point3(const Vector3& rhs)
	: Point3{ rhs.getX(), rhs.getY(), rhs.getZ() }
{
}

Point3::operator Vector3() const
{
	return	{ _x, _y, _z, _w };
}

Vector3	Point3::operator+(const Point3& rhs) const
{
	return	{ _x + rhs._x, _y + rhs._y, _z + rhs._z };
}

Vector3	Point3::operator-(const Point3& rhs) const
{
	return	{ _x - rhs._x, _y - rhs._y, _z - rhs._z };
}

// æZ
Point3	Point3::operator*(double a) const
{
	return{ _x * a, _y * a, _z * a };
}

// œZ
Point3	Point3::operator/(double a) const
{
	return{ _x / a, _y / a, _z / a };
}
