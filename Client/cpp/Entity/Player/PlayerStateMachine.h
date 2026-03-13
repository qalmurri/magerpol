#ifndef PLAYER_STATE_MACHINE_H
#define PLAYER_STATE_MACHINE_H

#include <godot_cpp/variant/vector2.hpp>

class Player;

class PlayerStateMachine {

public:

    enum class State {
        IDLE,
        WALK,
        RUN,
        ATTACK,
        USE_TOOL,
        INTERACT,
        DEAD
    };

private:

    Player *player = nullptr;
    State current_state = State::IDLE;

public:

    void setup(Player *p);

    void update(double delta, const godot::Vector2 &direction);

    void change_state(State new_state);

    State get_state() const;
};

#endif
