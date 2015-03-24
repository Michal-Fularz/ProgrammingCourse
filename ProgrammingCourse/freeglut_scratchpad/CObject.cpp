#include "CObject.h"

void CObiekt::Ukryj()
{
	ukryty = true;
}

void CObiekt::Pokaz()
{
	ukryty = false;
}

void CObiekt::Przesun(double dX, double dY, double dZ)
{
	translacja[0] += dX;
	translacja[1] += dY;
	translacja[2] += dZ;
}

void CObiekt::UstawPozycje(double x, double y, double z)
{
	translacja[0] = x;
	translacja[1] = y;
	translacja[2] = z;
}

void CObiekt::Obroc(double rotX, double rotY, double rotZ)
{
	rotacja[0] += rotX;
	rotacja[1] += rotY;
	rotacja[2] += rotZ;
}

void CObiekt::UstawKolor(double red, double green, double blue)
{
	kolor.red = red;
	kolor.green = green;
	kolor.blue = blue;
}

double CObiekt::GetX(void)
{
	return this->translacja[0];
}

double CObiekt::GetY(void)
{
	return this->translacja[1];
}

double CObiekt::GetZ(void)
{
	return this->translacja[2];
}


