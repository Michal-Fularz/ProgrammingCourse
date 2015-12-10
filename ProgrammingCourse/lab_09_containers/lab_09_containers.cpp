#include <stdio.h>
#include <iostream>
#include <conio.h>

#include <vector>
#include <list>

#include <chrono>

int main(void)
{
	// this requires VS 2013 or newer
	std::list<int> l{ 0, 1, 2, 3 };
	for (auto item : l)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;

	std::vector<std::vector<int>> v_2d;
	int number_of_rows = 5;
	int number_of_cols = 5;
	for (int i = 0; i < number_of_rows; i++)
	{
		std::vector<int> v_row;
		for (int j = 0; j < number_of_cols; j++)
		{
			v_row.push_back(10 * i + j);
		}
		v_2d.push_back(v_row);
	}

	for (auto itr = v_2d.begin(); itr != v_2d.end(); ++itr)
	{
		for (auto jtr = (*itr).begin(); jtr != (*itr).end(); ++jtr)
		{
			std::cout << *jtr << "\t";
		}
		std::cout << std::endl;
	}

	const int number_of_iterations = 100000;

	{
		auto start = std::chrono::steady_clock::now();
		//  Insert the code that will be timed
		std::vector<int> v_test_push_back;
		for (int i = 0; i < number_of_iterations; ++i)
		{
			v_test_push_back.push_back(i);
		}

		auto end = std::chrono::steady_clock::now();
		// Store the time difference between start and end
		auto diff = end - start;
		std::cout << "vector push back: ";
		// print the measured time in milliseconds:
		std::cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;
	}

	{
		auto start = std::chrono::steady_clock::now();
		//  Insert the code that will be timed
		std::list<int> l_test_push_back;
		for (int i = 0; i < number_of_iterations; ++i)
		{
			l_test_push_back.push_back(i);
		}

		auto end = std::chrono::steady_clock::now();
		// Store the time difference between start and end
		auto diff = end - start;
		std::cout << "list push back: ";
		// print the measured time in milliseconds:
		std::cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;
	}

	{
		auto start = std::chrono::steady_clock::now();
		//  Insert the code that will be timed
		std::vector<int> v_test_insert;
		for (int i = 0; i < number_of_iterations; ++i)
		{
			v_test_insert.insert(v_test_insert.begin(), i);
		}

		auto end = std::chrono::steady_clock::now();
		// Store the time difference between start and end
		auto diff = end - start;
		std::cout << "vector push front (by insert method): ";
		// print the measured time in milliseconds:
		std::cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;
	}

	{
		auto start = std::chrono::steady_clock::now();
		//  Insert the code that will be timed
		std::list<int> l_test_insert;
		for (int i = 0; i < number_of_iterations; ++i)
		{
			l_test_insert.push_front(i);
		}

		auto end = std::chrono::steady_clock::now();
		// Store the time difference between start and end
		auto diff = end - start;
		std::cout << "list push front: ";
		// print the measured time in milliseconds:
		std::cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;
	}

	std::cout << "Press any key to finish." << std::endl;
	_getch();

	return 0;
}