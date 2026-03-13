// cara penggunaan:
// int dmg = Random::range_int(10, 20);
// 
// if (Random::chance(0.25f)) {
//     Logger::info("Critical hit!");
// }

#include "Random.h"

std::mt19937 Random::rng;

void Random::init() {
    std::random_device rd;
    rng.seed(rd());
}

int Random::range_int(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

float Random::range_float(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(rng);
}

bool Random::chance(float probability) {
    std::bernoulli_distribution dist(probability);
    return dist(rng);
}
