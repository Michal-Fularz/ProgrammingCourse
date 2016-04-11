#pragma once

#include "Figure.h"
#include "Physics.h"

#define NDEBUG
#include <GL/freeglut.h>

namespace MF
{

	class Rectangle : public Figure, public Physics
	{
	public:
		Rectangle(double width, double height, double red, double green, double blue);
		~Rectangle();

		void Draw();

		void UpdatePhysicsPosition();
		void UpdateFigurePosition();

	private:
		double m_size_width;
		double m_size_height;
	};

}

