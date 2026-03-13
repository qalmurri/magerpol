#pragma once

#include <string>
#include <unordered_map>

class Config {
public:
    static bool load(const std::string& path);

    static std::string get_string(const std::string& key);
    static int get_int(const std::string& key);
    static float get_float(const std::string& key);

private:
    static std::unordered_map<std::string, std::string> values;
};
