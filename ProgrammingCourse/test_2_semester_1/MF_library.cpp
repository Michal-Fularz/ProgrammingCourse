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