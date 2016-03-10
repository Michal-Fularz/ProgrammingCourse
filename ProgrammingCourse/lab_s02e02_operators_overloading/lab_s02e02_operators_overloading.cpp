#include <stdio.h>
#include <iostream>
#include <conio.h>

#include "Fraction.h"
#include "SComplexNumber.h"

#include <cstdlib>
#include <time.h>
#include <vector>

void SComplexNumber_test(void)
{
	SComplexNumber complexNumber1, complexNumber2, complexNumberSum;

	// using functions
	Load(complexNumber1);
	Load(complexNumber2);
	complexNumberSum = Add(complexNumber1, complexNumber2);
	Show(complexNumber1);
	Show(complexNumber2);
	std::cout << "Sum of the above complex numbers is: " << std::endl;
	Show(complexNumberSum);

	// using overloading operators
	std::cin >> complexNumber1 >> complexNumber2;
	complexNumberSum = complexNumber1 + complexNumber2;
	std::cout << complexNumber1 << complexNumber2 << "Sum of the above complex numbers is: " << std::endl << complexNumberSum;

	// operator !
	std::cout << "Original: " << complexNumberSum << ", after operator !: " << !complexNumberSum << std::endl;

	std::cout << "Press enter to continue..." << std::endl;
	std::cin.sync(); // Flush The Input Buffer Just In Case
	std::cin.ignore(); // There's No Need To Actually Store The Users Input
}

void Fraction_test(void)
{
	Fraction f1(2, 3);
	Fraction f2(1, 5);

	f1.Show();
	f2.Show();

	Fraction f3 = f1.Add(f2);
	f3.Show();

	std::vector<Fraction> fractions;
	const int number_of_fractions = 10;
	for (int i = 0; i < number_of_fractions; i++)
	{
		Fraction new_fraction(rand() % 10, rand() % 10 + 5);
		fractions.push_back(new_fraction);
	}

	Fraction sum(0, 1);
	for (auto itr = fractions.begin(); itr != fractions.end(); itr++)
	{
		sum = sum + *itr;
	}
	std::cout << "Sum of fractions: " << sum << std::endl;


	std::cout << "Press any key to finish." << std::endl;
	_getch();
}

int main(void)
{
	srand(time(NULL));

	Fraction_test();
	//SComplexNumber_test();

	return 0;
}