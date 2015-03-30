#include "CBullet.h"

#include <GL/freeglut.h>

void CBullet::Draw(void)
{
	glPushMatrix();
	glTranslated(this->position.x, this->position.y, this->position.z);

	glPushMatrix();
	// draw the base
	glColor3d(this->objectColour.red, this->objectColour.green, this->objectColour.blue);
	DrawRectangle(this->bulletWidth, this->bulletHeight);
	glPopMatrix();

	glPopMatrix();
}