#pragma once

#include "Entity.hpp"

class Plane: public Entity {
public:
    sf::Texture* texture;

    Plane(sf::Vector3f position, sf::Vector2f size);

    void set_position(sf::Vector3f position);
    void move(sf::Vector3f delta);

    sf::Vector2f get_size();
    void set_size(sf::Vector2f size);

    void draw(sf::RenderWindow& window);

    void update();
private:
    sf::Vector2f size;
    sf::VertexArray quad;
};