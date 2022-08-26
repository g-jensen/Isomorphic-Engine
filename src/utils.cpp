#include "../headers/utils.hpp"

sf::Vector3f camera_position = {555.555,555.555,555.555};

sf::Clock dt;

sf::Vector2f world_to_screen(sf::Vector3f pos) {
    sf::Vector2f v;
    v.x = origin_x + (pos.x*cos_7PI_6) + (pos.y*cos_PI_6);
    v.y = origin_y + (pos.x*-sin_7PI_6) + (pos.y*sin_PI_6) - pos.z;
    return v;
}

float distance(sf::Vector3f v1, sf::Vector3f v2) {
    return sqrt(
        (v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y) + (v1.z-v2.z)*(v1.z-v2.z)
    );
}