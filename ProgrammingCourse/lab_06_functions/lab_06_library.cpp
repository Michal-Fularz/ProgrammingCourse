#include "lab_06_library.h"
#include <string.h>

int count_vowels(char* text)
{
	int number_of_vowels = 0;
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] == 'a' || text[i] == 'e' ||
			text[i] == 'i' ||
			text[i] == 'o' ||
			text[i] == 'u' ||
			text[i] == 'y')
		{
			number_of_vowels++;
		}
	}

	return number_of_vowels;
}

void increase_all(int &a, int &b, int &c, int how_much)
{
	a += how_much;
	b += how_much;
	c += how_much;
}