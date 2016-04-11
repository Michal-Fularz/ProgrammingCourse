#include <iostream>

#include <Windows.h>

#define NDEBUG
#include <GL/freeglut.h>

#include "Rectangle.h"
#include "Circle.h"

#include <vector>

#include <cstdlib>
#include <ctime>

MF::Circle pilka(0.6, 1.0, 0.0, 0.0);
MF::Rectangle paletka(10, 1, 0.0, 1.0, 0.0);

std::vector<MF::Rectangle> sciany;
std::vector<MF::Rectangle> klocki;

int punkty = 0;

/* GLUT callback Handlers */
void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*logika gry*/
void loop(int value)
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
			punkty++;

			// to wywo³uje problem - system cls jest wolne
			//system("cls");
			//printf("Punkty: %d", punkty);
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

	pilka.UpdateFigurePosition();

	glutTimerFunc(1, loop, 0);
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
	paletka.SetPosition((mouse_x - 300) / 15, -15);
	paletka.UpdatePhysicsPosition();
}

void keyboard(unsigned char key_pressed, int mouse_x, int mouse_y)
{
	switch (key_pressed)
	{
		case 'a':
			{
				paletka.Move(-1.0, 0.0);
			}
			break;
		case 'd':
			{
				paletka.Move(1.0, 0.0);
			}
			break;
	}

	paletka.UpdatePhysicsPosition();
}

void InitGLUTScene(char* window_name)
{
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);

	// set white as the clear colour
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}

void SetCallbackFunctions()
{
	//glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutPassiveMotionFunc(passiveMouseMotion);
	glutTimerFunc(5, loop, 0);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS); 
}

void InitObjects()
{
	//pi³ka
	pilka.SetPosition(0, -12);

	pilka.UstawPredkosc(3e-2, 60);
	pilka.UstawFizyke(9.81*1E-6, -90);

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
		sciana.SetPosition(0, 20);
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

	paletka.UpdatePhysicsPosition();
	pilka.UpdatePhysicsPosition();
	for (auto itr = klocki.begin(); itr != klocki.end(); itr++)
	{
		itr->UpdatePhysicsPosition();
	}
	for (auto itr = sciany.begin(); itr != sciany.end(); itr++)
	{
		itr->UpdatePhysicsPosition();
	}
}

int main(int argc, char *argv[])
{
	// it's still possible to use console to print messages
	printf("Hello openGL world!");
	// the same can be done with cout / cin

	srand(time(NULL));

	glutInit(&argc, argv);
	InitGLUTScene("freeglut template");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(-20.0, 20.0, -20.0, 20.0, -20.0, 20.0);

	SetCallbackFunctions();
	InitObjects();

	// start GLUT event loop. It ends when user close the window.
	glutMainLoop();

	// sposób na wykonanie czegoœ po zakoñczeniu gluta
	printf("End of GLUT");

	return 0;
}