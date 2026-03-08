#ifndef PLAYERS_H
#define PLAYERS_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/variant/vector2i.hpp>
#include <godot_cpp/core/object.hpp>

using namespace godot;

class MapManager; // forward declaration

class Players : public Node2D {
    GDCLASS(Players, Node2D)

private:
    Vector2i grid_pos = Vector2i(0, 0);
    MapManager *map_manager = nullptr;
    Node2D *player_visual = nullptr;

protected:
    static void _bind_methods();

public:
    void _ready();
    void try_move(Vector2 dir);

    void set_grid_pos(Vector2i grid);
    Vector2i get_grid_pos() const { return grid_pos; }
    void move_to_grid(Vector2i grid);
    void set_map_manager(MapManager* manager);
};

#endif
