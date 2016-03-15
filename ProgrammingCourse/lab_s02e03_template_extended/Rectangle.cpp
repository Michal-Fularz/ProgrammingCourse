#include "Rectangle.h"

#define NDEBUG
#include <GL/freeglut.h>

MF::Rectangle::Rectangle(double width, double height, double red, double green, double blue)
{
	m_width = width;
	m_height = height;

	m_position_x = 0.0;
	m_position_y = 0.0;

	m_rotation_z = 0.0;

	m_colour_red = red;
	m_colour_green = green;
	m_colour_blue = blue;
}


MF::Rectangle::~Rectangle()
{
}

void MF::Rectangle::Draw()
{
	glPushMatrix();
	glTranslated(m_position_x, m_position_y, 0.0);
	glRotated(m_rotation_z, 0.0, 0.0, 1.0);

	glColor3d(m_colour_red, m_colour_green, m_colour_blue);

	glBegin(GL_POLYGON);
	{
		glVertex3d(-m_width / 2, m_height / 2, 0);
		glVertex3d(m_width / 2, m_height / 2, 0);
		glVertex3d(m_width / 2, -m_height / 2, 0);
		glVertex3d(-m_width / 2, -m_height / 2, 0);
	}
	glEnd();
	glPopMatrix();
}

void MF::Rectangle::Move(double dx, double dy)
{
	m_position_x += dx;
	m_position_y += dy;
}

void MF::Rectangle::ChangeColour(double red, double green, double blue)
{
	m_colour_red = red;
	m_colour_green = green;
	m_colour_blue = blue;
}
