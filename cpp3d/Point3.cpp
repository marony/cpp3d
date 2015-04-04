#include "stdafx.h"
#include "Point3.hpp"
#include "Vector3.hpp"
#include "SFML/Graphics.hpp"

Point3::Point3(const Vector3& rhs)
	: Point3{ rhs.get_x(), rhs.get_y(), rhs.get_z() }
{
}

Point3::operator Vector3() const
{
	return	{ x_, y_, z_, w_ };
}

Vector3	Point3::operator+(const Point3& rhs) const
{
	return	{ x_ + rhs.x_, y_ + rhs.y_, z_ + rhs.z_ };
}

Vector3	Point3::operator-(const Point3& rhs) const
{
	return	{ x_ - rhs.x_, y_ - rhs.y_, z_ - rhs.z_ };
}

// æZ
Point3	Point3::operator*(double a) const
{
	return	{ x_ * a, y_ * a, z_ * a };
}

// œZ
Point3	Point3::operator/(double a) const
{
	return	{ x_ / a, y_ / a, z_ / a };
}
