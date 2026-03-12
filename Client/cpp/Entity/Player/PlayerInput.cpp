#include "PlayerInput.h"
#include "../../Input/Joystick.h"

using namespace godot;

void PlayerInput::setup(Joystick *j) {
    joystick = j;
}

Vector2 PlayerInput::get_direction() {

    if (joystick) {
        return joystick->get_direction();
    }

    return Vector2(0,0);
}
