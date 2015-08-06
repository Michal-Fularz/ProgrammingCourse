#ifndef CTANK_H
#define CTANK_H

#include "CObject.h"
#include <cmath>

class CTank : public CObject
{
private:
	SColour barrelColour;

	double tankWidth;
	double tankHeight;
	double barrelWidth;
	double barrelHeight;

	double barrelAngle;
	double bulletPower;

public:
	CTank(SColour tankColour,
		double _tankWidth, double _tankHeight,
		SColour barrelColour, 
		double _barrelWidth, double _barrelHeight
		)
		: CObject(tankColour)
	{
		this->tankWidth = _tankWidth;
		this->tankHeight = _tankHeight;

		this->barrelColour = barrelColour;
		this->barrelWidth = _barrelWidth;
		this->barrelHeight = _barrelHeight;

		this->barrelAngle = 0.0;
		this->bulletPower = 0.0;
	}

	CTank(double _tankWidth, double _tankHeight, double _barrelWidth, double _barrelHeight)
		// default green tank colour
		: CObject(SColour(0.0, 1.0, 0.0))
	{
		this->tankWidth = _tankWidth;
		this->tankHeight = _tankHeight;

		// black barrel
		this->barrelColour = SColour(0.0, 0.0, 0.0);

		this->barrelWidth = _barrelWidth;
		this->barrelHeight = _barrelHeight;

		this->barrelAngle = 0.0;
		this->bulletPower = 0.0;
	}

	void Draw(void);

	// example hot to create methods that safely change the parameters and are easy to mantain
	// method for rotating the barrel is using the Set method which do all the checking
	inline void RotateBarrel(double dBarrelAngle)
	{
		this->SetBarrelAngle(this->barrelAngle + dBarrelAngle);
	}

	void SetBarrelAngle(double newBarrelAngle);

	inline void ChangeBulletPower(double dBulletPower)
	{
		this->SetBulletPower(this->GetBulletPower() + dBulletPower);
	}

	void SetBulletPower(double newBulletPower);

	inline double GetBarrelAngle(void)
	{
		return this->barrelAngle;
	}

	inline double GetBulletPower(void)
	{
		return this->bulletPower;
	}

	inline SPosition GetPosition(void)
	{
		return this->position;
	}

	SPosition GetEndOfBarrelPosition(void);
};

#endif