#pragma once

#include "Figure.h"
#include "Physics.h"

namespace MF
{

	class Rectangle : public Figure, public Physics
	{
	public:
		Rectangle(double width, double height, double red, double green, double blue);
		~Rectangle();

		void Draw();

	private:
		double m_size_width;
		double m_size_height;
	};

}

