#include "MF_library.h"

#include <iostream>
using namespace std;

#include <stack>
#include <list>
#include <vector>

void showMenu(void)
{
	cout << endl << "MENU:" << endl;
	cout << "exercise 1 - press 1" << endl;
	cout << "exercise 2 - press 2" << endl;
	cout << "exercise 3 - press 3" << endl;
	cout << "exercise 4 - press 4" << endl;
	cout << "exercise 5 - press 5" << endl;
	cout << "exit - press x or X" << endl;
}

char chooseOption(void)
{
	char sign = 0;
	cout << "Choose option:\t";
	cin >> sign;
	return sign;
}

void exercise_1_prepare(void)
{
	FILE *file;
	// 3.14F - dodanie literki F likwiduje ostrze¿enie o konwersji z double na float
	// (informujemy kompilator, ¿e podawana sta³a jest typu float)
	SInputData inputData = { 10, 3.14F, true, 'x', "raz dwa trzy kolokwium robisz Ty" };
	file = fopen("data.bin", "wb");
	fwrite(&inputData, sizeof(SInputData), 1, file);
	fclose(file);
}

void exercise_1(void)
{
	FILE *file;
	SInputData inputData;
	file = fopen("data.bin", "r+b");
	fread(&inputData, sizeof(SInputData), 1, file);
	fclose(file);

	cout << "Data from file:" << endl << inputData.decimalValue << "\t" << inputData.floatingpointValue << "\t" << inputData.logicalValue << "\t" << inputData.singleSign << "\t" << inputData.text << endl;
}

void showBook(const SBook& book)
{
	cout << "Book: " << endl << "title: \"" << book.title << "\", number of pages: " << book.numberOfPages << ", published in: " << book.yearOfPublish << endl;
}

void setBook(SBook& book, char title[20], int numberOfPages, int yearOfPublish)
{
	strcpy(book.title, title);
	book.numberOfPages = numberOfPages;
	book.yearOfPublish = yearOfPublish;
}

bool isBookThick(const SBook& book)
{
	if (book.numberOfPages > 500)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void exercise_2(void)
{
	stack<SBook> stackOfBooks;

	for (int i = 0; i<3; i++)
	{
		char title[20];
		int numberOfPages;
		int yearOfPublish;

		cout << "Specify book title:\t";
		cin >> title;
		cout << "Specify number of pages:\t";
		cin >> numberOfPages;
		cout << "Specify in which year the book was published:\t";
		cin >> yearOfPublish;
		SBook book;
		setBook(book, title, numberOfPages, yearOfPublish);
		if (isBookThick(book))
		{
			stackOfBooks.push(book);
		}
	}

	for (int i = 0; i<3; i++)
	{
		if (!stackOfBooks.empty())
		{
			showBook(stackOfBooks.top());
			stackOfBooks.pop();
		}
	}
}

SVector SVector::operator+(const SVector& rightOperand)
{
	SVector result;
	result.x = this->x + rightOperand.x;
	result.y = this->y + rightOperand.y;
	return result;
}

SVector SVector::operator-(const SVector& rightOperand)
{
	SVector result;
	result.x = this->x - rightOperand.x;
	result.y = this->y - rightOperand.y;
	return result;
}

void showVector(SVector vector)
{
	cout << "Vector values:\tx: " << vector.x << "\ty: " << vector.y << endl;
}

void setVector(SVector &vector, int x, int y)
{
	vector.x = x;
	vector.y = y;
}

void exercise_3(void)
{
	cout << "Specify the number of elements:\t";
	int sizeOfTable;
	cin >> sizeOfTable;
	SVector* vectorTable = new SVector[sizeOfTable];
	for (int i = 0; i<sizeOfTable; i++)
	{
		setVector(vectorTable[i], rand() % 10, rand() % 10);
	}
	for (int i = 0; i<sizeOfTable; i++)
	{
		showVector(vectorTable[i]);
	}
	SVector sumOfVectors;
	setVector(sumOfVectors, 0, 0);
	for (int i = 0; i<sizeOfTable; i++)
	{
		sumOfVectors = sumOfVectors + vectorTable[i];
	}
	showVector(sumOfVectors);
	delete[] vectorTable;
}

bool compareGradesProgramming(SStudent& s1, SStudent s2)
{
	bool result;

	if (s1.gradeProgramming < s2.gradeProgramming)
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

void exercise_4(void)
{
	list<SStudent> listOfStudents;
	cout << "Podaj studentow:" << endl;
	for (int i = 0; i < 2; ++i)
	{
		SStudent newStudent;
		cin >> newStudent.firstName;
		cin >> newStudent.lastName;
		cin >> newStudent.gradeProgramming;

		listOfStudents.push_back(newStudent);
	}

	listOfStudents.sort(compareGradesProgramming);

	for (auto var : listOfStudents)
	{
		cout << var.firstName << " " << var.lastName << ": " << var.gradeProgramming << endl;
	}

	char firstNameOfStudentsToDelete[10];
	cout << "Specify the name of students to remove" << endl;
	cin >> firstNameOfStudentsToDelete;

	for (auto itr = listOfStudents.begin(); itr != listOfStudents.end();)
	{
		if (strcmp((*itr).firstName, firstNameOfStudentsToDelete) == 0)
		{
			itr = listOfStudents.erase(itr);
		}
		else
		{
			++itr;
		}
	}

	for each (auto var in listOfStudents)
	{
		cout << var.firstName << " " << var.lastName << ": " << var.gradeProgramming << endl;
	}
}

SFraction SFraction::operator*(const SFraction& f2)
{
	SFraction result;
	result.denominator = this->denominator * f2.denominator;
	result.nominator = this->nominator * f2.nominator;

	return result;
}

SFraction Reduce(const SFraction& f)
{
	bool flagEnd = false;

	SFraction reducedFraction;
	reducedFraction.denominator = f.denominator;
	reducedFraction.nominator = f.nominator;

	int i = 2;
	while (flagEnd == false)
	{
		if (i <= reducedFraction.denominator && i <= reducedFraction.nominator)
		{
			if ((reducedFraction.denominator%i == 0) && (reducedFraction.nominator%i == 0))
			{
				reducedFraction.denominator = reducedFraction.denominator / i;
				reducedFraction.nominator = reducedFraction.nominator / i;
				i = 2;
			}
			else
			{
				i++;
			}
		}
		else
		{
			flagEnd = true;
		}
	}

	return reducedFraction;
}

void exercise_5(void)
{
	vector<SFraction> vectorOfFractions;

	cout << "Specify fractions:" << endl;
	for (int i = 0; i < 2; ++i)
	{
		SFraction newFraction;
		cin >> newFraction.denominator;
		cin >> newFraction.nominator;
		vectorOfFractions.push_back(newFraction);
	}

	SFraction productOfFractions;
	productOfFractions.denominator = 1;
	productOfFractions.nominator = 1;
	for each (auto var in vectorOfFractions)
	{
		productOfFractions = productOfFractions * var;
	}

	cout << productOfFractions.denominator << "/" << productOfFractions.nominator << endl;

	SFraction reducedFraction = Reduce(productOfFractions);

	cout << reducedFraction.denominator << "/" << reducedFraction.nominator << endl;
}
