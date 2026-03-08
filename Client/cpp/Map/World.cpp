#include "World.h"
#include "MapManager.h"
#include "Client.h"
#include "../Gameplay/DropManager.h"
#include "../Gameplay/CombatManager.h"

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void World::_bind_methods() {
    // Bisa bind method jika mau expose ke GDScript
}

void World::_ready() {
    UtilityFunctions::print("World ready");

    // Ambil semua manager dari child nodes
    map_manager = Object::cast_to<MapManager>(get_node_or_null("MapManager"));
    client = Object::cast_to<Client>(get_node_or_null("Client"));
    drop_manager = Object::cast_to<DropManager>(get_node_or_null("DropManager"));
    combat_manager = Object::cast_to<CombatManager>(get_node_or_null("CombatManager"));

    // Debug: cek apakah semua manager ditemukan
    if (!map_manager) UtilityFunctions::printerr("MapManager not found!");
    if (!client) UtilityFunctions::printerr("Client not found!");
    if (!drop_manager) UtilityFunctions::printerr("DropManager not found!");
    if (!combat_manager) UtilityFunctions::printerr("CombatManager not found!");

    // Contoh: Client otomatis ambil MapManager supaya bisa update grid marker
    if (client && map_manager) {
        client->set_map_manager(map_manager); // Pastikan Client punya setter
    }
}
