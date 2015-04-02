#pragma once
class Size
{
public:
	Size(int width = 0, int height = 0)
		: width_{ width }, height_{ height }
	{
	}
	Size(const Size& rhs)
		: width_{ rhs.width_ }, height_{ rhs.height_ }
	{
	}

	const Size&	operator=(const Size& rhs)
	{
		width_ = rhs.width_;
		height_ = rhs.height_;
	}
	bool	operator==(const Size& rhs) const
	{
		return	(this == &rhs) ||
			(width_ == rhs.width_ && height_ == rhs.height_);
	}

	bool	operator!=(const Size& rhs) const
	{
		return !operator==(rhs);
	}

	int	get_width() const
	{
		return	width_;
	}
	int	get_height() const
	{
		return	height_;
	}

protected:
	int	width_, height_;
};
