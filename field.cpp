#include "field.h"

field::field()
{
	un_height = 30;
	un_width = 40;
	un_areaSize = 10;
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
	un_height = newHeight;
	un_width = newWidht;
	un_areaSize = 10;
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
	un_height = newHeight;
	un_width = newWidht;
	un_areaSize = newAreaSize;
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
	glClearColor(0, 0, 0, 255); // Красим все в чорное;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(128, 128, 128); // Выбираем серый цвет для линии;
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
			glColor3ub(102, 102, 102);
			glRectd(thisCell.getX(), thisCell.getY(), thisCell.getX() + 1, thisCell.getY() + 1);
		}
	}
}
