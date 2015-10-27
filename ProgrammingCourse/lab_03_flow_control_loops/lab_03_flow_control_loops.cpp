#include <stdio.h>
#include <iostream>
#include <conio.h>

int main(void)
{
	int user_choice = -1;

	do
	{
		std::cout << "Choose your way:" << std::endl;
		std::cout << "1 - exercise 1" << std::endl;
		std::cout << "2 - exercise 2" << std::endl;
		std::cout << "0 - exit" << std::endl;
		std::cin >> user_choice;

		// TODO: wybór opcji

	} while (user_choice != 0);

	std::cout << "Press any key to finish." << std::endl;
	_getch();

	return 0;
}