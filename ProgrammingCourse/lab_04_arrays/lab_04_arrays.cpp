#include <stdio.h>
#include <iostream>
#include <conio.h>

int main(void)
{
	// students ids
	int students_ids[5];

	std::cout << "Provide " << 5 << "students ids:" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		std::cin >> students_ids[i];
	}
	std::cout << "Students ids:" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << students_ids[i] << std::endl;
	}
	std::cout << "Even students ids:" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		if (students_ids[i] % 2 ==0)
		{
			std::cout << students_ids[i] << std::endl;
		}
	}
	std::cout << "Every second students id:" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		if (i % 2 == 0)
		{
			std::cout << students_ids[i] << std::endl;
		}
	}
	std::cout << "Average student id:" << std::endl;
	int sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		sum += students_ids[i];
	}
	std::cout << (float)sum / 5 << std::endl;


	const int name_size = 20;
	char name[name_size];

	std::cout << "Provide your name:";
	std::cin >> name;

	for (int i = 0; i < name_size; ++i)
	{
		//std::cout << "character: " << name[i] << "integer: " << name[i] << std::endl;
		printf("character: %c, integer: %d\n", name[i], name[i]);
	}

	std::cout << name << " is a hax0r" << std::endl;

	// lowercase <-> uppercase
	// difference between upper and lower letters
	int difference_lower_upper = 'a' - 'A'; // 'a' - 'A' = 32
	// for each character:
	for (int i = 0; i < strlen(name); ++i)
	{
		// check if lowercase
		if (name[i] >= 'a' && name[i] <= 'z')
		{
			name[i] -= difference_lower_upper;
		}
		else if (name[i] >= 'A' && name[i] <= 'Z')
		{
			name[i] += difference_lower_upper;
		}
	}
	std::cout << "After lower<->upper conversion: " << name << std::endl;

	// prepare filenames for loading files, use following format:
	// filename_X.txt
	// where X is number (e.g. 0-100)
	for (int i = 0; i < 20; ++i)
	{
		char current_filename[20];
		sprintf(current_filename, "file_%d.txt", i);
		std::cout << current_filename << std::endl;
	}

	std::cout << "Press any key to finish." << std::endl;
	_getch();

	return 0;
}