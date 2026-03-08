World
├── MapManager
├── TileMap
│   ├── Ground
│   ├── Decoration
│   └── Collision
├── Entities
│   ├── Player
│   ├── NPC
│   └── Enemy
└── Drops
====
Contoh penggunaan
Spawn player
map_manager->spawn_on_grid(player, Vector2i(10,8));

Drop item dari enemy
map_manager->drop_loot(item_scene, Vector2i(12,9));

Farming
map_manager->plant_crop(Vector2i(5,6), source_id, atlas);

Trigger tile event
Misalnya:
map_manager->register_tile_event(Vector2i(10,10),"house_enter");

Player injak tile:
String event = map_manager->trigger_tile_event(grid);

Kenapa ini cocok untuk game kamu
Game yang kamu rancang:
Citampi style
Diablo style combat
mobile joystick
MapManager ini bisa menangani:
map tile
entity spawn
loot
farming
event trigger
tanpa sistem berat seperti pathfinding.

====
World
├── MapManager
├── EntityManager
├── CombatManager
├── DropManager
├── TileMap
│   ├── Ground
│   ├── Decoration
│   └── Collision
├── Entities
│   ├── Player
│   ├── Enemies
│   └── NPC
└── Drops

