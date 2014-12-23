#include <iostream>

using namespace std;

struct SComplexNumber
{
	int Re;
	int Im;

	SComplexNumber operator+(const SComplexNumber& n2);
	friend ostream& operator<<(ostream& output, const SComplexNumber& n);
	friend istream& operator>>(istream& input, SComplexNumber& n);
};

SComplexNumber Add(const SComplexNumber& n1, const SComplexNumber& n2)
{
	SComplexNumber result;
	result.Re = n1.Re + n2.Re;
	result.Im = n1.Im + n2.Im;

	return result;
}

void Show(const SComplexNumber& n)
{
	cout << "Complex number: " << n.Re << " + " << n.Im << "j" << endl;
}

void Load(SComplexNumber& n)
{
	cout << "Provide Re part of complex number: ";
	cin >> n.Re;
	cout << "Provide Im part of complex number: ";
	cin >> n.Im;
}

SComplexNumber SComplexNumber::operator+(const SComplexNumber& n2)
{
	SComplexNumber result;
	// first way to access left operand
	result.Re = this->Re + n2.Re;
	// second way to access left operand
	result.Im = Im + n2.Im;

	return result;
}

ostream& operator<<(ostream& output, const SComplexNumber& n)
{
	output << "Complex number: " << n.Re << " + " << n.Im << "j" << endl;

	return output;
}

istream& operator>>(istream& input, SComplexNumber& n)
{
	cout << "Provide Re part of complex number: ";
	input >> n.Re;
	cout << "Provide Im part of complex number: ";
	input >> n.Im;

	return input;
}

int main(void)
{
	SComplexNumber complexNumber1, complexNumber2, complexNumberSum;

	// using functions
	Load(complexNumber1);
	Load(complexNumber2);
	complexNumberSum = Add(complexNumber1, complexNumber2);
	Show(complexNumber1);
	Show(complexNumber2);
	cout << "Sum of the above complex numbers is: " << endl;
	Show(complexNumberSum);
	
	// using overloading operators
	cin >> complexNumber1 >> complexNumber2;
	complexNumberSum = complexNumber1 + complexNumber2;
	cout << complexNumber1 << complexNumber2 << "Sum of the above complex numbers is: " << endl << complexNumberSum;

	std::cout << "Press enter to continue..." << std::endl;
	std::cin.sync(); // Flush The Input Buffer Just In Case
	std::cin.ignore(); // There's No Need To Actually Store The Users Input

	return 0;
}