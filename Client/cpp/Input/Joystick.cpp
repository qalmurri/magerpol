#include "Joystick.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/texture2d.hpp>

using namespace godot;

void Joystick::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_direction"), &Joystick::get_direction);
}

Joystick::Joystick() {
    touched = false;
}

Joystick::~Joystick() {}

void Joystick::_ready() {
    knob = get_node<Sprite2D>("Knob");
    
    // Mengambil radius dari shape (asumsi menggunakan CircleShape2D)
    Ref<CircleShape2D> shape_ref = get_shape();
    if (shape_ref.is_valid()) {
        max_distance = shape_ref->get_radius();
    }

    if (get_texture_normal().is_valid()) {
        stick_center = get_texture_normal()->get_size() / 2.0f;
    }

    if (knob) {
        knob->set_position(stick_center);
    }
    
    set_process(false);
}

void Joystick::_input(const Ref<InputEvent> &event) {
    Ref<InputEventScreenTouch> touch_event = event;
    
    if (touch_event.is_valid()) {
        if (touch_event->is_pressed()) {
            touched = true;
            set_process(true);
        } else {
            touched = false;
            set_process(false);
            
            if (knob) {
                knob->set_position(stick_center);
            }
            output = Vector2(0, 0);
        }
    }
}

void Joystick::_process(double delta) {
    if (!touched || !knob) {
        return;
    }

    // Mengikuti posisi mouse/touch secara global lalu dikonversi ke lokal
    knob->set_global_position(get_global_mouse_position());
    
    // Limit panjang pergerakan knob
    Vector2 offset = knob->get_position() - stick_center;
    knob->set_position(stick_center + offset.limit_length(max_distance));
    
    // Kalkulasi output (normalized)
    output = (knob->get_position() - stick_center).normalized();
}

Vector2 Joystick::get_direction() const {
    return output;
}
