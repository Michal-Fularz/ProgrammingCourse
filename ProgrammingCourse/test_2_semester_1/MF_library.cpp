#include "MF_library.h"

#include <iostream>
using namespace std;

void showMenu(void)
{
	cout << endl << "MENU:" << endl;
	cout << "exercise 1 - press 1" << endl;
	cout << "exercise 2 - press 2" << endl;
	cout << "exercise 3 - press 3" << endl;
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

#include <stack>

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