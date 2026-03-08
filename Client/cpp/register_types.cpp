#include <godot_cpp/core/class_db.hpp>

// Player
#include "Player/Movement.h"
#include "Player/Rotation.h"
#include "Player/InputHandler.h"

// Map
#include "Map/MapManager.h"

// Gameplay
#include "Gameplay/CombatManager.h"
#include "Gameplay/DropManager.h"
#include "Gameplay/EntityManager.h"

#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) return;

    // Player
    ClassDB::register_class<Movement>();
    ClassDB::register_class<Rotation>();
    ClassDB::register_class<InputHandler>();

    // Map
    ClassDB::register_class<MapManager>();

    // Gameplay
    ClassDB::register_class<CombatManager>();
    ClassDB::register_class<DropManager>();
    ClassDB::register_class<EntityManager>();
}

void uninitialize_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) return;
}

extern "C" {
GDExtensionBool GDE_EXPORT library_init(
    GDExtensionInterfaceGetProcAddress p_get_proc_address,
    const GDExtensionClassLibraryPtr p_library,
    GDExtensionInitialization *r_initialization) {

    GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
    init_obj.register_initializer(initialize_module);
    init_obj.register_terminator(uninitialize_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
    return init_obj.init();
}
}
