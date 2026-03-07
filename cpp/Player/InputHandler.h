#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/classes/node.hpp>

using namespace godot;

class InputHandler : public Node {
    GDCLASS(InputHandler, Node);

protected:
    static void _bind_methods();

private:
    Node* joystick_node = nullptr; // pointer ke node Joystick

public:
    InputHandler() {}
    ~InputHandler() {}

    void set_joystick(Node* Joystick) { joystick_node = Joystick; }
    Vector2 get_joystick_direction();

    bool is_moving_right();
    bool is_moving_left();
    bool is_moving_up();
    bool is_moving_down();
};

#endif
