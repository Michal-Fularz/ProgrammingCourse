#include <iostream>

#include <GL/freeglut.h>


double tankPositionX = 0.0;
double barrelAngle = 30;

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

void DrawRectangle(double width, double height)
{
	glPushMatrix();
	glBegin(GL_POLYGON);
	{
		glVertex3d(-width / 2, height / 2, 0);
		glVertex3d(width / 2, height / 2, 0);
		glVertex3d(width / 2, -height / 2, 0);
		glVertex3d(-width / 2, -height / 2, 0);
	}
	glEnd();
	glPopMatrix();
}

void DrawTank()
{
	const double barrelWidth = 1.5;
	const double barrelHeight = 0.3;

	const double tankWidth = 2.0;
	const double tankHeight = 0.7;

	glPushMatrix();

	glTranslated(tankPositionX, 0.0, 0.0);

	// barrel
	glColor3d(0.0, 0.0, 0.0);
	glPushMatrix();
	glRotated(barrelAngle, 0.0, 0.0, 1.0);
	glTranslated(barrelWidth / 2, 0.0, 0.0);
	DrawRectangle(barrelWidth, barrelHeight);
	glPopMatrix();

	// tank
	glColor3d(0.0, 1.0, 0.0);
	glPushMatrix();
	DrawRectangle(tankWidth, tankHeight);
	glPopMatrix();

	glPopMatrix();
}

void display()
{
	// clear the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	DrawTank();
	glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		tankPositionX += 0.1;
	}
	else if (key == 'a')
	{
		tankPositionX += -0.1;
	}
	else if (key == 'q')
	{
		barrelAngle += 5;
	}
	else if (key == 'e')
	{
		barrelAngle += -5;
	}
}

int main(int argc, char *argv[])
{
	// it's still possible to use console to print messages
	printf("Hello openGL world!");
	// the same can be done with cout / cin

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("OpenGLUT Shapes");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);

	// set white as clear colour
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glutMainLoop();

	return 0;
}