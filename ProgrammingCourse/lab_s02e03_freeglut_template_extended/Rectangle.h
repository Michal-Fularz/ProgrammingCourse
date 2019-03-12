#pragma once


namespace MF
{
	class Rectangle
	{
	private:
		double width_;
		double height_;

		double position_x_;
		double position_y_;

		double rotation_z_;

		double colour_red_;
		double colour_green_;
		double colour_blue_;

	public:
		Rectangle(
			double x, double y, 
			double red, double green, double blue
		);
		~Rectangle();

		void Draw();
		void Move(double dx, double dy);
		void ChangeColour(
			double red, double green, double blue
		);
	};
}
