#include <iostream>
#include <math.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Window/Event.hpp>

#include "../headers/utils.hpp"
#include "../headers/RectangularPrism.hpp"

int main() {

    sf::VideoMode mode = {WINDOW_X, WINDOW_Y, 32};
    sf::RenderWindow window(mode,"hello");
    sf::Event event;

    const sf::Vector3f camera_position = {333.33333,333.33333,333.33333};
    const float camera_distance = 1000.0f;

    sf::VertexArray x_axis, y_axis, z_axis;

    init_axes(x_axis,y_axis,z_axis);
    RectangularPrism rec1 = RectangularPrism({0,0,0},{50,50,100});
    RectangularPrism rec2 = RectangularPrism({0,0,0},{50,100,50});

    sf::Texture texture;
    texture.loadFromFile("resources/face.png");
    
    rec1.texture = &texture;
    rec2.texture = &texture;

    double t = 0.0;    

    while (window.isOpen()) {
        window.setFramerateLimit(60);

        t += 0.02;
        rec1.position.x = 150 * cos(t);
        rec1.position.y = 150 * sin(t);
        
        rec2.position.z = 100 * cos(t);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            window.close();
        }

        
        window.clear(sf::Color::Black);

        window.draw(x_axis);
        window.draw(y_axis);
        window.draw(z_axis);
        rec1.draw(window);
        rec2.draw(window);

        window.display();
    }

    return 0;
}