Main
├── Network
├── World
├── Players
├── Enemies
├── Projectiles
└── UI
| Node        | Fungsi              |
| ----------- | ------------------- |
| Network     | multiplayer manager |
| World       | map dan environment |
| Players     | semua player        |
| Enemies     | monster             |
| Projectiles | peluru / skill      |
| UI          | HUD                 |

===============================
World
└── Map
    ├── Ground (TileMap)
    ├── Decoration (TileMap)
    ├── Collision (TileMap)
    └── SpawnPoints
| Layer       | Fungsi                   |
| ----------- | ------------------------ |
| Ground      | lantai                   |
| Decoration  | pohon, rumah             |
| Collision   | tile tidak bisa dilewati |
| SpawnPoints | spawn player / monster   |

===============================
Player
├── CharacterBody2D
│
├── Sprite2D
├── AnimationPlayer
├── CollisionShape2D
│
├── Camera2D
│
└── Components
    ├── InputHandler
    ├── Movement
    ├── Combat
    └── NetworkSync
spawn player
destroy player
sync player

===============================
Players
├── Player_1
├── Player_2
└── Player_3
PlayerScene.instantiate()

===============================
Enemy
├── CharacterBody2D
├── Sprite2D
├── AnimationPlayer
├── CollisionShape2D
└── AI
Enemies
├── Slime
├── Skeleton
└── Boss

===============================
UI
├── HUD
│   ├── HPBar
│   ├── ManaBar
│   └── MiniMap
│
├── Mobile
│   ├── Joystick
│   └── SkillButtons
│
└── Menu
    ├── Inventory
    └── Settings

===============================
Main
├── Network
│   └── NetworkManager
│
├── World
│   └── Map
│       ├── Ground
│       ├── Decoration
│       ├── Collision
│       └── SpawnPoints
│
├── Players
│
├── Enemies
│
├── Projectiles
│
└── UI
    ├── HUD
    └── Mobile
        ├── Joystick
        └── Skills

======================
viavlo/
├── project.godot
│
├── scenes/
├── scripts/
├── assets/
├── cpp/
├── addons/
└── build/
| Folder  | Fungsi             |
| ------- | ------------------ |
| scenes  | semua scene Godot  |
| scripts | script GDScript    |
| assets  | sprite, sound, dll |
| cpp     | kode C++ extension |
| addons  | plugin Godot       |
| build   | hasil compile      |

scenes/
├── main/
│   └── main.tscn
│
├── world/
│   └── map.tscn
│
├── player/
│   └── player.tscn
│
├── enemy/
│   └── enemy.tscn
│
├── projectile/
│   └── projectile.tscn
│
└── ui/
    ├── hud.tscn
    └── joystick.tscn

scripts/
├── ui/
│   ├── joystick.gd
│   └── hud.gd
│
├── network/
│   └── network_manager.gd
│
└── utils/
    └── helper.gd

assets/
├── sprites/
│   ├── player/
│   ├── enemy/
│   └── environment/
│
├── tileset/
│   └── isometric/
│
├── sounds/
│
└── ui/

cpp/
├── SConstruct
│
├── include/
│   ├── player/
│   │   ├── InputHandler.h
│   │   ├── Movement.h
│   │   └── Rotation.h
│   │
│   ├── map/
│   │   └── MapManager.h
│   │
│   └── network/
│       └── NetworkManager.h
│
├── src/
│   ├── player/
│   │   ├── InputHandler.cpp
│   │   ├── Movement.cpp
│   │   └── Rotation.cpp
│   │
│   ├── map/
│   │   └── MapManager.cpp
│   │
│   └── network/
│       └── NetworkManager.cpp
│
└── register_types.cpp

Map
├── Ground (TileMap)
├── Decoration (TileMap)
├── Collision (TileMap)
└── SpawnPoints

viavlo/
│
├── project.godot
│
├── scenes/
│   ├── main/
│   │   └── main.tscn
│   │
│   ├── world/
│   │   └── map.tscn
│   │
│   ├── player/
│   │   └── player.tscn
│   │
│   ├── enemy/
│   │   └── enemy.tscn
│   │
│   ├── projectile/
│   │   └── projectile.tscn
│   │
│   └── ui/
│       ├── hud.tscn
│       └── joystick.tscn
│
├── scripts/
│   ├── ui/
│   ├── network/
│   └── utils/
│
├── assets/
│   ├── sprites/
│   ├── tileset/
│   ├── sounds/
│   └── ui/
│
├── cpp/
│   ├── include/
│   ├── src/
│   ├── SConstruct
│   └── register_types.cpp
│
└── build/
