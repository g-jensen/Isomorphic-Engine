#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/Color.hpp>

#include "utils.hpp"
#include "Entity.hpp"

class RectangularPrism: public Entity {
public:
    sf::Texture* texture_array[3];
    
    // Initialize RectangularPrism
    RectangularPrism(sf::Vector3f pos, sf::Vector3f size);

    void set_position(sf::Vector3f position);

    sf::Vector3f get_size();
    void set_size(sf::Vector3f size);

    // Updates position of quads based on the position of the world
    void update();
    
    // Draw RectangularPrism
    void draw(sf::RenderWindow& window);

private:
    sf::Vector3f size;
    sf::VertexArray quads[3];
};