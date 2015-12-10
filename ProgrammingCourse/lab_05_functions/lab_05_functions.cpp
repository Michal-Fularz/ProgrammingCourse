#include <stdio.h>
#include <iostream>
#include <conio.h>

// exercise 1
// write function subtract
int subtract(int a, int b);

// exercise 2
// write function swap
void swap(int &a, int &b);

// exercise 3
// write average function for array
float average(int* arr, int size);

// exercise 4
// write sort function that uses swap
void sort(int* arr, int arr_size);

// exercise 5
// write function that swap each provided sign to other provided sign
void convert(char* text, char sign_searched, char sign_new);

// exercise 6
// write mix function that mixes two strings
// exam, fail -> exil, faam


int main(void)
{
	std::cout << "subtract(5, 3): " << subtract(5, 3) << std::endl;

	int a = 5;
	int b = 3;

	std::cout << "Before swap: a: " << a << ", b: " << b << std::endl;
	swap(a, b);
	std::cout << "After swap: a: " << a << ", b: " << b << std::endl;

	const int arr_size = 5;
	int arr[arr_size];
	std::cout << "Array: ";
	for (int i = 0; i < arr_size; ++i)
	{
		arr[i] = i;
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;

	std::cout << "Average: " << average(arr, arr_size) << std::endl;

	sort(arr, arr_size);
	std::cout << "Array sorted: ";
	for (int i = 0; i < arr_size; ++i)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;

	char text[] = "aabbaacc";
	convert(text, 'a', 'x');
	std::cout << "convert(\"aabbaacc\", 'a', 'x'): " << text << std::endl;

	std::cout << "Press any key to finish." << std::endl;
	_getch();

	return 0;
}

int subtract(int a, int b)
{
	return (a - b);
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

float average(int* arr, int size)
{
	float sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	return (sum / size);
}

void sort(int* arr, int arr_size)
{
	for (int i = 0; i < arr_size; ++i)
	{
		for (int j = 0; j < (arr_size - 1); ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void convert(char* text, char sign_searched, char sign_new)
{
	for (int i = 0; i < strlen(text); ++i)
	{
		if (text[i] == sign_searched)
		{
			text[i] = sign_new;
		}
	}
}
