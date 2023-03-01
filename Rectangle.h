#pragma once
#include "getError.h"
#include "Movable.h"
#include "Shape.h"



class Rectangle : public Shape, public Movable
{
	int width;
	int height;
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
public:

	Rectangle(int topLeftX, int topLeftY, float rHeight, float rWidth);
	std::string getPoints();
	std::string toString();

	void move(int newPointX, int newPointY);
	void scale(float scaleX, float scaleY);

	friend std::ostream& operator<<(std::ostream& os, Rectangle* rectangle);

};
