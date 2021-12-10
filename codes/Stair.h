#ifndef STAIR_H
#define STAIR_H
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
#include "Stair.h"
using namespace std;

class Stair: public Item {
    int x_cor;
    int y_cor;
    public:
    Stair(int x, int y);
    char get_symbol() override;
};

#endif
