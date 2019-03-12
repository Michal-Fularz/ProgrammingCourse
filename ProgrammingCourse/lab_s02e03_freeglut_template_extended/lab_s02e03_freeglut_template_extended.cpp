#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>

#include "Rectangle.h"

MF::Rectangle rect1(2.0, 1.0, 1.0, 0.0, 0.0);
MF::Rectangle rect2(0.5, 0.5, 0.0, 1.0, 0.0);

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

void idle()
{
	glutPostRedisplay();
}

void display()
{
	// clear the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	rect1.Draw();
	rect2.Draw();
	glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int mouse_x, int mouse_y)
{
	if (key == 'w')
	{
		rect1.Move(0.0, 0.1);
	}
	else if (key == 's')
	{
		rect1.Move(0.0, -0.1);
	}
	else if (key == 'a')
	{
		rect1.Move(-0.1, 0.0);
	}
	else if (key == 'd')
	{
		rect1.Move(0.1, 0.0);
	}
}

void InitGLUTScene(char* window_name)
{
	glutInitWindowSize(800, 600);
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
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
}

void InitObjects()
{
	rect2.Move(1.5, 0.0);
}

int main(int argc, char *argv[])
{
	// it's still possible to use console to print messages
	printf("Hello openGL world!");
	// the same can be done with cout / cin

	glutInit(&argc, argv);
	InitGLUTScene("freeglut template extended");
	SetCallbackFunctions();
	InitObjects();

	// start GLUT event loop. It ends when user close the window.
	glutMainLoop();

	return 0;
}