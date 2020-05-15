#include <exception>
#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "lab_s02e09_MF.h"

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

void ex_4()
{
    std::unique_ptr<Vehicle> skoda_superb_as_vehicle = std::make_unique<Car>(
        "Skoda Superb", "Gasoline", 200, true);

    std::cout << "Name: " << skoda_superb_as_vehicle->name() << std::endl;
    //std::cout << "Has ABS: " << skoda_superb_as_vehicle->has_abs() << std::endl;
}

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

    ex_1();
    ex_2();
    ex_3();
    ex_4();
    ex_5();
    ex_6();


    return 0;
}
