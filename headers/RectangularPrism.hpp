#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/Color.hpp>

#include "utils.hpp"
#include "Entity.hpp"

class RectangularPrism: public Entity {
public:
    sf::Texture* texture;
    sf::Vector3f size;
    
    // Initialize RectangularPrism
    RectangularPrism(sf::Vector3f pos, sf::Vector3f size);

    // Updates position of quads based on the position of the world
    void update();
    
    // Draw RectangularPrism
    void draw(sf::RenderWindow& window);

private:
    sf::VertexArray quads[3];
};