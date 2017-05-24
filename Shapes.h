#pragma once

#include <iostream>
#include "Base.h"
#include "Container.h"

class Shape : public Printable{
public:
	Shape(){
		++count;
	};
	static int getCount(){
		return count;
	};
	virtual ~Shape(){

		--count;
	};
	virtual void print() const = 0;
private:
	static int count;
};

int Shape::count = 0;

class Point : public Named, public Shape{
public:
	Point() :Named("Point"){
		x_pos = 0;
		y_pos = 0;
	};
	Point(const Point & p) :Named(p.name){
		x_pos = p.x_pos;
		y_pos = p.y_pos;
	};
	Point(double x, double y) :Named("Point"){
		x_pos = x;
		y_pos = y;
	};
	virtual void print() const{
		std::cout << "I'm " << name
			<< ": P(" << x_pos << ", " << y_pos << ").\n";
	};
private:
	double x_pos;
	double y_pos;
};

class Circle : public Named, public Shape{
public:
	Circle() :Named("Circle"){
		x_pos = 0;
		y_pos = 0;
		radius = 1;
	};
	Circle(double x, double y, double r) :Named("Circle"){
		x_pos = x;
		y_pos = y;
		radius = r;
	};
	virtual void print() const{
		std::cout << "I'm " << name
			<< ": My centre is O(" << x_pos << ", " << y_pos << "), My radius is " << radius << ".\n";
	};
private:
	double x_pos;
	double y_pos;
	double radius;
};

class Rect : public Named, public Shape{
public:
	Rect() :Named("Rect"){
		x1_pos = 0;
		y1_pos = 0;
		x2_pos = 1;
		y2_pos = 1;
	}
	Rect(double x1, double y1, double x2, double y2) :Named("Rect"){
		if (x1 <= x2){
			x1_pos = x1;
			x2_pos = x2;
		}
		else{
			x1_pos = x2;
			x2_pos = x1;
		}
		if (y1 <= y2){
			y1_pos = y1;
			y2_pos = y2;
		}
		else{
			y1_pos = y2;
			y2_pos = y1;
		}
	};
	virtual void print() const{
		std::cout << "I'm " << name
			<< ": My points is A(" << x1_pos << ", " << y1_pos << "), B("
			<< x1_pos << ", " << y2_pos << "), C("
			<< x2_pos << ", " << y2_pos << "), D("
			<< x2_pos << ", " << y1_pos << ").\n";
	};
private:
	double x1_pos;
	double y1_pos;
	double x2_pos;
	double y2_pos;
};

class Square : public Named, public Shape{
public:
	Square() :Named("Square"){
		x_pos = 0;
		y_pos = 0;
		side = 1;
	};
	Square(double x, double y, double s) :Named("Square"){
		x_pos = x;
		y_pos = y;
		side = s;
	};
	virtual void print() const{
		std::cout << "I'm " << name
			<< ": My points is A(" << x_pos << ", " << y_pos << "), B("
			<< x_pos << ", " << y_pos + side << "), C("
			<< x_pos + side << ", " << y_pos + side << "), D("
			<< x_pos + side << ", " << y_pos << ").\n";
	};

private:
	double x_pos;
	double y_pos;
	double side;
};

class Polyline : public Named, public Shape{
public:
	Polyline() :Named("Polyline"){};
	void push_back(Point * p){
		points.push_back(p);
	}
	virtual void print() const{
		std::cout << "I'm " << name << ": my points are\n";
		for (unsigned int i = 0; i < points.size(); i++){
			std::cout << "       ";
			points[i]->print();
		}
	}
private:
	Container< Point * > points;
};

class Polygon : public Named, public Shape{
public:
	Polygon() :Named("Polygon "){};
	void push_back(Point * p){
		points.push_back(p);
	}
	virtual void print() const{
		std::cout << "I'm " << name << ": my points are\n";
		for (unsigned int i = 0; i < points.size(); i++){
			std::cout << "       ";
			points[i]->print();
		}
	}
private:
	Container< Point * > points;
};
