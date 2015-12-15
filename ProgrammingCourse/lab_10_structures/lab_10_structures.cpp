#include <stdio.h>
#include <iostream>
#include <conio.h>

struct Student
{
	char first_name[20];
	char last_name[20];
	int id;
	int computer_science_grade;

	// it is possible to nest one structure in another - structures are just new types (albeit a little bit more complex)
};

void print_student(const Student& s)
{
	std::cout << "Student: " << s.first_name;
	std::cout << " " << s.last_name;
	std::cout << ", id: " << s.id << " grades: " << std::endl;
	std::cout << "computer science: " << s.computer_science_grade << std::endl;
}

void fill_student(Student& s)
{
	std::cout << "Provide first name: ";
	std::cin >> s.first_name;
	std::cout << "Provide last name: ";
	std::cin >> s.last_name;
	std::cout << "Provide id: ";
	std::cin >> s.id;
	std::cout << "Provide computer science grade: ";
	std::cin >> s.computer_science_grade;
}

void sort_students_by_grade(Student* students, int number_of_students)
{
	for (int i = 0; i < number_of_students; ++i)
	{
		for (int j = 0; j < number_of_students; ++j)
		{
			if (students[j].computer_science_grade > students[j + 1].computer_science_grade)
			{
				std::swap(students[j], students[j + 1]);
			}
		}
	}
}

int main(void)
{
	Student example_student;
	
	fill_student(example_student);
	print_student(example_student);

	const int number_of_students = 5;
	Student students[number_of_students];

	for (int i = 0; i < number_of_students; i++)
	{
		std::cout << "Fill student nr " << i << std::endl;
		fill_student(students[i]);
	}

	sort_students_by_grade(students, number_of_students);

	std::cout << "Students:" << std::endl;
	for (int i = 0; i < number_of_students; i++)
	{
		print_student(students[i]);
	}

	std::cout << "Press any key to finish." << std::endl;
	_getch();

	return 0;
}