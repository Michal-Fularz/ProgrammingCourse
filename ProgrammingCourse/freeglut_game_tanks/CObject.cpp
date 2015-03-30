#include "CObject.h"

#include <GL/freeglut.h>

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