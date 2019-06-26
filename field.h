#pragma once
#include <vector>
#include "cell.h"

class field
{
public:
	field(); // Конструктор по умолчанию;
	field(const unsigned int, const unsigned int); // Создаем с кастомными шириной и высотой, площадь клетки по умолчанию;
	field(const unsigned int, const unsigned int, const unsigned int); // Создаем со всеми кастомными параметрами;
	~field(); // Деструктор по умолчанию;
protected:
	unsigned int un_height, un_width, un_areaSize; 
	// Высота и ширина поля, а так же размер ячейки (она квадратная, так что достаточно указать только сторону)
	std::vector<cell> field_cells; //Собственно контейнер с ячейками;
private:

};

