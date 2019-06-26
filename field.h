#pragma once
#include "FreeGLUT\include\GL\glut.h"
#include <vector>
#include "cell.h"

class field
{
public:
	field(); // Конструктор по умолчанию;
	field(const unsigned int, const unsigned int); // Создаем с кастомными шириной и высотой, площадь клетки по умолчанию;
	field(const unsigned int, const unsigned int, const unsigned int); // Создаем со всеми кастомными параметрами;
	~field(); // Деструктор по умолчанию;
	void drawField(); // Основная функция которая непосредственно отрисовывает поле;
	std::vector<cell*> get_freeSells(); // Функция которая возращает список указателей свободных ячеек, нужна для генерации хавки на пустом месте;
protected:
	unsigned int un_height, un_width, un_areaSize; 
	// Высота и ширина поля, а так же размер ячейки (она квадратная, так что достаточно указать только сторону)
	std::vector<cell> field_cells; // Собственно контейнер с ячейками;
	std::vector<cell*> food_cells; // Контейнер с указателями на ячейки, являющиеся едой;

private:

};

