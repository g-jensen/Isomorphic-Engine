#pragma once

#include "Entity.hpp"

class Plane: public Entity {
public:
    sf::Texture* texture;
    sf::Vector2f size;

    Plane(sf::Vector3f position, sf::Vector2f size);

    void draw(sf::RenderWindow& window);
private:
    sf::VertexArray quad;
};