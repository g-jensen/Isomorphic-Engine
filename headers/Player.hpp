#pragma once

#include "RectangularPrism.hpp"

class Player {
public:
    Player(sf::Vector3f pos, sf::Vector3f size);

    bool do_collision;

    sf::Vector3f get_position();
    void set_position(sf::Vector3f position);

    Hitbox get_hitbox();

    void move_forward();
    void move_backward();
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    
    bool can_move_forward();
    bool can_move_backward();
    bool can_move_left();
    bool can_move_right();
    bool can_move_up();
    bool can_move_down();

    void update_collision();
    RectangularPrism* rectangularPrism;
private:
    bool _can_move_forward;
    bool _can_move_backward;
    bool _can_move_left;
    bool _can_move_right;
    bool _can_move_up;
    bool _can_move_down;
};