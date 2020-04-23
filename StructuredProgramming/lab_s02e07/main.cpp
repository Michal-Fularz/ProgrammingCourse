#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

    sf::Clock clock;

    int rectangle_velocity_x = 100;
    int rectangle_velocity_y = 150;
    int rectangle_angular_velocity = 10;

    int print_counter = 0;

    // run the program as long as the window is open
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        rectangle.move(rectangle_velocity_x * elapsed.asSeconds(), rectangle_velocity_y * elapsed.asSeconds());
        rectangle.rotate(rectangle_angular_velocity * elapsed.asSeconds());

        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);

        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();

        bool bounce = false;
        if(rectangle_bounds.top <= 0)
        {
            rectangle_velocity_y = abs(rectangle_velocity_y);
            bounce = true;
        }
        if(rectangle_bounds.top + rectangle_bounds.height >= window.getSize().y)
        {
            rectangle_velocity_y = -abs(rectangle_velocity_y);
            bounce = true;
        }
        if(rectangle_bounds.left <= 0)
        {
            rectangle_velocity_x = abs(rectangle_velocity_x);
            bounce = true;
        }
        if(rectangle_bounds.left + rectangle_bounds.width >= window.getSize().x)
        {
            rectangle_velocity_x = -abs(rectangle_velocity_x);
            bounce = true;
        }
        if(bounce)
        {
            int R = std::rand() % 255;
            int G = std::rand() % 255;
            int B = std::rand() % 255;
            rectangle.setFillColor(sf::Color(R, G, B));
        }

        if(print_counter == 1000)
        {
            std::cout << elapsed.asMicroseconds() << " ms - " << 1.0 / elapsed.asSeconds() << " fps"  << std::endl;
            std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " " ;
            std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;
            print_counter = 0;
        }
        else
        {
            print_counter++;
        }

        // end the current frame
        window.display();
    }

    return 0;
}
