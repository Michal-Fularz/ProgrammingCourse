#include "CustomRectangleShape.h"


CustomRectangleShape::CustomRectangleShape(
        const sf::Vector2f &size,
        const sf::Vector2f &position
) : sf::RectangleShape(size)
{
    setPosition(position);
}

void CustomRectangleShape::setSpeed(int speed_x, int speed_y, int speed_r)
{
    m_speed_x = speed_x;
    m_speed_y = speed_y;
    m_speed_r = speed_r;
}

bool CustomRectangleShape::setBounds(int left, int right, int top, int bottom)
{
    if(left <= right && top <= bottom)
    {
        m_left_bound = left;
        m_right_bound = right;
        m_top_bound = top;
        m_bottom_bound = bottom;
        return true;
    }
    return false;
}

void CustomRectangleShape::select()
{
    m_is_selected = true;
}

void CustomRectangleShape::unselect()
{
    m_is_selected = false;
}

void CustomRectangleShape::animate(const sf::Time &elapsed)
{
    if(!m_is_selected)
    {
        move(elapsed.asSeconds() * m_speed_x, elapsed.asSeconds() * m_speed_y);
        rotate(elapsed.asSeconds() * m_speed_r);
        bounce();
    }
}
void CustomRectangleShape::moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key)
{
    if(m_is_selected)
    {
        sf::FloatRect rect = getGlobalBounds();
        switch(key)
        {
            case sf::Keyboard::Left:
                if(rect.left > m_left_bound)
                    move(-elapsed.asSeconds() * abs(m_speed_x), 0);
                break;
            case sf::Keyboard::Right:
                if(rect.left + rect.width < m_right_bound)
                    move(elapsed.asSeconds() * abs(m_speed_x), 0);
                break;
            case sf::Keyboard::Up:
                if(rect.top > m_top_bound)
                    move(0, -elapsed.asSeconds() * abs(m_speed_y));
                break;
            case sf::Keyboard::Down:
                if(rect.top + rect.height < m_bottom_bound)
                    move(0, elapsed.asSeconds() * abs(m_speed_y));
                break;
            default:
                break;
        }
    }
}
bool CustomRectangleShape::isClicked(const sf::Vector2i &mouse_position) const
{
    sf::FloatRect rect = getGlobalBounds();
    if(rect.left <= mouse_position.x && (rect.left + rect.width) >= mouse_position.x)
    {
        if(rect.top <= mouse_position.y && (rect.top + rect.height) >= mouse_position.y)
        {
            return true;
        }
    }
    return false;
}

void CustomRectangleShape::bounce()
{
    sf::FloatRect rect = getGlobalBounds();
    if(rect.left <= m_left_bound)
    {
        m_speed_x = abs(m_speed_x);
    }
    if(rect.left + rect.width >= m_right_bound)
    {
        m_speed_x = -abs(m_speed_x);
    }
    if(rect.top <= m_top_bound)
    {
        m_speed_y = abs(m_speed_y);
    }
    if(rect.top + rect.height >= m_bottom_bound)
    {
        m_speed_y = -abs(m_speed_y);
    }
}
