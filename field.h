#pragma once
#include "FreeGLUT\include\GL\glut.h"
#include <vector>
#include "cell.h"

class field
{
public:
	field(); // ����������� �� ���������;
	field(const unsigned int, const unsigned int); // ������� � ���������� ������� � �������, ������� ������ �� ���������;
	field(const unsigned int, const unsigned int, const unsigned int); // ������� �� ����� ���������� �����������;
	~field(); // ���������� �� ���������;
	void drawField(); // �������� ������� ������� ��������������� ������������ ����;
	std::vector<cell*> get_freeSells(); // ������� ������� ��������� ������ ���������� ��������� �����, ����� ��� ��������� ����� �� ������ �����;
protected:
	unsigned int un_height, un_width, un_areaSize; 
	// ������ � ������ ����, � ��� �� ������ ������ (��� ����������, ��� ��� ���������� ������� ������ �������)
	std::vector<cell> field_cells; // ���������� ��������� � ��������;
	std::vector<cell*> food_cells; // ��������� � ����������� �� ������, ���������� ����;

private:

};

