#include <stdio.h>
#include <iostream>
#include <conio.h>

#include <vector>
#include <list>

#include <string>

#include <algorithm>

void two_dimensional_array(void)
{
	// We start with declaring the object that will hold the data (two dimensional array) - vector of vectors
	std::vector<std::vector<int> > v_2d;
	int number_of_rows = 5;
	int number_of_cols = 5;
	for (int i = 0; i < number_of_rows; i++)
	{
		// after that we iterate over number of rows and create a new vector for each row  
		std::vector<int> v_row;
		// finally we fill the row with values
		for (int j = 0; j < number_of_cols; j++)
		{
			v_row.push_back(10 * i + j);
		}
		// and add the row to the main vector
		v_2d.push_back(v_row);
	}
	// vector elements can be accessed by [] operator
	std::cout << "Row 2, column 3: " << v_2d[2][3] << std::endl;
}

void strings(void)
{
	// create some strings
	std::string s1 = "Hello";
	std::string s2 = "world";
	// and print them
	std::cout << s1 << " " << s2 << "!" << std::endl;
	// it is possible to concatenate them
	std::string s3 = s1 + " " + s2 + "!";
	std::cout << s3 << std::endl;

	std::string s_from_user;
	std::getline(std::cin, s_from_user);      // provided text can contain spaces
	std::cout << "Text from user: " << s_from_user << std::endl;

	std::string word_from_user;
	std::cout << "Guess the lacking word: one, two, ..." << std::endl;
	std::getline(std::cin, word_from_user);
	// check if the length is appropriate
	if (word_from_user.length() != 5)
	{
		std::cout << "Your word is of wrong length" << std::endl;
	}
	else if (word_from_user == "three")
	{
		std::cout << "You guessed right!" << std::endl;
	}
	// access third letter in string using random access ([]) operator
	std::cout << "Third letter is: " << word_from_user[2] << std::endl;
	// iterate over string
	for (std::string::iterator itr = word_from_user.begin(); itr != word_from_user.end(); ++itr)
	{
		if (*itr == 'e')    // this time we compare char values so '' are required!
		{
			std::cout << "Letter e found" << std::endl;
		}
	}
}

void vector_sorting(void)
{
	std::vector<int> collection;
	for (int i = 0; i<10; i++)
	{
		collection.push_back(rand() % 100);
	}
	std::cout << std::endl << "Collection before sorting : " << std::endl;
	for (auto itr = collection.begin(); itr != collection.end(); itr++)
	{
		std::cout << *itr << ", ";
	}
	std::sort(collection.begin(), collection.end());        
	std::cout << std::endl << "Collection after sorting : " << std::endl;
	for (auto itr = collection.begin(); itr != collection.end(); itr++)
	{
		std::cout << *itr << ", ";
	}
}

void list_sorting(void)
{
	std::list<int> collection;
	for (int i = 0; i<10; i++)
	{
		collection.push_back(rand() % 100);
	}
	std::cout << std::endl << "Collection before sorting : " << std::endl;
	for (auto itr = collection.begin(); itr != collection.end(); itr++)
	{
		std::cout << *itr << ", ";
	}
	collection.sort();   
	std::cout << std::endl << "Collection after sorting : " << std::endl;
	for (auto itr = collection.begin(); itr != collection.end(); itr++)
	{
		std::cout << *itr << ", ";
	}
}

struct Student
{
	std::string first_name;
	std::string last_name;
	int computer_science_grade;
};

bool compare_students_grades(Student s1, Student s2)
{
	if (s1.computer_science_grade >= s2.computer_science_grade)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void structures(void)
{
	// somewhere in the main function
	std::vector<Student> air_students;
	Student student_new;
	student_new.first_name = "Geralt";
	student_new.last_name = "of Rivii";
	student_new.computer_science_grade = 6;
	air_students.push_back(student_new);

	for (int i = 0; i < 10; i++)
	{
		Student student_new;
		student_new.first_name = 'a' + i;
		student_new.last_name = 'z' - i;
		student_new.computer_science_grade = rand() % 4 + 2;
		air_students.push_back(student_new);
	}

	// this example assumes, that Student structure exists and the collection (vector) of it exists under name air_students
	std::cout << std::endl << "AiR students before sorting : " << std::endl;
	for (auto itr = air_students.begin(); itr != air_students.end(); itr++)
	{
		// access using . operator
		std::cout << (*itr).first_name << " " << (*itr).last_name << ": " << (*itr).computer_science_grade << std::endl;
	}
	std::sort(air_students.begin(), air_students.end(), compare_students_grades);        // for list use collection.sort()
	std::cout << std::endl << "AiR students after sorting : " << std::endl;
	for (auto itr = air_students.begin(); itr != air_students.end(); itr++)
	{
		// access using -> operator for pointer
		std::cout << itr->first_name << " " << itr->last_name << ": " << itr->computer_science_grade << std::endl;
	}
}

int main(void)
{
	//two_dimensional_array();
	//std::cout << std::endl;

	strings();
	std::cout << std::endl;

	vector_sorting();
	std::cout << std::endl;

	list_sorting();
	std::cout << std::endl;

	structures();
	std::cout << std::endl;


	std::cout << "Press any key to finish." << std::endl;
	_getch();

	return 0;
}