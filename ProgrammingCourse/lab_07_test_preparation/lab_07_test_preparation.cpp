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

void Task_1_2016()
{
	const int maxTextLength = 20;
	char text1[maxTextLength], 
		text2[maxTextLength], 
		resultText[2*maxTextLength];

	std::cin >> text1 >> text2;

	// version 1
	{
		int resultTextIndex = 0;
		bool flagEndOfText1 = false;
		bool flagEndOfText2 = false;
		for (int i = 0; i < maxTextLength; i++)
		{
			if (text1[i] == '\0')
			{
				flagEndOfText1 = true;
			}
			if (text2[i] == '\0')
			{
				flagEndOfText2 = true;
			}

			if (!flagEndOfText1)
			{
				resultText[resultTextIndex] = text1[i];
				resultTextIndex++;
			}
			if (!flagEndOfText2)
			{
				resultText[resultTextIndex] = text2[i];
				resultTextIndex++;
			}
		}
		resultText[resultTextIndex] = '\0';

		std::cout << "Version 1: " << resultText << std::endl;
	}
	
	// version 2
	{
		int resultTextIndex = 0;
		int shorterTextLength = 0;
		int longerTextLength = 0;
		char* longerText;
		if (strlen(text1) < strlen(text2))
		{
			shorterTextLength = strlen(text1);
			longerTextLength = strlen(text2);
			longerText = text2;
		}
		else
		{
			shorterTextLength = strlen(text2);
			longerTextLength = strlen(text1);
			longerText = text1;
		}

		for (int i = 0; i < shorterTextLength; i++)
		{
			resultText[resultTextIndex] = text1[i];
			resultTextIndex++;
			resultText[resultTextIndex] = text2[i];
			resultTextIndex++;
		}
		for (int i = shorterTextLength; i < longerTextLength; i++)
		{
			resultText[resultTextIndex] = longerText[i];
			resultTextIndex++;
		}
		resultText[resultTextIndex] = '\0';

		std::cout << "Version 2: " << resultText << std::endl;
	}
}

void Task_2_2016()
{
	const int arraySize = 10;
	int values[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		values[i] = rand() % 10;
	}

	std::cout << "Before sorting:" << std::endl;
	print_array(values, arraySize);

	sort(values, arraySize);

	std::cout << "After sorting:" << std::endl;
	print_array(values, arraySize);

	std::cout << "Median value: " << median(values, arraySize) << std::endl;

}

void Task_3_2016()
{
	int liczba = 0;
	int doPotegi = 0;
	std::cout << "Podaj liczbe do potegi: " << std::endl;
	std::cin >> liczba;
	std::cout << "Podaj do jakiej potegi podniesc: " << std::endl;
	std::cin >> doPotegi;

	std::cout << "Wynik wynosi: " << potega(liczba, doPotegi) << std::endl;
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
		std::cout << "11 - task 1 2016" << std::endl;
		std::cout << "12 - task 2 2016" << std::endl;
		std::cout << "13 - task 3 2016" << std::endl;
		std::cout << "14 - task 4 2016" << std::endl;
		std::cout << "15 - task 5 2016" << std::endl;
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
			case 11:
				Task_1_2016();
				break;
			case 12:
				Task_2_2016();
				break;
			case 13:
				Task_3_2016();
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