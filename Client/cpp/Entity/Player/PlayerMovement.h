#ifndef PLAYER_MOVEMENT_H
#define PLAYER_MOVEMENT_H

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/variant/vector2.hpp>

using namespace godot;

class PlayerMovement {

private:

    CharacterBody2D *body = nullptr;
    float speed = 200.0;

public:

    PlayerMovement();

    void setup(CharacterBody2D *p_body);

    void move(Vector2 direction);
};

#endif
