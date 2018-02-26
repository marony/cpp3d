#include "stdafx.h"
#include "Camera.hpp"
#include "Screen.hpp"

// ビューポート変換
Polygon3	Camera::convertToView(const Polygon3& polygon) const
{
	auto	z = direction().normalize();
	auto	x = up_.crossProduct(z).normalize();
	auto	y = z.crossProduct(x).normalize();
	auto	tx = static_cast<Vector3>(get_position()).dotProduct(x) * -1;
	auto	ty = static_cast<Vector3>(get_position()).dotProduct(y) * -1;
	auto	tz = static_cast<Vector3>(get_position()).dotProduct(z) * -1;
	auto	matrix = Matrix<> {
		x.get_x(), x.get_y(), x.get_z(), tx,
		y.get_x(), y.get_y(), y.get_z(), ty,
		z.get_x(), z.get_y(), z.get_z(), tz,
		0, 0, 0, 1
	};
	auto	polygon2 = polygon.affin(matrix);
	return	polygon2;
}

// 投影変換
Point3	Camera::projection(const Point3& point, const Screen& screen) const
{
	return	{
		near_ * 2 * point.get_x() / screen.get_size().get_width(),
		near_ * 2 * point.get_y() / screen.get_size().get_height(),
		(far_ + near_) * point.get_z() / (far_ - near_) + (2 * near_ * far_) / (far_ - near_),
		(2 * near_ * far_) * point.get_w() / (far_ - near_)
	};
}

// 投影変換
Polygon3	Camera::projection(const Polygon3& polygon, const Screen& screen) const
{
	return	{
		projection(polygon.get_p1(), screen),
		projection(polygon.get_p2(), screen),
		projection(polygon.get_p3(), screen)
	};
}

Polygon3	Camera::perspective(const Polygon3& polygon) const
{
	return	{
		polygon.get_p1() / polygon.get_p1().get_w(),
		polygon.get_p2() / polygon.get_p2().get_w(),
		polygon.get_p3() / polygon.get_p3().get_w()
	};
}
