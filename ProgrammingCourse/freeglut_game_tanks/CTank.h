#ifndef CTANK_H
#define CTANK_H

#include "CObject.h"
#include <cmath>

class CTank : public CObject
{
private:
	SColour tankColour;
	SColour barrelColour;

	double tankWidth;
	double tankHeight;
	double barrelWidth;
	double barrelHeight;

	double barrelAngle;
	double bulletPower;

public:
	CTank(double _tankWidth, double _tankHeight, double _barrelWidth, double _barrelHeight)
		: CObject()
	{
		this->tankWidth = _tankWidth;
		this->tankHeight = _tankHeight;
		this->barrelWidth = _barrelWidth;
		this->barrelHeight = _barrelHeight;
		// default object colour tank
		this->tankColour.red = this->objectColour.red;
		this->tankColour.green = this->objectColour.green;
		this->tankColour.blue = this->objectColour.blue;
		// black barrel
		this->barrelColour.red = 0.0;
		this->barrelColour.green = 0.0;
		this->barrelColour.blue = 0.0;

		this->barrelAngle = 0.0;
	}

	void Draw(void);

	// example hot to create methods that safely change the parameters and are easy to mantain
	// method for rotating the barrel is using the Set method which do all the checking
	void RotateBarrel(double dBarrelAngle);

	void SetBarrelAngle(double newBarrelAngle);

	void ChangeBulletPower(double dBulletPower)
	{
		this->SetBulletPower(this->GetBulletPower() + dBulletPower);
	}

	void SetBulletPower(double newBulletPower)
	{
		if (newBulletPower >= 0 && newBulletPower < 10)
		{
			this->bulletPower = newBulletPower;
		}
	}

	double GetBarrelAngle(void)
	{
		return this->barrelAngle;
	}

	double GetBulletPower(void)
	{
		return this->bulletPower;
	}

	SPosition GetPosition(void)
	{
		return this->position;
	}

	SPosition GetEndOfBarrelPosition(void)
	{
		SPosition endOfBarrel;
		endOfBarrel.x = this->position.x + this->barrelWidth * cos(3.14 / 180 * this->barrelAngle);
		endOfBarrel.y = this->position.y + this->barrelWidth * sin(3.14 / 180 * this->barrelAngle);
		endOfBarrel.z = 0.0;

		return endOfBarrel;
	}
};

#endif