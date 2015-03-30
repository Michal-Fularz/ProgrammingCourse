#ifndef CBULLET_H
#define CBULLET_H

#include "CObject.h"

class CBullet : public CObject
{
private:

	double bulletWidth;
	double bulletHeight;

public:
	CBullet(double _bulletWidth, double _bulletHeight)
		: CObject()
	{
		this->bulletWidth = _bulletWidth;
		this->bulletHeight = _bulletHeight;
	}

	void Draw(void);
};

#endif