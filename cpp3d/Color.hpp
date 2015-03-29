#pragma once
class Color
{
public:
	Color(int r = 0, int g = 0, int b = 0)
		: _r{ r }, _g{ g }, _b{ b }
	{
	}

	double	getR() const
	{
		return	_r;
	}
	double	getG() const
	{
		return	_g;
	}
	double	getB() const
	{
		return	_b;
	}

protected:
	int	_r, _g, _b;
};
