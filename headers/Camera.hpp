#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

class Camera {
public:
    Camera(sf::View view);
    
    sf::Vector2f get_position();
    void set_position(sf::Vector2f position);
    void move(sf::Vector2f delta);
    
    sf::Vector2f get_center();
    void set_center(sf::Vector2f center);

    sf::Vector2f get_size();
    void set_size(sf::Vector2f position);

    void update_window(sf::RenderWindow& window);
private:
    sf::View view;
    sf::Vector2f position;
    sf::Vector2f size;
};