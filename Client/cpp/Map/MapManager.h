#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/tile_map.hpp>
#include <godot_cpp/classes/tile_map_layer.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/vector2i.hpp>
#include <godot_cpp/templates/hash_map.hpp>

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

    int tile_width = 64;
    int tile_height = 32;

    HashMap<Vector2i, String> tile_events;
    HashMap<Vector2i, Node2D*> entity_grid;

protected:
    static void _bind_methods();

public:

    void _ready();
    void debug_grid_world(Vector2i grid);

    // coordinate
    Vector2 grid_to_iso(Vector2 grid);
    Vector2 iso_to_grid(Vector2 iso);
    Vector2 grid_to_world(Vector2 grid);
    Vector2 world_to_grid(Vector2 world);

    // tile
    int get_tile(Vector2i grid);
    void set_tile(Vector2i grid, int source_id, Vector2i atlas);
    void remove_tile(Vector2i grid);

    // gameplay
    bool is_walkable(Vector2i grid);
    Vector2 snap_to_grid(Vector2 world);
    Vector2 get_tile_center(Vector2i grid);

    // entity
    void spawn_on_grid(Node2D *node, Vector2i grid);
    void move_entity_to_grid(Node2D *node, Vector2i grid);

    // events
    void register_tile_event(Vector2i grid, String event);
    String trigger_tile_event(Vector2i grid);

    // loot
    void drop_loot(Node2D *item_scene, Vector2i grid);

    // farming
    void plant_crop(Vector2i grid, int source_id, Vector2i atlas);
    void harvest_crop(Vector2i grid);
};

#endif
