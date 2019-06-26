#pragma once
#include <cstdlib>

class cell
{
public:
	int getX(), getY(); // „тение координат €чейки;
	void setX(const int), setY(const int), setXY(const int, const int); // «апись координаты €чейки
	bool isFood(), isWall(), isSnake(), isFree(); // ћетоды позвол€ющие пон€ть чем €вл€етс€ €чейка;
	void setFood(), setWall(), setSnake(), setFree(); // ћетоды позвол€ющие переназначить €чейку;
	cell(); //  онструктор по умолчанию;
	cell(const int, const int); //  онструктор который позвол€ет сразу запихнуть значени€ координаты;
	//~cell(); // ƒеструктор по умолчанию;
protected:
	int x, y; //  оординаты €чеек;
	bool b_food, b_wall, b_snake, b_free; // ‘лаги чем €вл€етс€ €чейка;
private:

};

