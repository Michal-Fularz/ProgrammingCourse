#pragma once

#include "Figure.h"

namespace MF
{
	class Circle : public Figure
	{
	public:
		Circle(double radius, double red, double green, double blue);
		~Circle();

		void Draw();

	private:
		double m_size_radius;
	};
}

