#pragma once

class	sf::RenderWindow;
#include "Vector3.hpp"
#include "Point3.hpp"
#include "Color.hpp"
#include "Matrix4.hpp"

class Polygon3
{
public:
	Polygon3()
	{
	}
	Polygon3(const Point3& p1, const Point3& p2, const Point3& p3)
		: _p1{ p1 }, _p2{ p2 }, _p3{ p3 }
	{
	}

	Point3	getP1() const
	{
		return	_p1;
	}
	Point3	getP2() const
	{
		return	_p2;
	}
	Point3	getP3() const
	{
		return	_p3;
	}

	// �@���x�N�g��
	Vector3	normal() const
	{
		return	(_p2 - _p1).crossProduct(_p3 - _p1);
	}

	// �A�t�B���ϊ�
	Polygon3	affin(const Matrix4& matrix) const
	{
		return	{
			matrix * _p1,
			matrix * _p2,
			matrix * _p3
		};
	}

	// �ړ�
	// | 1 | 0 | 0 | tx |
	// | 0 | 1 | 0 | ty |
	// | 0 | 0 | 1 | tz |
	// | 0 | 0 | 0 | 1  |
	Polygon3	move(const Vector3& vector) const
	{
		//    Polygon3(p1 + vector, p2 + vector, p3 + vector)
		auto matrix = Matrix4 {
			1, 0, 0, vector.getX(),
			0, 1, 0, vector.getY(),
			0, 0, 1, vector.getZ(),
			0, 0, 0, 1
		};
		return	affin(matrix);
	}
	// �g��E�k���A���]
	// | sx | 0  | 0  | 0 |
	// | 0  | sy | 0  | 0 |
	// | 0  | 0  | sz | 0 |
	// | 0  | 0  | 0  | 1 |
	Polygon3	scale(const Vector3& vector) const
	{
		auto matrix = Matrix4 {
			vector.getX(), 0, 0, 0,
			0, vector.getY(), 0, 0,
			0, 0, vector.getZ(), 0,
			0, 0, 0, 1
		};
		return	affin(matrix);
	}
	// X������ɉ�]
	// | 1 | 0     | 0      | 0 |
	// | 0 | cos r | -sin r | 0 |
	// | 0 | sin r | cos r  | 0 |
	// | 0 | 0     | 0      | 1 |
	Polygon3	rotateX(double r) const
	{
		auto matrix = Matrix4 {
			1, 0, 0, 0,
			0, cos(r), -sin(r), 0,
			0, sin(r), cos(r), 0,
			0, 0, 0, 1
		};
		return	affin(matrix);
	}
	// Y������ɉ�]
	// | cos r  | 0 | sin r | 0 |
	// | 0      | 1 | 0     | 0 |
	// | -sin r | 0 | cos r | 0 |
	// | 0      | 0 | 0     | 1 |
	Polygon3	rotateY(double r) const
	{
		auto matrix = Matrix4 {
			cos(r), 0, sin(r), 0,
			0, 1, 0, 0,
			-sin(r), 0, cos(r), 0,
			0, 0, 0, 1
		};
		return	affin(matrix);
	}
	// Z������ɉ�]
	// | cos r | -sin r | 0 | 0 |
	// | sin r | cos r  | 0 | 0 |
	// | 0     | 0      | 1 | 0 |
	// | 0     | 0      | 0 | 1 |
	Polygon3	rotateZ(double r) const
	{
		auto matrix = Matrix4 {
			cos(r), -sin(r), 0, 0,
			sin(r), cos(r), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};
		return	affin(matrix);
	}

protected:
	Point3	_p1, _p2, _p3;
};
