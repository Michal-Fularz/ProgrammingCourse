#ifndef __CPocisk_h_
#define __CPocisk_h_

#include "CObject.h"

class CPocisk : public CObiekt
{
private:
	double predkoscX;
	double predkoscY;
	bool wystrzelony;

public:
	CPocisk(void);
	~CPocisk(void);
	void Rysuj(void);
	void Wystrzel(double kat, double sila, double x, double y, double z);
	void Lec(void);
	void Resetuj(void);
};

#endif __CPocisk_h_