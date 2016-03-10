#pragma once

#include <ostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator, int denominator);
	~Fraction();

	void set_numerator(int numerator);
	void set_denominator(int denominator);
	void set(int numerator, int denominator);

	void Show();
	Fraction Add(const Fraction& f2);
	Fraction operator+(const Fraction& f2);

	friend std::ostream &operator<<(std::ostream& stream, const Fraction& f);
};

