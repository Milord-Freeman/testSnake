#include "coordinates.h"

int coordinates::X()
{
	return x;
}

void coordinates::X(const int newX)
{
	x = newX;
}
int coordinates::Y()
{
	return y;
}

void coordinates::Y(const int newY)
{
	x = newY;
}

coordinates::coordinates()
{
	this->x = NULL;
	this->y = NULL;
}

coordinates::coordinates(const int newX, const int newY)
{
	this->X(newX);
	this->Y(newY);
}

void coordinates::swap(coordinates& other)
{
	std::swap(x, other.x);
	std::swap(y, other.y);
}
