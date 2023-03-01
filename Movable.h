#pragma once

class Movable
{
public:
	virtual void move(int newPointX, int newPointY) = 0;
	virtual void scale(float scaleX, float scaleY) = 0;
};
