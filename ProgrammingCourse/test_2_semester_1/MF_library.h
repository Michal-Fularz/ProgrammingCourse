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

void showBook(const SBook& book);
void setBook(SBook& book, char title[20], int numberOfPages, int yearOfPublish);
bool isBookThick(const SBook& book);

void exercise_2(void);

#endif