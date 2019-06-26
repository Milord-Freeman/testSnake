#include "field.h"

field::field()
{
	un_height = 30;
	un_width = 40;
	un_areaSize = 10;
	for (unsigned int i = 0; i < un_height; i++)
	{
		for (unsigned int j = 0; j < un_width; j++)
		{
			cell nextCell(i, j);
			field_cells.push_back(nextCell);
		}
	}
}

field::field(const unsigned int newHeight, const unsigned int newWidht)
{
	un_height = newHeight;
	un_width = newWidht;
	un_areaSize = 10;
	for (unsigned int i = 0; i < un_height; i++)
	{
		for (unsigned int j = 0; j < un_width; j++)
		{
			cell nextCell(i, j);
			field_cells.push_back(nextCell);
		}
	}
}

field::field(const unsigned int newHeight, const unsigned int newWidht, const unsigned int newAreaSize)
{
	un_height = newHeight;
	un_width = newWidht;
	un_areaSize = newAreaSize;
	for (unsigned int i = 0; i < un_height; i++)
	{
		for (unsigned int j = 0; j < un_width; j++)
		{
			cell nextCell(i, j);
			field_cells.push_back(nextCell);
		}
	}
}

field::~field()
{
	field_cells.clear();
}
