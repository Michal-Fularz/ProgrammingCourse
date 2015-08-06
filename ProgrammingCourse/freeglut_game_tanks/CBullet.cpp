#include "CBullet.h"

#include <GL/freeglut.h>
#include <cmath>

void CBullet::Draw(void)
{
	if (!this->flagHidden)
	{
		glPushMatrix();

		glTranslated(this->position.x, this->position.y, this->position.z);

		glColor3d(this->objectColour.red, this->objectColour.green, this->objectColour.blue);
		// draw the bullet
		glPushMatrix();
		this->DrawCircle(this->size);
		glPopMatrix();

		glPopMatrix();
	}
}

void CBullet::Fire(SPosition startingPosition, double initialVelocity, double angle)
{
	this->Fire(
		startingPosition.x,
		startingPosition.y,
		startingPosition.z,
		initialVelocity,
		angle
		);
}

void CBullet::Fire(double startinX, double startingY, double startingZ, double initialVelocity, double angle)
{
	this->SetPosition(startinX, startingY, startingZ);

	this->vX = initialVelocity * std::cos(this->DegreesToRadians(angle));
	this->vY = initialVelocity * std::sin(this->DegreesToRadians(angle));
}

void CBullet::Fly(double gravityAcceleration, double timeInMs)
{
	double dt = timeInMs / 1000;
	// some magic division to make falling a little bit slower
	double g = gravityAcceleration / 2;

	// TODO: 
	// currently this is the movement with constant velocity (in dt time) with velocity update
	// (s = current_v *dt)
	this->Move(vX*dt, vY*dt, 0.0);
	// while it should be movement with constant acceleration
	// (s = 1/2*a*dt^2 + v0*dt)
	//this->Move(vX*dt, 1.0 / 2.0 * g*dt*dt + Vy0*dt);
	// it requires storing the starting Vy velocity

	// update vertical velocity
	this->vY = this->vY - (g * dt);
}