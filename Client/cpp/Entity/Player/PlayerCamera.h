#ifndef PLAYER_CAMERA_H
#define PLAYER_CAMERA_H

using namespace godot;

class PlayerCamera {

private:

    Camera2D *camera = nullptr;

public:

    PlayerCamera();

    void setup(Camera2D *p_camera);

    void activate();
};

#endif
