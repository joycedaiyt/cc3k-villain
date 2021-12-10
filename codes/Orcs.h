#ifndef ORCS_H
#define ORCS_H
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

class Orcs: public Enemy {
    public:
    Orcs(int x_cor, int y_cor);
    ~Orcs();
    char get_symbol() override;
    void attacked_by(Character& c) override;
    void attack_to(Character& c) override;
};

#endif