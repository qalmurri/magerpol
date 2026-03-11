#include "PlayerMovement.h"

using namespace godot;

PlayerMovement::PlayerMovement() {}

void PlayerMovement::setup(CharacterBody2D *p_body) {

    body = p_body;
}

void PlayerMovement::move(Vector2 direction) {

    if (!body) return;

    body->set_velocity(direction * speed);
    body->move_and_slide();
}
