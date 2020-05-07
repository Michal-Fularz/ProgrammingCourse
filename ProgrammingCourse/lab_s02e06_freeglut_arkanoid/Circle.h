#pragma once

#include "Figure.h"
#include "Physics.h"

namespace MF
{
	class Circle : public Physics
	{
	public:
		Circle(double radius, double red, double green, double blue);
		~Circle();

		void Draw();

	private:
		double radius_;
	};
}

