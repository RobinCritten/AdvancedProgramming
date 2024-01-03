#include "Shape.h"
#include <iostream>

using namespace std;

bool Shape::checkCircular()
{
	return isCircular;
}

ostream& operator << (ostream& output, Shape& s) //is called whenever << is used in congunction with a shape
{
	s.toString(); //calls method overidden by child class
	output << endl;
	return output;
}

Shape::~Shape(){} //destructor