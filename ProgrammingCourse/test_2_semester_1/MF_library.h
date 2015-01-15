#ifndef __MF_LIBRARY_H__
#define __MF_LIBRARY_H__

void showMenu(void);
char chooseOption(void);

struct SInputData
{
	int decimalValue;
	float floatingpointValue;
	bool logicalValue;
	char singleSign;
	char text[33];
};

void exercise_1_prepare(void);
void exercise_1(void);

struct SBook
{
	char title[20];
	int numberOfPages;
	int yearOfPublish;
};

void exercise_2(void);

struct SVector
{
	int x;
	int y;

	SVector operator+(const SVector&);
	SVector operator-(const SVector&);
};

void exercise_3(void);

struct SStudent
{
	char firstName[10];
	char lastName[10];
	double gradeProgramming;
};

void exercise_4(void);

struct SFraction
{
	int denominator;
	int nominator;

	SFraction operator*(const SFraction&);
};

void exercise_5(void);


#endif