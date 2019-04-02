#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>

#include <vector>

#include "../_common/Figure.h"
#include "../_common/Rectangle.h"
#include "../_common/Circle.h"

std::vector<std::unique_ptr<MF::Figure>> figures;
std::vector<MF::Figure*> figs;

MF::Rectangle r1(2.0, 1.0, 1.0, 0.0, 0.0);
MF::Circle c1(1.0, 0.0, 0.0, 1.0);

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
	//r1.Draw();
	//c1.Draw();

	for (auto& f : figures)
		f->Draw();

	glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key_pressed, int mouse_x, int mouse_y)
{
	switch (key_pressed)
	{
		case 'w':
		{
			c1.Move(0.0, 0.1);
		}
		break;
		case 's':
		{
			c1.Move(0.0, -0.1);
		}
		break;
		case 'a':
		{
			c1.Move(-0.1, 0.0);
		}
		break;
		case 'd':
		{
			c1.Move(0.1, 0.0);
		}
		break;
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
	r1.Move(1.0, 0.0);
	r1.ChangeColour(0.0, 1.0, 0.0);
}

int main(int argc, char *argv[])
{
	figures.emplace_back(new MF::Circle(0.5, 1.0, 0.0, 1.0));
	figures.emplace_back(new MF::Rectangle(1.0, 0.5, 1.0, 0.0, 0.0));

	auto c = new MF::Circle(0.5, 1.0, 0.0, 0.0);
	figs.push_back(c);

	// it's still possible to use console to print messages
	printf("Hello openGL world!");
	// the same can be done with cout / cin

	glutInit(&argc, argv);
	InitGLUTScene("freeglut template");
	SetCallbackFunctions();
	InitObjects();

	// start GLUT event loop. It ends when user close the window.
	glutMainLoop();

	return 0;
}