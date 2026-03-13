#pragma once

#include <string>
#include <unordered_map>
#include <chrono>

class Profiler {
public:
    static void start(const std::string& name);
    static void end(const std::string& name);

private:
    static std::unordered_map<std::string,
        std::chrono::time_point<std::chrono::high_resolution_clock>> timers;
};
