#include "InputHandler.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void InputHandler::_bind_methods() {
    ClassDB::bind_method(D_METHOD("is_moving_right"), &InputHandler::is_moving_right);
    ClassDB::bind_method(D_METHOD("is_moving_left"), &InputHandler::is_moving_left);
    ClassDB::bind_method(D_METHOD("is_moving_up"), &InputHandler::is_moving_up);
    ClassDB::bind_method(D_METHOD("is_moving_down"), &InputHandler::is_moving_down);

    ClassDB::bind_method(D_METHOD("set_joystick", "joystick"), &InputHandler::set_joystick);
}

Vector2 InputHandler::get_joystick_direction() {
    if (!joystick_node) {
        UtilityFunctions::print("Joystick NOT SET");
        return Vector2(0,0);
    }

    Variant dir = joystick_node->call("direction");

    UtilityFunctions::print("Joystick dir:", dir);

    if (dir.get_type() == Variant::VECTOR2) {
        return dir;
    }

    return Vector2(0,0);
}

bool InputHandler::is_moving_right() { return get_joystick_direction().x > 0.2; }
bool InputHandler::is_moving_left()  { return get_joystick_direction().x < -0.2; }
bool InputHandler::is_moving_up()    { return get_joystick_direction().y < -0.2; }
bool InputHandler::is_moving_down()  { return get_joystick_direction().y > 0.2; }
