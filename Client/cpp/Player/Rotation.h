#ifndef ROTATION_H
#define ROTATION_H

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class Rotation : public Node2D {
    GDCLASS(Rotation, Node2D);

private:
    float rotation_speed = 5.0f;

protected:
    static void _bind_methods();

public:
    Rotation() {}
    ~Rotation() {}

    void _process(double delta);

    void set_rotation_speed(float r) {
        rotation_speed = r;
    }

    float get_rotation_speed() const {
        return rotation_speed;
    }
};

#endif
