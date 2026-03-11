#include "Stats.h"

Stats::Stats() {}

void Stats::damage(int value) {

    hp -= value;

    if (hp < 0) {
        hp = 0;
    }
}

void Stats::heal(int value) {

    hp += value;

    if (hp > max_hp) {
        hp = max_hp;
    }
}
