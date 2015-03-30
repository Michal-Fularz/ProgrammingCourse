#ifndef CTANK_H
#define CTANK_H

#include "CObject.h"

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

		this->barrelAngle = 90.0;
	}

	void Draw(void);

	// example hot to create methods that safely change the parameters and are easy to mantain
	// method for rotating the barrel is using the Set method which do all the checking
	void RotateBarrel(double dBarrelAngle);

	void SetBarrelAngle(double newBarrelAngle);
};

#endif