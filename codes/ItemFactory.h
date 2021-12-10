#ifndef ITEM_FACTORY_H
#define ITEM_FACTORY_H
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <functional>

#include "Item.h"
#include "Gold.h"
#include "Potion.h"

using namespace std;

class CItemFactory
{
public:
    CItemFactory() = delete;
    static std::shared_ptr<Item> Create(const std::string& szName, int x, int y， int value = 0)
	{
        std::shared_ptr<Item> pItem = nullptr;
        if(szName == "Gold")
        {
             pItem = std::make_shared<Gold>(x, y, value);
        }
        else if(szName == "RH")
        {
            pItem = std::make_shared<RH>(x, y);
        }
        else if(szName == "BA")
        {
            pItem = std::make_shared<BA>(x, y);
        }
        else if(szName == "BD")
        {
            pItem = std::make_shared<BD>(x, y);
        }
        else if(szName == "PH")
        {
            pItem = std::make_shared<PH>(x, y);
        }
        else if(szName == "WA")
        {
            pItem = std::make_shared<WA>(x, y);
        }
        else if(szName == "WD")
        {
            pItem = std::make_shared<WD>(x, y);
        }
        return pItem;
	}
};


#endif  //ITEM_FACTORY_H
