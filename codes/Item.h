#ifndef ITEM_H
#define ITEM_H
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
using namespace std;

class Item {
    public:
    int x_cor;
    int y_cor;
    // this return the symbol for the for renderring
    virtual char get_symbol();
};

#endif