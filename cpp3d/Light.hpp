#pragma once

#include "Point3.hpp"

class	Color;
class	Polygon3;

class Light
{
public:
	Light(const Point3& position)
		: _position{ position }
	{
	}

	Point3	getPosition() const
	{
		return	_position;
	}

	Color getDiffuseColor(const Color& color, const Polygon3& polygon) const;

protected:
	Point3	_position;
};
