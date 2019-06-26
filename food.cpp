#include "food.h"

food::food(std::vector<cell*> freeCells, int amountCells)
{
	if (!freeCells.empty() && amountCells < freeCells.size())
	{
		srand(time(NULL));
		// ‘ормируем список случайных неповтор€ющихс€ €чеек и помещаем их в список с указател€ми на еду;
		for (auto buffer : food::randomNumbersList(freeCells.size(), amountCells)) {
			food_cells.push_back(freeCells[buffer]);
		}
		// » пробегаемс€ по всем €чейкам дела€ их непосредственно едой.
		for (auto thisCell : food_cells)
		{
			thisCell->setFood();
		}
	}
}

std::vector<int> food::randomNumbersList(int range, int amount)
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
