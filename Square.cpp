#include "Square.h"
#include "getError.h"
#include <iterator>
#include <string>
#include <sstream>


Square::Square(int topLeftX, int topLeftY, int edgeLength)
{
	edge = edgeLength;
	leftTop = Point(topLeftX, topLeftY);
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}

void Square::calculateArea()
{
	area = edge * edge;
}

void Square::calculatePerimeter()
{
	perimeter = edge * 4;
}

void Square::move(int newPointX, int newPointY)
{
	leftTop = Point(newPointX, newPointY);
	calculatePoints();
	toString();
}

void Square::calculatePoints()
{
	points.clear(); //have to clear points otherwise the move function does not work
	points.push_back(&leftTop);
	points.push_back(new Point(leftTop.getX() + edge, leftTop.getY()));
	points.push_back(new Point(leftTop.getX(), leftTop.getY() + edge));
	points.push_back(new Point(leftTop.getX() + edge, leftTop.getY() + edge));
}

void Square::scale(float x, float y)
{
	try
	{	//must be same x and y otherwise it is a rectangle and not a square.
		if (x != y)
		{
			throw getError("The X and Y scale must be the same");
			std::cout << std::endl;
		}
		else
		{
			edge = edge * x;
		}

	}
	catch (getError error)
	{
		std::cout << error.getErrorMsg().c_str();
	}
}

std::string Square::getPoints()
{
	std::string temp = "Points[";

	for (auto p : points)
	{
		temp += "(" + std::to_string((p)->getX()) + "," + std::to_string((p)->getY()) + ")";
	}
	temp += "]";
	return temp;
}

std::string Square::toString()
{
	std::stringstream temp;
	temp << "Square[e=" + std::to_string(edge) + "]\n";
	temp << getPoints().c_str();
	temp << "\nArea=" + std::to_string(area) + " Perimeter=" + std::to_string(perimeter) + "\n";
	return temp.str();
}

std::ostream& operator<<(std::ostream& ostr, Square* square)
{
	std::string temp = square->toString();
	ostr << temp.c_str();
	return ostr;
}