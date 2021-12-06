#ifndef DRAGON_H
#define DRAGON_H
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

class Dragon: public Enemy {
    public:
    Dragon(int x_cor, int y_cor, Floor* floor);
    ~Dragon();
    int attacked_by(Character& c) override;
    int attack_to(Character& c) override;
};

#endif