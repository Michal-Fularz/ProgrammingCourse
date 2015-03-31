#include "CTank.h"

#include <GL/freeglut.h>

void CTank::Draw(void)
{
	glPushMatrix();
	glTranslated(this->position.x, this->position.y, this->position.z);

	glColor3d(this->barrelColour.red, this->barrelColour.green, this->barrelColour.blue);

	glPushMatrix();
	// draw the barrel
	glRotated(this->barrelAngle, 0.0, 0.0, 1.0);
	glTranslated(this->barrelWidth / 2, 0.0, 0.0);
	this->DrawRectangle(this->barrelWidth, this->barrelHeight);
	glPopMatrix();

	glColor3d(this->objectColour.red, this->objectColour.green, this->objectColour.blue);

	glPushMatrix();
	// draw the base
	DrawRectangle(this->tankWidth, this->tankHeight);
	glPopMatrix();

	glPopMatrix();
}

void CTank::SetBarrelAngle(double newBarrelAngle)
{
	if (newBarrelAngle >= 0 && newBarrelAngle <= 180)
	{
		this->barrelAngle = newBarrelAngle;
	}
}

void CTank::SetBulletPower(double newBulletPower)
{
	if (newBulletPower >= 0 && newBulletPower < 10)
	{
		this->bulletPower = newBulletPower;
	}
}

SPosition CTank::GetEndOfBarrelPosition(void)
{
	SPosition endOfBarrel;
	endOfBarrel.x = this->position.x + 
		this->barrelWidth * std::cos(CObject::DegreesToRadians(this->barrelAngle));
	endOfBarrel.y = this->position.y + 
		this->barrelWidth * std::sin(CObject::DegreesToRadians(this->barrelAngle));
	endOfBarrel.z = 0.0;

	return endOfBarrel;
}