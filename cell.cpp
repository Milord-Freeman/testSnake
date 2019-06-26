#include "cell.h"

cell::cell()
{
	// ������ ��������, �� ���������� �� ���������, ������ ���� �� b_free - ����������, ��� ������ ���������� � NULL.
	x = NULL;
	y = NULL;
	b_food = false;
	b_wall = false;
	b_snake = false;
	b_free = false;
}

cell::cell(const int newX, const int newY)
{
	// ������ ��������, �������� ���������, ������ ����� ����������;
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
	b_snake = true; // ������ ������ ����� ������;
	b_free = false; // ��� ������;
	b_food = false; //���� ������ ����� ������ ������, �� ������ � ���� ��� ��� ���� �� �����;
	b_wall = false;
}

void cell::setFood()
{
	b_food = true; // ������ ������ �����;
	b_free = false; // ��� ������;
	b_snake = false; // ���� ������ ����� ������, �� ������ � ������ ������ ��� ��� ���� �� �����;
	b_wall = false;
}

void cell::setWall()
{
	b_wall = true; // ������ ������ �����;
	b_free = false; // ��� ������;
	b_food = false; // ����� �� ������ �� ������;
	b_snake = false; // ���� ������ ����� �� �������;
}

void cell::setFree()
{
	b_free = true; // ������ ������ ��������!
	b_wall = false;
	b_food = false;
	b_snake = false;
}

