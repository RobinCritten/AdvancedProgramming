#define _USE_MATH_DEFINES

//all header files needed for this file to run
#include "Circle.h"
#include "Movable.h"
#include "Shape.h"
#include "Point.h"

//all pre-defined header files needed for this file to run
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//template for choosing largest input
template <typename T>
T maxScalar(T x, T y)
{
	return (x > y) ? x : y;
}

Circle::Circle(int x_coordinate_leftTopPoint, int y_coordinate_leftTopPoint, float radius_length)
{
	//set variables using given parameters 
	leftTop.setx(x_coordinate_leftTopPoint);
	leftTop.sety(y_coordinate_leftTopPoint);
	radius = radius_length;
	isCircular = true;
	//run methods to aquire needed information about shape
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}

void Circle::calculateArea() //area of a circle
{
	area = pow(radius,2) * M_PI; 
}

void Circle::calculatePerimeter() //circumference of a circle
{
	perimeter = 2 * M_PI * radius;
}

void Circle::calculatePoints() //calculate two required points (top left and bottom right)
{
	points[0] = leftTop;
	points[1] = Point(leftTop.getx() + 2*radius, leftTop.gety() + 2*radius);
}

void Circle::toString() //output information about circle to console
{
	cout << "Circle[r=" << radius << "]" << endl;
	cout << "Points[";
	for (int i = 0; i < 2; i++)
	{
		cout << "(" << points[i].getx() << "," << points[i].gety() << ")";
	}
	cout << "]" << endl;
	cout << "Area=" << area << " Perimeter=" << perimeter;
}

void Circle::move(int new_x_coordinate, int new_y_coordinate) //move circle coordinates
{
	//set new leftTop point
	leftTop.setx(new_x_coordinate);
	leftTop.sety(new_y_coordinate);
	calculatePoints(); //recalculate points
}

//Circle remains isotropic by only using the largest input to sclae the height and width of the circle
void Circle::scale(float x_axis_scalar, float y_axis_scalar)
{
	float scalar;
	//choose scalar
	scalar = maxScalar(x_axis_scalar, y_axis_scalar);
	//scale leftTop points and radius using scalar
	leftTop.setx(leftTop.getx() * scalar);
	leftTop.sety(leftTop.gety() * scalar);
	radius = radius * scalar;
	//recalculate appropriate attributes
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}

Circle::~Circle() {} //destructor