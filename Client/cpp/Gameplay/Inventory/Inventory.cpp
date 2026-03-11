#include "Inventory.h"

Inventory::Inventory() {}

void Inventory::add_item(int item_id) {

    items.push_back(item_id);
}
