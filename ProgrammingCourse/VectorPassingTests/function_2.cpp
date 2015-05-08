#include "function_2.h"

#include <iostream>
#include <vector>
#include "Timer.h"

static double testFunction_passByValue(std::vector<double> data, int iteration)
{
	double sum = 0.0;
	double divison = (double)(1 + iteration);
	for (auto value : data)
	{
		sum += value / divison;
	}

	return sum;
}

static double testFunction_passByReference(std::vector<double> &data, int iteration)
{
	double sum = 0;
	double divison = (double)(1 + iteration);
	for (auto value : data)
	{
		sum += value / divison;
	}

	return sum;
}

static double testFunction_passByConstReference(const std::vector<double> &data, int iteration)
{
	double sum = 0;
	double divison = (double)(1 + iteration);
	for (auto value : data)
	{
		sum += value / divison;
	}

	return sum;
}

static double testFunction_passByValue_move(std::vector<double>&& data, int iteration)
{
	double sum = 0;
	double divison = (double)(1 + iteration);
	for (auto value : data)
	{
		sum += value / divison;
	}

	return sum;
}

void TEST_function_2(int numberOfIteration, int sizeOfVector)
{
	std::vector<double> data;
	for (int i = 0; i < sizeOfVector; ++i)
	{
		data.push_back((double)i);
	}

	Timer timer;
	{
		std::cout << "Without functions: " << std::endl;

		timer.start();

		double result = 0.0;
		for (int i = 0; i < numberOfIteration; ++i)
		{
			double sum = 0.0;
			double divison = (double)(1 + i);
			for (auto value : data)
			{
				sum += value / divison;
			}

			result += sum;
		}

		timer.stop();

		std::cout << "Result: " << result << std::endl;
		std::cout << "Time: " << timer.getElapsedTimeInMilliSec() << std::endl << std::endl;
	}

	{
		std::cout << "Pass by value: " << std::endl;

		timer.start();

		double result = 0.0;
		for (int i = 0; i < numberOfIteration; ++i)
		{
			result += testFunction_passByValue(data, i);
		}

		timer.stop();

		std::cout << "Result: " << result << std::endl;
		std::cout << "Time: " << timer.getElapsedTimeInMilliSec() << std::endl << std::endl;
	}

	{
		std::cout << "Pass by reference: " << std::endl;

		timer.start();

		double result = 0.0;
		for (int i = 0; i < numberOfIteration; ++i)
		{
			result += testFunction_passByReference(data, i);
		}

		timer.stop();

		std::cout << "Result: " << result << std::endl;
		std::cout << "Time: " << timer.getElapsedTimeInMilliSec() << std::endl << std::endl;
	}

	{
		std::cout << "Pass by const reference: " << std::endl;

		timer.start();

		double result = 0.0;
		for (int i = 0; i < numberOfIteration; ++i)
		{
			result += testFunction_passByConstReference(data, i);
		}

		timer.stop();

		std::cout << "Result: " << result << std::endl;
		std::cout << "Time: " << timer.getElapsedTimeInMilliSec() << std::endl << std::endl;
	}

	{
		std::cout << "Pass by value (move constuctor): " << std::endl;

		timer.start();

		double result = 0.0;
		for (int i = 0; i < numberOfIteration; ++i)
		{
			result += testFunction_passByValue_move(std::move(data), i);
		}

		timer.stop();

		std::cout << "Result: " << result << std::endl;
		std::cout << "Time: " << timer.getElapsedTimeInMilliSec() << std::endl << std::endl;
	}
}
