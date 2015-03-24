#include <iostream>

#include <GL/freeglut.h>

const int glutWindowWidth = 640;
const int glutWindowHeight = 480;

float proportion = (float)glutWindowWidth / (float)glutWindowHeight;

double rectanglePositionX = 0.0;

#include "CObject.h"
class CBohater : public CObiekt
{
public:
	CBohater(void);
	~CBohater(void);
	void Rysuj();
};

CBohater::CBohater()
{
}

CBohater::~CBohater()
{
}

void CBohater::Rysuj()
{
	float w = 0.2;
	float h = 0.2;

	glColor3d(this->kolor.red, this->kolor.green, this->kolor.blue);
	//glColor3d(1,0,0);

	glPushMatrix();
	//glTranslated(0.0, 0.0, -3.0);
	glTranslated(this->translacja[0], this->translacja[1], this->translacja[2]);
	glRotated(this->rotacja[0], 1.0, 0.0, 0.0);
	glRotated(this->rotacja[1], 0.0, 1.0, 0.0);
	glRotated(this->rotacja[2], 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	{
		glVertex3d(-0.2, 0.2, 0);
		glVertex3d(0.2, 0.2, 0);
		glVertex3d(0.2, -0.2, 0);
		glVertex3d(-0.2, -0.2, 0);

		//glVertex3d(w / 2, -h / 2, 0);
		//glVertex3d(w / 2, h / 2, 0);
		//glVertex3d(-w / 2, h / 2, 0);
		//glVertex3d(-w / 2, -h / 2, 0);
	}
	glEnd();
	glPopMatrix();
}

CBohater *bohater;

/* GLUT callback Handlers */
static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;
	proportion = ar;

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

void DrawRectangle(void)
{
	double height = 0.5;
	double width = 0.5;

	glPushMatrix();
	// TODO
	// test functions below (glTranslated, glRotated, glColor3d) - what happen when you change their arguments?
	// does their order change the result?
	glTranslated(rectanglePositionX, 0, 0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(1.0, 0.0, 0.0);
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

void DrawCircle(float cx, float cy, float r, int num_segments) {

	glPushMatrix();
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)   {
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 
		glVertex2f(x + cx, y + cy);//output vertex 
	}
	glEnd();
	glPopMatrix();
}

void DrawText(void)
{

}

static void display(void)
{
	// wyczyszenie sceny
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	DrawRectangle();
	DrawCircle(0.0, 0.0, 1.0, 1000);

	bohater->Rysuj();

	glTranslated(1.0, 0.0, 0.0);
	glColor3f(0.5f, 0.5f, 0.5f);
	glRasterPos2i(0, 0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"text to render");


	glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{

	if (key == 'w')
	{
		glPushMatrix();

		glTranslated(bohater->translacja[0], bohater->translacja[1], bohater->translacja[2]);
		glRotated(bohater->rotacja[0], 1.0, 0.0, 0.0);
		glRotated(bohater->rotacja[1], 0.0, 1.0, 0.0);
		glRotated(bohater->rotacja[2], 0.0, 0.0, 1.0);
		glTranslated(0.0, 0.1, 0.0);

		double modelViewMatrix[16];
		glGetDoublev(GL_MODELVIEW_MATRIX, modelViewMatrix);

		bohater->UstawPozycje(modelViewMatrix[12], modelViewMatrix[13], 0.0);

		cout << bohater->translacja[0] << ", " << bohater->translacja[1] << endl;

		glPopMatrix();
	}
	if (key == 's')
	{
		bohater->Przesun(0.0, -0.1, 0.0);
	}
	if (key == 'a')
	{
		bohater->Obroc(0, 0, 5);
	}
	if (key == 'd')
	{
		bohater->Obroc(0, 0, -5);
	}
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		float mouseXGlobalCoords = (((float)x / glutWindowWidth) - 0.5f) * 2.0F * proportion;
		float mouseYGlobalCoords = -(((float)y / glutWindowHeight) - 0.5f) * 2.0F;

		bohater->UstawPozycje(mouseXGlobalCoords, mouseYGlobalCoords, 0);

		cout << mouseXGlobalCoords << ", " << mouseYGlobalCoords << endl;
	}
}

int main(int argc, char *argv[])
{
	// it's still possible to use console to print messages
	printf("Hello openGL world!");
	// the same can be done with cout / cin

	bohater = new CBohater();
	bohater->Przesun(0.0, 0.0, 0.0);
	bohater->UstawKolor(1.0, 0.0, 0.0);

	glutInitWindowSize(glutWindowWidth, glutWindowHeight);
	glutInitWindowPosition(40, 40);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("OpenGLUT Shapes");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

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