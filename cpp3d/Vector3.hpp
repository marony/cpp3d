#pragma once

class Point3;

class Vector3
{
public:
	Vector3(double x = 0.0, double y = 0.0, double z = 0.0, double w = 1.0)
		: _x{ x }, _y{ y }, _z{ z }, _w{ w }
	{
	}
	Vector3(const Vector3& rhs)
		: Vector3{ rhs._x, rhs._y, rhs._z, rhs._w }
	{
	}
	Vector3(const Point3& rhs);

	const Vector3&	operator=(const Vector3& rhs)
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
	bool	operator==(const Vector3& rhs) const
	{
		return (this == &rhs) ||
			(_x == rhs._x &&
			 _y == rhs._y &&
			 _z == rhs._z &&
			 _w == rhs._w);
	}
	bool	operator!=(const Vector3& rhs) const
	{
		return	!operator==(rhs);
	}
	operator Point3() const;

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

	// �x�N�g���̑傫�����擾
	double	length() const
	{
		return	sqrt(_x * _x + _y * _y + _z * _z);
	}
	// �P�ʃx�N�g�����擾
	Vector3	normalize() const
	{
		return	Vector3 {
			_x / length(),
			_y / length(),
			_z / length()
		};
	}
	// ���Z
	Vector3	operator+(const Vector3& rhs) const
	{
		return	Vector3 {
			_x + rhs._x,
			_y + rhs._y,
			_z + rhs._z
		};
	}
	// ���Z
	Vector3	operator-(const Vector3& rhs) const
	{
		return	{
			_x - rhs._x,
			_y - rhs._y,
			_z - rhs._z
		};
	}
	// ��Z
	Vector3	operator*(double a) const
	{
		return	{ _x * a, _y * a, _z * a };
	}
	// ���Z
	Vector3	operator/(double a) const
	{
		return	{ _x / a, _y / a, _z / a };
	}
	// ����
	double	dotProduct(const Vector3& rhs) const
	{
		return	_x * rhs._x + _y * rhs._y + _z * rhs._z;
	}
	// �O��
	Vector3	crossProduct(const Vector3& rhs) const
	{
		return	{
			_y * rhs._z - _z * rhs._y,
			_z * rhs._x - _x * rhs._z,
			_x * rhs._y - _y * rhs._x
		};
	}

protected:
	double	_x, _y, _z, _w;
};
