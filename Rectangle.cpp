#include "Rectangle.h"
#include <iterator>
#include <string>
#include <sstream>


Rectangle::Rectangle(int topLeftX, int topLeftY, float rHeight, float rWidth)
{
	leftTop = Point(topLeftX, topLeftY);
	height = rHeight;
	width = rWidth;
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}

void Rectangle::calculateArea()
{
	area = height * width;
}


void Rectangle::calculatePoints()
{
	points.clear();
	points.push_back(&leftTop);
	
	points.push_back(new Point(leftTop.getX() + width, leftTop.getY()));
	points.push_back(new Point(leftTop.getX(), leftTop.getY() + height));
	points.push_back(new Point(leftTop.getX() + width, leftTop.getY() + height));

}

void Rectangle::calculatePerimeter()
{
	perimeter = height * 2 + width * 2;
}

std::string Rectangle::getPoints()
{
	std::string temp = "Points[";

	for (auto p : points)
	{
		temp += "(" + std::to_string((p)->getX()) + "," + std::to_string((p)->getY()) + ")";
	}
	temp = temp + "]";
	return temp;
}

std::string Rectangle::toString()
{
	std::stringstream temp;
	temp << "Rectangle[h = " + std::to_string(height) + ",w =" + std::to_string(width) + "]\n";
	temp << getPoints().c_str();
	temp << "\nArea = " + std::to_string(area) + " Perimeter = " + std::to_string(perimeter) + "\n";
	return temp.str();
}

void Rectangle::move(int newPointX, int newPointY)
{
	leftTop = Point(newPointX, newPointY);
	calculatePoints();
	toString();
}

std::ostream& operator<<(std::ostream& ostr, Rectangle* rectangle)
{
	std::string temp = rectangle->toString();
	ostr << temp.c_str();
	return ostr;
}

void Rectangle::scale(float scaleX, float scaleY)
{
	height = height * scaleY;
	width = width * scaleX;
	calculatePoints();
	calculateArea();
	calculatePerimeter();
	toString();
}

