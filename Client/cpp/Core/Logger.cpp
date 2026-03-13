// Cara penggunaan
// Logger::info("Player spawned");
// Logger::warn("Inventory full");
// Logger::error("Animation not found");

#include "Logger.h"
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void Logger::info(const std::string &msg) {
    UtilityFunctions::print("[INFO] ", msg.c_str());
}

void Logger::warn(const std::string &msg) {
    UtilityFunctions::print("[WARN] ", msg.c_str());
}

void Logger::error(const std::string &msg) {
    UtilityFunctions::print("[ERROR] ", msg.c_str());
}
