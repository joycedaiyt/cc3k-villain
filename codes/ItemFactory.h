#ifndef ITEMFACTORY_h
#define ITEMFACTORY_h
#include "Item.h"
#include "Gold.h"
#include "Potion.h"
#include "Stair.h"
using namespace std;

class ItemFactory {
    public:
    ItemFactory() = delete;
    static std::shared_ptr<Item> Create(const std::string szName, int x, int y, int value = 0, bool pickup = 0);
};

#endif
