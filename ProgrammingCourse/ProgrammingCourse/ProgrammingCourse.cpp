#include <stdio.h>
#include <conio.h>

#include <iostream>

void Problem_CinGetline(void)
{
	std::cout << "cin.getlin() problem" << std::endl;

	char sign;
	std::cout << "Enter a sign" << std::endl;
	std::cin >> sign;
	std::cout << "Enter a sentence" << std::endl;
	const int sentenceSize = 20;
	char sentence[sentenceSize];
	// to work properly this program require the line below:
	//std::cin.ignore(100, '\n');
	std::cin.getline(sentence, sentenceSize);

	// detailed problem desciption and solution
	// http://mathbits.com/MathBits/CompSci/APstrings/APgetline.htm

	_getch();
}

/*
Funkcja g³ówna programu
o nazwie main
*/
int main(void)
{
	int liczbaNiedostatecznych;
	float sredniaOcen;

	printf("Hello world!\n");

	printf("Planowana liczba ocen 2.0:\n");
	scanf("%d", &liczbaNiedostatecznych);

	printf("Podaj planowana srednia:\n");
	scanf("%f", &sredniaOcen);

	printf("Nazywam sie Michal Fularz i jestem asystentem.\n");
	printf("W tym roku planuje wstawic %x ocen 2.0!\n", liczbaNiedostatecznych);
	printf("A srednia bedzie wynosic: %f!\n", sredniaOcen);

	// czekaj na znak
	_getch();

	Problem_CinGetline();

	return 1;
}
