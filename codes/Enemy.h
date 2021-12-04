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
using namespace std;

class Enemy: public Character {
    string type;
    public:
    string get_type();
    virtual int attacked_by(Character& c);
    virtual int attack_to(Character& c);
};

#endif