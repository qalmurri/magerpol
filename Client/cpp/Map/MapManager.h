#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/tile_map.hpp>

using namespace godot;

class MapManager : public Node2D {
    GDCLASS(MapManager, Node2D)

private:
    TileMap *ground;
    TileMap *decoration;
    TileMap *collision;

    int tile_width = 64;
    int tile_height = 32;

protected:
    static void _bind_methods();

public:
    void _ready();

    Vector2 grid_to_iso(Vector2 grid);
    Vector2 iso_to_grid(Vector2 iso);
};

#endif
