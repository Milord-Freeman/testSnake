#pragma once
#include <cstdlib>

class cell
{
public:
	int getX(), getY(); // ������ ��������� ������;
	void setX(const int), setY(const int), setXY(const int, const int); // ������ ���������� ������
	bool isFood(), isWall(), isSnake(), isFree(); // ������ ����������� ������ ��� �������� ������;
	void setFood(), setWall(), setSnake(), setFree(); // ������ ����������� ������������� ������;
	cell(); // ����������� �� ���������;
	cell(const int, const int); // ����������� ������� ��������� ����� ��������� �������� ����������;
	//~cell(); // ���������� �� ���������;
protected:
	int x, y; // ���������� �����;
	bool b_food, b_wall, b_snake, b_free; // ����� ��� �������� ������;
private:

};

