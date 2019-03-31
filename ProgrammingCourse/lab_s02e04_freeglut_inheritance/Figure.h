#pragma once


namespace MF
{
	class Figure
	{
	public:
		Figure(
			float x, float y,
			float red, float green, float blue
		);
		virtual ~Figure() = default;
		
		void Show();
		void Hide();
		void Move(float dx, float dy);
		void SetPosition(float x, float y);
		void Rotate(float dRotationZ);
		void ChangeColour(float r, float g, float b);

		virtual void Draw() = 0;

	protected:
		float position_x_;
		float position_y_;

		float rotation_z_;

		float colour_red_;
		float colour_green_;
		float colour_blue_;

		bool flag_show_;
	};
}
