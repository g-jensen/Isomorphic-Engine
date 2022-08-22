#include "../headers/utils.hpp"

sf::Vector2f world_to_screen(sf::Vector3f pos) {
    sf::Vector2f v;
    v.x = origin_x + (pos.x*cos_7PI_6) + (pos.y*cos_PI_6);
    v.y = origin_y + (pos.x*-sin_7PI_6) + (pos.y*sin_PI_6) - pos.z;
    return v;
}

void init_axes(sf::VertexArray& x_axis, sf::VertexArray& y_axis, sf::VertexArray& z_axis) {

    x_axis = sf::VertexArray(sf::Lines,2);
    y_axis = sf::VertexArray(sf::Lines,2);
    z_axis = sf::VertexArray(sf::Lines,2);

    sf::Vertex origin({origin_x,origin_y},sf::Color::Green);

    x_axis[0] = origin;
    origin.color = sf::Color::Yellow;
    y_axis[0] = origin;
    origin.color = sf::Color::Red;
    z_axis[0] = origin;

    float r = 200;

    x_axis[1] = {{origin_x+r*cos_7PI_6,origin_y+r*-sin_7PI_6},sf::Color::Green};
    y_axis[1] = {{origin_x+r*cos_PI_6,origin_y+r*sin_PI_6},sf::Color::Yellow};
    z_axis[1] = {{origin_x,origin_y-r},sf::Color::Red};
}

float distance(sf::Vector3f v1, sf::Vector3f v2) {
    return sqrt(
        (v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y) + (v1.z-v2.z)*(v1.z-v2.z)
    );
}