#pragma once

#include "Figure.h"

namespace MF
{
	class Circle : public Figure
	{
	public:
		Circle(
			float radius,
			float x, float y,
			float red, float green, float blue
		);
		~Circle() = default;

		void Draw() override;

	private:
		double radius_;
	};
}
