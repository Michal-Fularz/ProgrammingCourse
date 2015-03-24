#ifndef __CObiekt_h_
#define __CObiekt_h_

typedef struct
{
	double red;
	double green;
	double blue;
}SKolor;

class CObiekt
{
protected:
	SKolor kolor;
	bool ukryty;
	double translacja[3];
	double rotacja[3];

public:
	CObiekt()
	{
		translacja[0] = 0.0;
		translacja[1] = 0.0;
		translacja[2] = 0.0;
		rotacja[0] = 0.0;
		rotacja[1] = 0.0;
		rotacja[2] = 0.0;

		ukryty = false;

		kolor.red = 1.0;
		kolor.green = 0.0;
		kolor.blue = 0.0;
	}
	virtual void Rysuj() = 0;
	void Ukryj();
	void Pokaz();
	void Przesun(double dX, double dY, double dZ);
	void UstawPozycje(double x, double y, double z);
	void Obroc(double rotX, double rotY, double rotZ);
	void UstawKolor(double red, double green, double blue);
	double GetX(void);
	double GetY(void);
	double GetZ(void);
};

#endif __CObiekt_h_