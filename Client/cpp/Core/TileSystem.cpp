#include "TileSystem.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void TileSystem::_bind_methods() {
}

void TileSystem::setup(TileMapLayer *g, TileMapLayer *d, TileMapLayer *c) {
    ground = g;
    decoration = d;
    collision = c;
}

int TileSystem::get_tile(Vector2i grid) {
    return ground->get_cell_source_id(grid);
}

void TileSystem::set_tile(Vector2i grid, int source_id, Vector2i atlas) {
    ground->set_cell(grid, source_id, atlas);
}

void TileSystem::remove_tile(Vector2i grid) {
    ground->erase_cell(grid);
}

bool TileSystem::is_walkable(Vector2i grid) {
    return collision->get_cell_source_id(grid) == -1;
}

void TileSystem::plant_crop(Vector2i grid, int source_id, Vector2i atlas) {
    decoration->set_cell(grid, source_id, atlas);
}

void TileSystem::harvest_crop(Vector2i grid) {
    decoration->erase_cell(grid);
}
