#include "TileEventManager.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void TileEventManager::_bind_methods() {}

void TileEventManager::register_tile_event(Vector2i grid,String event) {

    tile_events.insert(grid,event);
}

String TileEventManager::trigger_tile_event(Vector2i grid) {

    if(tile_events.has(grid))
        return tile_events[grid];

    return "";
}
