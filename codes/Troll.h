#ifndef TROLL_H
#define TROLL_H
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

#include "Floor.h"

class Troll: public Player {
    public:
    Troll(int x_cor, int y_cor, Floor* floor, int chamber);
    ~Troll();
    int attacked_by(Character& c) override;
    int attack_to(Character& c) override;
};


#endif