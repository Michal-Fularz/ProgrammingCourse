#include "CPocisk.h"
#include <GL/freeglut.h>

// dla sin/cos i M_PI
#define _USE_MATH_DEFINES
#include <math.h>

CPocisk::CPocisk() : CObiekt()
{
	this->predkoscX = 0.0;
	this->predkoscY = 0.0;
	this->wystrzelony = false;
}

CPocisk::~CPocisk()
{
}

void CPocisk::Rysuj()
{
	double w = 0.1;
	double h = 0.1;

	if (this->ukryty != true)
	{
		// pamiêtaæ o wciêciach przy push/pop - ³atwiej znaleŸæ brakuj¹ce
		glPushMatrix();
			glTranslated(this->translacja[0], this->translacja[1], this->translacja[2]);
			glRotated(this->rotacja[0], 1.0, 0.0, 0.0);
			glRotated(this->rotacja[1], 0.0, 1.0, 0.0);
			glRotated(this->rotacja[2], 0.0, 0.0, 1.0);

			glColor3d(this->kolor.red, this->kolor.green, this->kolor.blue);
			glPushMatrix();
				glBegin(GL_POLYGON);
				{
					// kolejnoœæ ma znaczenie jeœli w³¹czona jest opcja GL_CULL_FACE
					glVertex3d(-w / 2, h / 2, 0);
					glVertex3d(w / 2, h / 2, 0);
					glVertex3d(w / 2, -h / 2, 0);
					glVertex3d(-w / 2, -h / 2, 0);
				}
				glEnd();
			glPopMatrix();
		glPopMatrix();
	}
}

void CPocisk::Wystrzel(double kat, double sila, double x, double y, double z)
{
	this->UstawPozycje(x, y, z);
	this->predkoscX = sila * cos(kat * M_PI / 180.0);
	this->predkoscY = sila * sin(kat * M_PI / 180.0);
	this->wystrzelony = true;
}

void CPocisk::Lec(void)
{
	if (wystrzelony)
	{
		this->Przesun(predkoscX, predkoscY, 0.0);
	}
}

void CPocisk::Resetuj(void)
{
	wystrzelony = false;
}