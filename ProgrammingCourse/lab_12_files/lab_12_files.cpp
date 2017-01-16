#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

void ex_1()
{
	std::fstream file;
	file.open("..//_data//file_ex1.txt", std::ios::in);

	if (file.is_open())
	{
		std::cout << "File opened correctly!" << std::endl;

		int intValue;
		float floatValue;
		std::string firstWord;
		std::string secondWord;

		file >> intValue >> floatValue >> firstWord >> secondWord;

		std::cout << intValue << ", " << floatValue << ", " << firstWord << ", " << secondWord << std::endl;
	}
	else
	{
		std::cout << "ERROR! File not found!" << std::endl;
	}

	file.close();
}

void ex_2()
{
	std::fstream file_to_load("..//_data//file_ex2_load.txt", std::ios::in);

	std::vector<std::string> words;
	if (file_to_load.is_open())
	{
		std::string line;
		while (!file_to_load.eof())
		{
			getline(file_to_load, line);
			std::cout << "Read from file: " << line << std::endl;
			words.push_back(line);
		}
	}
	else
	{
		std::cout << "ERROR! File not found!" << std::endl;
	}

	file_to_load.close();

	std::fstream file_to_save("..//_data//file_ex2_save.txt", std::ios::out);

	for (auto ritr = words.rbegin(); ritr != words.rend(); ritr++)
	{
		file_to_save << *ritr << std::endl;
	}

	file_to_save.close();
}

struct Student
{
	std::string firstName;
	std::string lastName;
	float grade;
};

bool compareStudents(const Student& s1, const Student& s2)
{
	if (s1.grade < s2.grade)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ex_3()
{
	std::fstream file_to_load("..//_data//students.txt", std::ios::in);

	std::vector<Student> students;
	if (file_to_load.is_open())
	{
		std::string line;
		while (!file_to_load.eof())
		{
			getline(file_to_load, line);
			std::cout << "Read from file: " << line << std::endl;
			// parse the line using stringstream
			std::stringstream ss(line);
			Student newStudent;
			ss >> newStudent.firstName >> newStudent.lastName >> newStudent.grade;
			students.push_back(newStudent);
		}
	}
	else
	{
		std::cout << "ERROR! File not found!" << std::endl;
	}

	file_to_load.close();

	std::sort(students.begin(), students.end(), compareStudents);
	for (auto itr = students.begin(); itr < students.end(); itr++)
	{
		std::cout << (*itr).firstName << " " << (*itr).lastName << ": " << (*itr).grade << std::endl;
	}
}

int main(void)
{
	//ex_1();
	ex_2();
	//ex_3();


	return 1;
}