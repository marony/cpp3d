#pragma once

#include <vector>
#include "Vector3.hpp"
#include "Point3.hpp"

template<typename T = double, int N = 4>
class Matrix
{
public:
	static const int	SIZE = N * N;

	// à»â∫ÇÃèáèòÇ≈óvëfÇìnÇ∑
	// |  0 |  1 |  2 |  3 |
	// |  4 |  5 |  6 |  7 |
	// |  8 |  9 | 10 | 11 |
	// | 12 | 13 | 14 | 15 |
	Matrix(std::initializer_list<T> init)
	{
		auto i = 0;
		for (auto iter = init.begin(); iter != init.end() && i < SIZE; ++iter, ++i)
			elements_[i] = *iter;
	}

	Matrix(T init[SIZE])
	{
		auto i = 0;
		for (auto i = 0; i < SIZE; ++i)
			elements_[i] = init[i];
	}

	// çsóÒìØémÇÃâ¡éZ
	Matrix	operator+(const Matrix& rhs) const;
	// çsóÒìØémÇÃå∏éZ
	Matrix	operator-(const Matrix& rhs) const;
	// èÊéZ
	Matrix	operator*(double a) const;
	// èÊéZ
	Vector3	operator*(const Vector3& vector) const;
	// èÊéZ
	Point3	operator*(const Point3& point) const;
	// èÊéZ
	Matrix	operator*(const Matrix& rhs) const;

protected:
	T	elements_[SIZE];
};

// çsóÒìØémÇÃâ¡éZ
template<typename T, int N>
Matrix<T, N>	Matrix<T, N>::operator+(const Matrix& rhs) const
{
	auto	matrix = Matrix<> {};
	for (auto i = 0; i < SIZE; ++i)
		matrix.elements_[i] = elements_[i] + rhs.elements_[i];
	return	matrix;
}

// çsóÒìØémÇÃå∏éZ
template<typename T, int N>
Matrix<T, N>	Matrix<T, N>::operator-(const Matrix& rhs) const
{
	auto	matrix = Matrix<> {};
	for (auto i = 0; i < SIZE; ++i)
		matrix.elements_[i] = elements_[i] - rhs.elements_[i];
	return	matrix;
}

// è≠êîÇ∆ÇÃèÊéZ
template<typename T, int N>
Matrix<T, N>	Matrix<T, N>::operator*(double a) const
{
	auto	matrix = Matrix<> {};
	for (auto i = 0; i < SIZE; ++i)
		matrix.elements_[i] = elements_[i] * a;
	return	matrix;
}

// ÉxÉNÉgÉãÇ∆ÇÃèÊéZ
template<typename T, int N>
Vector3	Matrix<T, N>::operator*(const Vector3& vector) const
{
	using	fnp_t = double (Vector3::*)() const;
	fnp_t	getters[] = {
		&Vector3::get_x,
		&Vector3::get_y,
		&Vector3::get_z,
		&Vector3::get_w,
	};
	double	buf[N];
	for (auto y = 0; y < N; ++y)
		buf[y] = elements_[y * N] * (vector.*(getters[0]))() +
			elements_[y * N + 1] * (vector.*(getters[1]))() +
			elements_[y * N + 2] * (vector.*(getters[2]))() +
			elements_[y * N + 3] * (vector.*(getters[3]))();
	return{ buf[0], buf[1], buf[2], buf[3] };
}

// ç¿ïWÇ∆ÇÃèÊéZ
template<typename T, int N>
Point3	Matrix<T, N>::operator*(const Point3& point) const
{
	using	fnp_t = double (Point3::*)() const;
	fnp_t	getters[] = {
		&Point3::get_x,
		&Point3::get_y,
		&Point3::get_z,
		&Point3::get_w,
	};
	double	buf[N];
	for (auto y = 0; y < N; ++y)
		buf[y] = elements_[y * N] * (point.*(getters[0]))() +
			elements_[y * N + 1] * (point.*(getters[1]))() +
			elements_[y * N + 2] * (point.*(getters[2]))() +
			elements_[y * N + 3] * (point.*(getters[3]))();
	return{ buf[0], buf[1], buf[2], buf[3] };
}

// çsóÒìØémÇÃèÊéZ
template<typename T, int N>
Matrix<T, N>	Matrix<T, N>::operator*(const Matrix& rhs) const
{
	auto	matrix = Matrix<> {};
	for (auto y = 0; y < N; ++y){
		for (auto x = 0; x < N; ++x) {
			auto	i = y * N + x;
			matrix.elements_[i] =
				elements_[x + y * N] * rhs.elements_[y * N] +
				elements_[x + y * N + 1] * rhs.elements_[y * N + 1] +
				elements_[x + y * N + 2] * rhs.elements_[y * N + 2] +
				elements_[x + y * N + 3] * rhs.elements_[y * N + 3];
		}
	}
	return	matrix;
}
