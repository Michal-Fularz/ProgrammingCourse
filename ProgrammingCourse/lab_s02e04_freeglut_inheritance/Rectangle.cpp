#include "Rectangle.h"

#define NDEBUG
#include <GL/freeglut.h>

using namespace MF;

Rectangle::Rectangle(
	float width, float height,
	float x, float y,
	float red, float green, float blue
): 
Figure(x, y, red, green, blue),
width_(width), height_(height)
{
}

void Rectangle::Draw()
{
	if (flag_show_)
	{
		glPushMatrix();
		{
			glTranslated(position_x_, position_y_, 0.0);
			glRotated(rotation_z_, 0.0, 0.0, 1.0);

			glColor3d(colour_red_, colour_green_, colour_blue_);

			glBegin(GL_POLYGON);
			{
				glVertex3d(-width_ / 2, height_ / 2, 0);
				glVertex3d(width_ / 2, height_ / 2, 0);
				glVertex3d(width_ / 2, -height_ / 2, 0);
				glVertex3d(-width_ / 2, -height_ / 2, 0);
			}
			glEnd();
		}
		glPopMatrix();
	}
}
