#pragma once
#include "FreeGLUT\include\GL\glut.h"
#include <vector>
#include "cell.h"

class field
{
public:
	field(); //  онструктор по умолчанию;
	field(const unsigned int, const unsigned int); // —оздаем с кастомными шириной и высотой, площадь клетки по умолчанию;
	field(const unsigned int, const unsigned int, const unsigned int); // —оздаем со всеми кастомными параметрами;
	~field(); // ƒеструктор по умолчанию;
	void drawField(); // ќсновна€ функци€ котора€ непосредственно отрисовывает поле;
	std::vector<cell*> get_freeSells(); // ‘ункци€ котора€ возращает список указателей свободных €чеек, нужна дл€ генерации хавки на пустом месте;
protected:
	unsigned int un_height, un_width, un_areaSize; 
	// ¬ысота и ширина пол€, а так же размер €чейки (она квадратна€, так что достаточно указать только сторону)
	std::vector<cell> field_cells; // —обственно контейнер с €чейками;
	std::vector<cell*> food_cells; //  онтейнер с указател€ми на €чейки, €вл€ющиес€ едой;

private:

};

