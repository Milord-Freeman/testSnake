#include "snake.h"

snake::snake(std::vector<cell*> newHead, int newLength)
{

}

snake::~snake()
{
}

int snake::getLength()
{
	return n_length;
}

cell* snake::getHead()
{
	return snake_cells[0];
}

short snake::getDirection()
{
	return sn_direction;
}

void snake::setDirection(short newDirection)
{
	sn_direction = newDirection;
}

bool snake::isDirChanged()
{
	return DirChanged;
}

void snake::makeStep()
{
}
