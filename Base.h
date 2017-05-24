#pragma once
#include <string>

class Printable{
public:
	virtual void print() const = 0;
	virtual ~Printable() {};
};

class Named : public Printable{
public:
	Named(std::string const & name){
		Named::name = name;
	};
	virtual void print() const = 0;
protected:
	std::string name;
};

