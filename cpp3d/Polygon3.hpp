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
		: p1_{ p1 }, p2_{ p2 }, p3_{ p3 }
	{
	}

	Point3	get_p1() const
	{
		return	p1_;
	}
	Point3	get_p2() const
	{
		return	p2_;
	}
	Point3	get_p3() const
	{
		return	p3_;
	}

	// ñ@ê¸ÉxÉNÉgÉã
	Vector3	normal() const
	{
		return	(p2_ - p1_).crossProduct(p3_ - p1_);
	}

	// ÉAÉtÉBÉìïœä∑
	Polygon3	affin(const Matrix4& matrix) const
	{
		return	{
			matrix * p1_,
			matrix * p2_,
			matrix * p3_
		};
	}

	// à⁄ìÆ
	// | 1 | 0 | 0 | tx |
	// | 0 | 1 | 0 | ty |
	// | 0 | 0 | 1 | tz |
	// | 0 | 0 | 0 | 1  |
	Polygon3	move(const Vector3& vector) const
	{
		//    Polygon3(p1 + vector, p2 + vector, p3 + vector)
		auto matrix = Matrix4 {
			1, 0, 0, vector.get_x(),
			0, 1, 0, vector.get_y(),
			0, 0, 1, vector.get_z(),
			0, 0, 0, 1
		};
		return	affin(matrix);
	}
	// ägëÂÅEèkè¨ÅAîΩì]
	// | sx | 0  | 0  | 0 |
	// | 0  | sy | 0  | 0 |
	// | 0  | 0  | sz | 0 |
	// | 0  | 0  | 0  | 1 |
	Polygon3	scale(const Vector3& vector) const
	{
		auto matrix = Matrix4 {
			vector.get_x(), 0, 0, 0,
			0, vector.get_y(), 0, 0,
			0, 0, vector.get_z(), 0,
			0, 0, 0, 1
		};
		return	affin(matrix);
	}
	// Xé≤é¸ÇËÇ…âÒì]
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
	// Yé≤é¸ÇËÇ…âÒì]
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
	// Zé≤é¸ÇËÇ…âÒì]
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
	Point3	p1_, p2_, p3_;
};
