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
    Human(int x_cor, int y_cor, Floor* floor);
    ~Human();
    int attacked_by(Character& c) override;
    int attack_to(Character& c) override;
};

#endif