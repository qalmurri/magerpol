#include "EntityManager.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void EntityManager::_bind_methods() {}

void EntityManager::register_player(Node2D *node) {
    players.push_back(node);
}

void EntityManager::register_enemy(Node2D *node) {
    enemies.push_back(node);
}

void EntityManager::register_npc(Node2D *node) {
    npcs.push_back(node);
}

void EntityManager::remove_entity(Node2D *node) {

    for (int i=0;i<enemies.size();i++)
        if (enemies[i] == node)
            enemies.remove_at(i);
}

Node2D* EntityManager::get_closest_enemy(Vector2 pos, float radius) {

    Node2D *target = nullptr;
    float best = radius;

    for (int i=0;i<enemies.size();i++) {

        float d = pos.distance_to(enemies[i]->get_position());

        if (d < best) {
            best = d;
            target = enemies[i];
        }
    }

    return target;
}
