#ifndef GOLD_H
#define GOLD_H
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
#include "Item.h"

using namespace std;

class Gold: public Item{
public:
    Gold(int x, int y, int value, bool pickup);
    char get_symbol() override;
    bool get_pickup() override;

private:
    bool    pickup;
};

#endif
