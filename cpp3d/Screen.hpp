#pragma once

#include "Size.hpp"

class	Point3;
class	Polygon3;

class Screen
{
public:
	Screen(const Size& size, double scale)
		: _size{ size }, _scale{ scale }
	{
	}

	Size	getSize() const
	{
		return	_size;
	}
	double	getScale() const
	{
		return	_scale;
	}

	Point3	convertToScreen(const Point3& point) const;
	Polygon3	convertToScreen(const Polygon3& polygon) const;

protected:
	Size	_size;
	double	_scale;
};
