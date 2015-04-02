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
	// �S�|���S���v�Z
	std::for_each(std::begin(polygons_), std::end(polygons_),
		[&](const std::tuple<Polygon3, Color>& tuple) { draw(tuple, workPolygons_); });
	// �������ɕ��ёւ���
	std::sort(std::begin(workPolygons_), std::end(workPolygons_),
		[&](const std::tuple<Polygon3, Color>& lhs, const std::tuple<Polygon3, Color>& rhs){
		const auto&	polygon1 = std::get<0>(lhs);
		const auto&	polygon2 = std::get<0>(rhs);
		return	polygon1.get_p1().get_z() + polygon1.get_p2().get_z() + polygon1.get_p3().get_z() >
			polygon2.get_p1().get_z() + polygon2.get_p2().get_z() + polygon2.get_p3().get_z();
	});
	// SFML�p�̒��_���X�g�쐬
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
	// �`��
	window.draw(&workVertices_[0], workVertices_.size(), sf::Triangles);
	window.display();
}

void	World::draw(const std::tuple<Polygon3, Color>& tuple, std::vector<std::tuple<Polygon3, Color>>& polygons)
{
	auto	polygon = std::get<0>(std::move(tuple));
	auto	color = std::get<1>(std::move(tuple));
	// �|���S���Q�𓊉e�ʂ̍��W�ɕϊ�
	polygon = polygon.rotateX(R / 360 * 2 * M_PI).
		rotateY((double)rotate_ / 360 * 2 * M_PI);
	// �J�����O(�J�������猩�ė��ʂ̃|���S���͏ȗ�)
	if (!camera_.isCull(polygon))
	{
		// �g�U���̌v�Z
		color = light_.getDiffuseColor(color, polygon);
		// �r���[�|�[�g�ϊ�
		polygon = camera_.convertToView(polygon);
		// �ˉe�ϊ�
		polygon = camera_.projection(polygon, screen_);
		// ���ߊ�
		if (polygon.get_p1().get_z() >= camera_.get_near() &&
			polygon.get_p1().get_z() <= camera_.get_far() &&
			polygon.get_p2().get_z() >= camera_.get_near() &&
			polygon.get_p2().get_z() <= camera_.get_far() &&
			polygon.get_p3().get_z() >= camera_.get_near() &&
			polygon.get_p3().get_z() <= camera_.get_far())
		{
			// �X�N���[���ϊ�
			polygon = screen_.convertToScreen(polygon);
			polygons.push_back(std::make_tuple(polygon, color));
		}
	}
}