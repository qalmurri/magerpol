#include "Player.h"

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/vector2.hpp>

using namespace godot;

Player::Player() {}
Player::~Player() {}

void Player::_bind_methods() {
}

void Player::_ready() {

    collision = Object::cast_to<CollisionShape2D>(get_node_or_null("Collision"));
    cameramanager = Object::cast_to<Camera2D>(get_node_or_null("CameraManager"));
    
    visual = Object::cast_to<Node2D>(get_node_or_null("Visual"));
    sprite = Object::cast_to<Sprite2D>(get_node_or_null("Visual/Sprite"));
    marker = Object::cast_to<Marker2D>(get_node_or_null("Visual/Marker"));

    movement.setup(this);
    camera.setup(cameramanager);
    camera.activate();
}

void Player::_physics_process(double delta) {

    Vector2 direction = input.get_direction();

    movement.move(direction);
}
