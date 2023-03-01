#include "Circle.h"
#include "getError.h"

#define _USE_MATH_DEFINES

#include <iterator>
#include <exception>
#include <math.h>
#include <sstream>
#include <typeinfo>

Circle::Circle(int topLeftX, int topLeftY, int circleRadius)
{
	pi = M_PI;
	leftTop = Point(topLeftX, topLeftY);
	radius = circleRadius;
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}

void Circle::calculatePerimeter()
{
	perimeter = pi * 2 * radius;
}

void Circle::calculateArea()
{
	area = pi * radius * radius;
}

void Circle::move(int newPointX, int newPointY)
{
	leftTop = Point(newPointX, newPointY);
	calculatePoints();
	toString();
}


void Circle::calculatePoints()
{
	points.clear(); //have to clear points otherwise the move function does not work
	points.push_back(&leftTop);
	points.push_back(new Point(leftTop.getX() + radius * 2, leftTop.getY() + radius * 2)); // right bottom
}

std::string Circle::toString()
{
	std::ostringstream temp;
	temp << "Circle[r=" + std::to_string(radius) + "]\n";
	temp << "" + getPoints();
	temp << "\nArea=" + std::to_string(area) + " Perimeter=" + std::to_string(perimeter) + "\n";
	return temp.str();
}

std::string Circle::getPoints()
{
	std::ostringstream temp;
	temp << "Points[";

	for (auto p : points)
	{
		temp << "(" << (p)->getX() << "," << (p)->getY() << ")";
	}
	temp << "]";
	return temp.str();
}

void Circle::scale(float x, float y)
{
	try
	{	//scale must be the same for a circle, otherwise it is not a circle
		if (x != y)
		{
			throw getError("The X and Y scale must be the same");
		}
		radius = radius * x;
		calculatePoints();
		calculateArea();
		calculatePerimeter();
		toString();
	}
	
	catch (getError error)
	{
		std::cout << error.getErrorMsg().c_str();
	}
}

std::ostream& operator<<(std::ostream& ostr, Circle* circle)
{
	std::string temp = circle->toString();
	ostr << temp.c_str();
	return ostr;
}