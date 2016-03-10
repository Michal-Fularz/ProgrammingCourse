#include "fraction.h"

#include <iostream>

Fraction::Fraction(int numerator, int denominator)
{
	set(numerator, denominator);
}


Fraction::~Fraction()
{
}

void Fraction::set_numerator(int numerator)
{
	m_numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator != 0)
	{
		m_denominator = denominator;
	}
	else
	{
		// just in case of usage in constructor set it to something
		m_denominator = 1;
		throw "Denominator can not be set to 0!";
	}
}
void Fraction::set(int numerator, int denominator)
{
	set_numerator(numerator);
	set_denominator(denominator);
}

void Fraction::Show()
{
	std::cout << m_numerator << "\\" << m_denominator << std::endl;
}
Fraction Fraction::Add(const Fraction& f2)
{
	Fraction result(1, 1);

	result.set_numerator(m_numerator * f2.m_denominator + m_denominator * f2.m_numerator);
	result.set_denominator(m_denominator * f2.m_denominator);

	return result;
}
Fraction Fraction::operator+(const Fraction& f2)
{
	return Add(f2);
}

std::ostream &operator<<(std::ostream& stream, const Fraction& f)
{
	stream << f.m_numerator << "\\" << f.m_denominator;

	return stream;
}
