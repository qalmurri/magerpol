#ifndef PLAYER_ANIMATION_CONTROLLER_H
#define PLAYER_ANIMATION_CONTROLLER_H

#include <godot_cpp/classes/animation_player.hpp>
#include <godot_cpp/variant/string.hpp>

using namespace godot;

class Player;

class PlayerAnimationController {

private:

    Player *player = nullptr;
    AnimationPlayer *animation_player = nullptr;

    void play_animation(const String &anim);

public:

    void setup(Player *p, AnimationPlayer *anim_player);

    void play_idle();
    void play_walk();
    void play_run();
    void play_attack();
    void play_use_tool();
    void play_interact();
    void play_dead();

};

#endif
