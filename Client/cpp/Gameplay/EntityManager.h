#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/templates/vector.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/variant/vector2i.hpp>

using namespace godot;

class EntityManager : public Node2D {
    GDCLASS(EntityManager, Node2D)

private:
    Vector<Node2D*> players;
    Vector<Node2D*> enemies;
    Vector<Node2D*> npcs;
    HashMap<Vector2i, Node2D*> entity_grid;

protected:
    static void _bind_methods();

public:
    bool is_tile_occupied(Vector2i grid);
    void _ready();
    void register_player(Node2D *node);
    void register_enemy(Node2D *node);
    void register_npc(Node2D *node);
    void remove_entity(Node2D *node);
    void set_entity_grid(Node2D* node, Vector2i grid);
    void remove_entity_grid(Vector2i grid);
    Node2D* get_entity_at(Vector2i grid);
    Node2D* get_closest_enemy(Vector2 pos, float radius);
};

#endif
