#include <iostream>
#include <ctime>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


#include "CustomRectangleShape.h"


int main()
{
    std::cout << "Hello lab08!" << std::endl;

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "PSiO lab08");
    std::srand(std::time(nullptr));

    std::vector<CustomRectangleShape> rectangles;
    for(int i=0; i<10; i++)
    {
        rectangles.emplace_back(
                    CustomRectangleShape(
                        sf::Vector2f(120.0f, 60.0f),
                        sf::Vector2f(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60))
                    )
        );
    }
    for(auto &r : rectangles)
    {
        r.setFillColor(sf::Color(0, 255, 0));
        r.setBounds(0, window.getSize().x, 0, window.getSize().y);
        r.setSpeed(100, 200, 10);
    }

    sf::Clock clock;
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if(event.type == sf::Event::Closed)
            {
                std::cout << "Closing the window" << std::endl;
                window.close();
            }
            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Space)
                    std::cout << "Space released" << std::endl;
            }
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    for(auto &rec : rectangles)
                    {
                        if(rec.isClicked(mouse_pos))
                        {
                            for(auto &r : rectangles)
                            {
                                r.unselect();
                                r.setFillColor(sf::Color(0, 255, 0));
                            }
                            rec.setFillColor(sf::Color(255, 0, 0));
                            rec.select();
                        }
                    }
                }
            }
        }
        const sf::Time elapsed = clock.restart();
        for(auto &rec : rectangles)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                rec.moveInDirection(elapsed, sf::Keyboard::Up);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                rec.moveInDirection(elapsed, sf::Keyboard::Down);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                rec.moveInDirection(elapsed, sf::Keyboard::Left);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                rec.moveInDirection(elapsed, sf::Keyboard::Right);
        }

        for(auto &r : rectangles)
        {
            r.animate(elapsed);
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        for(const auto &r : rectangles)
        {
            window.draw(r);
        }
        window.display();
    }

    return 0;
}
