#ifndef ENEMY_H
#define ENEMY_H

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

#include "Character.h"
#include "Floor.h"

using namespace std;

class Enemy: public Character {
    public:
    bool hostile;
    Enemy(int x_cor, int y_cor);
    ~Enemy();
    // virtual bool move(int new_x, int new_y, char new_location);
    virtual char get_symbol() = 0;
    // virtual void attacked_by(Character& c);
    // virtual void attack_to(Character& c);
};

#endif
