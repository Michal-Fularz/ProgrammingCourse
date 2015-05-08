#include "function_sum.h"

#include <iostream>
#include <vector>
#include "Timer.h"

static int sum_passByValue(std::vector<int> data)
{
	int sum = 0;
	for (auto value : data)
	{
		sum += value;
	}

	return sum;
}

static int sum_passByValue_move(std::vector<int>&& data)
{
	int sum = 0;
	for (auto value : data)
	{
		sum += value;
	}

	return sum;
}

static int sum_passByReference(std::vector<int> &data)
{
	int sum = 0;
	for (auto value : data)
	{
		sum += value;
	}

	return sum;
}

static int sum_passByConstReference(const std::vector<int> &data)
{
	int sum = 0;
	for (auto value : data)
	{
		sum += value;
	}

	return sum;
}

void TEST_function_sum(int numberOfIteration, int sizeOfVector)
{
	std::vector<int> data;
	for (int i = 0; i < sizeOfVector; ++i)
	{
		data.push_back(i);
	}


	Timer timer;
	{
		std::cout << "Without functions: " << std::endl;

		timer.start();

		int sum = 0;
		for (int i = 0; i < numberOfIteration; ++i)
		{
			int subSum = 0;
			for (auto value : data)
			{
				subSum += value;
			}

			sum += subSum;
		}

		timer.stop();

		std::cout << "Sum: " << sum << std::endl;
		std::cout << "Time: " << timer.getElapsedTimeInMilliSec() << std::endl << std::endl;
	}

	{
		std::cout << "Pass by value: " << std::endl;

		timer.start();

		int sum = 0;
		for (int i = 0; i < numberOfIteration; ++i)
		{
			sum += sum_passByValue(data);
		}

		timer.stop();

		std::cout << "Sum: " << sum << std::endl;
		std::cout << "Time: " << timer.getElapsedTimeInMilliSec() << std::endl << std::endl;
	}

	{
		std::cout << "Pass by reference: " << std::endl;

		timer.start();

		int sum = 0;
		for (int i = 0; i < numberOfIteration; ++i)
		{
			sum += sum_passByReference(data);
		}

		timer.stop();

		std::cout << "Sum: " << sum << std::endl;
		std::cout << "Time: " << timer.getElapsedTimeInMilliSec() << std::endl << std::endl;
	}

	{
		std::cout << "Pass by const reference: " << std::endl;

		timer.start();

		int sum = 0;
		for (int i = 0; i < numberOfIteration; ++i)
		{
			sum += sum_passByConstReference(data);
		}

		timer.stop();

		std::cout << "Sum: " << sum << std::endl;
		std::cout << "Time: " << timer.getElapsedTimeInMilliSec() << std::endl << std::endl;
	}

	{
		std::cout << "Pass by value (move constuctor): " << std::endl;

		timer.start();

		int sum = 0;
		for (int i = 0; i < numberOfIteration; ++i)
		{
			sum += sum_passByValue_move(std::move(data));
		}

		timer.stop();

		std::cout << "Sum: " << sum << std::endl;
		std::cout << "Time: " << timer.getElapsedTimeInMilliSec() << std::endl << std::endl;
	}
}
