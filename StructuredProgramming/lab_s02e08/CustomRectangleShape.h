#pragma once

#include <SFML/Graphics.hpp>


class CustomRectangleShape : public sf::RectangleShape {
public:
    CustomRectangleShape(const sf::Vector2f &size, const sf::Vector2f &position);

    void setSpeed(int speed_x, int speed_y, int speed_r);

    bool setBounds(int left, int right, int top, int bottom);

    void select();
    void unselect();

    void animate(const sf::Time &elapsed);

    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key);

    bool isClicked(const sf::Vector2i &mouse_position) const;

private:
    int m_speed_x = 0;
    int m_speed_y = 0;
    int m_speed_r = 0;
    int m_left_bound = 0;
    int m_right_bound = 0;
    int m_top_bound = 0;
    int m_bottom_bound = 0;
    bool m_is_selected  = false;

    void bounce();
};
