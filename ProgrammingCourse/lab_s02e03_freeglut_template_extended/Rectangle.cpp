#include "Rectangle.h"

#define NDEBUG
#include <GL/freeglut.h>

MF::Rectangle::Rectangle(
	double width, double height, 
	double red, double green, double blue
) {
	width_ = width;
	height_ = height;

	position_x_ = 0.0;
	position_y_ = 0.0;

	rotation_z_ = 0.0;

	colour_red_ = red;
	colour_green_ = green;
	colour_blue_ = blue;
}

MF::Rectangle::~Rectangle()
{
}

void MF::Rectangle::Draw()
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

void MF::Rectangle::Move(double dx, double dy)
{
	position_x_ += dx;
	position_y_ += dy;
}

void MF::Rectangle::ChangeColour(double red, double green, double blue)
{
	colour_red_ = red;
	colour_green_ = green;
	colour_blue_ = blue;
}
