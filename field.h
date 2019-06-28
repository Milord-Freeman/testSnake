#pragma once
#include "FreeGLUT\include\GL\glut.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "cell.h"

#define BLACK 0, 0, 0, 255
#define GREY 128, 128, 128
#define WHITE_GRAY 102, 102, 102
#define BLUE 0, 255, 255
#define PURPLE

class field
{
public:
	field(); // Конструктор по умолчанию;
	field(const  int, const  int); // Создаем с кастомными шириной и высотой, площадь клетки по умолчанию;
	field(const  int, const  int, const  int); // Ширина высота площадь задаются, количество хавки по умолчанию;
	field(const  int, const  int, const  int, const  int); // Создаем со всеми кастомными параметрами;
	~field(); // Деструктор по умолчанию;
	
	void				drawField(); // Основная функция которая непосредственно отрисовывает поле;
						// Можно получать параметры поля;
	int					getHeight(), 
						getWidth(), 
						getAreaSize(), 
						getAmountFood(); 
						// Можно ручками задавать;
	void				setHeight(int),	
						setWidth(int), 
						setAreaSize(int), 
						setAmountFood(int); 
						// Найти ячейку по координатам;
	cell*				getCellByXY(int, int); 
						// Функция которая возращает список указателей свободных ячеек, нужна для генерации хавки на пустом месте;
	std::vector<cell*>  get_freeCells();

protected:
	int					n_height,		// Высота;
						n_width,		// Ширина;
						n_areaSize,		// Размер стороны квадратной ячейки;
						n_amountFood;	// Число генерируемой еды на поле;
	
	std::vector<cell>	field_cells;	// Собственно контейнер с ячейками;

	//std::vector<cell*>  food_cells;		// Контейнер с указателями на ячейки, являющиеся едой;
						// Специальная версия рандома, выдает случайную неповторяющуюся последовательность;
	//std::vector<int>	randomNumbersList(int, int); 

private:

};

