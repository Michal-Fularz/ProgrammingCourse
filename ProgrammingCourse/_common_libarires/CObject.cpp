#include "CObject.h"

#define NDEBUG
#include <GL/freeglut.h>
#include <cmath>

const double CObject::PI = std::atan(1.0) * 4;

void CObject::DrawRectangle(double width, double height)
{
	glBegin(GL_POLYGON);
	{
		glVertex3d(-width / 2, height / 2, 0);
		glVertex3d(width / 2, height / 2, 0);
		glVertex3d(width / 2, -height / 2, 0);
		glVertex3d(-width / 2, -height / 2, 0);
	}
	glEnd();
}

void CObject::DrawCircle(double radius)
{
	const int numberOfElements = 1000;

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i<numberOfElements; ++i)
	{
		glVertex3f(
			radius * std::cos(2 * CObject::PI*i / numberOfElements),
			radius * std::sin(2 * CObject::PI*i / numberOfElements),
			0
			);
	}
	glEnd();
}