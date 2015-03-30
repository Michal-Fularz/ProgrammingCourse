#include "CObject.h"

#include <GL/freeglut.h>
#define _USE_MATH_DEFINES
#include <cmath>

void CObject::DrawRectangle(double width, double height)
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

void CObject::DrawCircle(double radius)
{
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i<1000; ++i)
	{
		glVertex3f(radius * cos(2 * M_PI*i / 1000.0), radius * sin(2 * M_PI*i / 1000.0), 0);
	}
	glEnd();
}