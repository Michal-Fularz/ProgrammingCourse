#ifndef CBULLET_H
#define CBULLET_H

#include "CObject.h"

class CBullet : public CObject
{
private:
	double size;

	double vX;
	double vY;

public:
	CBullet(double _bulletSize)
		// default red colour
		: CObject(SColour(1.0, 0.0, 0.0))
	{
		this->size = _bulletSize;

		this->vX = 0.0;
		this->vY = 0.0;
	}

	CBullet(double _bulletSize, SColour colour)
		: CObject(colour)
	{
		this->size = _bulletSize;

		this->vX = 0.0;
		this->vY = 0.0;
	}

	void Draw(void);

	void Fire(SPosition startingPosition, double initialVelocity, double angle);

	void Fire(double startinX, double startingY, double startingZ, double initialVelocity, double angle);

	void Fly(double gravityAcceleration, double timeInMs);
};

#endif