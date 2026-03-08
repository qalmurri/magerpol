#include "MapManager.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void MapManager::_bind_methods() {

    ClassDB::bind_method(D_METHOD("grid_to_iso","grid"), &MapManager::grid_to_iso);
    ClassDB::bind_method(D_METHOD("iso_to_grid","iso"), &MapManager::iso_to_grid);

    ClassDB::bind_method(D_METHOD("grid_to_world","grid"), &MapManager::grid_to_world);
    ClassDB::bind_method(D_METHOD("world_to_grid","world"), &MapManager::world_to_grid);

    ClassDB::bind_method(D_METHOD("get_tile","grid"), &MapManager::get_tile);
    ClassDB::bind_method(D_METHOD("set_tile","grid","source","atlas"), &MapManager::set_tile);
    ClassDB::bind_method(D_METHOD("remove_tile","grid"), &MapManager::remove_tile);

    ClassDB::bind_method(D_METHOD("is_walkable","grid"), &MapManager::is_walkable);
    ClassDB::bind_method(D_METHOD("snap_to_grid","world"), &MapManager::snap_to_grid);
    ClassDB::bind_method(D_METHOD("get_tile_center","grid"), &MapManager::get_tile_center);

    ClassDB::bind_method(D_METHOD("spawn_on_grid","node","grid"), &MapManager::spawn_on_grid);
    ClassDB::bind_method(D_METHOD("move_entity_to_grid","node","grid"), &MapManager::move_entity_to_grid);

    ClassDB::bind_method(D_METHOD("register_tile_event","grid","event"), &MapManager::register_tile_event);
    ClassDB::bind_method(D_METHOD("trigger_tile_event","grid"), &MapManager::trigger_tile_event);

    ClassDB::bind_method(D_METHOD("drop_loot","item","grid"), &MapManager::drop_loot);

    ClassDB::bind_method(D_METHOD("plant_crop","grid","source","atlas"), &MapManager::plant_crop);
    ClassDB::bind_method(D_METHOD("harvest_crop","grid"), &MapManager::harvest_crop);
}

void MapManager::_ready() {

    tilemap = Object::cast_to<TileMap>(get_node_or_null("../TileMap"));

    if (!tilemap) {
        UtilityFunctions::printerr("MapManager: TileMap missing!");
        return;
    }

    ground = Object::cast_to<TileMapLayer>(tilemap->get_node_or_null("Ground"));
    decoration = Object::cast_to<TileMapLayer>(tilemap->get_node_or_null("Decoration"));
    collision = Object::cast_to<TileMapLayer>(tilemap->get_node_or_null("Collision"));

    entity_root = Object::cast_to<Node2D>(get_node_or_null("../EntityManager"));
    drop_root = Object::cast_to<Node2D>(get_node_or_null("../DropManager"));
}

Vector2 MapManager::grid_to_iso(Vector2 grid) {

    float x = (grid.x - grid.y) * (tile_width * 0.5);
    float y = (grid.x + grid.y) * (tile_height * 0.5);

    return Vector2(x,y);
}

Vector2 MapManager::iso_to_grid(Vector2 iso) {

    float x = (iso.x/(tile_width*0.5)+iso.y/(tile_height*0.5))*0.5;
    float y = (iso.y/(tile_height*0.5)-iso.x/(tile_width*0.5))*0.5;

    return Vector2(x,y);
}

Vector2 MapManager::grid_to_world(Vector2 grid) {

    return grid_to_iso(grid);
}

Vector2 MapManager::world_to_grid(Vector2 world) {

    Vector2 g = iso_to_grid(world);
    return Vector2(Math::floor(g.x),Math::floor(g.y));
}

int MapManager::get_tile(Vector2i grid) {

    return ground->get_cell_source_id(grid);
}

void MapManager::set_tile(Vector2i grid,int source_id,Vector2i atlas) {

    ground->set_cell(grid,source_id,atlas);
}

void MapManager::remove_tile(Vector2i grid) {

    ground->erase_cell(grid);
}

bool MapManager::is_walkable(Vector2i grid) {

    if (collision->get_cell_source_id(grid) != -1)
        return false;

    return true;
}

Vector2 MapManager::snap_to_grid(Vector2 world) {

    Vector2 grid = world_to_grid(world);
    return grid_to_world(grid);
}

Vector2 MapManager::get_tile_center(Vector2i grid) {

    Vector2 pos = grid_to_world(grid);
    pos.x += tile_width*0.5;
    pos.y += tile_height*0.5;

    return pos;
}

void MapManager::spawn_on_grid(Node2D *node,Vector2i grid) {

    if(!node) return;

    node->set_position(get_tile_center(grid));
    entity_root->add_child(node);

    entity_grid.insert(grid,node);
}

void MapManager::move_entity_to_grid(Node2D *node,Vector2i grid) {

    if(!node) return;

    node->set_position(get_tile_center(grid));
    entity_grid.insert(grid,node);
}

void MapManager::register_tile_event(Vector2i grid,String event) {

    tile_events.insert(grid,event);
}

String MapManager::trigger_tile_event(Vector2i grid) {

    if(tile_events.has(grid))
        return tile_events[grid];

    return "";
}

void MapManager::drop_loot(Node2D *item_scene,Vector2i grid) {

    if(!item_scene) return;

    item_scene->set_position(get_tile_center(grid));
    drop_root->add_child(item_scene);
}

void MapManager::plant_crop(Vector2i grid,int source_id,Vector2i atlas) {

    decoration->set_cell(grid,source_id,atlas);
}

void MapManager::harvest_crop(Vector2i grid) {

    decoration->erase_cell(grid);
}
