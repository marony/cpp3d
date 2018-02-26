#pragma once

#include "Point3.hpp"

class	Color;
class	Polygon3;

class Light
{
public:
	Light(const Point3& position)
		: position_{ position }
	{
	}

	Point3	get_position() const
	{
		return	position_;
	}

	Color getDiffuseColor(const Color& color, const Polygon3& polygon) const;

protected:
	Point3	position_;
};
