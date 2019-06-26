#pragma once
#include "FreeGLUT\include\GL\glut.h"
#include <vector>
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
	field(const unsigned int, const unsigned int); // Создаем с кастомными шириной и высотой, площадь клетки по умолчанию;
	field(const unsigned int, const unsigned int, const unsigned int); // Создаем со всеми кастомными параметрами;
	~field(); // Деструктор по умолчанию;
	void drawField(); // Основная функция которая непосредственно отрисовывает поле;
	unsigned int getHeight(), getWidth(), getAreaSize(); // Можно получать параметры поля;
	void setHeight(unsigned int), setWidth(unsigned int), setAreaSize(unsigned int); // Можно ручками задавать;
	cell* getCellByXY(unsigned int, unsigned int); // Найти ячейку по координатам;
	std::vector<cell*> get_freeSells(); // Функция которая возращает список указателей свободных ячеек, нужна для генерации хавки на пустом месте;
protected:
	unsigned int un_height, un_width, un_areaSize; 
	// Высота и ширина поля, а так же размер ячейки (она квадратная, так что достаточно указать только сторону)
	std::vector<cell> field_cells; // Собственно контейнер с ячейками;
	//std::vector<cell*> food_cells; // Контейнер с указателями на ячейки, являющиеся едой;

private:

};

