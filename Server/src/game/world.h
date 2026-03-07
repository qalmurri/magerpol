#pragma once

#include <vector>
#include "game/player.h"
#include "game/enemy.h"

class World
{
public:
    void update();

    std::vector<Player> players;
    std::vector<Enemy> enemies;
};
