| Dari          | Ke            | Tujuan                                          |
| ------------- | ------------- | ----------------------------------------------- |
| Client        | MapManager    | Hitung grid / world position                    |
| Client        | EntityManager | Cek collisions / spawn entity                   |
| CombatManager | EntityManager | Hit target, apply damage                        |
| CombatManager | MapManager    | Drop loot setelah enemy mati                    |
| World         | Semua manager | Orchestrasi init, update, dan pointer manajemen |

.
├── Core
│   ├── MapManager.cpp
│   ├── MapManager.h
│   ├── README.MD
│   ├── World.cpp
│   └── World.h
├── Gameplay
│   ├── CombatManager.cpp
│   ├── CombatManager.h
│   ├── DropManager.cpp
│   ├── DropManager.h
│   ├── EntityManager.cpp
│   ├── EntityManager.h
│   └── README.MD
├── Network
├── Player
│   ├── InputHandler.cpp
│   ├── InputHandler.h
│   ├── Movement.cpp
│   ├── Movement.h
│   ├── Players.cpp
│   ├── Players.h
│   ├── Rotation.cpp
│   └── Rotation.h
├── README.MD
├── register_types.cpp
├── register_types.h
└── SConstruct

 ┖╴Main
    ┠╴Network
    ┠╴World
    ┃  ┠╴MapManager
    ┃  ┠╴TileMap
    ┃  ┃  ┠╴Layer0
    ┃  ┃  ┠╴Ground
    ┃  ┃  ┠╴Decoration
    ┃  ┃  ┖╴Collision
    ┃  ┠╴EntityManager
    ┃  ┃  ┠╴Enemies
    ┃  ┃  ┠╴Projectiles
    ┃  ┃  ┠╴NPCs
    ┃  ┃  ┠╴Animals
    ┃  ┃  ┖╴Players
    ┃  ┃     ┖╴Player
    ┃  ┃        ┠╴Sprite2D
    ┃  ┃        ┠╴CollisionShape2D
    ┃  ┃        ┠╴Movement
    ┃  ┃        ┠╴Rotation
    ┃  ┃        ┠╴InputHandler
    ┃  ┃        ┖╴Marker
    ┃  ┠╴CombatManager
    ┃  ┖╴DropManager
    ┖╴UI
       ┖╴Joystick
          ┖╴Knob

