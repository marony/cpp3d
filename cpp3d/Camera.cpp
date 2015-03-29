#include "stdafx.h"
#include "Camera.hpp"
#include "Screen.hpp"

// ビューポート変換
Polygon3	Camera::convertToView(const Polygon3& polygon) const
{
	auto	z = direction().normalize();
	auto	x = _up.crossProduct(z).normalize();
	auto	y = z.crossProduct(x).normalize();
	auto	tx = static_cast<Vector3>(getPosition()).dotProduct(x) * -1;
	auto	ty = static_cast<Vector3>(getPosition()).dotProduct(y) * -1;
	auto	tz = static_cast<Vector3>(getPosition()).dotProduct(z) * -1;
	auto	matrix = Matrix4 {
		x.getX(), x.getY(), x.getZ(), tx,
		y.getX(), y.getY(), y.getZ(), ty,
		z.getX(), z.getY(), z.getZ(), tz,
		0, 0, 0, 1
	};
	auto	polygon2 = polygon.affin(matrix);
	return	polygon2;
}

// 投影変換
Point3	Camera::projection(const Point3& point, const Screen& screen) const
{
	return	{
		_near * 2 * point.getX() / screen.getSize().getWidth(),
		_near * 2 * point.getY() / screen.getSize().getHeight(),
		(_far + _near) * point.getZ() / (_far - _near) + (2 * _near * _far) / (_far - _near),
		(2 * _near * _far) * point.getW() / (_far - _near)
	};
}

// 投影変換
Polygon3	Camera::projection(const Polygon3& polygon, const Screen& screen) const
{
	return	{
		projection(polygon.getP1(), screen),
		projection(polygon.getP2(), screen),
		projection(polygon.getP3(), screen)
	};
}

Polygon3	Camera::perspective(const Polygon3& polygon) const
{
	return	{
		polygon.getP1() / polygon.getP1().getW(),
		polygon.getP2() / polygon.getP2().getW(),
		polygon.getP3() / polygon.getP3().getW()
	};
}
