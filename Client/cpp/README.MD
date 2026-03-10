CPP/
├── Core                        # Simulation Layer
│   ├── MapManager
│   │   ├── MapManager.cpp
│   │   ├── MapManager.h
│   │   └── TileMap.cpp
│   │       TileMap.h
│   ├── EntityManager
│   │   ├── EntityManager.cpp
│   │   ├── EntityManager.h
│   │   ├── Player.cpp
│   │   ├── Player.h
│   │   ├── NPC.cpp
│   │   ├── NPC.h
│   │   ├── Animal.cpp
│   │   ├── Animal.h
│   │   ├── Enemy.cpp
│   │   ├── Enemy.h
│   │   ├── Object.cpp
│   │   └── Object.h
│   └── Interiors
│       └── House001
│           ├── MapManager.cpp
│           └── MapManager.h
│
├── Gameplay                     # Game Logic Layer
│   ├── InventoryManager.cpp
│   ├── InventoryManager.h
│   ├── Stats.cpp
│   └── Stats.h
│
├── Presentation                 # Presentation Layer
│   ├── Visual
│   │   ├── Sprite.cpp
│   │   ├── Sprite.h
│   │   ├── Marker.cpp
│   │   └── Marker.h
│   └── CameraManager.cpp
│       CameraManager.h
│
├── Infrastructure               # Systems & Utility Layer
│   ├── InventorySystem.cpp
│   ├── InventorySystem.h
│   ├── CameraSystem.cpp
│   ├── CameraSystem.h
│   ├── EntitySystem.cpp
│   └── EntitySystem.h
│
├── register_types.cpp
├── register_types.h
└── SConstruct
====
| Node Godot                           | C++ Class / File                           | Notes                                               |
| ------------------------------------ | ------------------------------------------ | --------------------------------------------------- |
| `ACT0/MapManager`                    | `Core/MapManager/MapManager.cpp/h`         | Handle TileMap load, collision, height, pathfinding |
| `ACT0/EntityManager/Clients/Player`  | `Core/EntityManager/Player.cpp/h`          | Logic + Visual + Collision + CameraManager          |
| `ACT0/EntityManager/NPCs/Seller`     | `Core/EntityManager/NPC.cpp/h`             | Bisa subclass NPC lain                              |
| `ACT0/EntityManager/Animals/Chicken` | `Core/EntityManager/Animal.cpp/h`          | Logic & Visual separated                            |
| `ACT0/EntityManager/Enemies/Thief`   | `Core/EntityManager/Enemy.cpp/h`           | AI logic, collision                                 |
| `ACT0/EntityManager/Objects/Chest`   | `Core/EntityManager/Object.cpp/h`          | Interactable objects                                |
| `ACT0/Interiors/House001/MapManager` | `Core/Interiors/House001/MapManager.cpp/h` | Local MapManager untuk interior                     |
| `Visual/Sprite / Visual/Marker`      | `Presentation/Visual/Sprite.cpp/h`         | Visual representation                               |
| `Logic/InventoryData`                | `Gameplay/InventoryManager.cpp/h`          | Player inventory data                               |
| `Logic/Stats`                        | `Gameplay/Stats.cpp/h`                     | Health, level, attributes                           |
| `CameraManager`                      | `Presentation/CameraManager.cpp/h`         | Per-player camera follow                            |
| `InventorySystem`                    | `Infrastructure/InventorySystem.cpp/h`     | Singleton / autoload                                |
| `CameraSystem`                       | `Infrastructure/CameraSystem.cpp/h`        | Singleton / autoload, global effects                |
| `EntitySystem`                       | `Infrastructure/EntitySystem.cpp/h`        | Singleton / global entity updates                   |
