#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

int main(void)
{
	/*
	int wzrost_w_cm = 0;
	float wzrost_w_m = 0.0;

	printf("Podaj wzrost w cm: ");
	scanf("%d", &wzrost_w_cm);
	printf("Mierzysz: %d cm.\n", wzrost_w_cm);

	std::cout << "Podaj wzrost w m: ";
	std::cin >> wzrost_w_m;
	std::cout << "Mierzysz " << wzrost_w_m << " m." << std::endl;

	int sumaWzrostow = wzrost_w_cm + wzrost_w_m * 100;
	// zmienna typu int dzielona przez zmienn� typu int daje wynik typu int
	// stosowane jest dzielenie bez reszty, np.
	// 190 podzielone bez reszty przez 100 = 1
	// aby to poprawi� nale�y potraktowa� jeden z element�w operacji jako zmienn� typu float poprzez rzutowanie
	float roznicaWzrostow = (float)wzrost_w_cm / 100 - wzrost_w_m;
	
	std::cout << "Razem mierzycie: " << sumaWzrostow << " cm." << std::endl;
	std::cout << "Pierwsza osoba jest wyzsza / nizsza o: " << roznicaWzrostow << " m." << std::endl;
	*/

	/*
	srand(time(NULL));

	// operator modulo % (reszta z dzielenia)
	// warto�ci losowe z zakresu 0 - 9
	// warto�ci losowe z zakresu 3 - 5
	// warto�ci losowe z zakresu -10 - 10
	// warto�ci losowe ze zbioru {0, 5, 10, 15}

	std::cout << rand() << std::endl;
	std::cout << rand() << std::endl;
	std::cout << rand() << std::endl;
	std::cout << rand() << std::endl;
	std::cout << rand() << std::endl;
	*/

	int kat_w_stopniach = 0;
	std::cout << "Podaj kat w stopniach: ";
	std::cin >> kat_w_stopniach;

	float kat_w_radianach = 2 * 3.14159 * (float)kat_w_stopniach / 360;

	float wartosc_sinus = sin(kat_w_radianach);
	std::cout << "Sinus kata " << kat_w_stopniach << " wynosi: " << wartosc_sinus << std::endl;


	_getch();

	return 0;
}