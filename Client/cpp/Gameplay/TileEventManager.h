#ifndef TILE_EVENT_MANAGER_H
#define TILE_EVENT_MANAGER_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/templates/hash_map.hpp>

using namespace godot;

class TileEventManager : public Object {
    GDCLASS(TileEventManager, Object)

private:
    HashMap<Vector2i, String> tile_events;

protected:
    static void _bind_methods();

public:
    void register_tile_event(Vector2i grid, String event);
    String trigger_tile_event(Vector2i grid);
};

#endif
