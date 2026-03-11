#include "PlayerCamera.h"

using namespace godot;

PlayerCamera::PlayerCamera() {}

void PlayerCamera::setup(Camera2D *p_camera) {

    camera = p_camera;
}

void PlayerCamera::activate() {

    if (camera) {
        camera->make_current();
    }
}
