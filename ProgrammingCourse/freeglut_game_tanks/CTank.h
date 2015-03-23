#ifndef CTANK2_H
#define CTANK2_H

#include <GL/freeglut.h>

struct SPosition
{
	double x;
	double y;
	double z;
};

struct SColour
{
	double red;
	double green;
	double blue;
};

class CTank
{
private:
	SPosition position;
	SColour tankColour;
	SColour barrelColour;

	double tankWidth;
	double tankHeight;
	double barrelWidth;
	double barrelHeight;

	double barrelAngle;

	void DrawRectangle(double width, double height)
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

public:
	CTank(double _tankWidth, double _tankHeight, double _barrelWidth, double _barrelHeight)
	{
		this->tankWidth = _tankWidth;
		this->tankHeight = _tankHeight;
		this->barrelWidth = _barrelWidth;
		this->barrelHeight = _barrelHeight;
		// green tank
		this->tankColour.red = 0.0;
		this->tankColour.green = 1.0;
		this->tankColour.blue = 0.0;
		// black barrel
		this->barrelColour.red = 0.0;
		this->barrelColour.green = 0.0;
		this->barrelColour.blue = 0.0;
	}

	void Draw(void)
	{
		glPushMatrix();
		glTranslated(this->position.x, this->position.y, this->position.z);

		glPushMatrix();
		// rysuj lufê
		glColor3d(this->barrelColour.red, this->barrelColour.green, this->barrelColour.blue);
		glRotated(this->barrelAngle, 0.0, 0.0, 1.0);
		glTranslated(this->barrelWidth / 2, 0.0, 0.0);

		this->DrawRectangle(this->barrelWidth, this->barrelHeight);
		glPopMatrix();

		glPushMatrix();
		// rysuj podstawê
		glColor3d(this->tankColour.red, this->tankColour.green, this->tankColour.blue);
		DrawRectangle(this->tankWidth, this->tankHeight);
		glPopMatrix();

		glPopMatrix();
	}

	void RotateBarrel(double dBarrelAngle)
	{
		this->SetBarrelAngle(this->barrelAngle + dBarrelAngle);
	}

	void SetBarrelAngle(double newBarrelAngle)
	{
		if (newBarrelAngle >= 0 && newBarrelAngle <= 180)
		{
			this->barrelAngle = newBarrelAngle;
		}
	}
};

#endif