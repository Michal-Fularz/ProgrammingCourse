#include "Rectangle.h"

#define NDEBUG
#include <GL/freeglut.h>

using namespace MF;

Rectangle::Rectangle(double width, double height, double red, double green, double blue) 
	: Physics(),
	width_(width), height_(height)
{
	SetBorders(
		-width_ / 2, -height_/2,
		width_ / 2, height_ / 2
		);

	colour_red_ = red;
	colour_green_ = green;
	colour_blue_ = blue;
}

Rectangle::~Rectangle()
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