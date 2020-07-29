#include "Square.h"



Square::Square(float x, float y)
{
	xpos = x;
	ypos = y;
	speed = 0.02;
}

void Square::update(float x, float y)
{
	xpos += x*speed;
	ypos += y*speed;
}


Square::~Square()
{
}

float Square::getx()
{
	return xpos;
}

float Square::gety()
{
	return ypos;
}

void Square::increaseSpeed()
{
	speed += 0.0001;
}
