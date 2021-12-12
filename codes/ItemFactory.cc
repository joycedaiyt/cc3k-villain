#include "ItemFactory.h"

std::shared_ptr<Item> ItemFactory::Create(const std::string szName, int x, int y, int value, bool pickup) {
    std::shared_ptr<Item> pItem = nullptr;
    if (szName == "Gold") {
        pItem = std::make_shared<Gold>(x, y, value, pickup);
    }
    else if (szName == "0") {
        pItem = std::make_shared<RH>(x, y);
    }
    else if (szName == "1") {
        pItem = std::make_shared<BA>(x, y);
    }
    else if (szName == "2") {
        pItem = std::make_shared<BD>(x, y);
    }
    else if (szName == "3") {
        pItem = std::make_shared<PH>(x, y);
    }
    else if (szName == "4") {
        pItem = std::make_shared<WA>(x, y);
    }
    else if (szName == "5") {
        pItem = std::make_shared<WD>(x, y);
    }
    else if (szName == "Stair") {
        pItem = std::make_shared<Stair>(x, y);
    }
    return pItem;
}
