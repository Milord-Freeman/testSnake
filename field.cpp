#include "field.h"

field::field()
{
	field::setHeight(30);
	field::setWidth(30);
	field::setAreaSize(10);
	field::setAmountFood(1);

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
	field::setHeight(newHeight);
	field::setWidth(newWidht);
	field::setAreaSize(10);
	field::setAmountFood(1);

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
	field::setHeight(newHeight);
	field::setWidth(newWidht);
	field::setAreaSize(newAreaSize);
	field::setAmountFood(1);

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
	field::setHeight(newHeight);
	field::setWidth(newWidht);
	field::setAreaSize(newAreaSize);
	field::setAmountFood(newAmountFood);

	// Заполняем поле;
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
			else
			{
				nextCell.setFree();
			}
			// Тестовая хавка на поле;
			//if (i == 5 && j == 10)
			//{
			//	nextCell.setFood();
			//}
			field_cells.push_back(nextCell);
		}
	}

	//srand(time(NULL));
	//bool isFinded = false;
	//while (!isFinded)
	//{
	//	int randomNumber = rand() % (n_height*n_width);
	//	if (field_cells[randomNumber].isFree())
	//	{
	//		isFinded = true;
	//		field_cells[randomNumber].setFood();
	//	}
	//}


	//Формируем список еды;
	std::vector<cell*> freeCells = field::get_freeCells();
	if (!freeCells.empty() && field::getAmountFood() < freeCells.size())
	{
		srand(time(NULL));
		// Формируем список случайных неповторяющихся ячеек и помещаем их в список с указателями на еду;
		for (auto nextNumber : randomNumbersList(freeCells.size(), field::getAmountFood())) {
			food_cells.push_back(freeCells[nextNumber]);
		}
		// И пробегаемся по всем ячейкам делая их непосредственно едой.
		for (auto thisCell : food_cells)
		{
			thisCell->setFood();
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
	for (auto thisCell : field_cells)
	{
		// Формируем список указателей на свободные ячейки;
		if (thisCell.isFree())
		{
			buffer.push_back(&thisCell);
		}
	}
	return buffer;
}

std::vector<int> field::randomNumbersList(int range, int amount)
{
	std::vector<int> bufferList;
	if (amount < range)
	{
		bool isAllGenerated = false;
		srand(time(NULL));
		while (!isAllGenerated)
		{
			bool isGeneratedYet = false;
			int bufferValue = rand() % range;
			for (auto thisValue : bufferList)
			{
				if (thisValue == bufferValue)
				{
					isGeneratedYet = true;
				}
			}
			if (!isGeneratedYet)
			{
				bufferList.push_back(bufferValue);
				if (bufferList.size() == amount)
				{
					isAllGenerated = true;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < range; i++)
		{
			bufferList.push_back(i);
		}
	}
	return bufferList;
}

