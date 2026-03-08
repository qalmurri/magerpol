#include "Movement.h"

#include "Players.h"
#include "../Core/MapManager.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Movement::_ready() {
}

void Movement::_bind_methods() {
    ClassDB::bind_method(
        D_METHOD("set_speed", "speed"),
        &Movement::set_speed
    );

    ClassDB::bind_method(
        D_METHOD("get_speed"),
        &Movement::get_speed
    );

    ClassDB::bind_method(
        D_METHOD("set_input_handler", "handler"),
        &Movement::set_input_handler
    );

    ADD_PROPERTY(
        PropertyInfo(Variant::FLOAT, "speed"),
        "set_speed",
        "get_speed"
    );
}

void Movement::_process(double delta) {
    if (!input_handler) {
        return;
    }

    Vector2 dir = input_handler->get_joystick_direction();

    Node *p = get_parent();

    while (p) {
        Players *players = Object::cast_to<Players>(p);

        if (players) {
            players->try_move(dir);
            break;
        }

        p = p->get_parent();
    }
}

void Movement::move_to(Vector2i new_grid) {
    if (!map_manager) {
        return;
    }

    Node2D *owner = Object::cast_to<Node2D>(get_parent());

    if (!owner) {
        return;
    }

    Vector2 world_pos = map_manager->grid_to_world(new_grid);

    owner->set_position(world_pos);

    map_manager->update_entity_grid(owner, new_grid);
}

void Movement::set_map_manager(MapManager *mm) {
    map_manager = mm;
}
