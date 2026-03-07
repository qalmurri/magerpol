#include "game/player.h"

Player::Player()
{
    x = 0;
    y = 0;

    vx = 0;
    vy = 0;
}

void Player::update()
{
    x += vx;
    y += vy;
}
