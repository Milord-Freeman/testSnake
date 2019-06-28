#pragma once
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "cell.h"
#include "field.h"

class food
{
public:
	food(std::vector<cell*>, int); // ����������� �������� ������ ��������� ����� � �������� ����� �����;
	//food(int); // ����������� � ����� ��������� ���������� �������, ����� ���������;
	//food(int, int*); // ����������� � ����� ��������� ���������� ������� � ������������;
	//~food(); // ���������� �� ���������
protected:
	std::vector<cell*>			food_cells; // ��������� � ����������� �� ������, ���������� ����;
	std::vector<int>			randomNumbersList(int, int); // ����������� ������ �������, ������ ��������� ��������������� ������������������;
	cell*						newPosition(cell*); // ������� ������� �� ���������;

private:
};

