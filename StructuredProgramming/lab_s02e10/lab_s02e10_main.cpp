#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <GL/glu.h>

#include "planet.h"


void set_viewport(int width, int height) {
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    gluLookAt(0, -5, 3, 0, 0, 0, 0, 0, 1);

    //    glMatrixMode(GL_MODELVIEW);
    //    glLoadIdentity();
}

void ex_1()
{
    sf::Window window(sf::VideoMode(1024, 768), "SFML OpenGL Template", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    window.setActive(true);

    // set viewport according to current window size
    set_viewport(window.getSize().x, window.getSize().y);

    glClearColor(0, 0, 0, 1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);
    glShadeModel(GL_SMOOTH);

    // setup lights
    GLfloat light_position[] = { 2.0, 0.0, 2.0, 1.0 };
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat light_specular[] = { 0.0, 0.0, 0.0, 1.0 };

    glLightfv( GL_LIGHT0, GL_POSITION, light_position);
    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );

    GLfloat global_ambient[] = {0.3, 0.3, 0.3, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    glEnable(GL_NORMALIZE) ;

    // load resources, initialize the OpenGL states, ...

    std::vector<Planet> objects;
    // objects.push_back(Planet(2.0, 0.0, 5.0, 0.0)); //double diameter = 1.0, double distance = 0.0, double spin_period = 0.0, double rotation_period = 0.0

    // load planets
    std::fstream solar_system_file("./../data/lab_s02e10/solar_system.txt");
    if (!solar_system_file.is_open()) {
        std::cerr << "Could not open file" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(solar_system_file, line)) {
        if (!line.empty() && line[0] != '#') {
            std::stringstream line_str(line);

            std::string name;
            double distance;
            double diameter;
            double spin_period;
            double orbit_period;
            double gravity;
            int number_of_moons;
            double r;
            double g;
            double b;
            line_str >> name >> distance >> diameter >> spin_period >> orbit_period >> gravity >> number_of_moons >> r >> g >> b;
            std::cout << name << " " << diameter << std::endl;

            objects.push_back(Planet(diameter, distance, spin_period, orbit_period));
            objects.back().set_color(r/255.0, g/255.0, b/255.0);
        }
    }

    // run the main loop
    bool running = true;
    sf::Clock clk;
    while (running) {
        double delta_t = clk.getElapsedTime().asSeconds();
        clk.restart();

        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // end the program
                running = false;
            } else if (event.type == sf::Event::Resized) {
                // adjust the viewport when the window is resized
                set_viewport(event.size.width, event.size.height);
            } else if (event.type == sf::Event::MouseWheelScrolled) {
                std::cerr << event.mouseWheelScroll.delta <<std::endl;
            }
        }

        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE) ;
        glEnable (GL_COLOR_MATERIAL);

        // draw stuff

        glPushMatrix();

        glScaled(1.0/1500, 1.0/1500, 1.0/1500);

        for (auto &p : objects) {
            p.step(delta_t);
            p.draw();
        }

        glPopMatrix();

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }
}

int main()
{
    std::cout << "Hello lab10!" << std::endl;

    ex_1();

    return 0;
}
