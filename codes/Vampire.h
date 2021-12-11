#ifndef VAMPIRE_H
#define VAMPIRE_H
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

class Vampire: public Player {
    public:
    Vampire(int x_cor, int y_cor, int chamber);
    ~Vampire();
    void attack_to(Character& c) override;
    void attack_to(Dwarf& c);
};

#endif