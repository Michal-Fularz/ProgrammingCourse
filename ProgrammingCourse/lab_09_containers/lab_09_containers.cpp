#include <stdio.h>
#include <iostream>
#include <conio.h>

#include <vector>
#include <list>

#include <chrono>

int main(void)
{
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

	{
		auto start = std::chrono::steady_clock::now();
		//  Insert the code that will be timed
		std::vector<int> v_test_insert;
		for (int i = 0; i < 100000; ++i)
		{
			v_test_insert.insert(v_test_insert.begin(), i);
		}

		auto end = std::chrono::steady_clock::now();
		// Store the time difference between start and end
		auto diff = end - start;
		// print the measured time in milliseconds:
		std::cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;
	}

	{
		auto start = std::chrono::steady_clock::now();
		//  Insert the code that will be timed
		std::list<int> l_test_insert;
		for (int i = 0; i < 100000; ++i)
		{
			l_test_insert.insert(l_test_insert.begin(), i);
		}

		auto end = std::chrono::steady_clock::now();
		// Store the time difference between start and end
		auto diff = end - start;
		// print the measured time in milliseconds:
		std::cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;
	}

	std::cout << "Press any key to finish." << std::endl;
	_getch();

	return 0;
}