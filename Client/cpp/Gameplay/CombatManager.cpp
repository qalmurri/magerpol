/*
File ini menangani logika interaksi antar entitas yang berkaitan dengan pertarungan. Fungsi utamanya adalah memanipulasi variabel status (seperti atribut health) pada objek target tanpa perlu tahu detail internal objek tersebut. Selain mengurangi nyawa dan menghapus objek jika nyawanya habis, file ini juga menangani efek fisik sederhana seperti knockback (dorongan) saat sebuah entitas terkena serangan.
*/

#include "CombatManager.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void CombatManager::_bind_methods() {
}

void CombatManager::_ready() {
    UtilityFunctions::print("CombatManager ready");
}

void CombatManager::apply_damage(Node2D *target, int damage) {
    if (!target) {
        return;
    }

    Variant health = target->get("health");

    if (health.get_type() == Variant::INT) {
        int hp = health;

        hp -= damage;

        target->set("health", hp);

        if (hp <= 0) {
            target->queue_free();
        }
    }
}

void CombatManager::apply_knockback(Node2D *target, Vector2 force) {
    if (!target) {
        return;
    }

    target->set_position(
        target->get_position() + force
    );
}
