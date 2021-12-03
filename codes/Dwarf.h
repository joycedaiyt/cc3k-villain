#ifndef DWARF_H
#define DWARF_H
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

#include "Enemy.h"
using namespace std;

class Drawf: public Enemy {
    public:
    int attacked_by(Character& c) override;
    int attack_to(Character& c) override;
};

#endif