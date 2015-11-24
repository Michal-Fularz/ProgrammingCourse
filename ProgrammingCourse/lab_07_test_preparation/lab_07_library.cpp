#include "lab_07_library.h"
#include <cmath>

int modulo_1(int value, int dividend)
{
	int quotient = value / dividend;

	int rest_of_division = value - quotient * dividend;

	return rest_of_division;
}

int modulo_2(int value, int dividend)
{
	while (value >= dividend)
	{
		value -= dividend;
	}

	return value;
}

float calculate_average(int* values, int number_of_values)
{
	int sum_of_values = 0;
	for (int i = 0; i < number_of_values; ++i)
	{
		sum_of_values += values[i];
	}

	float average = (float)sum_of_values / number_of_values;

	return average;
}

float calculate_standard_deviation(int* values, int number_of_values)
{
	float average = calculate_average(values, number_of_values);

	float sum_of_squared_differences = 0.0;

	for (int i = 0; i < number_of_values; ++i)
	{
		sum_of_squared_differences += pow(values[i] - average, 2);
	}

	float standard_deviation = sqrt(sum_of_squared_differences / number_of_values);

	return standard_deviation;
}