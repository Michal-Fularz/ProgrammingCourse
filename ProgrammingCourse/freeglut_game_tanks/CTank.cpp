#include "CTank.h"

#include <GL/freeglut.h>

void CTank::DrawRectangle(double width, double height)
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

void CTank::Draw(void)
{
	glPushMatrix();
	glTranslated(this->position.x, this->position.y, this->position.z);

	glPushMatrix();
	// draw the barrel
	glColor3d(this->barrelColour.red, this->barrelColour.green, this->barrelColour.blue);
	glRotated(this->barrelAngle, 0.0, 0.0, 1.0);
	glTranslated(this->barrelWidth / 2, 0.0, 0.0);

	this->DrawRectangle(this->barrelWidth, this->barrelHeight);
	glPopMatrix();

	glPushMatrix();
	// draw the base
	glColor3d(this->tankColour.red, this->tankColour.green, this->tankColour.blue);
	DrawRectangle(this->tankWidth, this->tankHeight);
	glPopMatrix();

	glPopMatrix();
}

// example hot to create methods that safely change the parameters and are easy to mantain
// method for rotating the barrel is using the Set method which do all the checking
void CTank::RotateBarrel(double dBarrelAngle)
{
	this->SetBarrelAngle(this->barrelAngle + dBarrelAngle);
}

void CTank::SetBarrelAngle(double newBarrelAngle)
{
	if (newBarrelAngle >= 0 && newBarrelAngle <= 180)
	{
		this->barrelAngle = newBarrelAngle;
	}
}