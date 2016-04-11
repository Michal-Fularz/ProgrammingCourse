#pragma once

#include "Figure.h"
#include "Physics.h"

#define NDEBUG
#include <GL/freeglut.h>

#define _USE_MATH_DEFINES
#include <cmath>

using namespace MF;

namespace MF
{
	class Circle : public Figure, public Physics
	{
	public:
		Circle(double radius, double red, double green, double blue);
		~Circle();

		void Draw();

		void UpdatePhysicsPosition();
		void UpdateFigurePosition();

	private:
		double m_size_radius;
	};
}

