#pragma once

class Vector3;

class Point3
{
public:
	Point3(double x = 0.0, double y = 0.0, double z = 0.0, double w = 1.0)
		: _x{ x }, _y{ y }, _z{ z }, _w{ w }
	{
	}
	Point3(const Point3& rhs)
		: Point3 { rhs._x, rhs._y, rhs._z, rhs._w }
	{
	}
	Point3(const Vector3& rhs);

	const Point3&	operator=(const Point3& rhs)
	{
		if (this != &rhs)
		{
			_x = rhs._x;
			_y = rhs._y;
			_z = rhs._z;
			_w = rhs._w;
		}
		return	*this;
	}
	bool	operator==(const Point3& rhs) const
	{
		return	(this == &rhs) ||
			(_x == rhs._x &&
			 _y == rhs._y &&
			 _z == rhs._z &&
			 _w == rhs._w);
	}
	bool	operator!=(const Point3& rhs) const
	{
		return	!operator==(rhs);
	}
	operator Vector3() const;

	Vector3	operator+(const Point3& rhs) const;
	Vector3	operator-(const Point3& rhs) const;
	// æZ
	Point3	operator*(double a) const;
	// œZ
	Point3	operator/(double a) const;

	double	getX() const
	{
		return	_x;
	}
	double	getY() const
	{
		return	_y;
	}
	double	getZ() const
	{
		return	_z;
	}
	double	getW() const
	{
		return	_w;
	}

protected:
	double	_x, _y, _z, _w;
};
