// cpp3d.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "World.hpp"
#include "Util.hpp"
#include <iostream>

auto _tmain(int argc, _TCHAR* argv[]) -> int
{
	auto	polygons = Util::objToPolygons("miku.obj");
	std::cout << polygons.size() << std::endl;

	World	world(polygons);
	sf::RenderWindow window{ sf::VideoMode(World::WIDTH, World::HEIGHT), "SFML works!" };
	window.setVerticalSyncEnabled(true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		world.draw(window);
		world.setRotate(world.getRotate() + 3);
	}

	return 0;
}
