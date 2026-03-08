/*
File ini adalah sistem database sederhana untuk melacak posisi. Ia menyimpan catatan (menggunakan map) tentang setiap objek Node2D berada di koordinat grid mana. Ini sangat berguna agar sistem tahu posisi logis sebuah entitas tanpa harus selalu melakukan perhitungan fisik yang berat.
*/

#include "GridSystem.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GridSystem::_bind_methods() {
}

void GridSystem::set_entity_grid(Node2D *node, Vector2i grid) {
    entity_grid[node] = grid;
}

void GridSystem::update_entity_grid(Node2D *node, Vector2i grid) {
    auto it = entity_grid.find(node);

    if (it != entity_grid.end()) {
        it->second = grid;
    } else {
        entity_grid[node] = grid;
    }
}

Vector2i GridSystem::get_entity_grid(Node2D *node) {
    auto it = entity_grid.find(node);

    if (it != entity_grid.end()) {
        return it->second;
    }

    return Vector2i(-1, -1);
}
