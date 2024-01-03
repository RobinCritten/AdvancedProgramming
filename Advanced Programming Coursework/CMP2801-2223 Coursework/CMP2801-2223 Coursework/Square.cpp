//all header files needed for this file to run
#include "Square.h"
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


Square::Square(int x_coordinate_leftTopPoint, int y_coordinate_leftTopPoint, float edge_length)
{
	//initialise variables using given information
	leftTop.setx(x_coordinate_leftTopPoint);
	leftTop.sety(y_coordinate_leftTopPoint);
	edge = edge_length; 
	//run methods to calculate neccessary informartion about shape
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}

void Square::calculateArea() //calculate area of square
{
	area = pow(edge,2);
}

void Square::calculatePerimeter() //calculate perimeter of square
{
	perimeter = 4 * edge;
}

void Square::calculatePoints() //calculate points of square
{
	points[0] = leftTop;
	points[1] = Point(leftTop.getx() + edge, leftTop.gety());
	points[2] = Point(leftTop.getx() + edge, leftTop.gety() + edge);
	points[3] = Point(leftTop.getx(), leftTop.gety() + edge);
}

void Square::toString() //output information about square to console as string
{
	cout << "Square[e=" << edge << "]" << endl;
	cout << "Points[";
	for (int i = 0; i < 4; i++)
	{
		cout << "(" << points[i].getx() << "," << points[i].gety() << ")";
	}
	cout << "]" << endl;
	cout << "Area=" << area << " Perimeter=" << perimeter;
}

void Square::move(int new_x_coordinate, int new_y_coordinate) //move LeftTop coords to new position
{
	leftTop.setx(new_x_coordinate);
	leftTop.sety(new_y_coordinate);
	calculatePoints(); //recalculate all other points accordingly
}

//Square remains isotropic by only using the largest input to scale the height and width of the square
void Square::scale(float x_axis_scalar, float y_axis_scalar)
{
	float scalar;
	//choose the larger scalar
	scalar = maxScalar(x_axis_scalar, y_axis_scalar);
	//change leftTop and edge according to scalar
	leftTop.setx(leftTop.getx() * scalar);
	leftTop.sety(leftTop.gety() * scalar);
	edge = edge * scalar;
	//recalculate appropriate information
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}

Square::~Square(){}  //destroy square
