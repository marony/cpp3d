#pragma once

#include <string>

class Polygon3;
class Color;

class Util
{
public:
	static std::vector<std::tuple<Polygon3, Color>>	objToPolygons(const std::string& fileName);
};
