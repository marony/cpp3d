#pragma once

#include "Point3.hpp"
#include "Vector3.hpp"
#include "Polygon3.hpp"

class	Screen;

class Camera
{
public:
	Camera(const Point3& position, const Point3& lookAt, const Vector3& up, double near, double far)
		: _position{ position }, _lookAt{ lookAt },
		_up{ up }, _near{ near }, _far{ far }
	{
	}

	Point3	getPosition() const
	{
		return	_position;
	}
	Point3	getLookAt() const
	{
		return	_lookAt;
	}
	Vector3	getUp() const
	{
		return	_up;
	}
	double	getNear() const
	{
		return	_near;
	}
	double	getFar() const
	{
		return	_far;
	}

	Vector3	direction() const
	{
		return	_lookAt - _position;
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
	Point3	_position, _lookAt;
	Vector3	_up;
	double	_near, _far;
};
