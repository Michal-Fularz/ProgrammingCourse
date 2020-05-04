#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <cmath>

int main() {
	std::cout << "Hello lab07!" << std::endl;
	
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Lab07");

    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));
	
	float rectangle_velocity_x = 50;
    float rectangle_velocity_y = -150;
    float rectangle_angular_velocity = 10;

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

    sf::Clock clock;

    int print_counter = 0;

	window.setFramerateLimit(60);
    // run the program as long as the window is open
    while (window.isOpen()) {
		// EVENTS
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

		// LOGIC
		sf::Time elapsed = clock.restart();
		rectangle.move(
            rectangle_velocity_x*elapsed.asSeconds(),
            rectangle_velocity_y*elapsed.asSeconds()
        );
        rectangle.rotate(rectangle_angular_velocity*elapsed.asSeconds());

        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();

        if(rectangle_bounds.top <= 0)
        {
            rectangle_velocity_y = std::abs(rectangle_velocity_y);
            rectangle.setFillColor(sf::Color(255, 0, 0));
        }
        if(rectangle_bounds.top+rectangle_bounds.height >= window.getSize().y)
        {
            rectangle_velocity_y = -std::abs(rectangle_velocity_y);
            rectangle.setFillColor(sf::Color(0, 255, 0));
        }
        if(rectangle_bounds.left <= 0)
        {
            rectangle_velocity_x = std::abs(rectangle_velocity_x);
            rectangle.setFillColor(sf::Color(0, 0, 255));
        }
        if(rectangle_bounds.left+rectangle_bounds.width >= window.getSize().x)
        {
            rectangle_velocity_x = -std::abs(rectangle_velocity_x);
            rectangle.setFillColor(sf::Color(255, 0, 255));
        }

        if(print_counter == 50)
        {
            std::cout << "Elapsed time: " << elapsed.asMicroseconds() << ", fps: " << 1/elapsed.asSeconds() << std::endl;

            std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " " ;
            std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;
            print_counter = 0;
        }
        else
        {
            print_counter++;
        }

		// DRAW
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);

        // end the current frame
        window.display();
    }

    return 0;
}
