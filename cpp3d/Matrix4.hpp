#pragma once

#include <vector>
#include "Vector3.hpp"
#include "Point3.hpp"

class Matrix4
{
public:
	// �ȉ��̏����ŗv�f��n��
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

	// �s�񓯎m�̉��Z
	Matrix4	operator+(const Matrix4& rhs) const;
	// �s�񓯎m�̌��Z
	Matrix4	operator-(const Matrix4& rhs) const;
	// ��Z
	Matrix4	operator*(double a) const;
	// ��
	Vector3	operator*(const Vector3& vector) const;
	// ��
	Point3	operator*(const Point3& vector) const;
	// ��
	Matrix4	operator*(const Matrix4& rhs) const;

protected:
	static const int	SIZE = 4 * 4;
	double	_elements[SIZE];
};

