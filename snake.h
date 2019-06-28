#pragma once
#include <vector>
#include "cell.h"

class snake
{
public:
	snake(); // ����������� �� ���������;
	~snake(); // ���������� �� ���������;

	int							getLength();			// �������� �����;
	cell*						getHead();				// ���������� ��������� �� ���������� ������;
	short						getDirection();			// ���������� ����������� ��������;
	void						setDirection(short);	// ������������� ����������� ��������;
	bool						isDirChanged();			// ���������� �������� �����
	void						makeStep();				// ������� ������ � ����������� ��������;

protected:
	int							n_length;
	short						sn_direction;			// ����������� ��������;
	bool						b_dirChanged;			// ������������ ������ ���, ����� ����������� �� �������� ���� ������ ����;
	std::vector<cell*>			snake_cells;			// ��������� � ����������� �� ������ ���� ������;
	
private:
	   
};

