#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/node2d.hpp>

#include "../Core/MapManager.h"
#include "InputHandler.h"

using namespace godot;

class Movement : public Node2D {
    GDCLASS(Movement, Node2D);

private:
    float speed = 200.0f;
    InputHandler *input_handler = nullptr;
    MapManager *map_manager = nullptr;

protected:
    static void _bind_methods();

public:
    Movement() {}
    ~Movement() {}

    void _ready();
    void _process(double delta);

    void set_speed(float p_speed) { speed = p_speed; }
    float get_speed() const { return speed; }

    void set_input_handler(InputHandler *handler) { input_handler = handler; }

    void move_to(Vector2i new_grid);
    void set_map_manager(MapManager *mm);
};

#endif
