#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/node_path.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/collision_shape2d.hpp>
#include <godot_cpp/classes/camera2d.hpp>
#include <godot_cpp/classes/marker2d.hpp>


#include "PlayerInput.h"
#include "PlayerMovement.h"
#include "PlayerCamera.h"
#include "../../Gameplay/Stats/Stats.h"
#include "../../Gameplay/Inventory/Inventory.h"

using namespace godot;

class Player : public CharacterBody2D {
    GDCLASS(Player, CharacterBody2D)

private:
    float speed = 200.0;

    Stats stats;
    Inventory inventory;

    PlayerInput input;
    PlayerMovement movement;
    PlayerCamera camera;

    Node2D *visual = nullptr;
    Sprite2D *sprite = nullptr;
    CollisionShape2D *collision = nullptr;
    Camera2D *cameramanager = nullptr;
    Marker2D *marker = nullptr;

protected:
    static void _bind_methods();

public:
    Player();
    ~Player();

    void _ready();
    void _physics_process(double delta);
};

#endif
