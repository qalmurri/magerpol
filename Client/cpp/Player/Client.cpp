#include "Client.h"
#include "../Core/MapManager.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

Node2D* find_marker(Node* parent) {
    if (!parent) return nullptr;

    if (parent->get_name() == StringName("Marker")) {
        return Object::cast_to<Node2D>(parent);
    }

    for (int i = 0; i < parent->get_child_count(); i++) {
        Node2D* found = find_marker(parent->get_child(i));
        if (found) return found;
    }

    return nullptr;
}

void Client::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_grid_pos", "grid"), &Client::set_grid_pos);
    ClassDB::bind_method(D_METHOD("get_grid_pos"), &Client::get_grid_pos);
    ClassDB::bind_method(D_METHOD("move_to_grid", "grid"), &Client::move_to_grid);
}

void Client::_ready() {
    UtilityFunctions::print("Client ready");

    // ambil MapManager dari parent/sibling
    map_manager = Object::cast_to<MapManager>(get_node_or_null("../MapManager"));
    if (!map_manager) {
        UtilityFunctions::printerr("Client: MapManager not found!");
    }

    // ambil Player child
    player_visual = Object::cast_to<Node2D>(get_node_or_null("Player"));
    if (!player_visual) {
        UtilityFunctions::printerr("Client: Player visual not found!");
    }

    // set posisi awal player
    move_to_grid(grid_pos);
}

void Client::set_grid_pos(Vector2i grid) {
    grid_pos = grid;
    move_to_grid(grid);
}

void Client::move_to_grid(Vector2i grid) {
    if (!map_manager || !player_visual) return;

    grid_pos = grid;
    Vector2 world_pos = map_manager->get_tile_center(grid); // pakai MapManager
    player_visual->set_position(world_pos);

    UtilityFunctions::print("Client grid_pos: ", grid_pos);

    // cari Marker rekursif di Player
    Node2D* marker = find_marker(player_visual);
    if (!marker) {
        UtilityFunctions::print("Marker not found inside Player!");
    } else {
        marker->set_global_position(world_pos); // marker ikut world pos
        UtilityFunctions::print("Marker found and moved!");
    }
}

void Client::set_map_manager(MapManager* manager) {
    map_manager = manager;
}
