#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/input.hpp>
#include "InputHandler.h"
#include "../Core/MapManager.h"

using namespace godot;

class Movement : public Node2D {
    GDCLASS(Movement, Node2D);

private:

    float speed = 200.0f;
    InputHandler* input_handler = nullptr;
    MapManager *map_manager = nullptr;

protected:
    static void _bind_methods();

public:
    Movement() {}
    ~Movement() {}

    void _process(double delta);
    void _ready();
    void set_speed(float p_speed) { speed = p_speed; }
    void set_input_handler(InputHandler* handler) { input_handler = handler; }
    float get_speed() const { return speed; }
    void move_to(Vector2i new_grid);
    void set_map_manager(MapManager *mm);
};

#endif
