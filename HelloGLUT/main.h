#include <GL/glut.h>
#include <ctime>
//#include <stdlib.h>
//#include <vector>
//#include <iostream>
//#include <locale>


#define COLUMNS 50 
#define ROWS 50
#define FPS 1000

#define UP 87
#define DOWN 68
#define LEFT 76
#define RIGHT 82

short Dir = RIGHT;
int PositionX[COLUMNS] = { 20, 20, 20, 20 }, PositionY[ROWS] = { 25, 24, 23, 22 };
int SnakeLength = 4;

bool food = true;
int foodX, foodY;

void display_callback();
void reshape_callback(int w, int h);
void timer_callback(int);
void keyboard_callback(int key, int x, int y);
void DrawGrid();
void DrawFood();
void DrawSnake();
void random(int& x, int& y);
