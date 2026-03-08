#ifndef GRID_SYSTEM_H
#define GRID_SYSTEM_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/vector2i.hpp>

#include <unordered_map>

using namespace godot;

class GridSystem : public Object {
    GDCLASS(GridSystem, Object)

private:
    std::unordered_map<Node2D *, Vector2i> entity_grid;

protected:
    static void _bind_methods();

public:
    void set_entity_grid(Node2D *node, Vector2i grid);
    void update_entity_grid(Node2D *node, Vector2i grid);
    Vector2i get_entity_grid(Node2D *node);
};

#endif
