/*
File ini berfungsi sebagai sistem pencatat peristiwa (event) yang terikat pada koordinat tertentu di peta. Ia menggunakan struktur data untuk memetakan posisi grid ke sebuah nama event (dalam bentuk string). Kegunaan utamanya adalah untuk memicu aksi khusus saat pemain menginjak petak tertentu, seperti memunculkan dialog, memicu jebakan, atau berpindah level.
*/

#include "TileEventManager.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void TileEventManager::_bind_methods() {
}

void TileEventManager::register_tile_event(Vector2i grid, String event) {
    tile_events.insert(grid, event);
}

String TileEventManager::trigger_tile_event(Vector2i grid) {
    if (tile_events.has(grid)) {
        return tile_events[grid];
    }

    return "";
}
