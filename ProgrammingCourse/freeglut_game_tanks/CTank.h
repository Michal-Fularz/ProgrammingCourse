#ifndef CTANK_H
#define CTANK_H

struct SPosition
{
	double x;
	double y;
	double z;
};

struct SColour
{
	double red;
	double green;
	double blue;
};

class CTank
{
private:
	SPosition position;
	SColour tankColour;
	SColour barrelColour;

	double tankWidth;
	double tankHeight;
	double barrelWidth;
	double barrelHeight;

	double barrelAngle;

	void DrawRectangle(double width, double height);

public:
	CTank(double _tankWidth, double _tankHeight, double _barrelWidth, double _barrelHeight)
	{
		this->tankWidth = _tankWidth;
		this->tankHeight = _tankHeight;
		this->barrelWidth = _barrelWidth;
		this->barrelHeight = _barrelHeight;
		// green tank
		this->tankColour.red = 0.0;
		this->tankColour.green = 1.0;
		this->tankColour.blue = 0.0;
		// black barrel
		this->barrelColour.red = 0.0;
		this->barrelColour.green = 0.0;
		this->barrelColour.blue = 0.0;

		// initial position
		this->position.x = 0.0;
		this->position.y = 0.0;
		this->position.z = 0.0;

		this->barrelAngle = 90.0;
	}

	void Draw(void);

	// example hot to create methods that safely change the parameters and are easy to mantain
	// method for rotating the barrel is using the Set method which do all the checking
	void RotateBarrel(double dBarrelAngle);

	void SetBarrelAngle(double newBarrelAngle);
};

#endif