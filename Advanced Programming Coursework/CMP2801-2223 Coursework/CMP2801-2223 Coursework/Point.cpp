#include "Point.h"

using namespace std;

float Point::getx()
{
	return x;
}

float Point::gety()
{
	return y;
}

void Point::setx(float X)
{
	x = X;
}

void Point::sety(float Y)
{
	y = Y;
}

Point::Point() //constructor is no coords are given, set coords to 0
{
	x = 0;
	y = 0;
}

Point::Point(float X, float Y) //constructor if coords are given, set appropriately
{
	x = X;
	y = Y;
}

Point::~Point(){} //class destructor