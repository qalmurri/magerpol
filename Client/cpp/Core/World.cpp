#include "World.h"
#include "MapManager.h"
#include "../Player/Client.h"
#include "../Gameplay/DropManager.h"
#include "../Gameplay/CombatManager.h"
#include "../Gameplay/EntityManager.h"

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;




void World::_bind_methods() {
    // Bisa bind method jika mau expose ke GDScript
}

void World::_ready() {
    UtilityFunctions::print("World ready");

    map_manager = Object::cast_to<MapManager>(get_node_or_null("MapManager"));
    drop_manager = Object::cast_to<DropManager>(get_node_or_null("DropManager"));
    combat_manager = Object::cast_to<CombatManager>(get_node_or_null("CombatManager"));

    EntityManager* entity_manager = Object::cast_to<EntityManager>(get_node_or_null("EntityManager"));
    if (!entity_manager) {
        UtilityFunctions::printerr("EntityManager not found!");
        return;
    }

    // Daftarkan Client/Player di EntityManager
    Client* client_node = Object::cast_to<Client>(entity_manager->get_node_or_null("Client"));
    if (client_node) {
        Node2D* player = Object::cast_to<Node2D>(
            client_node->get_node_or_null("Player")
        );
        
        if (player) {
            entity_manager->register_player(player);
        }
        client_node->set_map_manager(map_manager);
    } else {
        UtilityFunctions::printerr("Client not found inside EntityManager!");
    }
}
