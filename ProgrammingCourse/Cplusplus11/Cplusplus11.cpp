#include <iostream>
#include <cstdint>

// http://www.cprogramming.com/c++11/c++11-nullptr-strongly-typed-enum-class.html

int main(void)
{
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
	enum class Colors : std::int8_t { RED = 1, GREEN = 2, BLUE = 3 };

	// old NULL is dangerous, when passed to function it can be interpreted as int (all in all it is just a define with 0
	int* ptrToNull = nullptr;



	return 1;
}