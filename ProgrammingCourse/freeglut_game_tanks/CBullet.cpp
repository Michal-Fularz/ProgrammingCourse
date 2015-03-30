
#include "CBullet.h"

#include <GL/freeglut.h>

void CBullet::Draw(void)
{
	if (!this->flagHidden)
	{
		glPushMatrix();

		glTranslated(this->position.x, this->position.y, this->position.z);

		glPushMatrix();
		// draw the bullet
		glColor3d(this->objectColour.red, this->objectColour.green, this->objectColour.blue);
		//DrawRectangle(this->size, this->size);
		this->DrawCircle(this->size);
		glPopMatrix();

		glPopMatrix();
	}
}

void CBullet::Fire(double power, double angle)
{
	this->vX = power * cos(3.14 / 180 * angle);
	this->vY = power * sin(3.14 / 180 * angle);
}

void CBullet::Fly(double gravityAcceleration, double timeInMs)
{
	double dt = timeInMs / 1000;

	// TODO: 
	// ruch jednostajny w osi Y
	this->Move(vX*dt, vY*dt, 0.0);
	// a powinien byæ
	//this->Move(vX*dt, 1.0 / 2.0 * gravityAcceleration*dt + V0*dt);
	this->vY = this->vY - (gravityAcceleration / 2 * dt);
}