#include "stdafx.h"
#include "Light.hpp"
#include "Color.hpp"
#include "Polygon3.hpp"
#include <math.h>

Color Light::getDiffuseColor(const Color& color, const Polygon3& polygon) const
{
	// 拡散光の計算(ランバードの余弦則)
	auto L = (position_ - polygon.get_p1()).normalize();
	auto cosa = L.dotProduct(polygon.normal().normalize());
	auto r = static_cast<int>(color.get_r() * (cosa >= 0 ? cosa * 0.9 : 0.0) + 0.1);
	auto g = static_cast<int>(color.get_g() * (cosa >= 0 ? cosa * 0.9 : 0.0) + 0.1);
	auto b = static_cast<int>(color.get_b() * (cosa >= 0 ? cosa * 0.9 : 0.0) + 0.1);
	r = std::min(255, std::max(static_cast<int>(255.0 * 0.1), r));
	g = std::min(255, std::max(static_cast<int>(255.0 * 0.1), g));
	b = std::min(255, std::max(static_cast<int>(255.0 * 0.1), b));
	return	{ r, g, b };
}
