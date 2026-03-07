#include "Movement.h"
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Movement::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), &Movement::set_speed);
    ClassDB::bind_method(D_METHOD("get_speed"), &Movement::get_speed);
    ClassDB::bind_method(D_METHOD("set_input_handler", "handler"), &Movement::set_input_handler);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
}

void Movement::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) return;

    if (!input_handler) return;

    Vector2 dir = input_handler->get_joystick_direction();

    Node2D* parent2d = Object::cast_to<Node2D>(get_parent());

    if (parent2d) {
        parent2d->set_position(parent2d->get_position() + dir * speed * delta);
    }
}
