#include "../headers/utils.hpp"

sf::Vector2f world_to_screen(sf::Vector3f pos) {
    sf::Vector2f v;
    v.x = origin_x + (pos.x*cos_7PI_6) + (pos.y*cos_PI_6);
    v.y = origin_y + (pos.x*-sin_7PI_6) + (pos.y*sin_PI_6) - pos.z;
    return v;
}

void init_axes(Line& x_axis, Line& y_axis, Line& z_axis) {
    float r = 200;

    x_axis = Line({0,0,0},{r,0,0});
    x_axis.points[0].color = sf::Color::Green;
    x_axis.points[1].color = sf::Color::Green;
    y_axis = Line({0,0,0},{0,r,0});
    y_axis.points[0].color = sf::Color::Yellow;
    y_axis.points[1].color = sf::Color::Yellow;
    z_axis = Line({0,0,0},{0,0,r});
    z_axis.points[0].color = sf::Color::Red;
    z_axis.points[1].color = sf::Color::Red;
}

float distance(sf::Vector3f v1, sf::Vector3f v2) {
    return sqrt(
        (v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y) + (v1.z-v2.z)*(v1.z-v2.z)
    );
}