#ifndef CBULLET_H
#define CBULLET_H

#include "CObject.h"
#include <cmath>

class CBullet : public CObject
{
private:
	double size;

	double vX;
	double vY;

public:
	CBullet(double _bulletSize)
		: CObject()
	{
		this->size = _bulletSize;
	}

	void Draw(void);

	void Fire(double power, double angle);

	void Fly(double gravityAcceleration, double timeInMs);
};

#endif