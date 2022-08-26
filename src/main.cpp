#include <iostream>
#include <math.h>
#include <typeinfo> 

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Window/Event.hpp>

#include "../headers/utils.hpp"
#include "../headers/RectangularPrism.hpp"
#include "../headers/Line.hpp"
#include "../headers/Plane.hpp"

int main() {
    sf::VideoMode mode = {WINDOW_X, WINDOW_Y, 32};
    sf::RenderWindow window(mode,"hello");
    sf::Event event;

    RectangularPrism* player = new RectangularPrism({100,0,0},{50,50,50});

    Plane* plane = new Plane({-200,-200,0},{400,400});

    sf::Texture texture;
    texture.loadFromFile("resources/face.png");
    
    for(auto e: Entity::entities) {
        if (typeid(*e) == typeid(RectangularPrism)) {
            RectangularPrism* p = (RectangularPrism*)e;
            p->texture = &texture;
        } else if(typeid(*e) == typeid(Plane)) {
            Plane* p = (Plane*)e;
            p->texture = &texture;
        }
    }
    
    float t = 0.0;

    while (window.isOpen()) {
        window.setFramerateLimit(60);

        t += 0.01;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    player->position.x -= 50;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    player->position.x += 50;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    player->position.y -= 50;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    player->position.y += 50;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    player->position.z += 50;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                    player->position.z -= 50;
                }
            }
        }

        
        window.clear(sf::Color::Black);

        Entity::entities = Entity::reorder_entities(Entity::entities);
        for (auto e: Entity::entities) {
            if (e != nullptr) {
                e->draw(window);
            }
        }

        window.display();
    }
    for (auto e: Entity::entities) {
        delete e;
    }

    return 0;
}