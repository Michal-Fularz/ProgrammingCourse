#include "Figure.h"

using namespace MF;

Figure::Figure(double red, double green, double blue)
	: colour_red_(red), colour_green_(green), colour_blue_(blue)
{
	position_x_ = 0.0;
	position_y_ = 0.0;
	rotation_z_ = 0.0;
	flag_show_ = true;
}

Figure::~Figure()
{
}

void Figure::Show()
{
	flag_show_ = true;
}

void Figure::Hide()
{
	flag_show_ = false;
}

void Figure::Move(double dx, double dy)
{
	position_x_ += dx;
	position_y_ += dy;
}

void Figure::SetPosition(double x, double y)
{
	position_x_ = x;
	position_y_ = y;
}

void Figure::Rotate(double drotation_z)
{
	rotation_z_ += drotation_z;
}

void Figure::ChangeColour(double r, double g, double b)
{
	colour_red_ = r;
	colour_green_ = g;
	colour_blue_ = b;
}