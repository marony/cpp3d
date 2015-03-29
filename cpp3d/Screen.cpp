#include "stdafx.h"
#include "Screen.hpp"
#include "Point3.hpp"
#include "Polygon3.hpp"

Point3	Screen::convertToScreen(const Point3& point) const
{
	// ���e�ʂ��f�B�X�v���C�ɍ��킹��
	return	{
		_size.getWidth() / 2 + point.getX() * _scale,
		_size.getHeight() / 2 - point.getY() * _scale,
		point.getZ()
	};
}
Polygon3	Screen::convertToScreen(const Polygon3& polygon) const
{
	// �|���S�����X�N���[��(���)�̍��W�ɍ��킹��
	return	{
		convertToScreen(polygon.getP1()),
		convertToScreen(polygon.getP2()),
		convertToScreen(polygon.getP3())
	};
}
