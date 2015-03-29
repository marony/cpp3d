#pragma once

#include <vector>
#include "Vector3.hpp"
#include "Point3.hpp"

class Matrix4
{
public:
	// ˆÈ‰º‚Ì‡˜‚Å—v‘f‚ğ“n‚·
	// |  0 |  1 |  2 |  3 |
	// |  4 |  5 |  6 |  7 |
	// |  8 |  9 | 10 | 11 |
	// | 12 | 13 | 14 | 15 |
	Matrix4(std::initializer_list<double> init)
	{
		auto i = 0;
		for (auto iter = init.begin(); iter != init.end() && i < SIZE; ++iter, ++i)
			_elements[i] = *iter;
	}

	// s—ñ“¯m‚Ì‰ÁZ
	Matrix4	operator+(const Matrix4& rhs) const;
	// s—ñ“¯m‚ÌŒ¸Z
	Matrix4	operator-(const Matrix4& rhs) const;
	// æZ
	Matrix4	operator*(double a) const;
	// Ï
	Vector3	operator*(const Vector3& vector) const;
	// Ï
	Point3	operator*(const Point3& vector) const;
	// Ï
	Matrix4	operator*(const Matrix4& rhs) const;

protected:
	static const int	SIZE = 4 * 4;
	double	_elements[SIZE];
};

