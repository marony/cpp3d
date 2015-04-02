#pragma once

class Vector3;

class Point3
{
public:
	Point3(double x = 0.0, double y = 0.0, double z = 0.0, double w = 1.0)
		: x_{ x }, y_{ y }, z_{ z }, w_{ w }
	{
	}
	Point3(const Point3& rhs)
		: Point3 { rhs.x_, rhs.y_, rhs.z_, rhs.w_ }
	{
	}
	Point3(const Vector3& rhs);

	const Point3&	operator=(const Point3& rhs)
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
	bool	operator==(const Point3& rhs) const
	{
		return	(this == &rhs) ||
			(x_ == rhs.x_ &&
			 y_ == rhs.y_ &&
			 z_ == rhs.z_ &&
			 w_ == rhs.w_);
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

protected:
	double	x_, y_, z_, w_;
};
