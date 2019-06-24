#include "FreeGLUT\include\GL\glut.h"
#include <ctime>
#include <stdlib.h>
#include <string>
#include "coordinates.h"
//#include <vector>
//#include <iostream>
//#include <locale>


#define COLUMNS 50 
#define ROWS 30
#define SQUARE_AREA 15

#define UP 101
#define DOWN 103
#define LEFT 100
#define RIGHT 102

//struct Coordinates
//{
//	int x, y;
//};
//const bool operator==(const Coordinates& left, Coordinates& right) {
//	return (left.x == right.x && left.y == right.y);
//}

short Dir = RIGHT;
bool DirChanged = false;
coordinates Position[COLUMNS * ROWS] = { {1,1}, {1,2}, {1,3}, {1,4} };
int SnakeLength = 4;

bool food = true;
coordinates foodXY;
int FPS = 100;
bool GameOver = false;

void display_callback();
void reshape_callback(int w, int h);
void timer_callback(int);
void keyboard_callback(int key, int x, int y);
void DrawGrid();
void DrawFood();
void DrawSnake();
void random(int& x, int& y);
