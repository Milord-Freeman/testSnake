#include "main.h"

void DrawGrid() {
	glClearColor(0, 0, 0, 255);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(128, 128, 128);
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
			if (x == 0 || x == COLUMNS - 1 || y == 0 || y == ROWS - 1)
			{
				glColor3ub(102, 102, 102);
				glRectd(x, y, x + 1, y + 1);
			}
		}
	}
}

void DrawFood()
{
	if (food) {
		int newX = 0, newY = 0;
		random(newX, newY);
		foodXY.X(newX);
		foodXY.Y(newY);
		food = false;
	}
	glColor3ub(0, 255, 255);
	glRectf(foodXY.X, foodXY.Y, foodXY.X + 1, foodXY.Y + 1);
}

void DrawSnake()
{
	//�������������� ���������� ��� ����������� ���������� ���� ������
	coordinates NextStep = Position[0];
	//�������� ���������� ���������� ����
	switch (Dir)
	{
	case UP: NextStep.Y(NextStep.Y + 1);
		break;
	case DOWN: NextStep.Y(NextStep.Y - 1);
		break;
	case LEFT: NextStep.X(NextStep.X - 1);
		break;
	case RIGHT: NextStep.X(NextStep.X + 1);
		break;
	}
	//���������� ���� 
	DirChanged = false;

	//������ � �����? �������!
	if (!(GameOver = (NextStep.X == 0 ||
					  NextStep.X == COLUMNS - 1 ||
					  NextStep.Y == 0 ||
					  NextStep.Y == ROWS - 1))) {
			{ //������ ���� � ����? �������!
				for (int i = 0; i < SnakeLength; i++) {GameOver = (NextStep == Position[i]);}
				if (NextStep == foodXY) { // ������ � ������? ������� ���������.
					food = true;
					FPS -= 5;
					SnakeLength++;
					for (int i = SnakeLength; i > 0; i--)
					{
						Position[i] = Position[i - 1];
					}
					Position[0] = NextStep;
				}
				else {
					for (int i = SnakeLength; i > 0; i--)
					{
						Position[i] = Position[i - 1];
					}
					Position[0] = NextStep;
				}
			}
			//������������ �������������� ������
			for (int i = 0; i < SnakeLength; i++) {
				if (i == 0) glColor3ub(255, 0, 255);
				else {
					glColor3ub(0, 255, 255);
				}
				glRectd(Position[i].X, Position[i].Y, Position[i].X + 1, Position[i].Y + 1);
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
		case GLUT_KEY_LEFT: if (Dir != RIGHT && !DirChanged) {
			Dir = LEFT;
			DirChanged = true;
			break;
		}
		case GLUT_KEY_RIGHT: if (Dir != LEFT && !DirChanged) {
			Dir = RIGHT;
			DirChanged = true;
			break;
		}
		case GLUT_KEY_UP: if (Dir != DOWN && !DirChanged) {
			Dir = UP;
			DirChanged = true;
			break;
		}
		case GLUT_KEY_DOWN: if (Dir != UP && !DirChanged) {
			Dir = DOWN;
			DirChanged = true;
			break;
		}
		}
	}

	void display_callback() {
		DrawGrid();
		DrawFood();
		DrawSnake();
		glutSwapBuffers();
		if (GameOver) {
			//������� ����������� �� ����� ������� ������� � ���������, ��� LPCWSTR. 
			std::string stringBuf = std::to_string(SnakeLength - 4);
			std::wstring stemp = std::wstring(stringBuf.begin(), stringBuf.end());
			LPCWSTR sw = stemp.c_str();
			MessageBox(NULL, sw, L"You loose, sorry. Score is", 0);
			exit(0);
		}
	}

	int main(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
		glutInitWindowPosition(100, 100);
		glutInitWindowSize(COLUMNS * SQUARE_AREA, ROWS * SQUARE_AREA);
		glutCreateWindow("GameSnake");
		glutDisplayFunc(display_callback);
		glutReshapeFunc(reshape_callback);
		glutSpecialFunc(keyboard_callback);
		glutTimerFunc(FPS, timer_callback, 0);
		glutMainLoop();
		return 0;
	}