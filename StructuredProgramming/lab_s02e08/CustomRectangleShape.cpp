#include "customrectangleshape.h"

CustomRectangleShape::CustomRectangleShape(
) : CustomRectangleShape(
          sf::Vector2f(100, 100),
          sf::Vector2f(50, 50)
      )
{
}

CustomRectangleShape::CustomRectangleShape(
        const sf::Vector2f &size,
        const sf::Vector2f &position
) : sf::RectangleShape(size)
{
    setPosition(position);
}

void CustomRectangleShape::setSpeed(
        int speed_x,
        int speed_y,
        int speed_r
)
{
    speed_x_ = speed_x;
    speed_y_ = speed_y;
    speed_r_ = speed_r;
}

void CustomRectangleShape::animate(const sf::Time &elapsed)
{
    if(!is_selected_)
    {
        move(
            speed_x_*elapsed.asSeconds(),
            speed_y_*elapsed.asSeconds()
        );
        rotate(speed_r_*elapsed.asSeconds());
        bounce();
    }
    else
    {
        sf::FloatRect rectangle_bounds = getGlobalBounds();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if(rectangle_bounds.top > bounds_.top) {
                move(0, -100*elapsed.asSeconds());
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if(rectangle_bounds.top+rectangle_bounds.height < bounds_.bottom){
                move(0, 100*elapsed.asSeconds());
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            move(-100*elapsed.asSeconds(), 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            move(100*elapsed.asSeconds(), 0);
        }
    }
}

void CustomRectangleShape::setBounds(int left, int right, int top, int bottom)
{
    bounds_.left = left;
    bounds_.right = right;
    bounds_.top = top;
    bounds_.bottom = bottom;
}

void CustomRectangleShape::setBounds(const sf::IntRect &rect)
{
    setBounds(
            rect.left, rect.left+rect.width,
            rect.top, rect.top+rect.height
   );
}

void CustomRectangleShape::bounce()
{
    sf::FloatRect rectangle_bounds = getGlobalBounds();

    if(rectangle_bounds.top <= bounds_.top)
    {
        speed_y_ = std::abs(speed_y_);
    }
    if(rectangle_bounds.top+rectangle_bounds.height >= bounds_.bottom)
    {
        speed_y_ = -std::abs(speed_y_);
    }
    if(rectangle_bounds.left <= bounds_.left)
    {
        speed_x_ = std::abs(speed_x_);
    }
    if(rectangle_bounds.left+rectangle_bounds.width >= bounds_.right)
    {
        speed_x_ = -std::abs(speed_x_);
    }
}

void CustomRectangleShape::select()
{
    is_selected_ = true;
}

void CustomRectangleShape::unselect()
{
    is_selected_ = false;
}

void CustomRectangleShape::toggleSelection()
{
    is_selected_ = !is_selected_;
}

bool CustomRectangleShape::isClicked(const sf::Vector2i &mouse_position) const
{
    sf::FloatRect rectangle_bounds = getGlobalBounds();

    if(mouse_position.x >= rectangle_bounds.left &&
       mouse_position.x <= rectangle_bounds.left+rectangle_bounds.width &&
       mouse_position.y >= rectangle_bounds.top &&
       mouse_position.y <= rectangle_bounds.top+rectangle_bounds.height
      )
    {
        return true;
    }
    else
    {
        return false;
    }
}
