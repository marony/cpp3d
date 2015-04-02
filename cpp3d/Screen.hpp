#pragma once

#include "Size.hpp"

class	Point3;
class	Polygon3;

class Screen
{
public:
	Screen(const Size& size, double scale)
		: size_{ size }, scale_{ scale }
	{
	}

	Size	get_size() const
	{
		return	size_;
	}
	double	get_scale() const
	{
		return	scale_;
	}

	Point3	convertToScreen(const Point3& point) const;
	Polygon3	convertToScreen(const Polygon3& polygon) const;

protected:
	Size	size_;
	double	scale_;
};
