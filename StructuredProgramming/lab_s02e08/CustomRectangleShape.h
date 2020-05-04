#pragma once

#include <SFML/Graphics.hpp>


struct Bounds
{
    int left = 0;
    int right = 0;
    int top = 0;
    int bottom = 0;
};


class CustomRectangleShape : public sf::RectangleShape
{
public:
    // NOTE(MF): the default constructor is here only to show how to call another constuctor from a constructor
    CustomRectangleShape();
    CustomRectangleShape(const sf::Vector2f &size, const sf::Vector2f &position);
    void setSpeed(int speed_x_, int speed_y, int speed_r);
    void animate(const sf::Time &elapsed);
    void setBounds(int left, int right, int top, int bottom);
    void setBounds(const sf::IntRect &rect);
    void select();
    void unselect();
    void toggleSelection();
    bool isClicked(const sf::Vector2i &mouse_position) const;

private:
    int speed_x_ = 0;
    int speed_y_ = 0;
    int speed_r_ = 0;

    // NOTE(MF): there are few different options to keep the bounds information
    // each has some pros and cons
    // 1
    // int left_bound = 0;
    // int right_bound = 0;
    // int top_bound = 0;
    // int bottom_bound = 0;

    // 2
    // sf::IntRect boundsRect;

    // 3
    Bounds bounds_;

    void bounce();

    bool is_selected_ = false;
};
