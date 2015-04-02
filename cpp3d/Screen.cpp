#include "stdafx.h"
#include "Screen.hpp"
#include "Point3.hpp"
#include "Polygon3.hpp"

Point3	Screen::convertToScreen(const Point3& point) const
{
	// ���e�ʂ��f�B�X�v���C�ɍ��킹��
	return	{
		size_.get_width() / 2 + point.get_x() * scale_,
		size_.get_height() / 2 - point.get_y() * scale_,
		point.get_z()
	};
}
Polygon3	Screen::convertToScreen(const Polygon3& polygon) const
{
	// �|���S�����X�N���[��(���)�̍��W�ɍ��킹��
	return	{
		convertToScreen(polygon.get_p1()),
		convertToScreen(polygon.get_p2()),
		convertToScreen(polygon.get_p3())
	};
}
