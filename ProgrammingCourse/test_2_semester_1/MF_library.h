#ifndef __MF_LIBRARY_H__
#define __MF_LIBRARY_H__

#include <istream>
#include <ostream>

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

struct STime
{
	int hours;
	int minutes;
	int seconds;

	STime operator+(const STime&);
	STime operator-(const STime&);
	friend std::istream& operator>>(std::istream& output, const STime& t);
	friend std::ostream& operator<<(std::ostream& output, const STime& t);
};

void exercise_6(void);
void exercise_7(void);
void exercise_8(void);
void exercise_9(void);
void exercise_10(void);
void exercise_11(void);

#endif