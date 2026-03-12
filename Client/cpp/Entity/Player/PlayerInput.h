#ifndef PLAYER_INPUT_H
#define PLAYER_INPUT_H

#include <godot_cpp/variant/vector2.hpp>

namespace godot {
class Joystick;
}

class PlayerInput {

private:
    godot::Joystick *joystick = nullptr;

public:
    void setup(godot::Joystick *j);
    godot::Vector2 get_direction();
};

#endif
