#ifndef DROP_MANAGER_H
#define DROP_MANAGER_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/packed_scene.hpp>

using namespace godot;

class DropManager : public Node2D {
    GDCLASS(DropManager, Node2D)

private:
    Ref<PackedScene> gold_scene;

protected:
    static void _bind_methods();

public:
    void _ready();

    void set_gold_scene(Ref<PackedScene> scene);
    void drop_gold(Vector2 pos, int amount);
};

#endif
