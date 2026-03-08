#include "register_types.h"

#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "Core/MapManager.h"
#include "Core/World.h"
#include "Core/CoordinateSystem.h"
#include "Core/GridSystem.h"
#include "Core/TileSystem.h"

#include "Player/Movement.h"
#include "Player/Rotation.h"
#include "Player/InputHandler.h"
#include "Player/Players.h"

#include "Gameplay/CombatManager.h"
#include "Gameplay/DropManager.h"
#include "Gameplay/EntityManager.h"
#include "Gameplay/TileEventManager.h"

using namespace godot;

void initialize_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    ClassDB::register_class<MapManager>();
    ClassDB::register_class<World>();
    ClassDB::register_class<CoordinateSystem>();
    ClassDB::register_class<GridSystem>();
    ClassDB::register_class<TileSystem>();

    ClassDB::register_class<Movement>();
    ClassDB::register_class<Rotation>();
    ClassDB::register_class<InputHandler>();
    ClassDB::register_class<Players>();

    ClassDB::register_class<CombatManager>();
    ClassDB::register_class<DropManager>();
    ClassDB::register_class<EntityManager>();
    ClassDB::register_class<TileEventManager>();
}

void uninitialize_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
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
