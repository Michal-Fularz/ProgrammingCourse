#include "Figure.h"

using namespace MF;

Figure::Figure(
	float x, float y,
	float red, float green, float blue
):
position_x_(x), position_y_(y),
colour_red_(red), colour_green_(green), colour_blue_(blue)
{
	rotation_z_ = 0.0f;
	flag_show_ = true;
}

void Figure::Show()
{
	flag_show_ = true;
}

void Figure::Hide()
{
	flag_show_ = false;
}

void Figure::Move(float dx, float dy)
{
	position_x_ += dx;
	position_y_ += dy;
}

void Figure::SetPosition(float x, float y)
{
	position_x_ = x;
	position_y_ = y;
}

void Figure::Rotate(float dRotationZ)
{
	rotation_z_ += dRotationZ;
}

void Figure::ChangeColour(float r, float g, float b)
{
	colour_red_ = r;
	colour_green_ = g;
	colour_blue_ = b;
}
