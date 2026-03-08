#ifndef COMBAT_MANAGER_H
#define COMBAT_MANAGER_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class CombatManager : public Node {
    GDCLASS(CombatManager, Node)

protected:
    static void _bind_methods();

public:
    void _ready();

    void apply_damage(Node2D *target, int damage);
    void apply_knockback(Node2D *target, Vector2 force);
};

#endif
