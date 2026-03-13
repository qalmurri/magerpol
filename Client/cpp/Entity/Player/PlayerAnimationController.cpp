#include "PlayerAnimationController.h"
#include "Player.h"

#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void PlayerAnimationController::setup(Player *p, AnimationPlayer *anim_player) {
    player = p;
    animation_player = anim_player;
}

void PlayerAnimationController::play_animation(const String &anim) {

    if (!animation_player) {
        UtilityFunctions::print("AnimationPlayer not found!");
        return;
    }

    if (!animation_player->has_animation(anim)) {
        UtilityFunctions::print("Animation not found: ", anim);
        return;
    }

    animation_player->play(anim);
}

void PlayerAnimationController::play_idle() {

    int variant = UtilityFunctions::randi() % 2 + 1;
    String anim = "idle" + String::num_int64(variant);

    play_animation(anim);
}

void PlayerAnimationController::play_walk() {

    int variant = UtilityFunctions::randi() % 2 + 1;
    String anim = "walk" + String::num_int64(variant);

    play_animation(anim);
}

void PlayerAnimationController::play_run() {

    int variant = UtilityFunctions::randi() % 2 + 1;
    String anim = "run" + String::num_int64(variant);

    play_animation(anim);
}

void PlayerAnimationController::play_attack() {

    int variant = UtilityFunctions::randi() % 4 + 1;
    String anim = "attack" + String::num_int64(variant);

    play_animation(anim);
}

void PlayerAnimationController::play_use_tool() {

    int variant = UtilityFunctions::randi() % 2 + 1;
    String anim = "use_tool" + String::num_int64(variant);

    play_animation(anim);
}

void PlayerAnimationController::play_interact() {

    int variant = UtilityFunctions::randi() % 2 + 1;
    String anim = "interact" + String::num_int64(variant);

    play_animation(anim);
}

void PlayerAnimationController::play_dead() {

    int variant = UtilityFunctions::randi() % 2 + 1;
    String anim = "dead" + String::num_int64(variant);

    play_animation(anim);
}
