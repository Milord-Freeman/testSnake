#include "main.h"

void DrawGrid() {
	glClearColor(0, 0, 0, 255);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	for (int x = 0; x < COLUMNS; x++)
	{
		for (int y = 0; y < ROWS; y++)
		{
			glVertex2f(x, y);
			glVertex2f(x, y + 1);
			glVertex2f(x, y);
			glVertex2f(x + 1, y);
		}
	}
	glEnd();
	for (int x = 0; x < COLUMNS; x++)
	{
		for (int y = 0; y < ROWS; y++)
		{
			if (x == 0 || x == ROWS - 1 || y == 0 || y == ROWS - 1)
			{
				glColor3ub(255, 0, 255);
				glRectd(x, y, x + 1, y + 1);
			}
		}
	}
}

void DrawFood()
{
	if (food) {
		random(foodX, foodY);
		food = false;
	}
	glColor3ub(0, 255, 255);
	glRectf(foodX, foodY, foodX + 1, foodY + 1);
}

void DrawSnake()
{
	for (int i = SnakeLength - 1; i > 0; i--) {
		PositionX[i] = PositionX[i - 1];
		PositionY[i] = PositionY[i - 1];
	}
	glColor3ub(255, 255, 0);
	switch (Dir)
	{
	case UP: PositionY[0]++;
		break;
	case DOWN: PositionY[0]--;
		break;
	case LEFT: PositionX[0]--;
		break;
	case RIGHT: PositionY[0]++;
		break;
	}
	for (int i = 0; i < SnakeLength; i++) {
		if (i == 0) { glColor3ub(255, 0, 255); }
		else {
			glColor3ub(0, 255, 255);
		}
		glRectd(PositionX[i], PositionY[i], PositionX[i] + 1, PositionY[i] + 1);
	}
}

void random(int& x, int& y)
{
	int _maxX = COLUMNS - 2, _maxY = ROWS - 2, _min = 1;
	srand(time(NULL));
	x = _min + rand() % (_maxX - _min);
	y = _min + rand() % (_maxY - _min);
}

void reshape_callback(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, COLUMNS, 0, ROWS, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int)
{
	glutPostRedisplay();
	glutTimerFunc(FPS, timer_callback, 0);
}

void keyboard_callback(int key, int x, int y)
{

	switch (key) {
	case GLUT_KEY_LEFT: if (Dir != RIGHT) Dir = LEFT; break;
	case GLUT_KEY_RIGHT: if (Dir != LEFT) Dir = RIGHT; break;
	case GLUT_KEY_UP: if (Dir != DOWN) Dir = UP; break;
	case GLUT_KEY_DOWN: if (Dir != UP) Dir - DOWN; break;
	}

}

void display_callback() {
	DrawGrid();
	DrawFood();
	DrawSnake();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	using namespace std;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("GameSnake");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	glutSpecialFunc(keyboard_callback);
	glutTimerFunc(FPS, timer_callback, 0);
	glutMainLoop();
	return 0;
}