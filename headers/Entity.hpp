#pragma once

#include <vector>
#include <iostream>

#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "utils.hpp"

extern sf::Vector3f camera_position;

// Interface
class Entity {
public:
    sf::Vector3f position;
    bool do_collision;
    virtual void draw(sf::RenderWindow& window) = 0;
    

    static std::vector<Entity*> entities;

    // Reoders entities based on distance from camera
    static std::vector<Entity*> reorder_entities(std::vector<Entity*> e);
private:
    static std::vector<Entity*> reorder_entities_recursive(std::vector<Entity*> a, std::vector<Entity*> b);
};