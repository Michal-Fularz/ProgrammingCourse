#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "lab_06_library.h"

int main(void)
{
	// task 1 - write function that count number of vowels in provided text
	std::cout << "Number of vowels: " << count_vowels("abcdefghijkl") << std::endl;

	// task 2 - create library header (*.h) file and move there the declaration of count_vowels function
	// task 3 - create libarry source (*.cpp) file and move there the definition of count_vowels function

	// task 4 - write increase_all function that increases all (3) provided arguments by the fourth argument. Place this function in you library file.
	int a = 1;
	int b = 2;
	int c = 3;
	std::cout << "Before: a: " << a << ", b: " << b << ", c: " << c << std::endl;
	increase_all(a, b, c, 5);
	std::cout << "After: a: " << a << ", b: " << b << ", c: " << c << std::endl;

	std::cout << "Press any key to finish." << std::endl;
	_getch();

	return 0;
}