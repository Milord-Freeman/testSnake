#include "field.h"

field::field()
{
	field::setHeight(30);
	field::setWidth(30);
	field::setAreaSize(10);

	for (unsigned int i = 0; i < un_height; i++)
	{
		for (unsigned int j = 0; j < un_width; j++)
		{
			cell nextCell(i, j);
			if (i == 0 || i == un_height - 1 || j == 0 || j == un_width - 1)
			{
				// Задаем граничные ячейки;
				nextCell.setWall();
			}
			field_cells.push_back(nextCell);
		}
	}
}

field::field(const unsigned int newHeight, const unsigned int newWidht)
{
	field::setHeight(newHeight);
	field::setWidth(newWidht);
	field::setAreaSize(10);

	for (unsigned int i = 0; i < un_height; i++)
	{
		for (unsigned int j = 0; j < un_width; j++)
		{
			cell nextCell(i, j);
			if (i == 0 || i == un_height - 1 || j == 0 || j == un_width - 1)
			{
				// Задаем граничные ячейки;
				nextCell.setWall();
			}
			field_cells.push_back(nextCell);
		}
	}
}

field::field(const unsigned int newHeight, const unsigned int newWidht, const unsigned int newAreaSize)
{
	field::setHeight(newHeight);
	field::setWidth(newWidht);
	field::setAreaSize(newAreaSize);

	for (unsigned int i = 0; i < un_height; i++)
	{
		for (unsigned int j = 0; j < un_width; j++)
		{
			cell nextCell(i, j);
			if ((i == 0) || (i == (un_height - 1)) || (j == 0) || (j == (un_width - 1)))
			{
				// Задаем граничные ячейки;
				nextCell.setWall();
			}
			field_cells.push_back(nextCell);
		}
	}
}

field::~field()
{
	field_cells.clear();
}

void field::drawField()
{
	glClearColor(BLACK); // Красим все в чорное;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(GREY); // Выбираем серый цвет для линии;
	glLineWidth(1); // Задаем длину линии
	glBegin(GL_LINES); // Включаем режим формирования линий
	for (int x = 0; x < un_height; x++)
	{
		for (int y = 0; y < un_width; y++)
		{
			glVertex2f(x, y);
			glVertex2f(x, y + 1);
			glVertex2f(x, y);
			glVertex2f(x + 1, y);
		}
	}
	glEnd(); // Выключаем режим формирования линий

	for (auto thisCell : field_cells)
	{
		// Отрисовываем серым границы;
		if (thisCell.isWall())
		{
			glColor3ub(WHITE_GRAY);
			glRectd(thisCell.getX(), thisCell.getY(), thisCell.getX() + 1, thisCell.getY() + 1);
		}
		// А синим отрисовываем хавку;
		if (thisCell.isFood())
		{
			glColor3ub(BLUE);
			glRectd(thisCell.getX(), thisCell.getY(), thisCell.getX() + 1, thisCell.getY() + 1);
		}
	}
}

unsigned int field::getAreaSize()
{
	return un_areaSize;
}

unsigned int field::getHeight()
{
	return un_height;
}

unsigned int field::getWidth()
{
	return un_width;
}

void field::setHeight(unsigned int newHeight)
{
	un_height = newHeight;
}

void field::setWidth(unsigned int newWidth)
{
	un_width = newWidth;
}

void field::setAreaSize(unsigned int newAreaSize)
{
	un_areaSize = newAreaSize;
}

cell* field::getCellByXY(unsigned int findX, unsigned int findY)
{
	for (auto thisCell : field_cells)
	{
		if (thisCell.getX() == findX && thisCell.getY() == findY) {
			return &thisCell;
		}
	}
	// Если в списке нет ячеек с такими координатами, то просто пустой указатель возвращаем;
	return nullptr;
}

std::vector<cell*> field::get_freeSells()
{
	std::vector<cell*> buffer;
	for (auto thisCell : field_cells)
	{
		// Формируем список указателей на свободные ячейки;
		if (thisCell.isFree())
		{
			buffer.push_back(&thisCell);
		}
	}
	return std::vector<cell*>();
}
