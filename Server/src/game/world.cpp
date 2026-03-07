#include "game/world.h"

void World::update()
{
    for (auto& player : players)
    {
        player.update();
    }

    for (auto& enemy : enemies)
    {
        enemy.update();
    }
}
