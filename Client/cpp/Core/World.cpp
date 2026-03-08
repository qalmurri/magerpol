/*
File ini berfungsi sebagai pusat inisialisasi (Orchestrator) seluruh permainan. Saat level dimuat (_ready), file ini secara otomatis mencari dan menghubungkan semua manajer (Map, Drop, Combat, Entity) agar bisa saling berkomunikasi. Ia juga bertanggung jawab menyiapkan pemain di posisi awal (grid 0,0) dan memantau posisi pemain secara real-time untuk dikonversi ke koordinat grid dalam loop permainan.
*/

#include "World.h"

#include "MapManager.h"
#include "../Player/Players.h"
#include "../Gameplay/DropManager.h"
#include "../Gameplay/CombatManager.h"
#include "../Gameplay/EntityManager.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void World::_bind_methods() {
}

void World::_ready() {
    UtilityFunctions::print("World ready");

    map_manager = Object::cast_to<MapManager>(
        get_node_or_null("MapManager")
    );

    drop_manager = Object::cast_to<DropManager>(
        get_node_or_null("DropManager")
    );

    combat_manager = Object::cast_to<CombatManager>(
        get_node_or_null("CombatManager")
    );

    EntityManager *entity_manager = Object::cast_to<EntityManager>(
        get_node_or_null("EntityManager")
    );

    if (!entity_manager || !map_manager) {
        UtilityFunctions::printerr(
            "World: Critical managers missing! Path check: ",
            get_path()
        );
        return;
    }

    players = Object::cast_to<Players>(
        entity_manager->get_node_or_null("Players")
    );

    if (players) {
        players->set_map_manager(map_manager);

        Node2D *player_node = Object::cast_to<Node2D>(
            players->get_node_or_null("Player")
        );

        if (player_node) {
            entity_manager->register_player(player_node);
        }

        players->move_to_grid(Vector2i(0, 0));
    } else {
        UtilityFunctions::printerr(
            "World: Players node not found!"
        );
    }
}

void World::_process(double delta) {
    if (players && map_manager) {
        Node2D *p_visual = Object::cast_to<Node2D>(
            players->get_node_or_null("Player")
        );

        if (p_visual) {
            Vector2 global_pos = p_visual->get_global_position();

            Vector2i current_grid = map_manager->world_to_grid(
                global_pos
            );
        }
    }
}
