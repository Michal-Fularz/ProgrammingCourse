#include <GL/freeglut.h>
#include <iostream>
using namespace std;
#include "CCzolg.h"
#include "CPocisk.h"

CCzolg *czolg;
CPocisk *pocisk;


const int glutWindowWidth = 640;
const int glutWindowHeight = 480;

float proportion = (float)glutWindowWidth / (float)glutWindowHeight;

/* GLUT callback Handlers */
static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;
	proportion = ar;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	//gluOrtho2D(-ar, ar, -1.0, 1.0);
	glOrtho(-ar, ar, -1.0, 1.0, 2.0, 10.0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

static void idle(void)
{
	glutPostRedisplay();
}

static void gameLogic(int value)
{
	pocisk->Lec();
	glutTimerFunc(25, gameLogic, 0);
}

static void display(void)
{
	// wyczyszenie sceny
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_LIGHTING);

	glPushMatrix();
	czolg->Rysuj();
	pocisk->Rysuj();
	glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
	}
	if (key == 's')
	{
	}
	if (key == 'a')
	{
		czolg->Przesun(-0.1, 0.0, 0.0);
	}
	if (key == 'd')
	{
		czolg->Przesun(0.1, 0.0, 0.0);
	}
	if (key == 'q')
	{
		czolg->ObrocLufe(5.0);
	}
	if (key == 'e')
	{
		czolg->ObrocLufe(-5.0);
	}
	if (key == 32)	// space
	{
		pocisk->Wystrzel(czolg->GetKatLufy(), 0.05, czolg->GetX(), czolg->GetY(), czolg->GetZ());
	}
	if (key == 'z')
	{
		pocisk->Resetuj();
	}
}

int MainGraCzolgi(int argc, char *argv[])
{
	// mo¿liwoœæ wyœwietlania tekstu w konsoli
	printf("Hello openGL world!");

	czolg = new CCzolg();
	pocisk = new CPocisk();
	pocisk->Przesun(0.5, 0.2, 0.0);

	glutInitWindowSize(glutWindowWidth, glutWindowHeight);
	glutInitWindowPosition(40, 40);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("OpenGLUT Shapes");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(25, gameLogic, 0);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glutMainLoop();

	return EXIT_SUCCESS;
}