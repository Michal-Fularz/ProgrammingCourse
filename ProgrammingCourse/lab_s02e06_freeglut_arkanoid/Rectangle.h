#pragma once

#include "Physics.h"

namespace MF
{
	class Rectangle : public Physics
	{
	public:
		Rectangle(double width, double height, double red, double green, double blue);
		~Rectangle();

		void Draw();

	private:
		double width_;
		double height_;
	};
}
