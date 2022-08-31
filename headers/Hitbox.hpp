#pragma once

#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/Rect.hpp>

class Hitbox {
public:
    sf::Vector3f origin;
    sf::Vector3f size;
    bool intersects(Hitbox hb);
};