#pragma once
#include "Shape.h"
#include "Movable.h"

class Square : public Shape, public Movable
{
private:

	int edge;
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();

public:
	
	Square(int topLeftX, int topLeftY, int edgeLength);
	
	std::string toString();
	std::string getPoints();
	
	void move(int newX, int newY);
	friend std::ostream& operator<<(std::ostream& os, Square* s);
	void scale(float scaleX, float scaleY);
	

};
