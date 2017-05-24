#pragma once

#include "Shapes.h"
#include <string>

class Factory{
public:
	static Shape * create(std::string const & name);
private:
	static const std::string Point_name;
	static const std::string Circle_name;
	static const std::string Rect_name;
	static const std::string Square_name;
	static const std::string Polyline_name;
	static const std::string Polygon_name;
};

const std::string Factory::Point_name = "Point";
const std::string Factory::Circle_name = "Circle";
const std::string Factory::Rect_name = "Rect";
const std::string Factory::Square_name = "Square";
const std::string Factory::Polyline_name = "Polyline";
const std::string Factory::Polygon_name = "Polygon";

Shape * Factory::create(std::string const & name){
	if (Point_name == name){
		return new Point(rand() % 10, rand() % 10);
	}
	if (Circle_name == name){
		return new Circle(rand() % 10, rand() % 10, rand() % 5);
	}
	if (Rect_name == name){
		return new Rect(rand() % 10, rand() % 10, rand() % 10, rand() % 10);
	}
	if (Square_name == name){
		return new Square(rand() % 10, rand() % 10, rand() % 5);
	}
	int length = rand() % 5;
	if (Polyline_name == name){
		Polyline * pl = new Polyline();
		for (int i = 0; i < length; i++){
			pl->push_back(new Point(rand() % 10, rand() % 10));
		}
		return pl;
	}
	if (Polygon_name == name){
		Polygon * pg = new Polygon();
		for (int i = 0; i < length; i++){
			pg->push_back(new Point(rand() % 10, rand() % 10));
		}
		return pg;
	}
	throw std::invalid_argument("Factory: Invalid_argument.");
}