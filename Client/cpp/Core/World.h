#ifndef WORLD_H
#define WORLD_H

#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class MapManager;
class Players;
class DropManager;
class CombatManager;
class EntityManager;

class World : public Node {
    GDCLASS(World, Node)

private:
    MapManager* map_manager = nullptr;
    Players* players = nullptr;
    DropManager* drop_manager = nullptr;
    CombatManager* combat_manager = nullptr;

protected:
    static void _bind_methods();

public:
    void _ready();
    void _process(double delta) override;

    MapManager* get_map_manager() const { return map_manager; }
    Players* get_players() const { return players; }
    DropManager* get_drop_manager() const { return drop_manager; }
    CombatManager* get_combat_manager() const { return combat_manager; }
};

#endif
