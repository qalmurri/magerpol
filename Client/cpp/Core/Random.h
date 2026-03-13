#pragma once
#include <random>

class Random {
public:
    static void init();

    static int range_int(int min, int max);
    static float range_float(float min, float max);
    static bool chance(float probability);

private:
    static std::mt19937 rng;
};
