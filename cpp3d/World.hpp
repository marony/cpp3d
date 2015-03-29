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
		return	_rotate;
	}
	void	setRotate(int rotate)
	{
		_rotate = rotate;
		_rotate = _rotate % 360;
	}

	const static int	WIDTH = 640;
	const static int	HEIGHT = 480;

	void	draw(sf::RenderWindow& window);

protected:
	std::vector<std::tuple<Polygon3, Color>>	_polygons;

	int	_rotate = 0;
	const double	R = 0.0;

	// TODO: �ǂݍ��݂̍ۂɃ��f���̑傫�������킹��
	const double	SCALE = 2500.0;
	// �X�N���[��(���)
	Screen _screen = Screen(Size(WIDTH, HEIGHT), SCALE);
	// �J����
	Camera	_camera = Camera(Point3(0, 1.9, -100), Point3(0, 1.9, 0), Vector3(0, 1, 0), 10, 300);
	// ����
	Light	_light = Light(Point3(-500, 500, -500));

	void	draw(const std::tuple<Polygon3, Color>& tuple, std::vector<std::tuple<Polygon3, Color>>& vertices);
};
