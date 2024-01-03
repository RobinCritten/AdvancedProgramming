#pragma once
//all header files needed for this file to run
#include "Movable.h"
#include "Shape.h"
#include "Point.h"

class Square : public Shape, public Movable //inherits from Shape and Moveable classes
{
private:
	float edge;
	float height;
	float width;
	//no need for these methods to be accessed publically
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
	void toString();
public:
	void move(int, int);
	void scale(float, float);
	Square(int,int,float);
	~Square();
};

