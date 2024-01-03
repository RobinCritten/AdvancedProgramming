#pragma once
#include "Point.h"

#include <iostream>

using namespace std;

class Shape
{
protected: //protected as child classes need to access them
	float area;
	bool isCircular = false;
	Point leftTop;
	float perimeter;
	Point points[4];
public:
	//virtual classes overloaded and defined by child classes
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void calculatePoints() = 0;
	virtual void toString() = 0;
	bool checkCircular();
	friend ostream& operator << (ostream& output, Shape& s); //operator overload of <<
	~Shape();
};

