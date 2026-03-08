/*
File ini bertindak sebagai pengelola utama entitas pemain (Player) yang menjembatani hubungan antara visual karakter, sistem peta (MapManager), dan sistem manajemen entitas (EntityManager). Tugas utamanya adalah menangani penempatan pemain pada sistem koordinat grid, memastikan visual karakter sinkron dengan posisi teknis di peta, serta melakukan validasi apakah sebuah langkah boleh dilakukan (misalnya mengecek apakah area target bisa dilewati/walkable).
*/

#include "Players.h"

#include "../Core/MapManager.h"
#include "../Gameplay/EntityManager.h"
#include "Movement.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

Node2D *find_marker(Node *parent) {
    if (!parent) {
        return nullptr;
    }

    if (parent->get_name() == StringName("Marker")) {
        return Object::cast_to<Node2D>(parent);
    }

    for (int i = 0; i < parent->get_child_count(); i++) {
        Node2D *found = find_marker(parent->get_child(i));
        if (found) {
            return found;
        }
    }

    return nullptr;
}

void Players::_bind_methods() {
    ClassDB::bind_method(
        D_METHOD("set_grid_pos", "grid"),
        &Players::set_grid_pos
    );

    ClassDB::bind_method(
        D_METHOD("get_grid_pos"),
        &Players::get_grid_pos
    );

    ClassDB::bind_method(
        D_METHOD("move_to_grid", "grid"),
        &Players::move_to_grid
    );
}

void Players::_ready() {
    UtilityFunctions::print("Players ready");

    player_visual = Object::cast_to<Node2D>(
        get_node_or_null("Player")
    );

    EntityManager *entity_manager = nullptr;
    Node *p = get_parent();

    while (p) {
        entity_manager = Object::cast_to<EntityManager>(p);
        if (entity_manager) {
            break;
        }

        p = p->get_parent();
    }

    if (entity_manager && player_visual) {
        entity_manager->register_player(player_visual);
    }
}

void Players::set_grid_pos(Vector2i grid) {
    grid_pos = grid;
    move_to_grid(grid);
}

void Players::move_to_grid(Vector2i grid) {
    if (!map_manager || !player_visual) {
        return;
    }

    grid_pos = grid;

    Vector2 world_pos = map_manager->get_tile_center(grid);
    player_visual->set_position(world_pos);

    UtilityFunctions::print("Players grid_pos: ", grid_pos);

    Node2D *marker = find_marker(player_visual);

    if (!marker) {
        UtilityFunctions::print("Marker not found inside Player!");
    } else {
        marker->set_global_position(world_pos);
        UtilityFunctions::print("Marker found and moved!");
    }
}

void Players::set_map_manager(MapManager *manager) {
    map_manager = manager;

    for (int i = 0; i < get_child_count(); i++) {
        Movement *movement = Object::cast_to<Movement>(
            get_child(i)
        );

        if (movement) {
            movement->set_map_manager(manager);
        }
    }
}

void Players::try_move(Vector2 dir) {
    if (!map_manager) {
        return;
    }

    Vector2i move(0, 0);

    if (dir.x > 0.5) {
        move.x = 1;
    }

    if (dir.x < -0.5) {
        move.x = -1;
    }

    if (dir.y > 0.5) {
        move.y = 1;
    }

    if (dir.y < -0.5) {
        move.y = -1;
    }

    if (move == Vector2i(0, 0)) {
        return;
    }

    Vector2i target = grid_pos + move;

    if (!map_manager->is_walkable(target)) {
        return;
    }

    move_to_grid(target);
}
