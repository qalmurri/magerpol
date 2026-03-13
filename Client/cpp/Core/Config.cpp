#include "Config.h"
#include "FileSystem.h"

#include <sstream>

std::unordered_map<std::string, std::string> Config::values;

bool Config::load(const std::string& path) {

    std::string data = FileSystem::read_text(path);

    if (data.empty()) {
        return false;
    }

    std::stringstream stream(data);
    std::string line;

    while (std::getline(stream, line)) {

        size_t pos = line.find('=');

        if (pos == std::string::npos)
            continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        values[key] = value;
    }

    return true;
}

std::string Config::get_string(const std::string& key) {
    return values[key];
}

int Config::get_int(const std::string& key) {
    return std::stoi(values[key]);
}

float Config::get_float(const std::string& key) {
    return std::stof(values[key]);
}
