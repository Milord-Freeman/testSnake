#pragma once
#include <utility>

class coordinates
{
private:

public: 
	int X(); // Получаем значение в переменной X
	void X(int); // Заносим значение в переменную X
	int Y(); // Получаем значение в переменной Y
	void Y(int); // Заносим значения в переменную Y
	coordinates(); //Дефолт конструктор;
	coordinates(int, int); //Конструктор для обработки входных данных
	~coordinates(); //Деструктор, пускай будет, чо.
	void swap(coordinates & other); // Нужна для перегрузки "=";

	//Перегружаем оператор сравнения
	const bool operator==(const coordinates& other)
	{
		return (this->X == other.X && this->Y == other.Y);
	}
	//Перегружаем оператор присваивания
	coordinates & operator = (coordinates const& newCoordinates)
	{
		if (this != &newCoordinates)
		{
			coordinates(newCoordinates).swap(*this);
		}
		return *this;
	}

protected:
	int x, y;
};

