/*
File ini bertanggung jawab atas sistem looting atau pemunculan barang setelah suatu kejadian (seperti musuh mati). Ia menangani proses instantiate objek dari PackedScene (misalnya koin emas) ke dalam dunia permainan. File ini juga mengatur variasi posisi munculnya barang secara acak di sekitar titik koordinat tertentu agar tumpukan barang tidak terlihat bertumpuk kaku di satu titik yang sama.
*/

#include "DropManager.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void DropManager::_bind_methods() {
    ClassDB::bind_method(
        D_METHOD("set_gold_scene", "scene"),
        &DropManager::set_gold_scene
    );
}

void DropManager::_ready() {
    UtilityFunctions::print("DropManager ready");
}

void DropManager::set_gold_scene(Ref<PackedScene> scene) {
    gold_scene = scene;
}

void DropManager::drop_gold(Vector2 pos, int amount) {
    if (!gold_scene.is_valid()) {
        return;
    }

    for (int i = 0; i < amount; i++) {
        Node2D *gold = Object::cast_to<Node2D>(
            gold_scene->instantiate()
        );

        if (!gold) {
            continue;
        }

        gold->set_position(
            pos + Vector2(
                UtilityFunctions::randf() * 32,
                UtilityFunctions::randf() * 32
            )
        );

        add_child(gold);
    }
}
