#include "field.h"

field::field()
{
	setHeight(30);
	setWidth(30);
	setAreaSize(10);
	setAmountFood(1);

	for (int i = 0; i < n_height; i++)
	{
		for (int j = 0; j < n_width; j++)
		{
			cell nextCell(i, j);
			if (i == 0 || i == n_height - 1 || j == 0 || j == n_width - 1)
			{
				// Задаем граничные ячейки;
				nextCell.setWall();
			}
			field_cells.push_back(nextCell);
		}
	}
}

field::field(const  int newHeight, const  int newWidht)
{
	setHeight(newHeight);
	setWidth(newWidht);
	setAreaSize(10);
	setAmountFood(1);

	for (int i = 0; i < n_height; i++)
	{
		for (int j = 0; j < n_width; j++)
		{
			cell nextCell(i, j);
			if (i == 0 || i == n_height - 1 || j == 0 || j == n_width - 1)
			{
				// Задаем граничные ячейки;
				nextCell.setWall();
			}
			field_cells.push_back(nextCell);
		}
	}
}

field::field(const  int newHeight, const  int newWidht, const  int newAreaSize)
{
	setHeight(newHeight);
	setWidth(newWidht);
	setAreaSize(newAreaSize);
	setAmountFood(1);

	for (int i = 0; i < n_height; i++)
	{
		for (int j = 0; j < n_width; j++)
		{
			cell nextCell(i, j);
			if ((i == 0) || (i == (n_height - 1)) || (j == 0) || (j == (n_width - 1)))
			{
				// Задаем граничные ячейки;
				nextCell.setWall();
			}
			field_cells.push_back(nextCell);
		}
	}
}

field::field(const int newHeight, const int newWidht, const int newAreaSize, const int newAmountFood)
{
	setHeight(newHeight);
	setWidth(newWidht);
	setAreaSize(newAreaSize);
	setAmountFood(newAmountFood);

	// Заполняем поле;
	for (int i = 0; i < getHeight(); i++)
	{
		for (int j = 0; j < getWidth(); j++)
		{
			cell nextCell(i, j);
			if ((i == 0) || (i == (n_height - 1)) || (j == 0) || (j == (n_width - 1)))
			{
				// Задаем граничные ячейки;
				nextCell.setWall();
			}
			else
			{
				nextCell.setFree();
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
	glLineWidth(1); // Задаем длину линии;
	glBegin(GL_LINES); // Включаем режим формирования линий;
	for (int x = 0; x < n_height; x++)
	{
		for (int y = 0; y < n_width; y++)
		{
			glVertex2f(x, y);
			glVertex2f(x, y + 1);
			glVertex2f(x, y);
			glVertex2f(x + 1, y);
		}
	}
	glEnd(); // Выключаем режим формирования линий;

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

int field::getAreaSize()
{
	return n_areaSize;
}

int field::getHeight()
{
	return n_height;
}

int field::getWidth()
{
	return n_width;
}

int field::getAmountFood()
{
	return n_amountFood;
}

void field::setHeight(int newHeight)
{
	n_height = newHeight;
}

void field::setWidth(int newWidth)
{
	n_width = newWidth;
}

void field::setAreaSize(int newAreaSize)
{
	n_areaSize = newAreaSize;
}

void field::setAmountFood(int newAmountFood)
{
	n_amountFood = newAmountFood;
}

cell* field::getCellByXY(int findX, int findY)
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

std::vector<cell*> field::get_freeCells()
{
	std::vector<cell*> buffer;

	for (auto & thisCell : field_cells)
	{
		// Формируем список указателей на свободные ячейки;
		if (thisCell.isFree())
		{
			buffer.push_back(&thisCell);
		}
	}
	return buffer;
}


