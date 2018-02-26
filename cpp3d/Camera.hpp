#pragma once

#include "Point3.hpp"
#include "Vector3.hpp"
#include "Polygon3.hpp"

class	Screen;

class Camera
{
public:
	Camera(const Point3& position, const Point3& look_at, const Vector3& up, double near, double far)
		: position_{ position }, look_at_{ look_at },
		up_{ up }, near_{ near }, far_{ far }
	{
	}

	Point3	get_position() const
	{
		return	position_;
	}
	Point3	get_look_at() const
	{
		return	look_at_;
	}
	Vector3	get_up() const
	{
		return	up_;
	}
	double	get_near() const
	{
		return	near_;
	}
	double	get_far() const
	{
		return	far_;
	}

	Vector3	direction() const
	{
		return	look_at_ - position_;
	}

	bool	isCull(const Polygon3& polygon) const
	{
		return	polygon.normal().dotProduct(direction()) >= 0;
	}

	// ビューポート変換
	Polygon3	convertToView(const Polygon3& polygon) const;

	// 投影変換
	Point3	projection(const Point3& point, const Screen& screen) const;

	// 投影変換
	Polygon3	projection(const Polygon3& polygon, const Screen& screen) const;

	Polygon3	perspective(const Polygon3& polygon) const;

protected:
	Point3	position_, look_at_;
	Vector3	up_;
	double	near_, far_;
};
