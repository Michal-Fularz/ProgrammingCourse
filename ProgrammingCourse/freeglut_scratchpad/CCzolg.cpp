#include "CCzolg.h"
#include <GL/freeglut.h>

CCzolg::CCzolg() : CObiekt()
{
	this->katObrotuLufy = 0.0;
}

CCzolg::~CCzolg()
{
}

void CCzolg::Rysuj()
{
	double w = 0.4;
	double h = 0.2;

	if (this->ukryty != true)
	{


		// pamiêtaæ o wciêciach przy push/pop - ³atwiej znaleŸæ brakuj¹ce
		glPushMatrix();
		{
			glTranslated(this->translacja[0], this->translacja[1], this->translacja[2]);
			glRotated(this->rotacja[0], 1.0, 0.0, 0.0);
			glRotated(this->rotacja[1], 0.0, 1.0, 0.0);
			glRotated(this->rotacja[2], 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);
			glPushMatrix();
			{
				glRotated(this->katObrotuLufy, 0.0, 0.0, 1.0);
				glBegin(GL_POLYGON);
				{
					glVertex3d(0.0, h / 4, 0);
					glVertex3d(w*1.5, h / 4, 0);
					glVertex3d(w*1.5, -h / 4, 0);
					glVertex3d(0.0, -h / 4, 0);
				}
				glEnd();
			}
			glPopMatrix();

			glColor3d(this->kolor.red, this->kolor.green, this->kolor.blue);
			glPushMatrix();
			{
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
			}
		}
		glPopMatrix();
	}
}

void CCzolg::ObrocLufe(double dKatLufy)
{
	if ((this->katObrotuLufy + dKatLufy) <= 180 && (this->katObrotuLufy + dKatLufy) >= 0)
	{
		this->katObrotuLufy = this->katObrotuLufy + dKatLufy;
	}
}

void CCzolg::UstawLufe(double katLufy)
{
	if (katLufy < 180 && katLufy > 0)
	{
		this->katObrotuLufy = katLufy;
	}
}

double CCzolg::GetKatLufy(void)
{
	return this->katObrotuLufy;
}