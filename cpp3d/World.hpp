#pragma once

class	Polygon3;
class	Color;
class	sf::RenderWindow;
#include "Screen.hpp"
#include "Camera.hpp"
#include "Light.hpp"

class World
{
public:
	World(const std::vector<std::tuple<Polygon3, Color>>& polygons);

	int	getRotate() const
	{
		return	rotate_;
	}
	void	setRotate(int rotate)
	{
		rotate_ = rotate;
		rotate_ = rotate_ % 360;
	}

	const static int	WIDTH = 640;
	const static int	HEIGHT = 480;

	void	draw(sf::RenderWindow& window);

protected:
	std::vector<std::tuple<Polygon3, Color>>	polygons_;

	int	rotate_ = 0;
	const double	R = 0.0;

	// TODO: �ǂݍ��݂̍ۂɃ��f���̑傫�������킹��
	const double	SCALE = 2500.0;
	// �X�N���[��(���)
	Screen screen_ = Screen(Size(WIDTH, HEIGHT), SCALE);
	// �J����
	Camera	camera_ = Camera(Point3(0, 1.9, -100), Point3(0, 1.9, 0), Vector3(0, 1, 0), 10, 300);
	// ����
	Light	light_ = Light(Point3(-500, 500, -500));

	// ��Ɨp
	std::vector<std::tuple<Polygon3, Color>>	workPolygons_ = std::vector<std::tuple<Polygon3, Color>>{};
	std::vector<sf::Vertex>	workVertices_ = std::vector<sf::Vertex> {};

	void	draw(const std::tuple<Polygon3, Color>& tuple, std::vector<std::tuple<Polygon3, Color>>& vertices);
};
