#pragma once

#include "Figure.h"

namespace MF
{
	class Rectangle : public Figure
	{
	public:
		Rectangle(
			float width, float height,
			float x, float y,
			float red, float green, float blue
		);
		~Rectangle() = default;

		void Draw();

	private:
		double width_;
		double height_;
	};
}
