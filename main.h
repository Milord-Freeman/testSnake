#include "FreeGLUT\include\GL\glut.h"
#include <ctime>
#include <stdlib.h>
#include <string>

#include "field.h"
#include "cell.h"
#include "food.h"
#include "snake.h"

// Тут дефолт настройки;
#define COLUMNS 30 
#define ROWS 30
#define SQUARE_AREA 10
#define FOOD 3
#define LENGTH 4

#define UP 101
#define DOWN 103
#define LEFT 100
#define RIGHT 102

// Легаси структура для хранения любых пар координат X Y, нужна была для прототипа из спичек и желудей, сейчас все в объектах лежит.
struct Coordinates
{
	int x, y;
};
const bool operator==(const Coordinates& left, Coordinates& right) {
	return (left.x == right.x && left.y == right.y);
}

// Легаси переменные для хранения направления движения, флаг смены направления и список позиций змейки, сейчас все в snake.h
short		Dir = RIGHT;
bool		DirChanged = false;
Coordinates Position[COLUMNS * ROWS] = { {2,2}, {2,3}, {2,4}, {2,5} };
int			SnakeLength = 4;

// Легаси переменные для обработки генерации еды, сейчас все в food.h лежит.
//bool food = true;
Coordinates foodXY;
int			FPS = 100;
bool		GameOver = false;

// Спасибо богам рефакторинга, вот тут вся магия и происходит.
field		myField(COLUMNS, ROWS, SQUARE_AREA, FOOD);
snake		mySnake(myField.get_freeCells(), LENGTH); // Не дописан нормально;
food		myFood(myField.get_freeCells(), myField.getAmountFood());

// Функции для ввода и вывода данных;
void display_callback();
void reshape_callback(int w, int h);
void timer_callback(int);
void keyboard_callback(int key, int x, int y);
// Единственная не переписанная функция из легаси, отрисовывает и двигает змею;
void DrawSnake();
