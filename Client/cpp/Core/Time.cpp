// Cara penggunaannya:
// double t = Time::since_start();
// Logger::info("Game running for: " + std::to_string(t));

#include "Time.h"

std::chrono::time_point<std::chrono::steady_clock> Time::start_time =
    std::chrono::steady_clock::now();

double Time::now() {
    auto t = std::chrono::steady_clock::now().time_since_epoch();
    return std::chrono::duration<double>(t).count();
}

double Time::since_start() {
    auto t = std::chrono::steady_clock::now() - start_time;
    return std::chrono::duration<double>(t).count();
}
