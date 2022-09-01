#include "../headers/RectangularPrism.hpp"

void RectangularPrism::update() {
    quads[0][0] = {world_to_screen({position.x+size.x,position.y,position.z}),sf::Color::White,{0,0}};
    quads[0][1] = {world_to_screen({position.x+size.x,position.y,position.z+size.z}),sf::Color::White,{0,16}};
    quads[0][2] = {world_to_screen({position.x+size.x,position.y+size.y,position.z+size.z}),sf::Color::White,{16,16}};
    quads[0][3] = {world_to_screen({position.x+size.x,position.y+size.y,position.z}),sf::Color::White,{16,0}};

    quads[1][0] = {world_to_screen({position.x+size.x,position.y+size.y,position.z}),sf::Color::White,{0,0}};
    quads[1][1] = {world_to_screen({position.x+size.x,position.y+size.y,position.z+size.z}),sf::Color::White,{0,16}};
    quads[1][2] = {world_to_screen({position.x,position.y+size.y,position.z+size.z}),sf::Color::White,{16,16}};
    quads[1][3] = {world_to_screen({position.x,position.y+size.y,position.z}),sf::Color::White,{16,0}};

    quads[2][0] = {world_to_screen({position.x+size.x,position.y+size.y,position.z+size.z}),sf::Color::White,{0,0}};
    quads[2][1] = {world_to_screen({position.x+size.x,position.y,position.z+size.z}),sf::Color::White,{0,16}};
    quads[2][2] = {world_to_screen({position.x,position.y,position.z+size.z}),sf::Color::White,{16,16}};
    quads[2][3] = {world_to_screen({position.x,position.y+size.y,position.z+size.z}),sf::Color::White,{16,0}};
}

RectangularPrism::RectangularPrism(sf::Vector3f position, sf::Vector3f size) {
    this->position = position;
    this->size = size;
    this->do_collision = false;

    quads[0] = sf::VertexArray(sf::Quads,4);
    quads[1] = sf::VertexArray(sf::Quads,4);
    quads[2] = sf::VertexArray(sf::Quads,4);

    entities.push_back(this);

    texture_array[0] = nullptr;
    texture_array[1] = nullptr;
    texture_array[2] = nullptr;

    hitbox = Hitbox(position,size);

    update();

}

void RectangularPrism::set_position(sf::Vector3f position) {
    this->position = position;
    hitbox.origin = position;

    update();
}

sf::Vector3f RectangularPrism::get_size() {
    return this->size;
}

void RectangularPrism::set_size(sf::Vector3f size) {
    this->size = size;
    hitbox.size = size;
    update();
}

void RectangularPrism::draw(sf::RenderWindow& window) {
    if (texture_array[0] != nullptr)
        window.draw(quads[0],texture_array[0]);
    else
        window.draw(quads[0]);

    if (texture_array[1] != nullptr)
        window.draw(quads[1],texture_array[1]);
    else
        window.draw(quads[1]);

    if (texture_array[2] != nullptr)
        window.draw(quads[2],texture_array[2]);
    else
        window.draw(quads[2]);
}