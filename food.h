#pragma once
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "cell.h"
#include "field.h"

class food
{
public:
	food(std::vector<cell*>, int); // Конструктор получает список свободных ячеек и желаемое число хавки;
	//food(int); // Конструктор с явным указанием количества фруктов, место случайное;
	//food(int, int*); // Конструктор с явным указанием количества фруктов и координатами;
	//~food(); // Деструктор по умолчанию
protected:
	std::vector<cell*>			food_cells; // Контейнер с указателями на ячейки, являющиеся едой;
	std::vector<int>			randomNumbersList(int, int); // Специальная версия рандома, выдает случайную неповторяющуюся последовательность;
	cell*						newPosition(cell*); // Сменяем позицию на свободную;

private:
};

