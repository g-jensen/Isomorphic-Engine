#include "../headers/Plane.hpp"

void Plane::update() {
    quad[0] = {world_to_screen(position),sf::Color::White,{0,0}};
    quad[1] = {world_to_screen({position.x+size.x, position.y,position.z}),sf::Color::White,{0,16}};
    quad[2] = {world_to_screen({position.x+size.x, position.y+size.y,position.z}),sf::Color::White,{16,16}};
    quad[3] = {world_to_screen({position.x, position.y+size.y,position.z}),sf::Color::White,{16,0}};
}

Plane::Plane(sf::Vector3f position, sf::Vector2f size) {
    this->position = position;
    this->size = size;
    this->do_collision = false;

    this->hitbox = Hitbox(position,{size.x,size.y,1});

    texture = nullptr;

    quad = sf::VertexArray(sf::Quads,4);
    update();

    Entity::entities.push_back(this);
}

void Plane::set_position(sf::Vector3f position) {
    this->position = position;
    this->hitbox.origin = position;
    update();
}

void Plane::move(sf::Vector3f delta) {
    set_position(get_position()+delta);
}

void Plane::set_size(sf::Vector2f size) {
    this->size = size;
    this->hitbox.size = {size.x,size.y,0};
    update();
}

void Plane::draw(sf::RenderWindow& window) {
    if (texture != nullptr) {
        window.draw(quad,texture);
    } else {
        window.draw(quad);
    }
}