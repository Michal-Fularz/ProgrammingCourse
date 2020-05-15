#include <iostream>
#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void ex_1()
{
    //  2,147,483,647
    // 10,000,000,000
    //    100,000,000
    const int number_of_elements = 100000000;
    for (int i = 0; i < number_of_elements; i++) {
        int *number = new int;
    }
    std::cout << "Utworzono " << number_of_elements << " elementów int*. Nacisnij klawisz aby kontynuowac." << std::endl;
    std::getchar();
}

void ex_2()
{
    const int number_of_elements = 100000000;
    for (int i = 0; i < number_of_elements; i++) {
        auto number = std::make_unique<int>();
    }
    std::cout << "Utworzono " << number_of_elements << " elementów std::unique_ptr<int>. Nacisnij klawisz aby kontynuowac." << std::endl;
    std::getchar();
}

void ex_3()
{
    const int number_of_elements = 100000000;
    std::vector<std::unique_ptr<int>> some_pointers;
    for (int i = 0; i < 100000000; i++) {
        auto number = std::make_unique<int>();
        some_pointers.emplace_back(std::move(number));
    }
    std::cout << "Umieszczono " << number_of_elements << " elementow w std::vector<std::unique_ptr<int>>. Nacisnij klawisz aby kontynuowac." << std::endl;
    std::getchar();
}

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

void ex_4()
{
    std::unique_ptr<Vehicle> skoda_superb_as_vehicle = std::make_unique<Car>(
        "Skoda Superb", "Gasoline", 200, true);

    std::cout << "Name: " << skoda_superb_as_vehicle->name() << std::endl;
    //std::cout << "Has ABS: " << skoda_superb_as_vehicle->has_abs() << std::endl;
}

#include <exception>

void ex_5()
{
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    vehicles.emplace_back(std::make_unique<Car>("Skoda Superb", "Gasoline", 200, true));
    vehicles.emplace_back(std::make_unique<Bike>());

    for (size_t i = 0; i < vehicles.size(); i++) {
        try {
            Car &some_car = dynamic_cast<Car &>(*vehicles[i]);
            std::cout << "Has ABS: " << some_car.has_abs() << std::endl;
        } catch (std::exception e) {
            std::cout << e.what() << std::endl;
        }

    }
}

class AnimatedSprite : public sf::Sprite {
public:
    AnimatedSprite() : sf::Sprite() {
    }

    void add_animation_frame(const sf::IntRect &frame) {
        frames_.emplace_back(frame);
        current_frame_ = frames_.begin();
    }

    void step(const sf::Time &elapsed) {
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

private:
    std::vector<sf::IntRect> frames_;
    std::vector<sf::IntRect>::iterator current_frame_ = frames_.begin();
//    size_t current_frame_ = 0;
    float elapsed_accumulator_ = 0;
    float fps = 10;
};

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

void ex_6()
{
    sf::Texture texture_grass = loadTexture("./../data/lab_s02e09/grass.png");
    sf::Texture texture_wall = loadTexture("./../data/lab_s02e09/wall.png");
    texture_wall.setRepeated(true);
    sf::Texture texture_guy = loadTexture("./../data/lab_s02e09/guy.png");
    sf::Texture texture_hero = loadTexture("./../data/lab_s02e09/character.png");

    sf::RenderWindow window(sf::VideoMode(800, 600), "PSiO lab09");
    std::srand(std::time(nullptr));

    auto shapes = create_shapes();

    {
        std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(texture_grass);
        sprite->setScale(0.5, 0.5);
        sprite->setPosition(20, 20);
        shapes.emplace_back(std::move(sprite));
    }

    {
        std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(texture_guy);
        sprite->setTextureRect(sf::IntRect(10, 20, 20, 15)); //left, top, width, height
        sprite->setPosition(50, 50);
        shapes.emplace_back(std::move(sprite));
    }

    {
        std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(texture_wall);
        sprite->setScale(0.3, 0.3);
        sprite->setTextureRect(sf::IntRect(0, 0, 500, 500));
        sprite->setPosition(20, 200);
        shapes.emplace_back(std::move(sprite));
    }

    {
        std::unique_ptr<sf::Sprite> sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(texture_wall);
        sprite->setScale(1.5, 1.5);
        sprite->setPosition(200, 20);
        shapes.emplace_back(std::move(sprite));
    }

    AnimatedSprite hero;
    hero.setTexture(texture_hero);
    hero.add_animation_frame(sf::IntRect(0, 0, 50, 37)); // first frame of animation
    hero.add_animation_frame(sf::IntRect(50, 0, 50, 37)); // second frame
    hero.add_animation_frame(sf::IntRect(100, 0, 50, 37)); // third frame

    sf::Clock clock;

    while (window.isOpen()) {
        // EVENTS
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
            {
                std::cout << "Closing the window" << std::endl;
                window.close();
            }
        }

        // LOGIC
        const sf::Time elapsed = clock.restart();

        hero.step(elapsed);

        // DRAW
        window.clear(sf::Color::Black);

        for(const auto &s : shapes) {
            window.draw(*s);
        }
        window.draw(hero);

        window.display();
    }
}


int main()
{
    std::cout << "Hello lab09!" << std::endl;

//    ex_1();
//    ex_2();
//    ex_3();
    ex_4();
    ex_5();
    ex_6();


    return 0;
}
