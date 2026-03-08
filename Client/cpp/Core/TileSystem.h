#ifndef TILE_SYSTEM_H
#define TILE_SYSTEM_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/tile_map_layer.hpp>

using namespace godot;

class TileSystem : public Object {
    GDCLASS(TileSystem, Object)

private:
    TileMapLayer *ground;
    TileMapLayer *decoration;
    TileMapLayer *collision;

protected:
    static void _bind_methods();

public:

    void setup(TileMapLayer *g, TileMapLayer *d, TileMapLayer *c);

    int get_tile(Vector2i grid);
    void set_tile(Vector2i grid,int source_id,Vector2i atlas);
    void remove_tile(Vector2i grid);

    bool is_walkable(Vector2i grid);

    void plant_crop(Vector2i grid,int source_id,Vector2i atlas);
    void harvest_crop(Vector2i grid);
};

#endif
