#include "../headers/Plane.hpp"

Plane::Plane(sf::Vector3f position, sf::Vector2f size) {
    this->position = position;
    this->size = size;

    texture = nullptr;

    quad = sf::VertexArray(sf::Quads,4);
    quad[0] = {world_to_screen(position),sf::Color::White,{0,0}};
    quad[1] = {world_to_screen({position.x+size.x, position.y,position.z}),sf::Color::White,{0,16}};
    quad[2] = {world_to_screen({position.x+size.x, position.y+size.y,position.z}),sf::Color::White,{16,16}};
    quad[3] = {world_to_screen({position.x, position.y+size.y,position.z}),sf::Color::White,{16,0}};

    Entity::entities.push_back((Entity*)this);
}

void Plane::draw(sf::RenderWindow& window) {
    if (texture != nullptr) {
        window.draw(quad,texture);
    } else {
        window.draw(quad);
    }
}