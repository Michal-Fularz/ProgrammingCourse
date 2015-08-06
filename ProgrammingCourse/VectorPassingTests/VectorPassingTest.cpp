#include "function_sum.h"
#include "function_2.h"

#include <iostream>

int main(void)
{
	const int numberOfIteration = 1000;
	const int sizeOfVector = 100000;

	std::cout << std::endl << "Testing sum function: " << std::endl;
	TEST_function_sum(numberOfIteration, sizeOfVector);

	std::cout << std::endl << "Testing more complicated function: " << std::endl;
	TEST_function_2(numberOfIteration, sizeOfVector);

	return 0;
}