#include <iostream>
#include "Factory.h"

int main(){
	Container< Shape * > con;
	try{
		con.push_back(Factory::create("Point"));
		con.push_back(Factory::create("Circle"));
		con.push_back(Factory::create("Rect"));
		con.push_back(Factory::create("Square"));
		con.push_back(Factory::create("Polyline"));
		con.push_back(Factory::create("Polygon"));
		std::cout << "Now " << Shape::getCount() << ": Elements" << "\n";
		for (unsigned int i = 0; i < con.size(); i++){
			con[i]->print();
		}
		con.free();
		std::cout << "Now " << Shape::getCount() << " Elements" << "\n";
	}
	catch (std::exception & e){
		std::cout << e.what();
	}
	return 0;
}