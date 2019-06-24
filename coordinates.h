#pragma once
#include <utility>

class coordinates
{
private:

public: 
	int X(); // �������� �������� � ���������� X
	void X(int); // ������� �������� � ���������� X
	int Y(); // �������� �������� � ���������� Y
	void Y(int); // ������� �������� � ���������� Y
	coordinates(); //������ �����������;
	coordinates(int, int); //����������� ��� ��������� ������� ������
	~coordinates(); //����������, ������ �����, ��.
	void swap(coordinates & other); // ����� ��� ���������� "=";

	//����������� �������� ���������
	const bool operator==(const coordinates& other)
	{
		return (this->X == other.X && this->Y == other.Y);
	}
	//����������� �������� ������������
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

