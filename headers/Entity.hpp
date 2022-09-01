#pragma once

#include <vector>
#include <iostream>

#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "defs.hpp"
#include "utils.hpp"
#include "Hitbox.hpp"

extern sf::Vector3f camera_position;

// Interface
class Entity {
protected:
    sf::Vector3f position;
public:
    virtual void set_position(sf::Vector3f position) = 0;
    sf::Vector3f get_position();
    void move(sf::Vector3f delta);
    Hitbox hitbox;
    bool do_collision;
    virtual void draw(sf::RenderWindow& window) = 0;
    

    static std::vector<Entity*> entities;

    // Reoders entities based on distance from camera
    static std::vector<Entity*> reorder_entities(std::vector<Entity*> e);
private:
    static std::vector<Entity*> reorder_entities_recursive(std::vector<Entity*> a, std::vector<Entity*> b);
};