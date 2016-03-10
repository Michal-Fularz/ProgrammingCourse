#pragma once

#include <iostream>

struct SComplexNumber
{
	int Re;
	int Im;

	SComplexNumber operator+(const SComplexNumber& n2);
	SComplexNumber operator!();
	friend std::ostream& operator<<(std::ostream& output, const SComplexNumber& n);
	friend std::istream& operator>>(std::istream& input, SComplexNumber& n);
};

SComplexNumber Add(const SComplexNumber& n1, const SComplexNumber& n2);
void Show(const SComplexNumber& n);
void Load(SComplexNumber& n);