#include "FreeGLUT\include\GL\glut.h"
#include <ctime>
#include <stdlib.h>
#include <string>
//#include <vector>
//#include <iostream>
//#include <locale>


#define COLUMNS 60 
#define ROWS 60

#define UP 101
#define DOWN 103
#define LEFT 100
#define RIGHT 102

struct Coordinates
{
	int x, y;
};
const bool operator==(const Coordinates& left, Coordinates& right) {
	if (left.x == right.x && left.y == right.y) return true; else return false;
}

short Dir = RIGHT;
bool DirChanged = false;
Coordinates Position[COLUMNS * ROWS] = { {20,25}, {20,24}, {20,23}, {20,22} };
int SnakeLength = 4;

bool food = true;
Coordinates foodXY;
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
