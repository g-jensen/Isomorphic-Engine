#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/Color.hpp>

#include "utils.hpp"
#include "Entity.hpp"

class Line: public Entity {
public:
    sf::VertexArray points;
    Line();
    Line(sf::Vector3f p1, sf::Vector3f p2);
    
    void set_position(sf::Vector3f position);

    // Draws the line
    void draw(sf::RenderWindow& window);
};