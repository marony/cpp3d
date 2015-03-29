#include "stdafx.h"
#include "World.hpp"
#include "Point3.hpp"
#include "Color.hpp"
#include "SFML/Window.hpp"
#include <algorithm>

#define _USE_MATH_DEFINES
#include <math.h>

World::World(const std::vector<std::tuple<Polygon3, Color>>& polygons)
	: _polygons(polygons)
{
}

void	World::draw(sf::RenderWindow& window)
{
	window.clear();
	std::vector<std::tuple<Polygon3, Color>>	polygons{ _polygons.size() };
	// 全ポリゴン計算
	std::for_each(std::begin(_polygons), std::end(_polygons),
		[&](const std::tuple<Polygon3, Color>& tuple) { draw(tuple, polygons); });
	// 遠い順に並び替える
	std::sort(std::begin(polygons), std::end(polygons),
		[&](const std::tuple<Polygon3, Color>& lhs, const std::tuple<Polygon3, Color>& rhs){
		auto&	polygon1 = std::get<0>(lhs);
		auto&	polygon2 = std::get<0>(rhs);
		return	polygon1.getP1().getZ() + polygon1.getP2().getZ() + polygon1.getP3().getZ() >
			polygon2.getP1().getZ() + polygon2.getP2().getZ() + polygon2.getP3().getZ();
	});
	// SFML用の頂点リスト作成
	std::vector<sf::Vertex>	vertices2{ polygons.size() * 3 };
	std::for_each(std::begin(polygons), std::end(polygons),
		[&](const std::tuple<Polygon3, Color>& tuple){
		auto&	polygon = std::get<0>(tuple);
		auto&	color = std::get<1>(tuple);
		auto	color2 = sf::Color{
			static_cast<sf::Uint8>(color.getR()),
			static_cast<sf::Uint8>(color.getG()),
			static_cast<sf::Uint8>(color.getB())
		};
		vertices2.push_back(sf::Vertex{
			sf::Vector2f{
				static_cast<float>(polygon.getP1().getX()), static_cast<float>(polygon.getP1().getY())
			}, color2
		});
		vertices2.push_back(sf::Vertex{
			sf::Vector2f{
				static_cast<float>(polygon.getP2().getX()), static_cast<float>(polygon.getP2().getY())
			}, color2
		});
		vertices2.push_back(sf::Vertex{
			sf::Vector2f{
				static_cast<float>(polygon.getP3().getX()), static_cast<float>(polygon.getP3().getY())
			}, color2
		});
	});
	// 描画
	window.draw(&vertices2[0], vertices2.size(), sf::Triangles);
	window.display();
}

void	World::draw(const std::tuple<Polygon3, Color>& tuple, std::vector<std::tuple<Polygon3, Color>>& polygons)
{
	auto	polygon = std::get<0>(std::move(tuple));
	auto	color = std::get<1>(std::move(tuple));
	// ポリゴン群を投影面の座標に変換
	polygon = polygon.rotateX(R / 360 * 2 * M_PI).
		rotateY((double)_rotate / 360 * 2 * M_PI);
	// カリング(カメラから見て裏面のポリゴンは省略)
	if (!_camera.isCull(polygon))
	{
		// 拡散光の計算
		color = _light.getDiffuseColor(color, polygon);
		// ビューポート変換
		polygon = _camera.convertToView(polygon);
		// 射影変換
		polygon = _camera.projection(polygon, _screen);
		// 遠近感
		if (polygon.getP1().getZ() >= _camera.getNear() &&
			polygon.getP1().getZ() <= _camera.getFar() &&
			polygon.getP2().getZ() >= _camera.getNear() &&
			polygon.getP2().getZ() <= _camera.getFar() &&
			polygon.getP3().getZ() >= _camera.getNear() &&
			polygon.getP3().getZ() <= _camera.getFar())
		{
			// スクリーン変換
			polygon = _screen.convertToScreen(polygon);
			polygons.push_back(std::make_tuple(polygon, color));
		}
	}
}