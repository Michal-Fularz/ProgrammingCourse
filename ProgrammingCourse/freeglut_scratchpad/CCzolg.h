#ifndef __CCzolg_h_
#define __CCzolg_h_

#include "CObject.h"

class CCzolg : public CObiekt
{
	private:
		double katObrotuLufy;

	public:
		CCzolg(void);
		~CCzolg(void);
		void Rysuj(void);
		void ObrocLufe(double dKatLufy);
		void UstawLufe(double katLufy);
		double GetKatLufy(void);
};

#endif __CCzolg_h_