#ifndef HALFLING_H
#define HALFLING_H
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

class Halfling: public Enemy {
    public:
    Halfling(int x_cor, int y_cor);
    ~Halfling();
    char get_symbol() override;
    void attacked_by(Character& c) override;
    void attack_to(Character& c) override;
};

#endif
