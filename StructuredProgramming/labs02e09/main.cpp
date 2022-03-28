#include <iostream>
#include <memory>
#include <ctime>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


void ex_1()
{
    //  2 147 483 647 - 2^32,
    //    100 000 000
    //  1 000 000 000
    // 10 000 000 000
    const int number_of_elements = 100000000;
    for (int i = 0; i < number_of_elements; i++) {
        int *number = new int;
        delete number;
    }
    std::cout << "Utworzono " << number_of_elements << " wskaznikow na wartosc typu int. Nacisnij jakis klawisz aby kontynuowac." << std::endl;
    std::getchar();
}


void ex_2()
{
    const int number_of_elements = 100000000;
    for (int i = 0; i < number_of_elements; i++) {
        auto number = std::make_unique<int>();
    }
    std::cout << "Utworzono " << number_of_elements << " elementow w std::unique_ptr<int>. Nacisnij jakis klawisz aby kontynuowac." << std::endl;
    std::getchar();
}

void ex_3()
{
    std::vector<std::unique_ptr<int>> some_pointers;
    const int number_of_elements = 100000000;
    for (int i = 0; i < number_of_elements; i++) {
        auto number = std::make_unique<int>();
        some_pointers.emplace_back(std::move(number));
    }
    std::cout << "Umieszczono " << number_of_elements << " elementow w std::vector<std::unique_ptr<int>>. Nacisnij jakis klawisz aby kontynuowac." << std::endl;
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
    std::unique_ptr<Vehicle> skoda_superb_as_vehicle = std::make_unique<Car>("Skoda Superb", "Gasoline", 200, true);

    std::cout << "Name: " << skoda_superb_as_vehicle->name() << std::endl;
    //std::cout << "Has ABS: " << skoda_superb_as_vehicle->has_abs() << std::endl;
}

void ex_5()
{
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    vehicles.emplace_back(std::make_unique<Car>("Skoda Superb", "Gasoline", 200, true));
    vehicles.emplace_back(std::make_unique<Bike>());

    for (size_t i = 0; i < vehicles.size(); i++) {
        vehicles[i]->number_of_wheels();
        try {
            Car &some_car = dynamic_cast<Car &>(*vehicles[i]);
            std::cout << "Has ABS: " << some_car.has_abs() << std::endl;
        } catch (std::exception e) {
            std::cout << e.what() << std::endl;
        }
    }
}

enum TextureType
{
    Grass = 0,
    Wall = 1,
    Guy = 2,
    Character = 3
};

std::vector<std::unique_ptr<sf::Drawable>> create_shapes(
        const std::vector<sf::Texture> &textures
)
{
    std::vector<std::unique_ptr<sf::Drawable>> shapes;

    auto circle = std::make_unique<sf::CircleShape>(100.0);
    circle->setPosition(100.0, 300.0);
    circle->setFillColor(sf::Color(100, 250, 50));
    shapes.emplace_back(std::move(circle));

    auto rectangle = std::make_unique<sf::RectangleShape>(sf::Vector2f(120.0, 60.0));
    rectangle->setPosition(500.0, 400.0);
    rectangle->setFillColor(sf::Color(100, 50, 250));
    shapes.emplace_back(std::move(rectangle));

    auto triangle = std::make_unique<sf::ConvexShape>();
    triangle->setPointCount(3);
    triangle->setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle->setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle->setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle->setOutlineColor(sf::Color::Red);
    triangle->setOutlineThickness(5);
    triangle->setPosition(600.0, 100.0);
    shapes.emplace_back(std::move(triangle));

    {
        auto sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(textures[TextureType::Grass]);
        sprite->setPosition(200, 20);
        shapes.emplace_back(std::move(sprite));
    }

    {
        auto sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(textures[TextureType::Wall]);
        sprite->setPosition(20, 200);
        sprite->setScale(1.5, 1.5);
        shapes.emplace_back(std::move(sprite));
    }

    {
        auto sprite = std::make_unique<sf::Sprite>();
        sprite->setTexture(textures[TextureType::Guy]);
        sprite->setTextureRect(sf::IntRect(10, 20, 20, 15)); //left, top, width, height
        shapes.emplace_back(std::move(sprite));
    }

    return shapes;
}



sf::Texture loadTexture(std::string filename_with_path)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filename_with_path)) {
        std::cerr << "Could not load texture" << std::endl;
    }
    return texture;
}

class AnimatedSprite: public sf::Sprite
{
public:
    AnimatedSprite() : sf::Sprite()
    {
        current_frame_index_ = 0;
    }

    void add_animation_frame(const sf::IntRect &frame)
    {
        frames_.emplace_back(frame);
        current_frame_itr_ = frames_.begin();
    }

    void step(sf::Time elapsed)
    {
        if(current_frame_index_ < frames_.size()-1)
        {
            current_frame_index_++;
        }
        else
        {
            current_frame_index_ = 0;
        }
        setTextureRect(frames_[current_frame_index_]);
    }

    void step_itr()
    {
        if(current_frame_itr_ < frames_.end()-1)
        {
            current_frame_itr_++;
        }
        else
        {
            current_frame_itr_ = frames_.begin();
        }
        setTextureRect(*current_frame_itr_);
    }

private:
    std::vector<sf::IntRect> frames_;
    std::vector<sf::IntRect>::iterator current_frame_itr_;
    size_t current_frame_index_;

//    sf::Time elapsed_time_accumulator



};

void ex_6()
{
    std::srand(std::time(nullptr));

    std::vector<sf::Texture> textures;
    textures.emplace_back(loadTexture("./../data/lab_s02e09/grass.png"));
    textures.emplace_back(loadTexture("./../data/lab_s02e09/wall.png"));
    textures.emplace_back(loadTexture("./../data/lab_s02e09/guy.png"));
    textures.emplace_back(loadTexture("./../data/lab_s02e09/character.png"));

    sf::RenderWindow window(sf::VideoMode(800, 600), "PSiO Lab08");
    window.setFramerateLimit(60);

    std::vector<std::unique_ptr<sf::Drawable>> shapes = create_shapes(textures);

    AnimatedSprite hero;
    hero.setTexture(textures[TextureType::Character]);
    hero.setPosition(100, 100);
    hero.setScale(3.0, 3.0);

    /* add texture, set parameters, etc. */

    for(int i=0; i<(9*50); i+=50)
    {
        hero.add_animation_frame(sf::IntRect(i, 0, 50, 37));
    }


    sf::Clock clock;

    while (window.isOpen()) {
        // EVENTS
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // LOGIC
        sf::Time elapsed = clock.restart();
        hero.step_itr();

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
//    ex_4();
//    ex_5();

    ex_6();

    return 0;
}
