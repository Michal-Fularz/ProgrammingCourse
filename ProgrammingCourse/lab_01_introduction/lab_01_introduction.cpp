// ³adowanie bibliotek
#include <stdio.h>	// dla funkcji printf oraz scanf
#include <conio.h>	// dla funkcji _getch

int main(void)		// g³ówna funkcja programu, od niej program startuje
{
	printf("Hello world!\n");	// wyœwietla dane na wyjœciu standardowym
	printf("Zajecia numer 1");
	printf("\n");				// znak nowej linii
	printf("Ale trudne!\n");

	// zapytaj u¿ytkownika o wiek i go wyœwietl

	int wiekUzytkownika = 0;	// int -> integer -> zmienna przechowuj¹ca wartoœci ca³kowite

	printf("Podaj wiek: ");	// TODO: zapytaj o wiek
	scanf("%d", &wiekUzytkownika);	// TODO: pobierz wiek
	printf("Wiek uzytkownika to: %d\n", wiekUzytkownika);	// TODO: wyœwietl wiek

	// wyznacz ile lat bêdzie mia³ u¿ytkownik w roku 2050
	printf("W roku 2050 bedziesz mial: %d lat\n", (2050 - 2015) + wiekUzytkownika);

	// zapytaj u¿ytkownika o wiek, dla którego chce policzyæ liczbê swoich lat
	printf("Podaj rok, ktorym jestes zainteresowany: ");
	int rok = 0;
	scanf("%d", &rok);
	printf("W roku %d bedziesz mial: %d lat\n", rok, (rok - 2015) + wiekUzytkownika);

	/*
	Komentarz
	dla
	kilku
	linii
	*/

	_getch();		// czekaj na znak (= get character)

	return 1;		// zwróæ 1
}