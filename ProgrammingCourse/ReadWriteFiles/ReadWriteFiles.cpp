#include <stdio.h>		// for fprintf/fscanf/fwrite/fread/fopen/fclose
#include <fstream>		// for stream file operations

#include <iostream>
#include <conio.h>

using namespace std;

// TODO - add fstream examples

void ofstreamExample(void)
{
	// work in progress

	cout << "To jest tekst" << endl;
	cout << "wyswietlany na ekranie" << endl;

	ofstream plik;
	plik.open("dane.txt");


	plik << "To jest tekst" << endl;
	plik << "wyswietlany na ekranie" << endl;

	plik.close();
}

struct SStudent
{
	char name[10];
	int identificationNumber;
};

void HELPER_fillTwoStudents(SStudent* students)
{
	strcpy(students[0].name, "John");
	students[0].identificationNumber = 666;
	strcpy(students[1].name, "Alice");
	students[1].identificationNumber = 999;
}

void HELPER_fprintf_SaveStudentStructure(FILE* file, SStudent &studentToSave)
{
	fprintf(file, "Student:\n name: %s\n identification number: %d\n", studentToSave.name, studentToSave.identificationNumber);
}

void HELPER_fscanf_LoadStudentStructure(FILE* file, SStudent &studentToLoad)
{
	fscanf(file, "Student:\n name: %s\n identification number: %d\n", studentToLoad.name, &studentToLoad.identificationNumber);
}

void fprintf_SaveLoadStructure(void)
{
	const int numberOfStudents = 2;
	SStudent studentsToSave[numberOfStudents];
	HELPER_fillTwoStudents(studentsToSave);

	FILE* file = fopen("students.txt", "w+t");
	for (int i = 0; i < numberOfStudents; ++i)
	{
		HELPER_fprintf_SaveStudentStructure(file, studentsToSave[i]);
	}
	fclose(file);

	SStudent studentsFromFile[numberOfStudents];
	file = fopen("students.txt", "r+t");
	for (int i = 0; i < 2; ++i)
	{
		HELPER_fscanf_LoadStudentStructure(file, studentsFromFile[i]);
	}
	fclose(file);

	for (int i = 0; i < 2; ++i)
	{
		printf("Student %d:\n name: %s,\n identification: %d\n", i, studentsFromFile[i].name, studentsFromFile[i].identificationNumber);
	}
}

void fwrite_SaveLoadStructure(void)
{
	const int numberOfStudents = 2;
	SStudent studentsToSave[numberOfStudents];
	HELPER_fillTwoStudents(studentsToSave);

	FILE* file = fopen("students.bin", "w+b");
	fwrite(studentsToSave, sizeof(SStudent), numberOfStudents, file);
	fclose(file);

	SStudent studentsFromFile[numberOfStudents];
	file = fopen("students.bin", "r+b");
	fread(studentsFromFile, sizeof(SStudent), 2, file);
	fclose(file);

	for (int i = 0; i < 2; ++i)
	{
		printf("Student %d:\n name: %s,\n identification: %d\n", i, studentsFromFile[i].name, studentsFromFile[i].identificationNumber);
	}
}

void fprintf_Example(void)
{
	cout << "Example of writing to file using fprintf" << endl;

	float valueFromUser;
	int numberOfWrites;
	cout << "Provide number to write to file: ";
	cin >> valueFromUser;
	cout << "Provide number of write operations: ";
	cin >> numberOfWrites;

	FILE *file;
	file = fopen("data.txt", "w+t");
	if (file != NULL)
	{
		printf("This's how you write on screen using printf\n");
		fprintf(file, "And this's the way to do it using fprintf\n");
		fprintf(file, "Number of writes: %d\n", numberOfWrites);
		for (int i = 0; i < numberOfWrites; i++)
		{
			fprintf(file, "Value from user: %.4f\n", valueFromUser);
		}
		fclose(file);
	}

	cout << "End of example" << endl;
}

void fscanf_Example(void)
{
	cout << "Example of reading from file using fscanf" << endl;

	FILE *file;
	file = fopen("data.txt", "r+t");
	if (file != NULL)
	{
		fscanf(file, "And this's the way to do it using fprintf\n");
		int numberOfWrites;
		fscanf(file, "Number of writes: %d\n", &numberOfWrites);
		float valueFromFile;
		for (int i = 0; i < numberOfWrites; i++)
		{
			fscanf(file, "Value from user: %f\n", &valueFromFile);
			cout << "Iteration: " << i << ". Value from file: " << valueFromFile << endl;
		}
		fclose(file);	
	}

	cout << "End of example" << endl;
}

void fwrite_Example(void)
{
	cout << "Example of writing to file using fwrite" << endl;

	float valueFromUser;
	int numberOfWrites;
	cout << "Provide number to write to file: ";
	cin >> valueFromUser;
	cout << "Provide number of write operations: ";
	cin >> numberOfWrites;

	FILE *file;
	file = fopen("data.bin", "w+b");
	if (file != NULL)
	{
		fwrite(&numberOfWrites, sizeof(numberOfWrites), 1, file);
		for (int i = 0; i < numberOfWrites; i++)
		{
			fwrite(&valueFromUser, sizeof(valueFromUser), 1, file);
		}
	}
	fclose(file);

	cout << "End of example" << endl;
}

void fread_Example(void)
{
	cout << "Example of reading from file using fread" << endl;

	FILE *file;
	file = fopen("data.bin", "r+b");
	if (file != NULL)
	{
		float valueFromFile;
		int numberOfWrites;
		fread(&numberOfWrites, sizeof(numberOfWrites), 1, file);
		for (int i = 0; i < numberOfWrites; i++)
		{
			fread(&valueFromFile, sizeof(valueFromFile), 1, file);
			cout << "Iteration: " << i << ". Value from file: " << valueFromFile << endl;
		}
		fclose(file);
	}
	cout << "End of example" << endl;
}

int main(void)
{
	fprintf_SaveLoadStructure();
	fwrite_SaveLoadStructure();

	fwrite_Example();
	fread_Example();
	fprintf_Example();
	fscanf_Example();

	std::cout << "Press enter to continue..." << std::endl;
	std::cin.sync(); // Flush The Input Buffer Just In Case
	std::cin.ignore(); // There's No Need To Actually Store The Users Input

	std::cout << "Press any key to finish." << std::endl;
	_getch();

	return 0;
}