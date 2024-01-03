#pragma once
class Movable
{
public:
	//virtual methods overloaded and defined by child classes
	virtual void move(int,int) = 0;
	virtual void scale(float,float) = 0;
	~Movable();
};

