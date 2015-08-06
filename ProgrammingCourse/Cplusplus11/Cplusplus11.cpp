#include <iostream>
//#include <cstdint>
#include <stdint.h>
#include <string>

#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

void reverse_in_place(std::string &text)
{
	for (int i = 0; i < text.size()/2; i++)
	{
		std::swap(text[i], text[text.size() - 1 - i]);
	}
}

void reverse_in_place_iterator_version(std::string &text)
{
	// iterator version
	auto itr_end = text.end() - 1;
	for (auto itr_start = text.begin(); itr_start < itr_end; ++itr_start, --itr_end)
	{
		std::swap(*itr_start, *itr_end);
	}
}


void my_own_atoi()
{

}

class SimpleTestClass
{
	SimpleTestClass()
	{

	}

	~SimpleTestClass()
	{

	}

public:
	int DoSomething(void)
	{
		CountSomeThing();
		std::cout << this->value << std::endl;
		return value;
	}
private:
	int CountSomeThing(void)
	{
		return value * 2;
	}

	int value;
};

int my_own_partition(std::vector<int>& table, int low, int high)
{
	int pivotIndex = (high - low) / 2;
	int pivotValue = table[pivotIndex];
	std::swap(table[pivotIndex], table[high]);

	int storeIndex = low;
	for (int i = low; i <= (high - 1); ++i)
	{
		if (table[i] < pivotValue)
		{
			std::swap(table[i], table[storeIndex]);
			storeIndex++;
		}
	}
	std::swap(table[storeIndex], table[high]);

	return storeIndex;
}

void my_own_quicksort(std::vector<int>& table, int low, int high)
{
	if (low < high)
	{
		int part = my_own_partition(table, low, high);
		my_own_quicksort(table, low, part - 1);
		my_own_quicksort(table, part + 1, high);
	}
}

void merge(int pocz, int sr, int kon)
{
}

void my_own_merge(std::vector<int>& table, int low, int high)
{

}

void my_own_merge_sort(std::vector<int>& table, int start, int end)
{
	if (start < end)
	{
		int split = (start + end) / 2;
		my_own_merge_sort(table, start, split);
		my_own_merge_sort(table, split + 1, end);
		my_own_merge(table, start, end);
	}
}

void my_own_sort_tests(void)
{
	std::vector<int> table = { 1, 3, 10, 2, 8, 9, 7, 5, 4, 6 };
	my_own_quicksort(table, 0, table.size()-1);
	std::cout << "Sorted table: " << std::endl;
	for (auto &item : table)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;

	table = { 1, 3, 10, 2, 8, 9, 7, 5, 4, 6 };
	my_own_quicksort(table, 0, table.size() - 1);
	std::cout << "Sorted table: " << std::endl;
	for (auto &item : table)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
}

void google(void)
{
	std::vector<std::string> candidate_set = { "gopher", "cheater", "chess" };
	std::vector<std::string> prefix_set = { "go", "chess", "checkers" };
	std::sort(prefix_set.begin(), prefix_set.end());

	for (auto &item : candidate_set)
	{
		// gopher
		// go
		// goo
		// gop
		// gor
		auto found_item = std::lower_bound(prefix_set.begin(), prefix_set.end(), item);
		std::string prefix = *found_item;

		bool flag_same = false;
		if (item.size() > prefix.size())
		{
			flag_same = true;
			for (int i = 0; i<prefix.size(); ++i)
			{
				if (item[i] != prefix[i])
				{
					flag_same = false;
					break;
				}
			}
		}

		if (flag_same)
		{
			std::cout << "The word : " << prefix << " is a prefix of word : " << item << std::endl;
		}
		else
		{
			std::cout << "The word " << item << "does NOT have a prefix in the set" << std::endl;

		}

	}
}



int main(void)
{
	// http://www.cprogramming.com/c++11/c++11-nullptr-strongly-typed-enum-class.html
	// this code won't compile!
	/*
	enum Color { RED, GREEN, BLUE };
	enum Feelings { EXCITED, MOODY, BLUE };
	*/
	// BLUE is redefined

	// this code will compile (if your compiler supports C++11 strongly typed enums)
	enum class Color { RED, GREEN, BLUE };
	enum class Feelings { EXCITED, MOODY, BLUE };

	Color color = Color::GREEN;
	if (Color::RED == color)
	{
		// the color is red
	}

	// you can also decide how big the enum type should be (default int)
	enum class Colors : int8_t { RED = 1, GREEN = 2, BLUE = 3 };

	// old NULL is dangerous, when passed to function it can be interpreted as int (all in all it is just a define with 0
	int* ptrToNull = nullptr;

	// OTHER codes (from different sources)

	// stdint.h types with defined size
	int8_t int_8_bits = 0;
	int16_t int_16_bits = 0;
	int32_t int_32_bits = 0;
	int64_t int_64_bits = 0;

	// do NOT use C like casts (eg. (int)value)
	double doubleValue = 3.2;
	int intValue = static_cast<int>(doubleValue);

	std::cout << "doubleValue: " << doubleValue << ", intValue: " << intValue << std::endl;

	std::string text = "Madam I'm Adam";
	std::cout << "Original string: " << text << std::endl;
	reverse_in_place(text);
	std::cout << "Reversed string: " << text << std::endl;

	std::vector<int> table = { 8, 3, 10, 2, 1, 9, 7, 5, 4, 6 };

	std::cout << "Vector sum: " << std::accumulate(table.begin(), table.end(), 0, std::plus<int>()) << std::endl;

	if (std::all_of(table.begin(), table.end(), [](int x){return x % 2; }))
	{
		std::cout << "All the elements are odd numbers.\n";
	}

	auto it = std::find(table.begin(), table.end(), 8);
	int elemnts_count = std::count(table.begin(), table.end(), 8);
	if (it != table.end())
	{
		std::cout << elemnts_count << " element with value: " << *it << " was found! Its position is: " << (it - table.begin()) << std::endl;
	}
	// there is count_if!!!

	std::sort(table.begin(), table.end());

	std::cout << "Sorted table: " << std::endl;
	for (auto &item : table)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;

	auto it_lower = std::lower_bound(table.begin(), table.end(), 5);
	std::cout << "Value lower or equal to 5 in the table is: " << *it_lower << ", its position is: " << (it_lower - table.begin()) << std::endl;

	// TODO - test this product
	// https://code.google.com/p/googletest/

	// TODO - create simple tree and do breadth or depth first look up

	// implement merge and quicksort
	//my_own_sort_tests();
	google();



	return 1;
}