#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class Vehicle {
public:
    std::string name() { return name_; }
    int number_of_wheels() { return number_of_wheels_; }
    std::string propulsion_type() { return propulsion_type_; }
    double max_speed() { return max_speed_; }

    virtual ~Vehicle() = default;

protected:
    Vehicle(const std::string &name, int number_of_wheels,
            const std::string &propulsion_type, double max_speed)
        : name_(name), number_of_wheels_(number_of_wheels),
          propulsion_type_(propulsion_type), max_speed_(max_speed) {}

    std::string name_;
    int number_of_wheels_;
    std::string propulsion_type_;
    double max_speed_;
};

class Car : public Vehicle {
public:
    Car(const std::string &name, const std::string &propulsion_type,
        double max_speed, bool has_abs)
        : Vehicle(name, 4, propulsion_type, max_speed),
          has_abs_(has_abs) {}

    bool has_abs() { return has_abs_; }

private:
    bool has_abs_;
};

class Bike : public Vehicle {
public:
    Bike()
        : Vehicle("Fuji", 4, "pedals", 2.0)
    {}
};

class AnimatedSprite : public sf::Sprite {
public:
    AnimatedSprite() : sf::Sprite()
    {
    }
    void add_animation_frame(const sf::IntRect &frame);
    void step(const sf::Time &elapsed);

private:
    std::vector<sf::IntRect> frames_;
    std::vector<sf::IntRect>::iterator current_frame_ = frames_.begin();
//    size_t current_frame_ = 0;
    float elapsed_accumulator_ = 0;
    float fps = 10;
};

std::vector<std::unique_ptr<sf::Drawable>> create_shapes();

sf::Texture loadTexture(const std::string &filename_with_path);

