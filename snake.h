#pragma once
#include <vector>
#include "cell.h"

class snake
{
public:
	snake(std::vector<cell*>, int); // Конструктор по умолчанию;
	~snake(); // Деструктор по умолчанию;

	int							getLength();			// Получить длину;
	cell*						getHead();				// Возвращает указатель на координаты головы;
	short						getDirection();			// Возвращает направление движения;
	void						setDirection(short);	// Устанавливает направление движения;
	bool						isDirChanged();			// Возвращает значение флага
	void						makeStep();				// Двигает змейку в направлении движения;

protected:
	int							n_length;
	short						sn_direction;			// Направление движения;
	bool						b_dirChanged;			// Сбрасывается каждый шаг, чтобы направление не менялось чаще одного шага;
	std::vector<cell*>			snake_cells;			// Контейнер с указателями на ячейки тела змейки;
	
private:
	   
};

