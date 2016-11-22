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

	// task 5 - game of war
	// subtask 1 - how to represent deck of cards (one colour?)
	// subtask 2 - create array that holds 13 cards (represent them as 2-14)
	// subtask 3 - randomize values in array (some of them will duplicate - how to solve it?
	// subtask 4 - add shuffle function - it takes an array and shuffles the values - randomly generate two indicies and swap values that are stored in the array under theses indices
	// subtask 5 - create a function play_war that compars two players decks and finds the winner (compared first card from deck 1 with first card with deck one, the higher card gets the player one point. Draws does not give any points.

	// int max(int* array, int arraySize);
	// void fillTableWithRandomValues(int* array, int arraySize, int valueMin=0, int valueMax=10);

	std::cout << "Press any key to finish." << std::endl;
	_getch();

	return 0;
}
