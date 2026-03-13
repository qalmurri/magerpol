#include "FileSystem.h"
#include <fstream>
#include <sstream>
#include <filesystem>

std::string FileSystem::read_text(const std::string& path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

bool FileSystem::write_text(const std::string& path, const std::string& content) {
    std::ofstream file(path);

    if (!file.is_open()) {
        return false;
    }

    file << content;
    return true;
}

bool FileSystem::exists(const std::string& path) {
    return std::filesystem::exists(path);
}
