#include "../headers/Player.hpp"

Player::Player(sf::Vector3f pos, sf::Vector3f size) {
    do_collision = false;
    rectangularPrism = new RectangularPrism(pos,size);
    _can_move_forward = true;
    _can_move_backward = true;
    _can_move_left = true;
    _can_move_right = true;
    _can_move_up = true;
    _can_move_down = true;
}

sf::Vector3f Player::get_position() {
    return rectangularPrism->get_position();
}

void Player::set_position(sf::Vector3f position) {
    rectangularPrism->set_position(position);
}

void Player::move_forward() { rectangularPrism->move({-PANEL_SIZE,0,0}); }
void Player::move_backward() { rectangularPrism->move({PANEL_SIZE,0,0}); }
void Player::move_left() { rectangularPrism->move({0,-PANEL_SIZE,0}); }
void Player::move_right() { rectangularPrism->move({0,PANEL_SIZE,0}); }
void Player::move_up() { rectangularPrism->move({0,0,PANEL_SIZE}); }
void Player::move_down() { rectangularPrism->move({0,0,-PANEL_SIZE}); }

bool Player::can_move_forward() { return _can_move_forward; }
bool Player::can_move_backward() { return _can_move_backward; }
bool Player::can_move_left() { return _can_move_left; }
bool Player::can_move_right() { return _can_move_right; }
bool Player::can_move_up() { return _can_move_up; }
bool Player::can_move_down() { return _can_move_down; }

void Player::update_collision() {
    _can_move_forward = true;
    _can_move_backward = true;
    _can_move_left = true;
    _can_move_right = true;
    _can_move_up = true;
    _can_move_down = true;    
    if (do_collision) {
        for (Entity* e : Entity::entities) {
            if (e->do_collision && e != this->rectangularPrism) {
                Hitbox hb = rectangularPrism->hitbox;
                if (Hitbox({hb.origin.x-PANEL_SIZE,hb.origin.y,hb.origin.z},hb.size).intersects(e->hitbox)) {
                    _can_move_forward = false;
                }
                if (Hitbox({hb.origin.x+PANEL_SIZE,hb.origin.y,hb.origin.z},hb.size).intersects(e->hitbox)) {
                    _can_move_backward = false;
                }
                if (Hitbox({hb.origin.x,hb.origin.y-PANEL_SIZE,hb.origin.z},hb.size).intersects(e->hitbox)) {
                    _can_move_left = false;
                }
                if (Hitbox({hb.origin.x,hb.origin.y+PANEL_SIZE,hb.origin.z},hb.size).intersects(e->hitbox)) {
                    _can_move_right = false;
                }
                if (Hitbox({hb.origin.x,hb.origin.y,hb.origin.z+PANEL_SIZE},hb.size).intersects(e->hitbox)) {
                    _can_move_up = false;
                }
                if (Hitbox({hb.origin.x,hb.origin.y,hb.origin.z-PANEL_SIZE},hb.size).intersects(e->hitbox)) {
                    _can_move_down = false;
                }
            }
        }
    }
}