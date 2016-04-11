#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define NDEBUG
#include <GL/freeglut.h>

#include "Rectangle.h"
#include "Circle.h"

const int GAME_LOGIC_REFRESH_TIME = 1;

MF::Circle pilka(0.6, 1.0, 0.0, 0.0);
MF::Rectangle paletka(10, 1, 0.0, 1.0, 0.0);

std::vector<MF::Rectangle> sciany;
std::vector<MF::Rectangle> klocki;

/* GLUT callback Handlers */
void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 45, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*logika gry*/
void logicLoop(int value)
{
	//sprawdzanie kolizji ze œcianami
	for (auto itr = sciany.begin(); itr != sciany.end(); itr++)
	{
		pilka.Kolizja(*itr);
	}

	for (auto itr = klocki.begin(); itr != klocki.end();)
	{
		if (pilka.Kolizja(*itr))
		{
			itr = klocki.erase(itr);
		}
		else
		{
			itr++;
		}
	}

	//sprawdzanie kolizji z paletk¹
	pilka.Kolizja(paletka);

	//wyliczenie nowej pozycji pi³ki
	pilka.Aktualizuj(glutGet(GLUT_ELAPSED_TIME));

	glutTimerFunc(GAME_LOGIC_REFRESH_TIME, logicLoop, 0);
}

void idle()
{
	glutPostRedisplay();
}

void display()
{
	// clear the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	pilka.Draw();
	paletka.Draw();

	for (auto itr = sciany.begin(); itr != sciany.end(); itr++)
	{
		itr->Draw();
	}

	for (auto itr = klocki.begin(); itr != klocki.end(); itr++)
	{
		itr->Draw();
	}

	glPopMatrix();

	glutSwapBuffers();
}

void passiveMouseMotion(int mouse_x, int mouse_y)
{
	double windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	double windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

	double mouse_gl_x = (((double)mouse_x - (windowWidth / 2)) / windowWidth) * ((windowWidth/windowHeight)*45);
	
	paletka.SetPosition(mouse_gl_x, -15);
}

void keyboard(unsigned char key_pressed, int mouse_x, int mouse_y)
{
	switch (key_pressed)
	{
		case 'a':
			{
				paletka.Move(-2.0, 0.0);
			}
			break;
		case 'd':
			{
				paletka.Move(2.0, 0.0);
			}
			break;
	}
}

void InitGLUTScene(char* window_name)
{
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);

	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}

void SetCallbackFunctions()
{
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutPassiveMotionFunc(passiveMouseMotion);

	glutTimerFunc(GAME_LOGIC_REFRESH_TIME, logicLoop, 0);
}

void InitObjects()
{
	//pi³ka
	pilka.SetPosition(0, -12);

	pilka.UstawPredkosc(3e-2, 60);
	pilka.UstawFizyke(9.81*1E-6, -90);
	pilka.UstawCzas(glutGet(GLUT_ELAPSED_TIME));

	//paletka
	paletka.SetPosition(0, -15);

	//klocki
	for (int l = 2, n = 0; l < 6; l++, n++)
	{
		for (int i = -16; i < 20; i += 4)
		{
			double red = (double)(rand() % 1000) / 1000.0;
			double green = (double)(rand() % 1000) / 1000.0;
			double blue = (double)(rand() % 1000) / 1000.0;
			MF::Rectangle newBlock(4, 1, red, green, blue);
			newBlock.SetPosition(i, l);
			klocki.push_back(newBlock);
		}
	}

	//œciany
	{
		MF::Rectangle sciana(68, 2, 0.5, 0.5, 0.5);
		sciana.SetPosition(0, 22);
		sciany.push_back(sciana);
	}

	{
		MF::Rectangle sciana(4, 60, 0.5, 0.5, 0.5);
		sciana.SetPosition(21, 0);
		sciany.push_back(sciana);
	}

	{
		MF::Rectangle sciana(4, 60, 0.5, 0.5, 0.5);
		sciana.SetPosition(-21, 0);
		sciany.push_back(sciana);
	}
}

int main(int argc, char *argv[])
{
	srand(time(NULL));

	glutInit(&argc, argv);
	InitGLUTScene("Arkanoid");

	SetCallbackFunctions();

	InitObjects();

	glutMainLoop();
	
	return 0;
}