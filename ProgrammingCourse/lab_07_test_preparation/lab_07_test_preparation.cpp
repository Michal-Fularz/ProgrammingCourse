#include <iostream>
#include <conio.h>
#include <ctime>

#include "lab_07_library.h"

void Task1(void)
{
	bool flag_error = false;
	for (int i = 0; i < 100; ++i)
	{
		int a = rand() % 1000;
		int b = rand() % 20 + 1;

		int m1 = modulo_1(a, b);
		int m2 = modulo_2(a, b);
		int m3 = a % b;

		
		if (m1 != m3 || m2 != m3)
		{
			std::cout << "Error! Incorrect values!" << std::endl;
			std::cout << "a: " << a << ", b: " << b << std::endl;
			std::cout << "m1: " << m1 << ", m2: " << m2 << ", should be (%): " << m3 << std::endl;
			flag_error = true;
		}
	}
	
	if (!flag_error)
	{
		std::cout << "All modulo tests passed!" << std::endl;
	}
}

void Task2(void)
{
	std::cout << "Task 2" << std::endl;

	char text_from_user[50];
	std::cout << "Provide a text to process" << std::endl;
	std::cin.sync();
	std::cin.getline(text_from_user, 50);
	//strcpy(text_from_user, "A111la m2a kota 444 duzego. T5en spi6 wciaz");

	char letters_1[50];
	char letters_2[50];
	char digits[50];
	bool flag_dot_found = false;

	int letters_1_index = 0;
	int letters_2_index = 0;
	int digits_index = 0;

	for (int i = 0; i < strlen(text_from_user); ++i)
	{
		char current_sign = text_from_user[i];
		if (current_sign >= '0' && current_sign <= '9')
		{
			digits[digits_index] = current_sign;
			digits_index++;
		}
		else
		{
			if (flag_dot_found)
			{
				letters_2[letters_2_index] = current_sign;
				letters_2_index++;
			}
			else
			{
				if (current_sign == '.')
				{
					flag_dot_found = true;
				}
				else
				{
					letters_1[letters_1_index] = current_sign;
					letters_1_index++;
				}
			}
		}
	}
	letters_1[letters_1_index] = '\0';
	letters_2[letters_2_index] = '\0';
	digits[digits_index] = '\0';

	std::cout << "Text processed: " << std::endl;
	std::cout << "letters_1: " << letters_1 << std::endl;
	std::cout << "letters_2: " << letters_2 << std::endl;
	std::cout << "digits: " << digits << std::endl;
}

void Task3(void)
{
	std::cout << "Task 3" << std::endl;

	const int number_of_values = 20;
	int values[number_of_values];

	for (int i = 0; i < number_of_values; ++i)
	{
		values[i] = i;// rand() % 20;
	}

	std::cout << "average: " << calculate_average(values, number_of_values) << std::endl;
	std::cout << "standard deviation: " << calculate_standard_deviation(values, number_of_values) << std::endl;
}

int main(void)
{
	srand(time(NULL));

	int user_choice = -1;

	do
	{
		std::cout << std::endl << std::endl;
		std::cout << "Choose your way:" << std::endl;
		std::cout << "1 - task 1" << std::endl;
		std::cout << "2 - task 2" << std::endl;
		std::cout << "3 - task 3" << std::endl;
		std::cout << "0 - exit" << std::endl;
		std::cin >> user_choice;

		switch (user_choice)
		{
			case 1:
				Task1();
				break;
			case 2:
				Task2();
				break;
			case 3:
				Task3();
				break;
			case 0:
				break;
			default:
				std::cout << "Wrong value entered!" << std::endl;
		}

	} while (user_choice != 0);

	std::cout << "Press any key to finish." << std::endl;
	_getch();

	return 0;
}