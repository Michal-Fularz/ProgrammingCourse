#include "Circle.h"

#define NDEBUG
#include <GL/freeglut.h>

#define _USE_MATH_DEFINES
#include <cmath>

using namespace MF;

Circle::Circle(
	float radius,
	float x, float y,
	float red, float green, float blue
): 
Figure(x, y, red, green, blue),
radius_(radius)
{
}

void Circle::Draw()
{
	if (flag_show_)
	{
		glPushMatrix();
		{
			glTranslated(position_x_, position_y_, 0.0);
			glRotated(rotation_z_, 0.0, 0.0, 1.0);

			glColor3d(colour_red_, colour_green_, colour_blue_);

			glBegin(GL_TRIANGLE_FAN);
			{
				for (int i = 0; i <= 360; i++)
				{
					// 180 - pi
					// i - degInRad
					float degInRad = i*M_PI / 180;
					glVertex2f(
						cos(degInRad)*radius_, 
						sin(degInRad)*radius_
					);
				}
			}
			glEnd();
		}
		glPopMatrix();
	}
}
