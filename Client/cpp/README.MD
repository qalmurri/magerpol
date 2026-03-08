| Dari          | Ke            | Tujuan                                          |
| ------------- | ------------- | ----------------------------------------------- |
| Client        | MapManager    | Hitung grid / world position                    |
| Client        | EntityManager | Cek collisions / spawn entity                   |
| CombatManager | EntityManager | Hit target, apply damage                        |
| CombatManager | MapManager    | Drop loot setelah enemy mati                    |
| World         | Semua manager | Orchestrasi init, update, dan pointer manajemen |
