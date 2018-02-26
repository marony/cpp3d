#include "stdafx.h"
#include "Util.hpp"
#include "Polygon3.hpp"
#include "Color.hpp"
#include <regex>
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<std::tuple<Polygon3, Color>>	Util::objToPolygons(const std::string& fileName)
{
	// 初期データ(objファイル)読み込み
	auto	points = std::vector<Point3> {};
	auto	polygons = std::vector<std::tuple<Polygon3, Color>> {};

	auto	regex1 = std::regex{ "^v +([-0-9.]+) +([-0-9.]+) +([-0-9.]+)" };
	auto	regex2 = std::regex{ "^f +([0-9]+)//?[0-9]+ +([0-9]+)//?[0-9]+ +([0-9]+)//?[0-9]+ +([0-9]+)//?[0-9]+ *" };
	auto	regex3 = std::regex{ "^f +([0-9]+)//?[0-9]+ +([0-9]+)//?[0-9]+ +([0-9]+)//?[0-9]+ *" };

	auto count = 0;
	auto ifs = std::ifstream { fileName };
	for (std::string line; std::getline(ifs, line); )
	{
		std::stringstream	ss;
		ss.str(line);
		char	ch;
		ss >> ch;
		switch (ch)
		{
		case	'v':
			// 頂点
			{
				double	x, y, z;
				ss >> x;
				ss >> y;
				ss >> z;
				points.push_back({ x, y, z });
			}
			break;
		case	'f':
			// ポリゴン
			{
				int	a, b, c, d, dummy;
				ss >> a;
				ss >> ch;
				ss >> dummy;
				ss >> b;
				ss >> ch;
				ss >> dummy;
				ss >> c;
				ss >> ch;
				ss >> dummy;
				if (ss.eof())
				{
					auto	p1 = Polygon3{ points[a - 1], points[b - 1], points[c - 1] };
					polygons.push_back(std::make_tuple(p1, Color(255, 230, 230)));
				}
				else
				{
					ss >> d;
					auto	p1 = Polygon3{ points[a - 1], points[b - 1], points[c - 1] };
					auto	p2 = Polygon3{ points[a - 1], points[c - 1], points[d - 1] };
					polygons.push_back(std::make_tuple(p1, Color(255, 230, 230)));
					polygons.push_back(std::make_tuple(p2, Color(255, 230, 230)));
				}
			}
			break;
		}
	}
	return	polygons;
}
