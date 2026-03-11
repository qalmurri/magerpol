#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

class Inventory {

public:

    std::vector<int> items;

    Inventory();

    void add_item(int item_id);
};

#endif
