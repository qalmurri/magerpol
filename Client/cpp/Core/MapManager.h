#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/tile_map.hpp>
#include <godot_cpp/classes/tile_map_layer.hpp>

#include "CoordinateSystem.h"
#include "GridSystem.h"
#include "TileSystem.h"
#include "../Gameplay/TileEventManager.h"

using namespace godot;

class MapManager : public Node2D {
    GDCLASS(MapManager, Node2D)

private:

    TileMap *tilemap;

    TileMapLayer *ground;
    TileMapLayer *decoration;
    TileMapLayer *collision;

    Node2D *entity_root;
    Node2D *drop_root;

    CoordinateSystem *coord;
    GridSystem *grid;
    TileSystem *tile;
    TileEventManager *events;

protected:
    static void _bind_methods();

public:

    void _ready();

    // grid
    void set_entity_grid(Node2D* node, Vector2i grid_pos);
    void update_entity_grid(Node2D* node, Vector2i grid_pos);
    Vector2i get_entity_grid(Node2D* node);

    // coordinate
    Vector2 grid_to_iso(Vector2 grid);
    Vector2 iso_to_grid(Vector2 iso);
    Vector2 grid_to_world(Vector2i grid_pos);
    Vector2i world_to_grid(Vector2 world);

    // tile
    int get_tile(Vector2i grid_pos);
    void set_tile(Vector2i grid_pos, int source_id, Vector2i atlas);
    void remove_tile(Vector2i grid_pos);
    bool is_walkable(Vector2i grid_pos);

    // helper
    Vector2 snap_to_grid(Vector2 world);
    Vector2 get_tile_center(Vector2i grid_pos);

    // entity
    void spawn_on_grid(Node2D *node, Vector2i grid_pos);
    void move_entity_to_grid(Node2D *node, Vector2i grid_pos);

    // tile events
    void register_tile_event(Vector2i grid_pos, String event);
    String trigger_tile_event(Vector2i grid_pos);

    // drop
    void drop_loot(Node2D *item_scene, Vector2i grid_pos);

    // farming
    void plant_crop(Vector2i grid_pos, int source_id, Vector2i atlas);
    void harvest_crop(Vector2i grid_pos);
};

#endif
