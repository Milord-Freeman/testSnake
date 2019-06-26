#pragma once
#include <vector>
#include "cell.h"

class field
{
public:
	field(); // ����������� �� ���������;
	field(const unsigned int, const unsigned int); // ������� � ���������� ������� � �������, ������� ������ �� ���������;
	field(const unsigned int, const unsigned int, const unsigned int); // ������� �� ����� ���������� �����������;
	~field(); // ���������� �� ���������;
protected:
	unsigned int un_height, un_width, un_areaSize; 
	// ������ � ������ ����, � ��� �� ������ ������ (��� ����������, ��� ��� ���������� ������� ������ �������)
	std::vector<cell> field_cells; //���������� ��������� � ��������;
private:

};

