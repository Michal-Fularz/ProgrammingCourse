#include "SComplexNumber.h"

SComplexNumber Add(const SComplexNumber& n1, const SComplexNumber& n2)
{
	SComplexNumber result;
	result.Re = n1.Re + n2.Re;
	result.Im = n1.Im + n2.Im;

	return result;
}

void Show(const SComplexNumber& n)
{
	std::cout << "Complex number: " << n.Re << " + " << n.Im << "j" << std::endl;
}

void Load(SComplexNumber& n)
{
	std::cout << "Provide Re part of complex number: ";
	std::cin >> n.Re;
	std::cout << "Provide Im part of complex number: ";
	std::cin >> n.Im;
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

SComplexNumber SComplexNumber::operator!()
{
	SComplexNumber result;

	result.Im = this->Re;
	result.Re = this->Im;

	return result;
}

std::ostream& operator<<(std::ostream& output, const SComplexNumber& n)
{
	output << "Complex number: " << n.Re << " + " << n.Im << "j" << std::endl;

	return output;
}

std::istream& operator>>(std::istream& input, SComplexNumber& n)
{
	std::cout << "Provide Re part of complex number: ";
	input >> n.Re;
	std::cout << "Provide Im part of complex number: ";
	input >> n.Im;

	return input;
}