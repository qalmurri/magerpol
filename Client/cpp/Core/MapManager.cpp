/*
File ini adalah gerbang utama (Facade) untuk semua urusan terkait peta. Daripada memanggil banyak sistem kecil secara terpisah, komponen lain cukup memanggil MapManager. Ia menyatukan logika koordinat, pengaturan tile, dan penempatan entitas. File ini menghubungkan data visual dari TileMap Godot dengan logika backend yang Anda buat di C++.
*/

#include "MapManager.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void MapManager::_bind_methods() {
    ClassDB::bind_method(
        D_METHOD("set_entity_grid", "node", "grid"),
        &MapManager::set_entity_grid
    );

    ClassDB::bind_method(
        D_METHOD("update_entity_grid", "node", "grid"),
        &MapManager::update_entity_grid
    );

    ClassDB::bind_method(
        D_METHOD("get_entity_grid", "node"),
        &MapManager::get_entity_grid
    );

    ClassDB::bind_method(
        D_METHOD("grid_to_iso", "grid"),
        &MapManager::grid_to_iso
    );

    ClassDB::bind_method(
        D_METHOD("iso_to_grid", "iso"),
        &MapManager::iso_to_grid
    );

    ClassDB::bind_method(
        D_METHOD("grid_to_world", "grid"),
        &MapManager::grid_to_world
    );

    ClassDB::bind_method(
        D_METHOD("world_to_grid", "world"),
        &MapManager::world_to_grid
    );

    ClassDB::bind_method(
        D_METHOD("get_tile", "grid"),
        &MapManager::get_tile
    );

    ClassDB::bind_method(
        D_METHOD("set_tile", "grid", "source", "atlas"),
        &MapManager::set_tile
    );

    ClassDB::bind_method(
        D_METHOD("remove_tile", "grid"),
        &MapManager::remove_tile
    );

    ClassDB::bind_method(
        D_METHOD("is_walkable", "grid"),
        &MapManager::is_walkable
    );

    ClassDB::bind_method(
        D_METHOD("snap_to_grid", "world"),
        &MapManager::snap_to_grid
    );

    ClassDB::bind_method(
        D_METHOD("get_tile_center", "grid"),
        &MapManager::get_tile_center
    );

    ClassDB::bind_method(
        D_METHOD("spawn_on_grid", "node", "grid"),
        &MapManager::spawn_on_grid
    );

    ClassDB::bind_method(
        D_METHOD("move_entity_to_grid", "node", "grid"),
        &MapManager::move_entity_to_grid
    );

    ClassDB::bind_method(
        D_METHOD("register_tile_event", "grid", "event"),
        &MapManager::register_tile_event
    );

    ClassDB::bind_method(
        D_METHOD("trigger_tile_event", "grid"),
        &MapManager::trigger_tile_event
    );

    ClassDB::bind_method(
        D_METHOD("drop_loot", "item", "grid"),
        &MapManager::drop_loot
    );

    ClassDB::bind_method(
        D_METHOD("plant_crop", "grid", "source", "atlas"),
        &MapManager::plant_crop
    );

    ClassDB::bind_method(
        D_METHOD("harvest_crop", "grid"),
        &MapManager::harvest_crop
    );
}

void MapManager::_ready() {
    UtilityFunctions::print("MapManager ready");

    tilemap = Object::cast_to<TileMap>(
        get_node_or_null("../TileMap")
    );

    if (!tilemap) {
        UtilityFunctions::printerr("MapManager: TileMap missing!");
        return;
    }

    ground = Object::cast_to<TileMapLayer>(
        tilemap->get_node_or_null("Ground")
    );

    decoration = Object::cast_to<TileMapLayer>(
        tilemap->get_node_or_null("Decoration")
    );

    collision = Object::cast_to<TileMapLayer>(
        tilemap->get_node_or_null("Collision")
    );

    entity_root = Object::cast_to<Node2D>(
        get_node_or_null("../EntityManager")
    );

    drop_root = Object::cast_to<Node2D>(
        get_node_or_null("../DropManager")
    );

    coord = memnew(CoordinateSystem);
    grid = memnew(GridSystem);
    tile = memnew(TileSystem);
    events = memnew(TileEventManager);

    tile->setup(ground, decoration, collision);
}

void MapManager::set_entity_grid(Node2D *node, Vector2i grid_pos) {
    grid->set_entity_grid(node, grid_pos);
}

void MapManager::update_entity_grid(Node2D *node, Vector2i grid_pos) {
    grid->update_entity_grid(node, grid_pos);
}

Vector2i MapManager::get_entity_grid(Node2D *node) {
    return grid->get_entity_grid(node);
}

Vector2 MapManager::grid_to_iso(Vector2 grid_pos) {
    return coord->grid_to_iso(grid_pos);
}

Vector2 MapManager::iso_to_grid(Vector2 iso) {
    return coord->iso_to_grid(iso);
}

Vector2 MapManager::grid_to_world(Vector2i grid_pos) {
    return coord->grid_to_world(grid_pos);
}

Vector2i MapManager::world_to_grid(Vector2 world) {
    return coord->world_to_grid(world);
}

int MapManager::get_tile(Vector2i grid_pos) {
    return tile->get_tile(grid_pos);
}

void MapManager::set_tile(Vector2i grid_pos, int source_id, Vector2i atlas) {
    tile->set_tile(grid_pos, source_id, atlas);
}

void MapManager::remove_tile(Vector2i grid_pos) {
    tile->remove_tile(grid_pos);
}

bool MapManager::is_walkable(Vector2i grid_pos) {
    return tile->is_walkable(grid_pos);
}

Vector2 MapManager::snap_to_grid(Vector2 world) {
    Vector2i grid_pos = world_to_grid(world);
    return grid_to_world(grid_pos);
}

Vector2 MapManager::get_tile_center(Vector2i grid_pos) {
    return grid_to_world(grid_pos);
}

void MapManager::spawn_on_grid(Node2D *node, Vector2i grid_pos) {
    if (!node) {
        return;
    }

    node->set_position(
        get_tile_center(grid_pos)
    );

    entity_root->add_child(node);

    grid->set_entity_grid(node, grid_pos);
}

void MapManager::move_entity_to_grid(Node2D *node, Vector2i grid_pos) {
    if (!node) {
        return;
    }

    node->set_position(
        get_tile_center(grid_pos)
    );

    grid->update_entity_grid(node, grid_pos);
}

void MapManager::register_tile_event(Vector2i grid_pos, String event) {
    events->register_tile_event(grid_pos, event);
}

String MapManager::trigger_tile_event(Vector2i grid_pos) {
    return events->trigger_tile_event(grid_pos);
}

void MapManager::drop_loot(Node2D *item_scene, Vector2i grid_pos) {
    if (!item_scene) {
        return;
    }

    item_scene->set_position(
        get_tile_center(grid_pos)
    );

    drop_root->add_child(item_scene);
}

void MapManager::plant_crop(Vector2i grid_pos, int source_id, Vector2i atlas) {
    tile->plant_crop(grid_pos, source_id, atlas);
}

void MapManager::harvest_crop(Vector2i grid_pos) {
    tile->harvest_crop(grid_pos);
}
