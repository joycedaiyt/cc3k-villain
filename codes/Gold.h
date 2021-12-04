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
using namespace std;

class Gold: Item {
    int amount;
    public:
    Gold(int amount);
    int get_amount();
};

#endif