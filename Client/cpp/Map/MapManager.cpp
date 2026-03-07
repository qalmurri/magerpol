#include "MapManager.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void MapManager::_bind_methods() {
    ClassDB::bind_method(D_METHOD("grid_to_iso", "grid"), &MapManager::grid_to_iso);
    ClassDB::bind_method(D_METHOD("iso_to_grid", "iso"), &MapManager::iso_to_grid);
}

void MapManager::_ready() {

    ground = get_node<TileMap>("Ground");
    decoration = get_node<TileMap>("Decoration");
    collision = get_node<TileMap>("Collision");

    if (!ground || !decoration || !collision) {
        UtilityFunctions::printerr("TileMap nodes not found!");
    }
}

Vector2 MapManager::grid_to_iso(Vector2 grid) {

    float x = (grid.x - grid.y) * (tile_width / 2);
    float y = (grid.x + grid.y) * (tile_height / 2);

    return Vector2(x, y);
}

Vector2 MapManager::iso_to_grid(Vector2 iso) {

    float x = (iso.x / (tile_width / 2) + iso.y / (tile_height / 2)) / 2;
    float y = (iso.y / (tile_height / 2) - iso.x / (tile_width / 2)) / 2;

    return Vector2(x, y);
}
