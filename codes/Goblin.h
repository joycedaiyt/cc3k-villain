#ifndef GOBLIN_H
#define GOBLIN_H
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
#include "Player.h"
using namespace std;

class Goblin: public Player {
    public:
    Goblin(int x_cor, int y_cor, int chamber);
    ~Goblin();
    void attacked_by(Character& c) override;
    void attack_to(Character& c) override;
};


#endif