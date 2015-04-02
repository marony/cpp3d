#pragma once
class Color
{
public:
	Color(int r = 0, int g = 0, int b = 0)
		: r_{ r }, g_{ g }, b_{ b }
	{
	}

	double	get_r() const
	{
		return	r_;
	}
	double	get_g() const
	{
		return	g_;
	}
	double	get_b() const
	{
		return	b_;
	}

protected:
	int	r_, g_, b_;
};
