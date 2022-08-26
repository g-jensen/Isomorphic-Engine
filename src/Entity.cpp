#include "../headers/Entity.hpp"

std::vector<Entity*> Entity::entities;

std::vector<Entity*> Entity::reorder_entities_recursive(std::vector<Entity*> a, std::vector<Entity*> b) {
    std::vector<Entity*> c;
    while (!a.empty() && !b.empty()) {
        if (distance(a[0]->position,camera_position) < distance(b[0]->position,camera_position)) {
            c.push_back(b[0]);
            b.erase(b.begin()+0);
        } else {
            c.push_back(a[0]);
            a.erase(a.begin()+0);
        }
    }

    while (!a.empty()) {
        c.push_back(a[0]);
        a.erase(a.begin()+0);
    }

    while (!b.empty()) {
        c.push_back(b[0]);
        b.erase(b.begin()+0);
    }


    return c;
}

std::vector<Entity*> Entity::reorder_entities(std::vector<Entity*> e) {
    if (e.size() == 1) { return e; }

    std::vector<Entity*> a;
    for (int i = 0; i < e.size()/2; i++) {
        a.push_back(e[i]);
    }
    std::vector<Entity*> b;
    for (int i = e.size()/2; i < e.size(); i++) {
        b.push_back(e[i]);
    }

    a = Entity::reorder_entities(a);
    b = Entity::reorder_entities(b);

    return reorder_entities_recursive(a,b);
}