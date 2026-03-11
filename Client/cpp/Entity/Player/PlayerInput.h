#ifndef PLAYER_INPUT_H
#define PLAYER_INPUT_H

#include <godot_cpp/variant/vector2.hpp>

using namespace godot;

class PlayerInput {

public:

    PlayerInput();

    Vector2 get_direction();
};

#endif
