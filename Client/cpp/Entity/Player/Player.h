#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerInput.h"
#include "PlayerMovement.h"
#include "PlayerCamera.h"
#include "PlayerStateMachine.h"
#include "PlayerAnimationController.h"
#include "../../Input/Joystick.h"
#include "../../Gameplay/Stats/Stats.h"
#include "../../Gameplay/Inventory/Inventory.h"

using namespace godot;

class Player : public CharacterBody2D {
    GDCLASS(Player, CharacterBody2D)

private:
    Stats stats;
    Inventory inventory;

    PlayerInput input;
    PlayerMovement movement;
    PlayerCamera camera;
    PlayerStateMachine state_machine;
    PlayerAnimationController animation;

    Joystick *joystick = nullptr;

    CollisionShape2D *collisionplayer = nullptr;
    Camera2D *cameramanager = nullptr;
    Area2D *interaction = nullptr;
    AnimationPlayer *animationplayer = nullptr;

    Node2D *marker = nullptr;
    Marker2D *tool = nullptr;
    Marker2D *interactionpoint= nullptr;
    Marker2D *damagetext = nullptr;
    Marker2D *itemdrop = nullptr;

    Node2D *visual = nullptr;
    Sprite2D *pants= nullptr;
    Sprite2D *shirt = nullptr;
    Sprite2D *head = nullptr;
    Sprite2D *hair = nullptr;
    Sprite2D *lefthand = nullptr;
    Sprite2D *righthand = nullptr;
    Sprite2D *lefttool = nullptr;
    Sprite2D *righttool = nullptr;
    Sprite2D *bag = nullptr;

protected:
    static void _bind_methods();

public:
    Player();
    ~Player();

    void _ready();
    void _physics_process(double delta);

    PlayerAnimationController &get_animation();
};

#endif
