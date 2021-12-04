#ifndef POTION_H
#define POTION_H
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

struct Potion: public Item {
    string potion_type;
    Potion(int x, int y, string potion_type);
    ~Potion();
};

#endif
