#pragma once

#include <vector>

class Map {

public:

    bool is_walkable(int x, int y);

private:

    std::vector<int> grid;

};
