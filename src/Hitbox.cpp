#include "../headers/Hitbox.hpp"

bool Hitbox::intersects(Hitbox hb) {
    sf::IntRect r1;
    sf::IntRect r2;
    bool b1 = false;
    bool b2 = false;
    r1.left = origin.x;
    r1.top = origin.y;
    r1.width = size.x;
    r1.height = size.y;
    r2.left = hb.origin.x;
    r2.top = hb.origin.y;
    r2.width = hb.size.x;
    r2.height = hb.size.y;
    if (r1.intersects(r2)) {b1 = true;}
    r1.left = origin.x;
    r1.top = origin.z;
    r1.width = size.x;
    r1.height = size.z;
    r2.left = hb.origin.x;
    r2.top = hb.origin.z;
    r2.width = hb.size.x;
    r2.height = hb.size.z;
    if (r1.intersects(r2)) {b2 = true;}
    return b1 && b2;
}