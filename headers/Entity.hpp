#pragma once

#include <vector>

#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

// Interface
class Entity {
public:
    sf::Vector3f position;
    virtual void draw(sf::RenderWindow& window) = 0;

    static std::vector<Entity*> entities;
};