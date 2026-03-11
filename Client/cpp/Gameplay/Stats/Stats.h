#ifndef STATS_H
#define STATS_H

class Stats {

public:

    int hp = 100;
    int max_hp = 100;

    int stamina = 100;
    int max_stamina = 100;

    int level = 1;

    Stats();

    void damage(int value);
    void heal(int value);
};

#endif
