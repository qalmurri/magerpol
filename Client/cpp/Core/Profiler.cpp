#include "Profiler.h"
#include <iostream>

std::unordered_map<std::string,
std::chrono::time_point<std::chrono::high_resolution_clock>> Profiler::timers;

void Profiler::start(const std::string& name) {
    timers[name] = std::chrono::high_resolution_clock::now();
}

void Profiler::end(const std::string& name) {

    auto end = std::chrono::high_resolution_clock::now();
    auto start = timers[name];

    auto duration = std::chrono::duration<double, std::milli>(end - start);

    std::cout << name << " : " << duration.count() << " ms" << std::endl;
}
