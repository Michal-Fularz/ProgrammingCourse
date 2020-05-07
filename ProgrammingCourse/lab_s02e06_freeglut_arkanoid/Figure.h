#pragma once

namespace MF
{
	class Figure
	{
	public:
		Figure(double red, double green, double blue);
		~Figure();

		void Show();
		void Hide();
		void Move(double dx, double dy);
		void SetPosition(double x, double y);
		void Rotate(double dgamma);
		void ChangeColour(double r, double g, double b);

		virtual void Draw() = 0;

	protected:
		double position_x_;
		double position_y_;

		double rotation_z_;

		double colour_red_;
		double colour_green_;
		double colour_blue_;

		bool flag_show_;
	};
}
