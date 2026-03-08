/*
File ini berisi logika matematika untuk konversi ruang. Ia menangani perhitungan proyeksi Isometrik, yaitu mengubah koordinat grid 2D biasa (X, Y) menjadi posisi visual miring (belah ketupat) yang terlihat di layar, dan sebaliknya. Ini adalah "otak" di balik penempatan objek agar terlihat presisi di dunia isometrik.
*/

#include "CoordinateSystem.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/vector2i.hpp>

using namespace godot;

void CoordinateSystem::_bind_methods() {
}

Vector2 CoordinateSystem::grid_to_iso(Vector2 grid) {
    float x = (grid.x - grid.y) * (tile_width * 0.5);
    float y = (grid.x + grid.y) * (tile_height * 0.5);

    return Vector2(x, y);
}

Vector2 CoordinateSystem::iso_to_grid(Vector2 iso) {
    float x = (iso.x / (tile_width * 0.5) + iso.y / (tile_height * 0.5)) * 0.5;
    float y = (iso.y / (tile_height * 0.5) - iso.x / (tile_width * 0.5)) * 0.5;

    return Vector2(x, y);
}

Vector2 CoordinateSystem::grid_to_world(Vector2i grid) {
    return grid_to_iso(
        Vector2(grid.x, grid.y)
    );
}

Vector2i CoordinateSystem::world_to_grid(Vector2 world) {
    Vector2 grid = iso_to_grid(world);

    return Vector2i(
        Math::round(grid.x),
        Math::round(grid.y)
    );
}
