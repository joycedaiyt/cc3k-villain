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
    Enemy(int x_cor, int y_cor, Floor* floor);
    ~Enemy();
    virtual void move(string s);
    virtual char get_symbol() = 0;
    virtual int attacked_by(Character& c) = 0;
    virtual int attack_to(Character& c) = 0;
};

#endif
