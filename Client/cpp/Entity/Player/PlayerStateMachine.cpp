#include "PlayerStateMachine.h"
#include "Player.h"

using namespace godot;

void PlayerStateMachine::setup(Player *p) {
    player = p;
}

PlayerStateMachine::State PlayerStateMachine::get_state() const {
    return current_state;
}

void PlayerStateMachine::change_state(State new_state) {

    if (current_state == new_state) {
        return;
    }

    current_state = new_state;

    switch (current_state) {

        case State::IDLE:
            player->play_animation("idle");
        break;

        case State::WALK:
            player->play_animation("walk");
        break;

        case State::ATTACK:
            player->play_animation("attack");
        break;

        case State::USE_TOOL:
            player->play_animation("use_tool");
        break;

        case State::INTERACT:
            player->play_animation("interact");
        break;

        case State::DEAD:
            player->play_animation("dead");
        break;
    }
}

void PlayerStateMachine::update(double delta, const Vector2 &direction) {

    if (current_state == State::DEAD) {
        return;
    }

    if (direction.length() > 0) {
        change_state(State::WALK);
    } else {
        change_state(State::IDLE);
    }
}
