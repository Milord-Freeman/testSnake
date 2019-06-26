#pragma once
#include <cstdlib>

class cell
{
public:
	int getX(), getY(); // Чтение координат ячейки;
	void setX(const int), setY(const int), setXY(const int, const int); // Запись координаты ячейки
	bool isFood(), isWall(), isSnake(), isFree(); // Методы позволяющие понять чем является ячейка;
	void setFood(), setWall(), setSnake(), setFree(); // Методы позволяющие переназначить ячейку;
	cell(); // Конструктор по умолчанию;
	cell(const int, const int); // Конструктор который позволяет сразу запихнуть значения координаты;
	//~cell(); // Деструктор по умолчанию;
protected:
	int x, y; // Координаты ячеек;
	bool b_food, b_wall, b_snake, b_free; // Флаги чем является ячейка;
private:

};

