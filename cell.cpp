#include "cell.h"

cell::cell()
{
	// Память выделили, но координаты не прописали, ячейка судя по b_free - недоступна, ибо нельзя обращаться к NULL.
	x = NULL;
	y = NULL;
	b_food = false;
	b_wall = false;
	b_snake = false;
	b_free = false;
}

cell::cell(const int newX, const int newY)
{
	// Память выделили, значения прописали, значит можно обращаться;
	x = newX; 
	y = newY;
	b_food = false;
	b_wall = false;
	b_snake = false;
	b_free = true;
}

int cell::getX()
{
	return 0;
}

int cell::getY()
{
	return 0;
}

void cell::setX(const int newX)
{
	x = newX;
}

void cell::setY(const int newY)
{
	y = newY;
}

void cell::setXY(const int newX, const int newY)
{
	x = newX;
	y = newY;
}

bool cell::isWall()
{
	return b_wall;
}

bool cell::isFree()
{
	return b_free;
}

bool cell::isSnake()
{
	return b_snake;
}

bool cell::isFood()
{
	return b_food;
}

void cell::setSnake()
{
	b_snake = true; // Ячейка теперь часть змейки;
	b_free = false; // Она занята;
	b_food = false; //Если ячейка стала частью змейки, то стеной и едой она уже быть не может;
	b_wall = false;
}

void cell::setFood()
{
	b_food = true; // Ячейка теперь хавка;
	b_free = false; // Она занята;
	b_snake = false; // Если ячейка стала хавкой, то стеной и частью змейки она уже быть не может;
	b_wall = false;
}

void cell::setWall()
{
	b_wall = true; // Ячейка теперь стена;
	b_free = false; // Она занята;
	b_food = false; // Хавка на стенах не растет;
	b_snake = false; // Змеи сквозь стены не ползают;
}

void cell::setFree()
{
	b_free = true; // Ячейка теперь свободна!
	b_wall = false;
	b_food = false;
	b_snake = false;
}

