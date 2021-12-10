#ifndef HUMAN_H
#define HUMAN_H
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
#include "Floor.h"
using namespace std;

class Human: public Enemy {
    public:
    Human(int x_cor, int y_cor);
    ~Human();
    char get_symbol() override;
    void attacked_by(Character& c) override;
    void attack_to(Character& c) override;
};

#endif