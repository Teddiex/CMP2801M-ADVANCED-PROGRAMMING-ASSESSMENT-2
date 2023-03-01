#pragma once

#include <strstream>
#include <vector>
#include <string>
#include <iostream>
#include "Point.h"


class Shape
{
protected:
	
	float area;
	bool isCircular;
	Point leftTop;
	float perimeter;
	std::vector<Point*> points;

	virtual void calculatePoints() = 0;
	
	virtual void calculateArea() = 0;
	
	virtual void calculatePerimeter() = 0;

	

	virtual std::string getPoints() = 0;
public:

	virtual std::string toString() = 0;

};