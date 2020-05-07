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
    std::cout << "Utworzono " << number_of_elements << " elementów int*. Nacisnij jakis klawisz aby kontynuowac." << std::endl;
    std::getchar();
}

void ex_2()
{
    const int number_of_elements = 100000000;
    for (int i = 0; i < number_of_elements; i++) {
        auto number = std::make_unique<int>();
    }
    std::cout << "Utworzono " << number_of_elements << " elementów std::unique_ptr<int>. Nacisnij jakis klawisz aby kontynuowac." << std::endl;
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
        Car &some_car = dynamic_cast<Car &>(*vehicles[i]);
    }
}


int main()
{
    std::cout << "Hello lab09!" << std::endl;

    //ex_1();
    //ex_2();
    //ex_3();
    ex_4();
    ex_5();

    sf::RenderWindow window(sf::VideoMode(800, 600), "PSiO lab98");
    std::srand(std::time(nullptr));

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

        // DRAW
        window.clear(sf::Color::Black);

        window.display();
    }

    return 0;
}
