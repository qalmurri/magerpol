#include "PlayerInput.h"

#include <godot_cpp/classes/input.hpp>

using namespace godot;

PlayerInput::PlayerInput() {}

Vector2 PlayerInput::get_direction() {

    Input *input = Input::get_singleton();

    Vector2 direction;

    direction.x = input->get_action_strength("ui_right")
                - input->get_action_strength("ui_left");

    direction.y = input->get_action_strength("ui_down")
                - input->get_action_strength("ui_up");

    return direction.normalized();
}
