#pragma once

class Point3;

#include <math.h>

class Vector3
{
public:
	Vector3(double x = 0.0, double y = 0.0, double z = 0.0, double w = 1.0)
		: x_{ x }, y_{ y }, z_{ z }, w_{ w }
	{
	}
	Vector3(const Vector3& rhs)
		: Vector3{ rhs.x_, rhs.y_, rhs.z_, rhs.w_ }
	{
	}
	Vector3(const Point3& rhs);

	const Vector3&	operator=(const Vector3& rhs)
	{
		if (this != &rhs)
		{
			x_ = rhs.x_;
			y_ = rhs.y_;
			z_ = rhs.z_;
			w_ = rhs.w_;
		}
		return	*this;
	}
	bool	operator==(const Vector3& rhs) const
	{
		return (this == &rhs) ||
			(x_ == rhs.x_ &&
			 y_ == rhs.y_ &&
			 z_ == rhs.z_ &&
			 w_ == rhs.w_);
	}
	bool	operator!=(const Vector3& rhs) const
	{
		return	!operator==(rhs);
	}
	operator Point3() const;

	double	get_x() const
	{
		return	x_;
	}
	double	get_y() const
	{
		return	y_;
	}
	double	get_z() const
	{
		return	z_;
	}
	double	get_w() const
	{
		return	w_;
	}

	// ベクトルの大きさを取得
	double	length() const
	{
		return	sqrt(x_ * x_ + y_ * y_ + z_ * z_);
	}
	// 単位ベクトルを取得
	Vector3	normalize() const
	{
		return	{
			x_ / length(),
			y_ / length(),
			z_ / length()
		};
	}
	// 加算
	Vector3	operator+(const Vector3& rhs) const
	{
		return	{
			x_ + rhs.x_,
			y_ + rhs.y_,
			z_ + rhs.z_
		};
	}
	// 減算
	Vector3	operator-(const Vector3& rhs) const
	{
		return	{
			x_ - rhs.x_,
			y_ - rhs.y_,
			z_ - rhs.z_
		};
	}
	// 乗算
	Vector3	operator*(double a) const
	{
		return	{ x_ * a, y_ * a, z_ * a };
	}
	// 除算
	Vector3	operator/(double a) const
	{
		return	{ x_ / a, y_ / a, z_ / a };
	}
	// 内積
	double	dotProduct(const Vector3& rhs) const
	{
		return	x_ * rhs.x_ + y_ * rhs.y_ + z_ * rhs.z_;
	}
	// 外積
	Vector3	crossProduct(const Vector3& rhs) const
	{
		return	{
			y_ * rhs.z_ - z_ * rhs.y_,
			z_ * rhs.x_ - x_ * rhs.z_,
			x_ * rhs.y_ - y_ * rhs.x_
		};
	}

protected:
	double	x_, y_, z_, w_;
};
