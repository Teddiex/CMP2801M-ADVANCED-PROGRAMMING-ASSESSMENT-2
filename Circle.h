#pragma once
#include "Movable.h"
#include "Shape.h"


class Circle : public Shape, public Movable
{
private:
	float radius;
	float pi;
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
public:
	Circle(int topLeftX, int topLeftRightx, int circleRadius);
	std::string getPoints();
	std::string toString();
	void move(int newPointX, int newPointY);
	void scale(float scaleX, float scaleY);
	friend std::ostream& operator<<(std::ostream& os, Circle* circle);
};
