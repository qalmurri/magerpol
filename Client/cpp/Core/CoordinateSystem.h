#ifndef COORDINATE_SYSTEM_H
#define COORDINATE_SYSTEM_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/vector2i.hpp>

using namespace godot;

class CoordinateSystem : public Object {
    GDCLASS(CoordinateSystem, Object)

private:
    int tile_width = 64;
    int tile_height = 32;

protected:
    static void _bind_methods();

public:
    Vector2 grid_to_iso(Vector2 grid);
    Vector2 iso_to_grid(Vector2 iso);

    Vector2 grid_to_world(Vector2i grid);
    Vector2i world_to_grid(Vector2 world);
};

#endif
