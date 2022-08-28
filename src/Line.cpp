#include "../headers/Line.hpp"

Line::Line(){}

Line::Line(sf::Vector3f p1, sf::Vector3f p2) {
    points = sf::VertexArray(sf::Lines,2);
    points[0] = world_to_screen(p1);
    points[1] = world_to_screen(p2);
    position = p1;
    
    this->do_collision = false;
    
    Entity::entities.push_back(this);
}

void Line::draw(sf::RenderWindow& window) {
    window.draw(points);
}