#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

#include "CustomRectangleShape.h"


void toggleRectangles(
        std::vector<CustomRectangleShape> &rectangles,
        const sf::Vector2i &mouse_pos,
        const sf::Color &color,
        bool select
)
{
    for(auto &r : rectangles)
    {
        if(r.isClicked(mouse_pos))
        {
            if(select)
            {
                r.select();
            }
            else
            {
                r.unselect();
            }
            r.setFillColor(color);
        }
    }
}


int main()
{
    std::cout << "Hello lab08!" << std::endl;

    std::srand(std::time(nullptr));

    sf::RenderWindow window(sf::VideoMode(800, 600), "PSiO Lab08");
    window.setFramerateLimit(60);

    std::cout << "hello git";

    CustomRectangleShape my_rectangle(
                sf::Vector2f(120.0, 60.0),
                sf::Vector2f(120.0, 60.0)
    );
    my_rectangle.setFillColor(sf::Color(100, 50, 250));
    my_rectangle.setSpeed(100, 150, 10); // predkosc x, y, obrotowa
    my_rectangle.setBounds(0, window.getSize().x, 0, window.getSize().y);
    // NOTE(MF): test how the following line affects the program
    //my_rectangle.setBounds(sf::IntRect(10, 10, 400, 400));

    std::vector<CustomRectangleShape> rectangles;

    for (int i=0; i<10; i++) {
        rectangles.emplace_back(
                    CustomRectangleShape(
                        sf::Vector2f(120.0, 60.0),
                        sf::Vector2f(
                            std::rand() % (window.getSize().x - 120),
                            std::rand() % (window.getSize().y - 60)
                        )
                    )
        );
    }

    for (auto &rec : rectangles) {
        rec.setFillColor(sf::Color(0, 255, 0));
        rec.setBounds(0, window.getSize().x, 0, window.getSize().y);
        rec.setSpeed(100, 200, 10);
    }

    sf::Clock clock;

    while (window.isOpen()) {
        // EVENTS
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Space) {
                    std::cout << "Space released" << std::endl;
                    my_rectangle.toggleSelection();
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;

                    toggleRectangles(
                        rectangles,
                        mouse_pos,
                        sf::Color(std::rand() % 256, std::rand() % 256, std::rand() % 256),
                        true
                    );
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Right) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

                    toggleRectangles(
                        rectangles,
                        mouse_pos,
                        sf::Color(0, 255, 0),
                        false
                    );
                }
            }
        }

        // LOGIC
        sf::Time elapsed = clock.restart();
        my_rectangle.animate(elapsed);

        for(auto &r : rectangles)
        {
            r.animate(elapsed);
        }

        // DRAW
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(my_rectangle);

        for(const auto &rec : rectangles) {
            window.draw(rec);
        }

        // end the current frame
        window.display();
    }

    return 0;
}
