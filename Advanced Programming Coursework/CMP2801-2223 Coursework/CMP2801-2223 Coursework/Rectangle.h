#pragma once
//all header files needed for this file to run
#include "Movable.h"
#include "Shape.h"
#include "Point.h"

using namespace std;

class Rectangle : public Shape, public Movable //inherited from Shape and Moveable classes
{
private:
	float height;
	float width;
	//no need for these methods to be accessed publically
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
	void toString();
public:
	Rectangle(int,int,float,float);
	void move(int, int);
	void scale(float, float);
	~Rectangle();
};

