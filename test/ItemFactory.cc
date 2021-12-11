#include "ItemFactory.h"

std::shared_ptr<Item> ItemFactory::Create(const std::string szName, int x, int y, int value, bool pickup) {
    std::shared_ptr<Item> pItem = nullptr;
    if (szName == "Gold") {
        pItem = std::make_shared<Gold>(x, y, value, pickup);
    }
    else if (szName == "RH") {
        pItem = std::make_shared<RH>(x, y);
    }
    else if (szName == "BA") {
        pItem = std::make_shared<BA>(x, y);
    }
    else if (szName == "BD") {
        pItem = std::make_shared<BD>(x, y);
    }
    else if (szName == "PH") {
        pItem = std::make_shared<PH>(x, y);
    }
    else if (szName == "WA") {
        pItem = std::make_shared<WA>(x, y);
    }
    else if (szName == "WD") {
        pItem = std::make_shared<WD>(x, y);
    }
    else if (szName == "Stair") {
        pItem = std::make_shared<Stair>(x, y);
    }
    return pItem;
}
