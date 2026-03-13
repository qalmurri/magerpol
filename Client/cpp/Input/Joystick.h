#ifndef JOYSTICK_H
#define JOYSTICK_H

namespace godot {

class Joystick : public TouchScreenButton {
    GDCLASS(Joystick, TouchScreenButton)

private:
    Sprite2D *knob;
    float max_distance;
    Vector2 stick_center;
    bool touched = false;
    Vector2 output = Vector2(0, 0);

protected:
    static void _bind_methods();

public:
    Joystick();
    ~Joystick();

    void _ready() override;
    void _input(const Ref<InputEvent> &event) override;
    void _process(double delta) override;

    Vector2 get_direction() const;
};

}

#endif
