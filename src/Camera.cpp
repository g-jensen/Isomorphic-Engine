#include "../headers/Camera.hpp"

Camera::Camera(sf::View view) {
    this->view = view;
    this->size = view.getSize();
    this->position = view.getCenter() - sf::Vector2f{size.x/2,size.y/2};
}

sf::Vector2f Camera::get_position() {
    return this->position;
}

void Camera::set_position(sf::Vector2f position) {
    this->position = position;

    view.setCenter(position + sf::Vector2f{size.x/2,size.y/2});
}

void Camera::move(sf::Vector2f delta) {
    set_position(get_position()+delta);
}

sf::Vector2f Camera::get_center() {
    return view.getCenter();
}

void Camera::set_center(sf::Vector2f center) {
    view.setCenter(center);
    this->position = view.getCenter() - sf::Vector2f{size.x/2,size.y/2};
}

sf::Vector2f Camera::get_size() {
    return this->size;
}

void Camera::set_size(sf::Vector2f size) {
    this->size = size;
    view.setSize(size);
}

void Camera::update_window(sf::RenderWindow& window) {
    window.setView(view);
}