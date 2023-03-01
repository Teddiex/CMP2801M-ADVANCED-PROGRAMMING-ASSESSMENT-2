#include "Point.h"
#include <iostream>

Point::Point(int pointX, int pointY)
{
	x = pointX;
	y = pointY;
};

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}
