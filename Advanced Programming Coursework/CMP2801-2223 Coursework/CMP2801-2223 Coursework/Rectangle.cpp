//all header files needed for this file to run
#include "Rectangle.h"
#include "Movable.h"
#include "Shape.h"
#include "Point.h"

//all pre-defined header files needed for this file to run
#include <iostream>
#include <string>

using namespace std;

//rectangle constructor 
Rectangle::Rectangle(int x_coordinate_leftTopPoint, int y_coordinate_leftTopPoint, float h, float w)
{
	//set variables using parameters
	leftTop.setx(x_coordinate_leftTopPoint);
	leftTop.sety(y_coordinate_leftTopPoint);
	width = w;
	height = h;
	//calculate information about rectangle
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}

void Rectangle::calculateArea() //calculate are of rectangle
{
	area = height * width;
}

void Rectangle::calculatePerimeter() //calculate perimeter of rectangle
{
	perimeter = 2 * height + 2 * width;
}

void Rectangle::calculatePoints() //calculate four corners of rectangle
{
	points[0] = leftTop;
	points[1] = Point(leftTop.getx() + width, leftTop.gety());
	points[2] = Point(leftTop.getx() + width, leftTop.gety() + height);
	points[3] = Point(leftTop.getx(), leftTop.gety() + height);
}

void Rectangle::toString() //about information about rectangle to console
{
	cout << "Rectangle[h=" << height << ",w=" << width << "]" << endl;
	cout << "Points[";
	for (int i = 0; i < 4; i++)
	{
		cout << "(" << points[i].getx() << "," << points[i].gety() << ")";
	}
	cout << "]" << endl;
	cout << "Area=" << area << " Perimeter=" << perimeter;
}

void Rectangle::move(int new_x_coordinate, int new_y_coordinate) //move rectangle to new coordinates
{
	leftTop.setx(new_x_coordinate);
	leftTop.sety(new_y_coordinate);
	calculatePoints();
}

void Rectangle::scale(float x_axis_scalar, float y_axis_scalar) //scale rectangle width and height independantly
{
	leftTop.setx(leftTop.getx() * x_axis_scalar);
	leftTop.sety(leftTop.gety() * y_axis_scalar);
	height = height * y_axis_scalar;
	width = width * x_axis_scalar;
	//recalculate appropriate information
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}

Rectangle::~Rectangle() {} //destructor