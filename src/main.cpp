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
#include "../headers/Plane.hpp"
#include "../headers/Camera.hpp"
#include "../headers/Hitbox.hpp"
#include "../headers/Player.hpp"

extern sf::Clock dt;

int main() {
    sf::VideoMode mode = {WINDOW_X, WINDOW_Y, 32};
    sf::RenderWindow window(mode,"hello");
    sf::Event event;

    Camera camera(window.getView());

    Player* player = new Player({0,PANEL_SIZE,1},{PANEL_SIZE,PANEL_SIZE,PANEL_SIZE});
    player->do_collision = true;

    RectangularPrism* box1 = new RectangularPrism({0,-PANEL_SIZE,1},{PANEL_SIZE,PANEL_SIZE,PANEL_SIZE});
    box1->do_collision = true;

    RectangularPrism* box2 = new RectangularPrism({0,0,1+PANEL_SIZE},{PANEL_SIZE,PANEL_SIZE,PANEL_SIZE});
    box2->do_collision = true;

    Plane* plane = new Plane({-PANEL_SIZE*3,-PANEL_SIZE*3,0},{PANEL_SIZE*7,PANEL_SIZE*7});
    plane->do_collision = true;

    
    // load textures
    sf::Texture texture;
    texture.loadFromFile("resources/face.png");
    for(auto e: Entity::entities) {
        if (typeid(*e) == typeid(RectangularPrism)) {
            RectangularPrism* p = (RectangularPrism*)e;
            p->texture_array[0] = &texture;
            p->texture_array[1] = &texture;
            p->texture_array[2] = &texture;
        } else if(typeid(*e) == typeid(Plane)) {
            Plane* p = (Plane*)e;
            p->texture = &texture;
        }
    }
    
    float t = 0.0;

    dt.restart();

    while (window.isOpen()) {
        window.setFramerateLimit(60);

        t += dt.getElapsedTime().asSeconds();

        player->update_collision();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    if (player->can_move_forward()) {
                        player->move_forward();
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    if (player->can_move_backward()) {
                        player->move_backward();
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    if (player->can_move_left()) {
                        player->move_left();
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    if (player->can_move_right()) {
                        player->move_right();
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    if (player->can_move_up()) {
                        player->move_up();
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                    if (player->can_move_down()) {
                        player->move_down();
                    }
                }
            }
        }

        camera.set_center(world_to_screen(player->get_position()));

        camera.update_window(window);
        window.clear(sf::Color::Black);

        Entity::entities = Entity::reorder_entities(Entity::entities);
        for (auto e: Entity::entities) {
            if (e != nullptr) {
                e->draw(window);
            }
        }

        window.display();
        dt.restart();
    }

    for (auto e: Entity::entities) {
        delete e;
        e = nullptr;
    }

    return 0;
}