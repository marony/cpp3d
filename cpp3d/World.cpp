#include "stdafx.h"
#include "World.hpp"
#include "Point3.hpp"
#include "Color.hpp"
#include "SFML/Window.hpp"
#include <algorithm>

#define _USE_MATH_DEFINES
#include <math.h>

World::World(const std::vector<std::tuple<Polygon3, Color>>& polygons)
	: polygons_(polygons)
{
}

void	World::draw(sf::RenderWindow& window)
{
	window.clear();
	workPolygons_.clear();
	// 全ポリゴン計算
	std::for_each(std::begin(polygons_), std::end(polygons_),
		[&](const std::tuple<Polygon3, Color>& tuple) { draw(tuple, workPolygons_); });
	// 遠い順に並び替える
	std::sort(std::begin(workPolygons_), std::end(workPolygons_),
		[&](const std::tuple<Polygon3, Color>& lhs, const std::tuple<Polygon3, Color>& rhs){
		const auto&	polygon1 = std::get<0>(lhs);
		const auto&	polygon2 = std::get<0>(rhs);
		return	polygon1.get_p1().get_z() + polygon1.get_p2().get_z() + polygon1.get_p3().get_z() >
			polygon2.get_p1().get_z() + polygon2.get_p2().get_z() + polygon2.get_p3().get_z();
	});
	// SFML用の頂点リスト作成
	workVertices_.clear();
	std::for_each(std::begin(workPolygons_), std::end(workPolygons_),
		[&](const std::tuple<Polygon3, Color>& tuple){
		const auto&	polygon = std::get<0>(tuple);
		const auto&	color = std::get<1>(tuple);
		auto	color2 = sf::Color{
			static_cast<sf::Uint8>(color.get_r()),
			static_cast<sf::Uint8>(color.get_g()),
			static_cast<sf::Uint8>(color.get_b())
		};
		workVertices_.push_back(sf::Vertex{
			sf::Vector2f{
				static_cast<float>(polygon.get_p1().get_x()), static_cast<float>(polygon.get_p1().get_y())
			}, color2
		});
		workVertices_.push_back(sf::Vertex{
			sf::Vector2f{
				static_cast<float>(polygon.get_p2().get_x()), static_cast<float>(polygon.get_p2().get_y())
			}, color2
		});
		workVertices_.push_back(sf::Vertex{
			sf::Vector2f{
				static_cast<float>(polygon.get_p3().get_x()), static_cast<float>(polygon.get_p3().get_y())
			}, color2
		});
	});
	// 描画
	window.draw(&workVertices_[0], workVertices_.size(), sf::Triangles);
	window.display();
}

void	World::draw(const std::tuple<Polygon3, Color>& tuple, std::vector<std::tuple<Polygon3, Color>>& polygons)
{
	auto	polygon = std::get<0>(std::move(tuple));
	auto	color = std::get<1>(std::move(tuple));
	// ポリゴン群を投影面の座標に変換
	polygon = polygon.rotateX(R / 360 * 2 * M_PI).
		rotateY((double)rotate_ / 360 * 2 * M_PI);
	// カリング(カメラから見て裏面のポリゴンは省略)
	if (!camera_.isCull(polygon))
	{
		// 拡散光の計算
		color = light_.getDiffuseColor(color, polygon);
		// ビューポート変換
		polygon = camera_.convertToView(polygon);
		// 射影変換
		polygon = camera_.projection(polygon, screen_);
		// 遠近感
		if (polygon.get_p1().get_z() >= camera_.get_near() &&
			polygon.get_p1().get_z() <= camera_.get_far() &&
			polygon.get_p2().get_z() >= camera_.get_near() &&
			polygon.get_p2().get_z() <= camera_.get_far() &&
			polygon.get_p3().get_z() >= camera_.get_near() &&
			polygon.get_p3().get_z() <= camera_.get_far())
		{
			// スクリーン変換
			polygon = screen_.convertToScreen(polygon);
			polygons.push_back(std::make_tuple(polygon, color));
		}
	}
}