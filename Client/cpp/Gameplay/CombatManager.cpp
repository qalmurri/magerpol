#include "CombatManager.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void CombatManager::_bind_methods() {}

void CombatManager::apply_damage(Node2D *target, int damage) {

    if (!target) return;

    Variant health = target->get("health");

    if (health.get_type() == Variant::INT) {

        int hp = health;
        hp -= damage;

        target->set("health", hp);

        if (hp <= 0)
            target->queue_free();
    }
}

void CombatManager::apply_knockback(Node2D *target, Vector2 force) {

    if (!target) return;

    target->set_position(target->get_position() + force);
}
