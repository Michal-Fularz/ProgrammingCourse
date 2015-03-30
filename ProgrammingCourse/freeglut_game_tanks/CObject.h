#ifndef COBJECT_H
#define COBJECT_H

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

class CObject
{
protected:
	SPosition position;
	SColour objectColour;

	bool flagHidden;

	void DrawRectangle(double width, double height);
	void DrawCircle(double radius);

public:
	CObject(void)
	{
		// green object
		this->objectColour.red = 0.0;
		this->objectColour.green = 1.0;
		this->objectColour.blue = 0.0;

		// initial position
		this->position.x = 0.0;
		this->position.y = 0.0;
		this->position.z = 0.0;

		this->flagHidden = false;
	}

	virtual void Draw(void) = 0;

	void SetPosition(SPosition newPosition)
	{
		this->SetPosition(
			newPosition.x,
			newPosition.y,
			newPosition.z
			);
	}

	void SetPosition(double newX, double newY, double newZ)
	{
		// put any constraints if needed
		// example: if (newX > 0 && newX < 10)
		this->position.x = newX;
		this->position.y = newY;
		this->position.z = newZ;
	}

	void Move(double dX, double dY, double dZ)
	{
		this->SetPosition(
			this->position.x + dX,
			this->position.y + dY,
			this->position.z + dZ
			);
	}
};

#endif