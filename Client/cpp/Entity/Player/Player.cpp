#include "Player.h"

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

Player::Player() {}
Player::~Player() {}

void Player::_bind_methods() {
}

void Player::_ready() {

    collisionplayer = Object::cast_to<CollisionShape2D>(get_node_or_null("CollisionPlayer"));
    cameramanager = Object::cast_to<Camera2D>(get_node_or_null("CameraManager"));
    interaction = Object::cast_to<Area2D>(get_node_or_null("Interaction"));
    animationplayer = Object::cast_to<AnimationPlayer>(get_node_or_null("AnimationPlayer"));

    marker = Object::cast_to<Node2D>(get_node_or_null("Marker"));
    tool = Object::cast_to<Marker2D>(get_node_or_null("Marker/Tool"));
    interactionpoint = Object::cast_to<Marker2D>(get_node_or_null("Marker/InteractionPoint"));
    damagetext = Object::cast_to<Marker2D>(get_node_or_null("Marker/DamageText"));
    itemdrop = Object::cast_to<Marker2D>(get_node_or_null("Marker/ItemDrop"));
    
    visual = Object::cast_to<Node2D>(get_node_or_null("Visual"));
    pants = Object::cast_to<Sprite2D>(get_node_or_null("Visual/Pants"));
    shirt = Object::cast_to<Sprite2D>(get_node_or_null("Visual/Shirt"));
    head = Object::cast_to<Sprite2D>(get_node_or_null("Visual/Head"));
    hair = Object::cast_to<Sprite2D>(get_node_or_null("Visual/Hair"));
    lefthand = Object::cast_to<Sprite2D>(get_node_or_null("Visual/LeftHand"));
    righthand = Object::cast_to<Sprite2D>(get_node_or_null("Visual/RightHand"));

    joystick = Object::cast_to<Joystick>(get_node_or_null("/root/Main/UI/CanvasLayer/Joystick"));
    input.setup(joystick);

    movement.setup(this);
    camera.setup(cameramanager);
    camera.activate();

    state_machine.setup(this);
}

void Player::_physics_process(double delta) {

    Vector2 direction = input.get_direction();

    state_machine.update(delta, direction);

    movement.move(direction);
}

void Player::play_animation(const char *anim) {

    if (!animationplayer) {
        UtilityFunctions::print("AnimationPlayer not found!");
        return;
    }

    if (!animationplayer->has_animation(anim)) {
        UtilityFunctions::print("Animation not found: ", anim);
        return;
    }

    animationplayer->play(anim);
}
