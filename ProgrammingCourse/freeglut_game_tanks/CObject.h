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

	SColour()
	{
		this->red = 0.0;
		this->green = 0.0;
		this->blue = 0.0;
	}

	SColour(double r, double g, double b)
	{
		this->red = r;
		this->green = g;
		this->blue = b;
	}
};

class CObject
{
protected:
	SPosition position;
	SColour objectColour;

	bool flagHidden;

	// to make code more robust, the PI used is declared here
	static const double PI;

	void DrawRectangle(double width, double height);
	void DrawCircle(double radius);

	inline double DegreesToRadians(double degrees)
	{
		return (CObject::PI / 180.0 * degrees);
	}

public:

	CObject(SColour colour)
	{
		this->objectColour = colour;

		// initial position
		this->position.x = 0.0;
		this->position.y = 0.0;
		this->position.z = 0.0;

		this->flagHidden = false;
	}

	virtual void Draw(void) = 0;

	inline void SetPosition(SPosition newPosition)
	{
		this->SetPosition(
			newPosition.x,
			newPosition.y,
			newPosition.z
			);
	}

	inline void SetPosition(double newX, double newY, double newZ)
	{
		// put any constraints if needed
		// example: if (newX > 0 && newX < 10)
		this->position.x = newX;
		this->position.y = newY;
		this->position.z = newZ;
	}

	inline void Move(double dX, double dY, double dZ)
	{
		this->SetPosition(
			this->position.x + dX,
			this->position.y + dY,
			this->position.z + dZ
			);
	}
};

#endif