#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>

// Initial translation (x,y,z) and rotation (xrot, yrot, zrot) of model coordinate system
double x = 0, y = 0, z = 0;
double xrot = 0, yrot = 0, zrot = 0;

// Last mouse position
int mouseLastX = 0, mouseLastY = 0;

// Storing information if left mouse button is clicked
bool mouseLeftBtnClicked = false;

// object for gluCylinder drawing functions
GLUquadricObj *quadratic;

/* GLUT callback Handlers */
void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void idle(void)
{
	glutPostRedisplay();
}

void keyboard(unsigned char key, int mouse_x, int mouse_y) {

	// X axis
	if (key == 'q')
	{
		x = x - 0.1;
	}
	else if (key == 'w')
	{
		x = x + 0.1;
	}
	else if (key == 'e')
	{
		xrot = xrot - 5;
	}
	else if (key == 'r')
	{
		xrot = xrot + 5;
	}

	// Y axis
	if (key == 'a')
	{
		y = y - 0.1;
	}
	else if (key == 's')
	{
		y = y + 0.1;
	}
	else if (key == 'd')
	{
		yrot = yrot - 5;
	}
	else if (key == 'f')
	{
		yrot = yrot + 5;
	}

	// Z axis
	else if (key == 'z')
	{
		z = z - 0.1;
	}
	else if (key == 'x')
	{
		z = z + 0.1;
	}
	else if (key == 'c')
	{
		zrot = zrot - 5;
	}
	else if (key == 'v')
	{
		zrot = zrot + 5;
	}
}

void mouseMovement(int mouse_x, int mouse_y) {

	if (mouseLeftBtnClicked)
	{
		int diff_x = mouse_x - mouseLastX; //check the difference between the current x and the last x position
		int diff_y = mouse_y - mouseLastY; //check the difference between the current y and the last y position
		mouseLastX = mouse_x; //set lastx to the current x position
		mouseLastY = mouse_y; //set lasty to the current y position

		// conversion between mouse plane and axes of coordination system
		yrot += diff_x * 0.5; // rotation around Y axis is based on mouse movement in x direction
		xrot += diff_y * 0.5; // rotation around X axis is based on mouse movement in y direction
	}
}

void onMouseButton(int button, int state, int mouse_x, int mouse_y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		mouseLeftBtnClicked = false;
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mouseLastX = mouse_x;
		mouseLastY = mouse_y;
		mouseLeftBtnClicked = true;
	}
}

void setModelRotationAndTranslation()
{
	// Translation of model coordinate system
	glTranslated(x, y, z);

	// Initial rotation of model coordinate system
	glRotated(xrot, 1, 0, 0);
	glRotated(yrot, 0, 1, 0);
	glRotated(zrot, 0, 0, 1);
}

void drawAxesOfCoordinateSystem()
{
	// Drawing axes

	// X axis -> blue
	glPushMatrix();
	{
		glColor3d(0.0, 0.0, 1.0);
		glRotated(90, 0, 1, 0);
		gluCylinder(quadratic, 0.1f, 0.1f, 2, 32, 32);
	}
	glPopMatrix();

	// Y axis -> red
	glPushMatrix();
	{
		glColor3d(1.0, 0.0, 0.0);
		glRotated(-90, 1, 0, 0);
		gluCylinder(quadratic, 0.1f, 0.1f, 2, 32, 32);
	}
	glPopMatrix();

	// Z axis -> green
	glPushMatrix();
	{
		glColor3d(0.0, 1.0, 0.0);
		gluCylinder(quadratic, 0.1f, 0.1f, 2, 32, 32);
	}
	glPopMatrix();
}

void drawCube(float x, float y, float z, float r, float g, float b, float size) {
	glPushMatrix();
	{
		glTranslated(x, y, z);
		glColor3d(r, g, b);
		glutSolidCube(size);
	}
	glPopMatrix();
}

void display(void)
{
	// clear the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{
		setModelRotationAndTranslation();
		drawAxesOfCoordinateSystem();

		// Drawing a cube at (1,1,1) with black color (0.0, 0.0, 0.0) and size = 0.5
		drawCube(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.5);

		// Add your drawing functions below 
		// ...
		// ...
		// ...
	}
	glPopMatrix();

	glutSwapBuffers();
}

void menu() {
	std::cout << "Keys: " << std::endl << std::endl;

	// X axis
	std::cout << "'q' - move coordinate system in direction of minus X" << std::endl;
	std::cout << "'w' - move coordinate system in direction of plus X" << std::endl;
	std::cout << "'e' - rotate coordinate system of minus angle around X" << std::endl;
	std::cout << "'r' - rotate coordinate system of plus angle around X" << std::endl << std::endl;

	// Y axis
	std::cout << "'a' - move coordinate system in direction of minus Y" << std::endl;
	std::cout << "'s' - move coordinate system in direction of plus Y" << std::endl;
	std::cout << "'d' - rotate coordinate system of minus angle around Y" << std::endl;
	std::cout << "'f' - rotate coordinate system of plus angle around Y" << std::endl << std::endl;

	// Z axis
	std::cout << "'z' - move coordinate system in direction of minus Z" << std::endl;
	std::cout << "'x' - move coordinate system in direction of plus Z" << std::endl;
	std::cout << "'c' - rotate coordinate system of minus angle around Z" << std::endl;
	std::cout << "'v' - rotate coordinate system of plus angle around Z" << std::endl << std::endl;

	std::cout << "Use mouse (with left button pressed) to rotate the scene" << std::endl;
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
	glutMouseFunc(onMouseButton);
	glutMotionFunc(mouseMovement);
}

int main(int argc, char *argv[])
{
	menu();

	glutInit(&argc, argv);
	InitGLUTScene("3d rotations by mouse");
	SetCallbackFunctions();

	quadratic = gluNewQuadric();

	glutMainLoop();

	return 0;
}