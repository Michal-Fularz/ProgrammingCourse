#include <iostream>

#include <list>
#include <vector>

int main(void)
{
	// vector
	std::vector<int> sampleVectorEmpty;					// no elements inside
	std::vector<int> sampleVectorWithElements(100, 5);	// 100 elements with value 5

	std::vector<int> v;
	v.assign(5, 13);

	std::cout << "Vector size: " << v.size() << std::endl;
	std::cout << "Vector elements: " << std::endl;
	for (auto item : v)
	{
		std::cout << item << ", ";
	}
	std::cout << std::endl;
	
	v.clear();

	// list
	std::list<int> sampleList;

	for (int i = 0; i < 3; ++i)
	{
		sampleList.push_back(i);
	}
	for (int i = 0; i < 3; ++i)
	{
		sampleList.push_front(i + 10);
	}

	std::cout << "List size: " << sampleList.size() << std::endl;
	std::cout << "List elements: " << std::endl;
	for (std::list<int>::iterator itr = sampleList.begin(); itr != sampleList.end(); itr++)
	{
		std::cout << (*itr) << ", ";
	}
	std::cout << std::endl;

	return 1;
}