#pragma once
class Size
{
public:
	Size(int width = 0, int height = 0)
		: _width{ width }, _height{ height }
	{
	}
	Size(const Size& rhs)
		: _width{ rhs._width }, _height{ rhs._height }
	{
	}

	const Size&	operator=(const Size& rhs)
	{
		_width = rhs._width;
		_height = rhs._height;
	}
	bool	operator==(const Size& rhs) const
	{
		return	(this == &rhs) ||
			(_width == rhs._width && _height == rhs._height);
	}

	bool	operator!=(const Size& rhs) const
	{
		return !operator==(rhs);
	}

	int	getWidth() const
	{
		return	_width;
	}
	int	getHeight() const
	{
		return	_height;
	}

protected:
	int	_width, _height;
};
