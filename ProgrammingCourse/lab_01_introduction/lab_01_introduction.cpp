// �adowanie bibliotek
#include <stdio.h>	// dla funkcji printf oraz scanf
#include <conio.h>	// dla funkcji _getch

int main(void)		// g��wna funkcja programu, od niej program startuje
{
	printf("Hello world!\n");	// wy�wietla dane na wyj�ciu standardowym
	printf("Zajecia numer 1");
	printf("\n");				// znak nowej linii
	printf("Ale trudne!\n");

	// zapytaj u�ytkownika o wiek i go wy�wietl

	int wiekUzytkownika = 0;	// int -> integer -> zmienna przechowuj�ca warto�ci ca�kowite

	printf("Podaj wiek: ");	// TODO: zapytaj o wiek
	scanf("%d", &wiekUzytkownika);	// TODO: pobierz wiek
	printf("Wiek uzytkownika to: %d\n", wiekUzytkownika);	// TODO: wy�wietl wiek

	// wyznacz ile lat b�dzie mia� u�ytkownik w roku 2050
	printf("W roku 2050 bedziesz mial: %d lat\n", (2050 - 2015) + wiekUzytkownika);

	// zapytaj u�ytkownika o wiek, dla kt�rego chce policzy� liczb� swoich lat
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

	return 1;		// zwr�� 1
}