#ifndef PLAYER_MOVEMENT_H
#define PLAYER_MOVEMENT_H

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
