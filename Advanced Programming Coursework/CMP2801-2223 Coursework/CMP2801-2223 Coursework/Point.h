#pragma once
class Point
{
private: //private class member variables
	float x;
	float y;
public: //private class variables only accessable through public methods
	float getx();
	float gety();
	void setx(float);
	void sety(float);
	Point();
	Point(float, float);
	~Point();
};

