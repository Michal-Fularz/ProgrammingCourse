#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>

#include "../_common_libarires/CTank.h"
#include "../_common_libarires/CBullet.h"

// default constructor
CTank tank1(1.0, 0.3, 0.7, 0.2);
// specialized constructor 
CTank tank2(
	SColour(0.0, 0.0, 1.0),
	1.0, 0.3,
	SColour(0.5, 0.0, 0.5),
	0.7, 0.2
	);
CBullet bullet(0.125);

const double gravityAcceleration = 9.81;
const int gameLogicUpdateIntervalInMs = 25;

/* GLUT callback Handlers */
static void resize(int width, int height)
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

static void idle(void)
{
	glutPostRedisplay();
}

static void display(void)
{
	// clear the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	tank1.Draw();
	tank2.Draw();
	bullet.Draw();
	glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'q')
	{
		tank1.RotateBarrel(-5);
	}
	else if (key == 'e')
	{
		tank1.RotateBarrel(5);
	}
	else if (key == 'a')
	{
		tank1.ChangeBulletPower(1);
		std::cout << "Bullet power: " << tank1.GetBulletPower() << std::endl;
	}
	else if (key == 'd')
	{
		tank1.ChangeBulletPower(-1);
		std::cout << "Bullet power: " << tank1.GetBulletPower() << std::endl;
	}
	else if (key == 'z')
	{
		bullet.Fire(
			tank1.GetEndOfBarrelPosition(),
			tank1.GetBulletPower(),
			tank1.GetBarrelAngle()
			);
	}
}

void gameLogic(int value)
{
	bullet.Fly(gravityAcceleration, gameLogicUpdateIntervalInMs);

	glutTimerFunc(gameLogicUpdateIntervalInMs, gameLogic, value);
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

	tank1.SetPosition(-2.0, -2.0, 0.0);
	tank2.SetPosition(2.0, -2.0, 0.0);

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(gameLogicUpdateIntervalInMs, gameLogic, 0);

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