#include "lab_s02e09_MF.h"

#include <iostream>


void AnimatedSprite::add_animation_frame(const sf::IntRect &frame) {
    frames_.emplace_back(frame);
    current_frame_ = frames_.begin();
}

void AnimatedSprite::step(const sf::Time &elapsed) {
    elapsed_accumulator_ += elapsed.asSeconds();
    while (elapsed_accumulator_ >= 1.0/fps) {
        elapsed_accumulator_ -= 1.0/fps;
        if (!frames_.empty()) {
//                setTextureRect(frames_[current_frame_]);
//                current_frame_ = (current_frame_ + 1) % frames_.size();
            setTextureRect(*current_frame_);
            current_frame_++;
            if(current_frame_ == frames_.end())
            {
                current_frame_ = frames_.begin();
            }
        }
    }
}

std::vector<std::unique_ptr<sf::Drawable>> create_shapes()
{
    std::vector<std::unique_ptr<sf::Drawable>> shapes;

    std::unique_ptr<sf::CircleShape> circle = std::make_unique<sf::CircleShape>(100.0);
    circle->setPosition(100.0, 300.0);
    circle->setFillColor(sf::Color(100, 250, 50));
    shapes.emplace_back(std::move(circle));

    std::unique_ptr<sf::RectangleShape> rectangle = std::make_unique<sf::RectangleShape>(sf::Vector2f(120.0, 60.0));
    rectangle->setPosition(500.0, 400.0);
    rectangle->setFillColor(sf::Color(100, 50, 250));
    shapes.emplace_back(std::move(rectangle));

    std::unique_ptr<sf::ConvexShape> triangle = std::make_unique<sf::ConvexShape>();
    triangle->setPointCount(3);
    triangle->setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle->setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle->setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle->setOutlineColor(sf::Color::Red);
    triangle->setOutlineThickness(5);
    triangle->setPosition(600.0, 100.0);
    shapes.emplace_back(std::move(triangle));

    return shapes;
}

sf::Texture loadTexture(const std::string &filename_with_path)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filename_with_path)) {
        std::cerr << "Could not load texture" << std::endl;
    }
    return texture;
}
