#include "EntityManager.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>
#include "../Core/MapManager.h"
#include "../Player/Players.h"

using namespace godot;

bool EntityManager::is_tile_occupied(Vector2i grid) {
    return entity_grid.has(grid);
}
void EntityManager::set_entity_grid(Node2D* node, Vector2i grid) {

    if (!node) return;

    entity_grid.insert(grid, node);
}

void EntityManager::remove_entity_grid(Vector2i grid) {

    if (entity_grid.has(grid))
        entity_grid.erase(grid);
}
Node2D* EntityManager::get_entity_at(Vector2i grid) {

    if (entity_grid.has(grid))
        return entity_grid[grid];

    return nullptr;
}

void EntityManager::_ready() {
    UtilityFunctions::print("EntityManager ready");

    MapManager *map_manager = get_node<MapManager>("../MapManager");
    Players *players = get_node<Players>("Players");
    if (players) {
        players->set_map_manager(map_manager);
    }
}

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

    for (int i = 0; i < enemies.size(); i++) {
        // GUNAKAN get_global_position()
        float d = pos.distance_to(enemies[i]->get_global_position());

        if (d < best) {
            best = d;
            target = enemies[i];
        }
    }
    return target;
}
