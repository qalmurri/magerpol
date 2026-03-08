/*
File ini bertanggung jawab atas logika rotasi objek berdasarkan input keyboard. Komponen ini memungkinkan sebuah objek (seperti karakter atau kamera) untuk berputar ke kiri atau ke kanan menggunakan aksi "ui_left" dan "ui_right". File ini juga mengekspos variabel rotation_speed ke editor Godot agar kecepatannya bisa diatur langsung melalui Inspector tanpa mengubah kode.
*/

#include "Rotation.h"

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Rotation::_bind_methods() {
    ClassDB::bind_method(
        D_METHOD("set_rotation_speed", "rotation_speed"),
        &Rotation::set_rotation_speed
    );

    ClassDB::bind_method(
        D_METHOD("get_rotation_speed"),
        &Rotation::get_rotation_speed
    );

    ADD_PROPERTY(
        PropertyInfo(Variant::FLOAT, "rotation_speed"),
        "set_rotation_speed",
        "get_rotation_speed"
    );
}

void Rotation::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) return;

    Input *input = Input::get_singleton();

    if (input->is_action_pressed("ui_right")) {
        set_rotation(get_rotation() + rotation_speed * delta);
    }

    if (input->is_action_pressed("ui_left")) {
        set_rotation(get_rotation() - rotation_speed * delta);
    }
}
