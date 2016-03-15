#pragma once

namespace MF
{

	class Rectangle
	{
	private:
		double m_width;
		double m_height;

		double m_position_x;
		double m_position_y;

		double m_rotation_z;

		double m_colour_red;
		double m_colour_green;
		double m_colour_blue;


	public:
		Rectangle(double x, double y, double red, double green, double blue);
		~Rectangle();

		void Draw();
		void Move(double dx, double dy);
		void ChangeColour(double red, double green, double blue);
	};

}

