#include <iostream>
#include <time.h>

#define NDEBUG
#include <GL/freeglut.h>

#include "../_common/Figure.h"
#include "../_common/Rectangle.h"
#include "../_common/Circle.h"
#include <vector>

std::vector<MF::Figure*> figures;
std::vector<MF::Figure*>::iterator selectedFigure;

/* GLUT callback Handlers */
void resize(int width, int height)
{
	const float ar = static_cast<float>(width) / static_cast<float>(height);

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
	for (const auto& f : figures)
	{
		f->Draw();
	}
	glPopMatrix();

	glutSwapBuffers();
}


// this function shows, that while we have our main variables as globals
// we should not overuse it. Here the function is more general 
// and could work for two or more different collections of figures
std::vector<MF::Figure*>::iterator GetNextIteratorSafely(
	std::vector<MF::Figure*>::iterator itr,
	std::vector<MF::Figure*>& collection
)
{
	// change selected figure to next
	++itr;
	// check if we are still pointing to an existing figure
	if (itr == collection.end())
	{
		itr = collection.begin();
	}
	return itr;
}

void keyboard(
	unsigned char key_pressed, int mouse_x, int mouse_y
)
{
	switch (key_pressed)
	{
		case 'q':
		{
			// random colour for a figure we were previously controlling
			(*selectedFigure)->ChangeColour(
				(rand() % 255) / 255.0f,
				(rand() % 255) / 255.0f,
				(rand() % 255) / 255.0f
			);
			selectedFigure = GetNextIteratorSafely(selectedFigure, figures);
			// selected figure is pink
			(*selectedFigure)->ChangeColour(
				255 / 255.0f,
				105 / 255.0f,
				180 / 255.0f
			);
		}
		break;

		case 'w':
		{
			(*selectedFigure)->Move(0.0f, 0.1f);
		}
		break;
		case 's':
		{
			(*selectedFigure)->Move(0.0f, -0.1f);
		}
		break;
		case 'a':
		{
			(*selectedFigure)->Move(-0.1f, 0.0f);
		}
		break;
		case 'd':
		{
			(*selectedFigure)->Move(0.1f, 0.0f);
		}
		break;
		default:
			break;
	}
}

void InitGLUTScene(const char* window_name)
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

MF::Circle* GenerateRandomCircle()
{
	MF::Circle* circle = new MF::Circle(
		// [0.1, 0.5]
		(rand() % 5 + 1) / 10.0f,
		// [-2.0, 2.0]
		(rand() % 400) / 100.0f - 2.0f,
		// [-2.0, 2.0]
		(rand() % 400) / 100.0f - 2.0f,
		// [0.0, 1.0]
		(rand() % 255) / 255.0f,
		// [0.0, 1.0]
		(rand() % 255) / 255.0f,
		// [0.0, 1.0]
		(rand() % 255) / 255.0f
	);
	return circle;
}

MF::Rectangle* GenerateRandomRectangle()
{
	MF::Rectangle* rectangle = new MF::Rectangle(
		// [0.1, 0.5]
		(rand() % 5 + 1) / 10.0f,
		// [0.1, 0.5]
		(rand() % 5 + 1) / 10.0f,
		// [-2.0, 2.0]
		(rand() % 400) / 100.0f - 2.0f,
		// [-2.0, 2.0]
		(rand() % 400) / 100.0f - 2.0f,
		// [0.0, 1.0]
		(rand() % 255) / 255.0f,
		// [0.0, 1.0]
		(rand() % 255) / 255.0f,
		// [0.0, 1.0]
		(rand() % 255) / 255.0f
	);
	return rectangle;
}

void InitObjects()
{
	for (int i = 0; i<10; i++)
	{
		// 60-40 split between circles and rectangles
		if (rand() % 100 < 60)
		{
			figures.push_back(GenerateRandomRectangle());
		}
		else
		{
			figures.push_back(GenerateRandomCircle());
		}
	}
	// very important - we have to init which figure is selected
	selectedFigure = figures.begin();
}

void DeInitObjects()
{
	// properly release the memory allocated for objects
	for (auto itr = figures.begin(); itr != figures.end(); ++itr)
	{
		delete *itr;
	}
}

int main(int argc, char *argv[])
{
	srand(time(nullptr));
	// it's still possible to use console to print messages
	printf("Hello openGL world!");
	// the same can be done with cout / cin

	glutInit(&argc, argv);
	InitGLUTScene("freeglut template");
	SetCallbackFunctions();
	InitObjects();

	// start GLUT event loop. It ends when user close the window.
	glutMainLoop();

	DeInitObjects();

	return 0;
}
