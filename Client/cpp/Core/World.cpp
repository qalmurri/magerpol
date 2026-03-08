#include "World.h"
#include "MapManager.h"
#include "../Player/Players.h"
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

    // Jika script ini menempel di node "World", maka anaknya cukup dipanggil namanya saja
    map_manager = Object::cast_to<MapManager>(get_node_or_null("MapManager"));
    drop_manager = Object::cast_to<DropManager>(get_node_or_null("DropManager"));
    combat_manager = Object::cast_to<CombatManager>(get_node_or_null("CombatManager"));

    // EntityManager juga anak langsung dari World
    EntityManager* entity_manager = Object::cast_to<EntityManager>(get_node_or_null("EntityManager"));
    
    if (!entity_manager || !map_manager) {
        // Jika masih error, print path aslinya untuk debug
        UtilityFunctions::printerr("World: Critical managers missing! Path check: ", get_path());
        return;
    }

    // 2. Ambil node Players yang berada di dalam EntityManager
    players = Object::cast_to<Players>(entity_manager->get_node_or_null("Players"));
    
    if (players) {
        // PENTING: Berikan MapManager ke Players agar ia bisa menghitung grid_to_world
        players->set_map_manager(map_manager);
        
        // Daftarkan visual player ke registry EntityManager
        Node2D* player_node = Object::cast_to<Node2D>(players->get_node_or_null("Player"));
        if (player_node) {
            entity_manager->register_player(player_node);
        }
        
        // Inisialisasi posisi awal player di grid (misal 0,0)
        players->move_to_grid(Vector2i(0, 0));
    } else {
        UtilityFunctions::printerr("World: Players node not found!");
    }
}

void World::_process(double delta) {
    if (players && map_manager) {
        // Ambil posisi global visual player melalui Players controller
        Node2D* p_visual = Object::cast_to<Node2D>(players->get_node_or_null("Player"));
        if (p_visual) {
            Vector2 global_pos = p_visual->get_global_position();
            Vector2i current_grid = map_manager->world_to_grid(global_pos);
            
            // World sekarang tahu koordinat grid player setiap saat
            // UtilityFunctions::print("Player is at grid: ", current_grid);
        }
    }
}
