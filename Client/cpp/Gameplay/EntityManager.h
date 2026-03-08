#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/templates/vector.hpp>

using namespace godot;

class EntityManager : public Node2D {
    GDCLASS(EntityManager, Node2D)

private:

    Vector<Node2D*> players;
    Vector<Node2D*> enemies;
    Vector<Node2D*> npcs;

protected:
    static void _bind_methods();

public:
    void _ready();
    void register_player(Node2D *node);
    void register_enemy(Node2D *node);
    void register_npc(Node2D *node);

    void remove_entity(Node2D *node);

    Node2D* get_closest_enemy(Vector2 pos, float radius);
};

#endif
